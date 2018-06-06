/* Example for NodeMCU ESP8266 ans FireBase */

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "helloled-78e56.firebaseio.com"
#define FIREBASE_AUTH "uJxoIO2Untv8ozspgllLaEeMsEYO97gnxzk59vr5"
#define WIFI_SSID "the-net"
#define WIFI_PASSWORD "the-password"

int hora = 0;
float horas = 0;

void setup() {
  Serial.begin(115200);
  
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  delay(1000);
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setBool("encendido", false);
}

void loop() {
  Serial.println("Enviando datos ...");
  Firebase.setBool("encendido", true);
  Serial.print("Leyendo \"tiempo\": ");
  Serial.println(Firebase.getInt("tiempo"));
  delay (1000);

  if (Firebase.failed()) {
    Serial.print("setting /message failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(3000);
}
