
#include <WiFiNINA.h> 
#include <BlynkSimpleWiFiNINA.h>

const char* ssid = "MH";    
const char* password = "2222222222";  
char auth[] = "3qNCDrZK4swO0eyXKsLgTFceDs5dZA7F"; 

int fsrPin = 1;     
int fsrReading;    

WidgetLCD lcd(V1);

void notifications() {
      
   if (fsrReading < 100) {

    Blynk.notify("Your laundry detergent is running out. Please buy another.");
    Blynk.email("avery.moorhead42@gmail.com", "Your Laundry Detergent has run out", "Hi Avery, Your laundry detergent has run out. Please buy another.");
    
  }
   else {
    Blynk.notify("You still have enough laundry detergent remaining and you don't need to buy any");
    Blynk.email("avery.moorhead42@gmail.com", "Your Laundry Detergent ", "Hi Avery, You still have enough laundry detergent remaining and you don't need to buy any.");
  }
  
}

void blynkLCD() {

   if (fsrReading < 100) {
    lcd.clear();
    lcd.print(0, 0, "Your Detergent");
    lcd.print(0, 1, "is empty");
  }
  
   else {
    lcd.clear();
    lcd.print(0, 0, "Your Detergent");
    lcd.print(0, 1, "is full");
  }
  
}
 
void setup(void) {
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, password);  
}


void loop(void) {
  Blynk.run();
  fsrReading = analogRead(fsrPin);  
  notifications();
  blynkLCD();
  delay(86400000);
 
 
}
