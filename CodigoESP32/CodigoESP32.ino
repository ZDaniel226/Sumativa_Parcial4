#include <Firebase_ESP_Client.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <addons/TokenHelper.h>

// Pins para el LED RGB
int pinRojo = 15;
int pinVerde = 16;
int pinAzul = 17;

// Conectar a una red WiFi
const char* WIFI_SSID = "WiFi-UETS";
const char* WIFI_PASSWORD = "U3TS-1705";

// Recursos de Firebase
const char* API_KEY = "AIzaSyAW7VVBao7UQ_G4tLwZ_dHMssPDpT_nE1Q";
const char* FIREBASE_PROJECT_ID = "pokedex-dd742";

// CONFIGURAR UN EMAIL Y CONTRASEÑA EN AUTHENTICATION de Firebase
const char* USER_EMAIL = "benitocamela@gmail.com";
const char* USER_PASSWORD = "benito";

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
bool firebaseRequestInProgress = false;

void setupWiFi() {
  Serial.print("Conectando a Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Conectado con IP: ");
  Serial.println(WiFi.localIP());
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.token_status_callback = tokenStatusCallback; // Ver addons/TokenHelper.h
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void setup() {
  Serial.begin(115200);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  setupWiFi();
  setupFirebase();
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED && !firebaseRequestInProgress) {
    firebaseRequestInProgress = true;

    if (Firebase.Firestore.getDocument(&fbdo, FIREBASE_PROJECT_ID, "", "pokedex/pokemon")) {
      StaticJsonDocument<1024> doc;
      DeserializationError error = deserializeJson(doc, fbdo.payload().c_str());
      if (!error) {
        const char* document_name = doc["name"].as<const char*>();
        const char* tipo = doc["fields"]["tipo"]["stringValue"];
        Serial.print("Nombre: ");
        Serial.println(document_name);
        Serial.print("Tipo: ");
        Serial.println(tipo);

        // Aquí puedes agregar tu lógica para encender/apagar los LEDs según el tipo
        if (strcmp(tipo, "normal") == 0) {
    // Color normal: RGB (168, 167, 122)
    analogWrite(pinRojo, 168);
    analogWrite(pinVerde, 167);
    analogWrite(pinAzul, 122);
} else if (strcmp(tipo, "fire") == 0) {
    // Color fuego: RGB (230, 34, 35)
    analogWrite(pinRojo, 230);
    analogWrite(pinVerde, 34);
    analogWrite(pinAzul, 35);
} else if (strcmp(tipo, "water") == 0) {
    // Color agua: RGB (36, 129, 240)
    analogWrite(pinRojo, 36);
    analogWrite(pinVerde, 129);
    analogWrite(pinAzul, 240);
} else if (strcmp(tipo, "electric") == 0) {
    // Color eléctrico: RGB (250, 193, 0)
    analogWrite(pinRojo, 250);
    analogWrite(pinVerde, 193);
    analogWrite(pinAzul, 0);
} else if (strcmp(tipo, "grass") == 0) {
    // Color hierba: RGB (61, 162, 36)
    analogWrite(pinRojo, 61);
    analogWrite(pinVerde, 162);
    analogWrite(pinAzul, 36);
} else if (strcmp(tipo, "ice") == 0) {
    // Color hielo: RGB (61, 162, 36)
    analogWrite(pinRojo, 61);
    analogWrite(pinVerde, 162);
    analogWrite(pinAzul, 36);
} else if (strcmp(tipo, "fighting") == 0) {
    // Color lucha: RGB (255, 129, 0)
    analogWrite(pinRojo, 255);
    analogWrite(pinVerde, 129);
    analogWrite(pinAzul, 0);
} else if (strcmp(tipo, "poison") == 0) {
    // Color veneno: RGB (145, 62, 203)
    analogWrite(pinRojo, 145);
    analogWrite(pinVerde, 62);
    analogWrite(pinAzul, 203);
}else if (strcmp(tipo, "ground") == 0) {
    // Color tierra: RGB (145, 79, 26)
    analogWrite(pinRojo, 145);
    analogWrite(pinVerde, 79);
    analogWrite(pinAzul, 26);
} else if (strcmp(tipo, "flying") == 0) {
    // Color volador: RGB (130, 186, 240)
    analogWrite(pinRojo, 130);
    analogWrite(pinVerde, 186);
    analogWrite(pinAzul, 240);
} else if (strcmp(tipo, "psychic") == 0) {
    // Color psíquico: RGB (239, 63, 122)
    analogWrite(pinRojo, 239);
    analogWrite(pinVerde, 63);
    analogWrite(pinAzul, 122);
} else if (strcmp(tipo, "bug") == 0) {
    // Color bicho: RGB (151, 166, 29)
    analogWrite(pinRojo, 151);
    analogWrite(pinVerde, 166);
    analogWrite(pinAzul, 29);
} else if (strcmp(tipo, "rock") == 0) {
    // Color roca: RGB (175, 170, 129)
    analogWrite(pinRojo, 175);
    analogWrite(pinVerde, 170);
    analogWrite(pinAzul, 129);
} else if (strcmp(tipo, "ghost") == 0) {
    // Color fantasma: RGB (111, 63, 112)
    analogWrite(pinRojo, 111);
    analogWrite(pinVerde, 63);
    analogWrite(pinAzul, 112);
} else if (strcmp(tipo, "dark") == 0) {
    // Color oscuro: RGB (78, 63, 60)
    analogWrite(pinRojo, 78);
    analogWrite(pinVerde, 63);
    analogWrite(pinAzul, 60);
} else if (strcmp(tipo, "dragon") == 0) {
    // Color dragón: RGB (79, 96, 226)
    analogWrite(pinRojo, 79);
    analogWrite(pinVerde, 96);
    analogWrite(pinAzul, 226);
} else if (strcmp(tipo, "steel") == 0) {
    // Color acero: RGB (96, 162, 185)
    analogWrite(pinRojo, 96);
    analogWrite(pinVerde, 162);
    analogWrite(pinAzul, 185);
} else if (strcmp(tipo, "fairy") == 0) {
    // Color hada: RGB (239, 112, 240)
    analogWrite(pinRojo, 239);
    analogWrite(pinVerde, 112);
    analogWrite(pinAzul, 240);
}
else {
    // Si no coincide con ningún tipo conocido, establece el LED en blanco
    analogWrite(pinRojo, 255);
    analogWrite(pinVerde, 255);
    analogWrite(pinAzul, 255);
}
      } else {
        Serial.println("Error al deserializar el JSON recibido de Firebase");
      }
    } else {
      Serial.println("Error al obtener el documento de Firebase");
    }

    firebaseRequestInProgress = false;
  }

  delay(100);
}