void loop() {

  WiFiClient client = server.available();   
  
  if (client) {                             
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          
    String currentLine = "";   
          
    while (client.connected() && currentTime - previousTime <= timeoutTime) { 
      currentTime = millis();
      
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        header += c;
        
        if (c == '\n') {                   
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: keep-alive");
            client.println();

            // Turn on and off your digital LED's
            
            if (header.indexOf("GET /26/on") >= 0) {    
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output[0], HIGH);
            }
             
            else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output[0], LOW);
            }
             
            else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output[1], HIGH);
            }
            
            else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output[1], LOW);
            }
        
            //Creadte the analog values
            if(output26State == "on"){
              analogvalues();
            }
            
            else{                           
              ledcWrite(ledChannel[0],LOW);
              ledcWrite(ledChannel[1],LOW);
              ledcWrite(ledChannel[2],LOW);
            }       
            //your HTML/CSS/JS is Stored in the HTML-method
             client.println(html());        
            
            break;
          } 
          
          else { 
            currentLine = "";
          }
        } 
        
        else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }
    
    header = "";
    client.stop();
    Serial.println("Disconnected.");          //Server disconnected
    Serial.println("");
  }
}
