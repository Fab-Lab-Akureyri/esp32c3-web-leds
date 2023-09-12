#include <WiFi.h>
#include <bitset>

// Replace with your network credentials
const char *ssid = "Hotspot";
const char *password = "Password";

// LED pins
#define clock D0
#define data D1

uint8_t ledByte = B00000000; 

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliary variables to store the current output state
String output1State = "off";

// Assign output variables to GPIO pins
const int output1 = 2; 

void setup() {
  pinMode(clock, OUTPUT); // make the clock pin an output
  pinMode(data , OUTPUT); // make the data pin an output
  
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output1, OUTPUT);
  digitalWrite(output1, LOW);
  

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  delay(2000);
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

  shiftOut(data, clock, MSBFIRST, B00000000); // send this binary value to the shift register
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  //shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            
            // Set bit for LED 0
            if (header.indexOf("GET /0/on") >= 0) {
              Serial.println("LED 0 on");
              bitSet(ledByte, 0);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register/
            } else if (header.indexOf("GET /0/off") >= 0) {
              Serial.println("LED 0 off");
              bitClear(ledByte, 0);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register
            } 

            // Set bit for LED 1
            if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("LED 1 on");
              bitSet(ledByte, 1);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register/
            } else if (header.indexOf("GET /1/off") >= 0) {
              Serial.println("LED 1 off");
              bitClear(ledByte, 1);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register
            } 

            // Set bit for LED 2
            if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("LED 2 on");
              bitSet(ledByte, 2);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register/
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("LED 2 off");
              bitClear(ledByte, 2);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register
            } 

            // Set bit for LED 3
            if (header.indexOf("GET /3/on") >= 0) {
              Serial.println("LED 3 on");
              bitSet(ledByte, 3);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register/
            } else if (header.indexOf("GET /3/off") >= 0) {
              Serial.println("LED 3 off");
              bitClear(ledByte, 3);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register
            } 

            // Set bit for LED 4
            if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("LED 4 on");
              bitSet(ledByte, 4);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register/
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("LED 4 off");
              bitClear(ledByte, 4);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register
            }

            // Set bit for LED 5
            if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("LED 5 on");
              bitSet(ledByte, 5);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register/
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("LED 5 off");
              bitClear(ledByte, 5);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register
            } 

            // Set bit for LED 6
            if (header.indexOf("GET /6/on") >= 0) {
              Serial.println("LED 6 on");
              bitSet(ledByte, 6);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register/
            } else if (header.indexOf("GET /6/off") >= 0) {
              Serial.println("LED 6 off");
              bitClear(ledByte, 6);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register
            } 

            // Set bit for LED 7
            if (header.indexOf("GET /7/on") >= 0) {
              Serial.println("LED 7 on");
              bitSet(ledByte, 7);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register/
            } else if (header.indexOf("GET /7/off") >= 0) {
              Serial.println("LED 7 off");
              bitClear(ledByte, 7);
              shiftOut(data, clock, MSBFIRST, ledByte); // send this binary value to the shift register
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            client.println("<style> body { display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0; }");
            client.println(".button { width: 60px; height: 60px; border-radius: 0%; background-color: #3498db; color: #fff; font-size: 24px; display: inline-flex; justify-content: center; align-items: center; margin: 5px; }");
            client.println(".top-line { display: flex; justify-content: center;}");        
            client.println(".stem { display: flex; flex-direction: column; align-items: center; }");
            client.println(".bottom-curve { display: flex; justify-content: left; } </style>");

            // Web Page Heading
            client.println("<body><h1>\"J\" LED display</h1>");            
            client.println("<div class=\"letter-j\">");
            // Top line of J
            client.println("<div class=\"top-line\">");
            for(int i = 0; i < 3; i++){
              if (bitRead(ledByte, i)) {
                client.println("<a href=\"/" + String(i) + "/off\"><div class=\"button\">Off</div></a>");
              } else {
                client.println("<a href=\"/" + String(i) + "/on\"><div class=\"button\">On</div></a>");
              } 
            }
            client.println("</div>");

            // Stem part of J
            client.println("<div class=\"stem\">");
            for (int i = 3; i < 6; i++){
              if (bitRead(ledByte, i)) {
                client.println("<a href=\"/" + String(i) + "/off\"><div class=\"button\">Off</div></a>");
              } else {
                client.println("<a href=\"/" + String(i) + "/on\"><div class=\"button\">On</div></a>");
              } 
            }
            client.println("</div>");

            // Bottom curve of J
            client.println("<div class=\"bottom-curve\">");
            for (int i = 7; i > 5; i--){
              if (bitRead(ledByte, i)) {
                client.println("<a href=\"/" + String(i) + "/off\"><div class=\"button\">Off</div></a>");
              } else {
                client.println("<a href=\"/" + String(i) + "/on\"><div class=\"button\">On</div></a>");
              } 
            }
            client.println("</div>");

            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}