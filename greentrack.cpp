#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHT_PIN 12
#define DHTTYPE DHT22
DHT dht(DHT_PIN, DHTTYPE);
#define LDR_PIN 34

// configurações de rede e MQTT
const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";
const char* BROKER_MQTT = "broker.hivemq.com";
const int BROKER_PORT = 1883;
const char* TOPIC_TEMPERATURA = "/hidrogenio/temperatura";
const char* TOPIC_LUMINOSIDADE = "/hidrogenio/luminosidade";
const char* TOPIC_ALERTA = "/hidrogenio/alerta";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  Serial.print("Conectando ao WiFi...");
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}
void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao broker MQTT...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("Conectado ao broker!");
    } else {
      Serial.print("Falha ao conectar. Código de erro: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}
void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(BROKER_MQTT, BROKER_PORT);
  dht.begin();
  Serial.println("Sistema inicializado.");
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  float temperatura = dht.readTemperature();
  bool alertaDHT = false;
  if (!isnan(temperatura)) {
    // Publicar a temperatura no tópico MQTT
    String payload = String(temperatura);
    client.publish(TOPIC_TEMPERATURA, payload.c_str());
    Serial.print("Temperatura enviada: ");
    Serial.println(payload);

    // verifica limites e enviar alerta de temperatura
    if (temperatura > 30.0) {
      alertaDHT = true;

      //a eletrólise é realizada a temperaturas de 25°C a 80°C acima de 80°C, o risco de sobreaquecimento dos componentes e a possível degradação do eletrólito tornam-se preocupações
      //o valor de 30°C do sensor DHT será usado para representar a temperatura crítica de 80°C.

      client.publish(TOPIC_ALERTA, "Alerta! Temperatura da eletrólise acima de 80°C.");
      Serial.println("Alerta enviado: Temperatura da eletrólise acima de 80°C.");
    }
  } else {
    Serial.println("Erro ao ler o sensor.");
  }

  int ldrValue = analogRead(LDR_PIN);
  bool alertaLDR = false;
  String luminosidadePayload = String(ldrValue);
  client.publish(TOPIC_LUMINOSIDADE, luminosidadePayload.c_str());
  Serial.print("Fluxo de Hidrogênio enviado: ");
  Serial.println(luminosidadePayload);

  // envia um alerta se o fluxo de hidrogênio estiver abaixo de 200 (fluxo baixo)
  if (ldrValue < 200) {
    alertaLDR = true;
    client.publish(TOPIC_ALERTA, "Alerta! Fluxo de hidrogênio muito baixo.");
    Serial.println("Alerta enviado: Fluxo de hidrogênio muito baixo.");
  }
  // envia um alerta se o fluxo de hidrogênio estiver acima de 1000 (fluxo muito alto)
  if (ldrValue > 1000) {
    alertaLDR = true;
    client.publish(TOPIC_ALERTA, "Alerta! Fluxo de hidrogênio muito alto.");
    Serial.println("Alerta enviado: Fluxo de hidrogênio muito alto.");
  }
  delay(1000);
}
