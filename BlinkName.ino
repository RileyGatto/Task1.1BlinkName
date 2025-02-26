/* R = o - o 
   I = o o
   L = o - o o
   E = o
   Y = - o - -
*/


const int Dot = 500;
const int Dash = 1500;
const int Wait = 500;
const int Next = 1500;
#define buttonPin  A2
bool restart = false;


int Name[][4] = {
  {Dot,Dash,Dot,0},
  {Dot,Dot,0,0},
  {Dot,Dash,Dot,Dot},
  {Dot,0,0,0},
  {Dash,Dot,Dash,Dash}
};

void display(const int &Time) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(Time);
  digitalWrite(LED_BUILTIN, LOW);
  delay(Wait);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void morse() {
    for(int i = 0; i < 5; i++) {
          
        for(int j = 0; j < 4; j++) {
          if(digitalRead(buttonPin) == HIGH) restart = true;
          if(restart) return;
          
          
          int symbol = Name[i][j];

          if(symbol == Dash) {
            display(Dash);
          }
          else if(symbol == Dot) {
            display(Dot);
          }
        }
        delay(Next);
    }          
}

void check() {
  
  if(digitalRead(buttonPin) == HIGH) {
    
    restart = false;
    morse();
  }

  
}

void loop() {
  check();
}
