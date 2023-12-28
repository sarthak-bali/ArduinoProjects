#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 330
#define NOTE_F 349

#define ACTIVATED LOW

const int buzzer = 3;

const int BUTTON_C = 12;
const int BUTTON_D = 11;
const int BUTTON_E = 10;
const int BUTTON_F = 9;

void setup() 
{
  pinMode(buzzer, OUTPUT);

  pinMode(BUTTON_C, INPUT);
    digitalWrite(BUTTON_C, HIGH);
  pinMode(BUTTON_D, INPUT);
    digitalWrite(BUTTON_D, HIGH);
  pinMode(BUTTON_E, INPUT);
    digitalWrite(BUTTON_E, HIGH);
  pinMode(BUTTON_F, INPUT);
    digitalWrite(BUTTON_F, HIGH);
}

void loop() 
{
  while(digitalRead(BUTTON_C) == ACTIVATED);
  {
    tone(buzzer, NOTE_C);
  }
  while(digitalRead(BUTTON_D) == ACTIVATED);
  {
    tone(buzzer, NOTE_D);
  }
  while(digitalRead(BUTTON_E) == ACTIVATED);
  {
    tone(buzzer, NOTE_E);
  }
  while(digitalRead(BUTTON_F) == ACTIVATED);
  {
    tone(buzzer, NOTE_F);
  }

}
