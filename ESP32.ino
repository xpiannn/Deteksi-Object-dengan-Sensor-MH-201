#define IR_SENSOR_PIN 32  
#define LED_PIN 14        
#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
String Objek;

//konfigurasi wifi
const char* ssid = "qwerty";
const char* pass = "12345678";
const char* server ="http://192.168.59.148";

//variabel kirim data
long zero = 0;
long jeda = 5000; //kirim data waktu

void setup() {
  // Inisialisasi pin
  pinMode(IR_SENSOR_PIN, INPUT); 
  pinMode(LED_PIN, OUTPUT);     

  // Inisialisasi serial monitor
  Serial.begin(115200);
  Serial.println("Program mulai...");

  // WiFi koneksi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print("-");
  }
  Serial.println("Terkoneksi");
}

//konversi string jadi format url
String urlEncode(String str){
  String encodedString= "";
  char c;
  char code0;
  char code1;
  for (int i=0; i < str.length();i++) {
    c = str.charAt(i);
    if(isalnum(c)){
      encodedString += c;
    } else{
      code0 =(c >> 4)& 0xF;
      code1 = (c & 0xF);
      encodedString += '%';
      encodedString += String("0123456789ABCDEF").charAt(code0);
      encodedString += String("0123456789ABCDEF").charAt(code1);
    }
  }
  return encodedString;
}

void loop() {
  // Membaca status sensor infrared
  int sensorValue = digitalRead(IR_SENSOR_PIN);
  
  // Log data sensor ke Serial Monitor/tampilkan nilai sensor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // logika deteksi objek
  if (sensorValue == LOW) { // HIGH sensor mendeteksi objek
    digitalWrite(LED_PIN, HIGH);        // Nyalakan LED
    Serial.println("Objek terdeteksi, LED menyala.");
    Objek = "Terdapat Objek";
  } else { // tidak ada objek
    digitalWrite(LED_PIN, LOW);        // Matikan LED utama
    Serial.println("Tidak ada objek, LED mati.");
    Objek = "Tidak Ada Objek";
  }

  // Log kondisi LED ke Serial Monitor
  Serial.print("LED Utama State: ");
  Serial.println(digitalRead(LED_PIN));
  
  delay(100); // Delay pembacaan sensor

  // Kirim data ke server secara berkala!!!!!!
  if (millis() - zero > jeda) {
    //bangun url request
    String URL = String("") + server + "/tugasiot2024/input.php?sensor_infrared="+ urlEncode(Objek);
    Serial.println(URL);
    //kirim data jika terhubung wifi
    if (WiFi.status() == WL_CONNECTED){
      HTTPClient http;
      http.begin(URL);
      int httpCode = http.GET();
      //cek respon server
      if (httpCode > 0) {
        String payload = http.getString();
        Serial.println(payload);
      }
      http.end();
    }
    zero = millis(); // Reset timer
  }
}
