void analogvalues(){
  if(header.indexOf("GET /?value=")>=0) {
      pos[0] = header.indexOf('=');
      pos[1] = header.indexOf('&');
      valueString = header.substring(pos[0]+1, pos[1]);
      ledcWrite(ledChannel[0],valueString.toInt());
    }
    
    if(header.indexOf("GET /?value2=")>=0) {
      pos[2] = header.indexOf('=');
      pos[3] = header.indexOf('&');
      valueString2 = header.substring(pos[2]+1, pos[3]);
      ledcWrite(ledChannel[1],valueString2.toInt());
    }

     if(header.indexOf("GET /?value3=")>=0) {
      pos[4] = header.indexOf('=');
      pos[5] = header.indexOf('&');
      valueString = header.substring(pos[4]+1, pos[5]);
      ledcWrite(ledChannel[2],valueString3.toInt());
    }
}
