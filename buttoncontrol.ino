#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("Andrul", "12345678");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print("...");
    delay(200);
  }
  Serial.println();
  Serial.println("Connected Successfull");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  client = server.available();
  if(client == 1){
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledon HTTP/1.1"){
      delay(200);
      digitalWrite(LED_BUILTIN, LOW);
    }
    if(request == "GET /ledoff HTTP/1.1"){
      delay(200);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    
    // HTML content as a single string
    String htmlContent = 
      "<!DOCTYPE html>"
      "<html lang='en'>"
      "<head>"
      "<meta charset='UTF-8'>"
      "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
      "<title>LED Control</title>"
      "<link href='https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css' rel='stylesheet'>"
      "<style> a { max-width: 200px; display: inline-block; } </style>"
      "</head>"
      "<body>"
      "<div class='container my-5 text-center mt-5'>"
      "<h1 class='mb-4'>LED Control Panel</h1>"
      "<div class='row justify-content-center'>"
      "<div class='col-12 col-md-6 mb-3'>"
      "<a href='/ledon' class='btn btn-success btn-md w-100'>ON</a>"
      "</div>"
      "<div class='col-12 col-md-6 mb-3'>"
      "<a href='/ledoff' class='btn btn-danger btn-md w-100'>OFF</a>"
      "</div>"
      "</div>"
      "<p>LED is " + String(digitalRead(LED_BUILTIN) == LOW ? "ON" : "OFF") + "</p>"
      "</div>"
      "<script src='https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js'></script>"
      "</body>"
      "</html>";

    // Send HTTP response headers and content
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println(htmlContent);  // Send the HTML content
    client.println("");
  }
}
