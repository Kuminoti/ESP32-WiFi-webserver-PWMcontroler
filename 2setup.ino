void setup(){
  
  Serial.begin(115200);             
  
  //PWM-Setup
  ledcSetup(ledChannel[0], freq, resolution);  
  ledcAttachPin(pwmpin[0], ledChannel[0]);        
  
  ledcSetup(ledChannel[1], freq, resolution);   
  ledcAttachPin(pwmpin[1], ledChannel[1]);      //Pin PWM-Channel und Frequency
  
  ledcSetup(ledChannel[2], freq, resolution);
  ledcAttachPin(pwmpin[2], ledChannel[2]);

  pinMode(output[0], OUTPUT);               
  pinMode(output[0], OUTPUT);
  
  digitalWrite(output[1], LOW);                 //Outputs low
  digitalWrite(output[1], LOW);    
  
  Serial.print("Verbinden mit ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  #undef ssid
  #undef password
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Connected");
  Serial.println("IP-address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  String html();
  void getvalues();
  void analogvalues();
}
