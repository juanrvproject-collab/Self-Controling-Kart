#include <PS4Controller.h>

// ================= CONFIGURACIÓN =================
char* MAC_PS4 = "01:02:03:04:05:06"; // <--- PON TU MAC AQUÍ

// ================= PINES (DAC) =================
#define PIN_MOTOR_IZQ 25
#define PIN_MOTOR_DER 26

// ================= AJUSTE DE "DRIFT" (ZONA MUERTA) =================
// Ajusta esto mirando lo que sale en la consola.
// Si sueltas el mando y ves valores de 10 o 20, pon esto en 30.
const int ZONA_MUERTA_R2 = 30;    // Para el acelerador
const int ZONA_MUERTA_STICK = 20; // Para el giro

// Variables globales
int throttle = 0; 
int steering = 0; 
int motorIzq = 0;
int motorDer = 0;
int rawR2 = 0;      // Valor crudo del mando
int rawStickX = 0;  // Valor crudo del mando

// Variable para controlar cada cuánto imprimimos en pantalla
unsigned long lastDebugTime = 0;

void setup() {
  // Iniciamos la consola a 115200 baudios
  Serial.begin(115200);
  
  // Seguridad inicial
  dacWrite(PIN_MOTOR_IZQ, 0);
  dacWrite(PIN_MOTOR_DER, 0);

  PS4.begin(MAC_PS4);
  Serial.println("==========================================");
  Serial.println("INICIANDO SISTEMA - ESPERANDO MANDO PS4...");
  Serial.println("==========================================");
}

void loop() {
  if (PS4.isConnected()) {
    
    // --- 1. LECTURAS CRUDAS (RAW) ---
    rawR2 = PS4.R2Value();       // 0 a 255
    rawStickX = PS4.LStickX();   // -127 a 127
    
    // --- 2. FILTRO DE ZONA MUERTA (DRIFT) ---
    
    // Filtro Acelerador
    if (rawR2 < ZONA_MUERTA_R2) {
      throttle = 0;
    } else {
      throttle = rawR2;
    }

    // Filtro Giro
    if (abs(rawStickX) < ZONA_MUERTA_STICK) {
      steering = 0;
    } else {
      steering = rawStickX;
    }

    // --- 3. MEZCLA (ARCADE DRIVE) ---
    int turnFactor = steering * 2; 

    motorIzq = throttle + turnFactor;
    motorDer = throttle - turnFactor;

    // --- 4. LIMITADORES DE SEGURIDAD ---
    if (motorIzq > 255) motorIzq = 255;
    if (motorIzq < 0)   motorIzq = 0;
    
    if (motorDer > 255) motorDer = 255;
    if (motorDer < 0)   motorDer = 0;

  } else {
    // Si no hay mando, todo a cero
    motorIzq = 0;
    motorDer = 0;
    rawR2 = 0;
    rawStickX = 0;
  }

  // --- 5. SALIDA A MOTORES ---
  dacWrite(PIN_MOTOR_IZQ, motorIzq);
  dacWrite(PIN_MOTOR_DER, motorDer);

  // --- 6. IMPRIMIR EN CONSOLA (Cada 200ms) ---
  if (millis() - lastDebugTime > 200) {
    if (PS4.isConnected()) {
      Serial.print("ENTRADA R2 (Raw): ");
      Serial.print(rawR2); // Valor real que envía el mando (para ver el drift)
      Serial.print("\t | "); // Tabulador para separar

      Serial.print("ENTRADA STICK (Raw): ");
      Serial.print(rawStickX); // Valor real del stick
      Serial.print("\t || "); 

      Serial.print("SALIDA MOTORES -> IZQ: ");
      Serial.print(motorIzq);
      Serial.print(" / DER: ");
      Serial.println(motorDer);
    } else {
      Serial.println("... Buscando mando PS4 ...");
    }
    lastDebugTime = millis();
  }

  delay(10); 
}