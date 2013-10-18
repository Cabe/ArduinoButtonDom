// I am really sorry for this terrible code, if it proves fun 
//this weekend I will make it better. I promise!
//Released under GPL V3 - I think that means have at it, but keep it free!

int redbtn = 2;
int blubtn = 3;
int redstate = 0;
int blustate = 0;

int red = 10;           
int redbright = 0;
int redfade = 1;
int redscore;
int redcap;

int grn = 9;
int grnbright = 0;
int grnfade = 1; 
int grnscore;
int grncap;

int blu = 11;
int blubright = 0;
int blufade = 1; 
int bluscore;
int blucap;

int gamelength;
int x = 0;
long previousMillis;
long gametick;

// the setup routine runs once when you press reset:
void setup()  { 
 
  pinMode(red, OUTPUT);
  pinMode(grn, OUTPUT);
  pinMode(blu, OUTPUT);
  pinMode(redbtn, INPUT);
  pinMode(blubtn, INPUT);
  gamelength = 600;
  redscore = 0;
  redcap = 0;
  bluscore = 0;
  blucap = 0;
  previousMillis = 0;
  gametick = 1000;
  Serial.begin(9600);
} 

// the loop routine runs over and over again forever:
void loop()  {
    unsigned long currentMillis = millis();
    
    if(currentMillis - previousMillis > gametick) {
    previousMillis = currentMillis;
    
    if (redcap == 1) redscore = redscore + 1; 
    if (blucap == 1) bluscore = bluscore + 1;
    Serial.print("Red Score: ");
    Serial.println(redscore);
    Serial.print("Blu Score: ");
    Serial.println(bluscore);
    Serial.print("Game Time (ish): ");
    Serial.println((currentMillis/1000));
}   

    
    if ((currentMillis/1000) > gamelength) {

    if (redscore > bluscore) {
      while (x = 100) {
      analogWrite(red, 0);
      delay(200);     
      analogWrite(red, 255);  
      delay(200);
      }
      }

    if (redscore < bluscore) {
      while (x = 100) {
      analogWrite(blu, 0); 
      delay(200);       
      analogWrite(blu, 255); 
      delay(200);
      }
      }

    if (redscore = bluscore) {
      while (x = 100) {
      analogWrite(red, 0);  
      delay(200);           
      analogWrite(red, 255); 
      delay(200);
      analogWrite(red, 0);   
      delay(200);
      analogWrite(blu, 0);   
      delay(200);            
      analogWrite(blu, 255); 
      delay(200);
      analogWrite(blu, 0);   
      delay(200);
      } 
      }
}

  redstate  = digitalRead(redbtn);
  blustate  = digitalRead(blubtn);

  if (redstate == HIGH) {

  blucap = 0;
 
 
  analogWrite(red, redbright);
  analogWrite(blu, blubright);     

 
  delay(40);
  redbright = redbright + redfade;
  blubright = blubright - blufade;

  if (redbright >= 255) {
      redbright = 255;
      
       if (redcap == 0) {
        redscore = redscore + 5;
        redcap = 1;
       }
       
      analogWrite(red, 0);
      delay(200);            
      analogWrite(red, 255);  
      delay(200);
      analogWrite(red, 0);  
      delay(200);           
      analogWrite(red, 255);  
      delay(200);
      analogWrite(red, 0); 
      delay(200);           
      analogWrite(red, 255); 
      delay(200);
      analogWrite(red, 0);  
      delay(200);           
      analogWrite(red, 255); 
      delay(200);
  } 

  if (blubright <= 0) {
    blubright = 0;
  } 
  

  delay(30);
}

else {
  
    analogWrite(red, redbright);
    analogWrite(blu, blubright); 
  }

  if (blustate == HIGH) {

  redcap = 0;
 
  analogWrite(red, redbright);
  analogWrite(blu, blubright);     

  delay(40);
  redbright = redbright - redfade;
  blubright = blubright + blufade;

  if (blubright >= 255) {
      blubright = 255;
      
       if (blucap == 0){
        bluscore = bluscore + 5;
        blucap = 1;
       }
       
      analogWrite(blu, 0); 
      delay(200);          
      analogWrite(blu, 255);  
      delay(200);
      analogWrite(blu, 0);   
      delay(200);            
      analogWrite(blu, 255);  
      delay(200);
      analogWrite(blu, 0);  
      delay(200);            
      analogWrite(blu, 255);   
      delay(200);
      analogWrite(blu, 0);  
      delay(200);           
      analogWrite(blu, 255);  
      delay(200);
  } 

  if (redbright <= 0) {
    redbright = 0;
  } 
  
    delay(30);
}



}
