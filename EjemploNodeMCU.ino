/* Ejemplo NodeMCU con FireBase */

#include <ESP8266WiFi.h> // Manejo de la comunicación WiFi
#include <FirebaseArduino.h> // Conexión con la base de datos

// Información para conectarse a una red inalámbrica
#define WIFI_SSID "" // Coloque entre las comillas el nombre de la red ianlámbrica
#define WIFI_PASSWORD "" // Coloque entre las comillas la contraseña de la red ianlámbrica

// Información para conectarse a la base de datos en Firebase
#define FIREBASE_HOST "" // Coloque entre las comillas el enlace a la base de datos
#define FIREBASE_AUTH "" // Coloque entre las comillas la clave de seguridad de la base de datos

void setup() {
  Serial.begin(115200); // Inicialización del puerto serial
  
  // Conectarse a la red WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("."); // Mandar por el serial mientras no se pueda conectar
    delay(500);
  }
  delay(1000);
  Serial.println();
  Serial.print("Conectadocon direccion: ");
  Serial.println(WiFi.localIP()); // Mardar por el serial la dirección de red

  // Conectarse a la base de datos Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Acá va el código para leer y escribir información en la base se datos
  // Mire las funciones útiles del manual

  // En caso de que la conexión con la base de datos falle
  if (Firebase.failed()) {
    Serial.print("Fallo en la comunicacion: ");
    Serial.println(Firebase.error());
    return;
  }
  delay(3000);
}
