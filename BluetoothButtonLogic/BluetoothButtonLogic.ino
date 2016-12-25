char junk;
String inputString="";
int button = 4;
int stateChanged = 0;
int previousState =0;
void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
 pinMode(13, OUTPUT);
 pinMode(button, INPUT);
}

void loop()
{
  int buttonState= 0;
  if(Serial.available()){
    buttonState = digitalRead(button);
    if(previousState!=buttonState){
      stateChanged =1;
      sendTransmission(previousState, buttonState);
      stateChanged =0;
      previousState = buttonState;
    }
    
  }
}

void sendTransmission(int previousState, int buttonState){
  if(buttonState==1){
       Serial.write("button on\n");
    }
  else Serial.write("button off\n");
}
