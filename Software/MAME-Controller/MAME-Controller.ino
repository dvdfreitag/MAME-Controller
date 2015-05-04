const int joystick[4] = { 5, 10, 9, 8 };
const int button[6] = { 18, 19, 20, 21, 22, 23 };

int buttonState[6] = { LOW };
int joystickState[4] = { LOW };

void setup() {
  for (int i = 0; i < 4; i++) pinMode(joystick[i], INPUT);
  for (int i = 0; i < 6; i++) pinMode(button[i], INPUT);
  
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < 4; i++)
  {
    int state = digitalRead(joystick[i]);
    
    if (state == HIGH && joystickState[i] == LOW)
    {
      joystickState[i] = state;
      
      switch (i)
      {
        case 0:
          Serial.print("DOWN");
          Keyboard.press(KEY_DOWN_ARROW);
          break;
        case 1:
          Serial.print("RIGHT");
          Keyboard.press(KEY_RIGHT_ARROW);
          break;
        case 2:
          Serial.print("UP");
          Keyboard.press(KEY_UP_ARROW);
          break;
        case 3:
          Serial.print("LEFT");
          Keyboard.press(KEY_LEFT_ARROW);
          break;
      }
      
      Serial.println(": pressed");
      break;
    }
    else if (state == LOW && joystickState[i] == HIGH)
    {
      joystickState[i] = state; 
      
      switch (i)
      {
        case 0:
          Serial.print("DOWN");
          Keyboard.release(KEY_DOWN_ARROW);
          break;
        case 1:
          Serial.print("RIGHT");
          Keyboard.release(KEY_RIGHT_ARROW);
          break;
        case 2:
          Serial.print("UP");
          Keyboard.release(KEY_UP_ARROW);
          break;
        case 3:
          Serial.print("LEFT");
          Keyboard.release(KEY_LEFT_ARROW);
          break;
      }
      
      Serial.println(": released");
      break;
    }
  }
  
  // For some reason, buttons 4 and 5 are not working correctly, so only loop on 0-3
  for (int i = 0; i < 4; i++)
  {
    int state = digitalRead(button[i]);
    
    if (state == HIGH && buttonState[i] == LOW)
    {
      buttonState[i] = state;
      
      switch (i)
      {
        case 0:
          Serial.print("White");
          Keyboard.press('a');
          break;
        case 1:
          Serial.print("Red");
          Keyboard.press('s');
          break;
        case 2:
          Serial.print("Blue");
          Keyboard.press('d');
          break;
        case 3:
          Serial.print("Black");
          Keyboard.press('z');
          break;
        case 4:
          Serial.print("Green");
          Keyboard.press('x');
          break;
        case 5:
          Serial.print("Yellow");
          Keyboard.press('c');
          break;
      }
      
      Serial.println(": pressed");
      break;
    }
    else if (state == LOW && buttonState[i] == HIGH)
    {
      buttonState[i] = state;
      
      switch (i)
      {
        case 0:
          Serial.print("White");
          Keyboard.release('a');
          break;
        case 1:
          Serial.print("Red");
          Keyboard.release('s');
          break;
        case 2:
          Serial.print("Blue");
          Keyboard.release('d');
          break;
        case 3:
          Serial.print("Black");
          Keyboard.release('z');
          break;
        case 4:
          Serial.print("Green");
          Keyboard.release('x');
          break;
        case 5:
          Serial.print("Yellow");
          Keyboard.release('c');
          break;
      }
      
      Serial.println(": released");
      break;
    }
  }
}

