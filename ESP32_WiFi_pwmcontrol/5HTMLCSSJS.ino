/*Your Webpage is stored is stored in the html()-funtion in a String.
  with some HTML you can create your own GUI if you want and use 
  some Javascript to make it dynamic.
  
  The client.println() method (Tab3 line 63) will send your HTML
  to your Browser and display it a a webpage.
  Use the 3 sliders to control the PWM-pins 0, 2 and 4 on your ESP-32.
  And use the Button to turn off the digital and analog pinns.
*/

String html(){
String webpage;
if (output26State == "off") {
  
webpage = "<!DOCTYPE html> \
<html lang=\"en\"> \
<head> \
    <meta charset=\"UTF-8\"> \
    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> \
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> \
    <title>Mein Webserver</title> \
    <link rel=\"icon\" href=\"data:,\"> \
    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\"> \
    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin> \
    <link href=\"https://fonts.googleapis.com/css2?family=Gajraj+One&display=swap\" rel=\"stylesheet\"> \
    <style>\
        html {\
            color: white;\
        }\
        body {\
            margin: 0;\
            padding: 0;\
            overflow: hidden;\
            background-color: #000000c4\
        }\
        header {\
            background: linear-gradient(to right, black, #000028);\
            color: white;\
            height: 100px;\
            font-family: \"Gajraj One\";\
        }\
        ul {\
            list-style: none;\
            margin-left: 0;\
            margin-top: 50px;\
        }\
        li{\
            padding-top: 5px;\
        }\
        .main {\
            display: flex;\
            flex-direction: row;\
        }\
        .navbar {\
            width: 175px;\
            height: 100vh;\
            background-color: navy;\
            background: linear-gradient(to bottom, black, navy);\
        }\
        .content {\
            display: flex;\
            flex-direction: column;\
            align-items: center;\
            width: 75%;\
            height: 200px;\
            margin-left: 10%;\
            background-color: black;\
            justify-content: center;\
            margin-top: 50px;\
            border-width: 5px;\
            border-color: white;\
            border-radius: 10px;\
            border-style: solid;\
        }\
        .main-content{\
            display: flex;\
            flex-direction: column;\
            width: 100%\
        }\
        .content2 {\
            display: flex;\
            flex-direction: column;\
            align-items: center;\
            width: 75%;\
            height: 250px;\
            margin-left: 10%;\
            background-color: black;\
            justify-content: center;\
            margin-top: 50px;\
            border-width: 5px;\
            border-color: white;\
            border-radius: 10px;\
            border-style: solid;\
        }\
        .red {\
            -webkit-appearance: none;\
            background-color: red;\
            border-radius: 15px;\
        }\
        .green {\
            -webkit-appearance: none;\
            background-color: green;\
            border-radius: 15px;\
        }\
        .blue {\
            -webkit-appearance: none;\
            background-color: cyan;\
            border-radius: 15px;\
        }\
        .button-on {\
            width: 150px;\
            height: 50px;\
            background-color: green;\
            font-size: large;\
            color: white;\
            font-famiy: \"Gajraj One\"\
        }\
    .button-on:hover{\
        background-color: chartreuse;\
    }\
        .button-off {\
            width: 150px;\
            height: 50px;\
            background-color: red;\
            font-size: large;\
            color: white;\
            font-famiy: \"Gajraj One\" \
        }\
        .button-off:hover{\
            background-color: crimson;\
        }\
    </style>\
    <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script> \
</head> \
  <body> \
    <header> \
      <h1>My Webserver</h1> \
    </header>\
       <div class=\"main\">\
        <div class=\"navbar\">\
            <h3 style=\"text-align: center;\">Github</h3>\
            <ul>\
                <li id=\"ana\">Value1:</li>\
                <li id=\"ana2\">Value1:</li>\
                <li id=\"ana3\">Value1:</li>\
            </ul>\
        </div>\
        <div class=\"main-content\">\
        <div class=\"content\">\
            <p>Wohnzimmerlicht " + output26State + "</p>\
            <input type=\"range\" min=\"0\" max=\"254\" id=\"Slider\"  class=\"red\" onchange=\"Led1(this.value)\"value=\""+valueString+"\">\   
            <input type=\"range\" min=\"0\" max=\"254\" id=\"Slider2\"  class=\"green\" onchange=\"Led2(this.value)\"value=\""+valueString2+"\">\
            <input type=\"range\" min=\"0\" max=\"254\" id=\"Slider3\"  class=\"blue\" onchange=\"Led3(this.value)\"value=\""+valueString3+"\">\
            <p class=\"button-text\"><a href=\"/26/off\"><button class=\"button-off\">OFF</button></a></p>\
        </div>\
        <div class=\"content2\">\
        </div>\
    </div>\
</div>\
    <script>\
            setInterval(() => {\
                let slider1 = document.getElementById(\"Slider\").value;\
                let slider2 = document.getElementById(\"Slider2\").value;\
                let slider3 = document.getElementById(\"Slider3\").value;\
                let text1 = document.getElementById(\"ana\");\
                let text2 = document.getElementById(\"ana2\");\
                let text3 = document.getElementById(\"ana3\");\
                                                        \
                text1.innerHTML = `Value1: ${slider1}`;\
                text2.innerHTML = `Value2: ${slider2}`;\
                text3.innerHTML = `Value3: ${slider3}`;\
            })\
        </script>\
  </body>\
</html>";
}



else{
  webpage = "<!DOCTYPE html> \
<html lang=\"en\"> \
<head> \
    <meta charset=\"UTF-8\"> \
    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> \
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> \
    <title>Mein Webserver</title> \
    <link rel=\"icon\" href=\"data:,\"> \
    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\"> \
    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin> \
    <link href=\"https://fonts.googleapis.com/css2?family=Gajraj+One&display=swap\" rel=\"stylesheet\"> \
    <style>\
        html {\
            color: white;\
        }\
        body {\
            margin: 0;\
            padding: 0;\
            overflow: hidden;\
            background-color: #000000c4\
        }\
        header {\
            background: linear-gradient(to right, black, #000028);\
            color: white;\
            height: 100px;\
            font-family: \"Gajraj One\";\
        }\
        ul {\
            list-style: none;\
            margin-left: 0;\
            margin-top: 50px;\
        }\
        li{\
            padding-top: 5px;\
        }\
        .main {\
            display: flex;\
            flex-direction: row;\
        }\
        .navbar {\
            width: 175px;\
            height: 100vh;\
            background-color: navy;\
            background: linear-gradient(to bottom, black, navy);\
        }\
        .content {\
            display: flex;\
            flex-direction: column;\
            align-items: center;\
            width: 75%;\
            height: 200px;\
            margin-left: 10%;\
            background-color: black;\
            justify-content: center;\
            margin-top: 50px;\
            border-width: 5px;\
            border-color: white;\
            border-radius: 10px;\
            border-style: solid;\
        }\
        .main-content{\
            display: flex;\
            flex-direction: column;\
            width: 100%\
        }\
        .content2 {\
            display: flex;\
            flex-direction: column;\
            align-items: center;\
            width: 75%;\
            height: 250px;\
            margin-left: 10%;\
            background-color: black;\
            justify-content: center;\
            margin-top: 50px;\
            border-width: 5px;\
            border-color: white;\
            border-radius: 10px;\
            border-style: solid;\
        }\
        .red {\
            -webkit-appearance: none;\
            background-color: red;\
            border-radius: 15px;\
        }\
        .green {\
            -webkit-appearance: none;\
            background-color: green;\
            border-radius: 15px;\
        }\
        .blue {\
            -webkit-appearance: none;\
            background-color: cyan;\
            border-radius: 15px;\
        }\
        .button-on {\
            width: 150px;\
            height: 50px;\
            background-color: green;\
            font-size: large;\
            color: white;\
            font-famiy: \"Gajraj One\"\
        }\
    .button-on:hover{\
        background-color: chartreuse;\
    }\
        .button-off {\
            width: 150px;\
            height: 50px;\
            background-color: red;\
            font-size: large;\
            color: white;\
            font-famiy: \"Gajraj One\"\
        }\
        .button-off:hover{\
            background-color: crimson;\
        }\
    </style>\
    <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script> \
</head> \
<body> \
    <header> \
      <h1>My Webserver</h1> \
    </header>\
       <div class=\"main\">\
        <div class=\"navbar\">\
            <h3 style=\"text-align: center;\">Github</h3>\
            <ul>\
                <li id=\"ana\">Value1:</li>\
                <li id=\"ana2\">Value1:</li>\
                <li id=\"ana3\">Value1:</li>\
            </ul>\
        </div>\
        <div class=\"main-content\">\
        <div class=\"content\">\
            <p>Wohnzimmerlicht " + output26State + "</p>\
            <input type=\"range\" min=\"0\" max=\"254\" id=\"Slider\"  class=\"red\" onchange=\"Led1(this.value)\"value=\""+valueString+"\">\   
            <input type=\"range\" min=\"0\" max=\"254\" id=\"Slider2\"  class=\"green\" onchange=\"Led2(this.value)\"value=\""+valueString2+"\">\
            <input type=\"range\" min=\"0\" max=\"254\" id=\"Slider3\"  class=\"blue\" onchange=\"Led3(this.value)\"value=\""+valueString3+"\">\
            <p class=\"button-text\"><a href=\"/26/on\"><button class=\"button-off\">OFF</button></a></p>\
        </div>\
        <div class=\"content2\">\
        </div>\
    </div>\
</div>\
  <script>\
  var slider = document.getElementById(\"Slider\");\
  slider.oninput = function() {\
    slider.value = this.value;\ 
    };\
   $.ajaxSetup({timeout:1000});\
  function Led1(pos) {\
    $.get(\'/?value=\' + pos + \"&\", { Connection: \'close\' });\
  }\
    </script>\
    \
    <script>\
    var slider2 = document.getElementById(\"Slider2\");\
    slider2.oninput = function() {\
      slider2.value = this.value;\ 
    };\
      $.ajaxSetup({timeout:1000});\
      function Led2(pos) {\
      $.get(\'/?value2=\' + pos + \"&\", { Connection: \'close\' });\
  }\
    </script>\
    <script>\
            setInterval(() => {\
                let slider1 = document.getElementById(\"Slider\").value;\
                let slider2 = document.getElementById(\"Slider2\").value;\
                let slider3 = document.getElementById(\"Slider3\").value;\
                let text1 = document.getElementById(\"ana\");\
                let text2 = document.getElementById(\"ana2\");\
                let text3 = document.getElementById(\"ana3\");\
\
                text1.innerHTML = \`Value1: ${slider1}\`; \
                text2.innerHTML = \`Value2: ${slider2}\`; \
                text3.innerHTML = \`Value3: ${slider3}\`; \
            })\
        </script>\
  </body>\
</html>";
}

  return webpage;

}


// <input type=\"range\" min=\"0\" max=\"254\" id=\"Slider\"  class=\"red\" onchange=\"Led1(this.value)\"value=\""+valueString+"\">\   
//      <input type=\"range\" min=\"0\" max=\"254\" id=\"Slider2\"  class=\"green\" onchange=\"Led2(this.value)\"value=\""+valueString2+"\">\
//      <input type=\"range\" min=\"0\" max=\"254\" id=\"Slider3\"  class=\"blue\" onchange=\"Led3(this.value)\"value=\""+valueString3+"\">\
     
