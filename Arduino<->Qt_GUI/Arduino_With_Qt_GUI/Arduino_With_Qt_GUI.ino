const int LEDIN = 13;
String StringCommand = "";
String Input_Data = "";
bool Is_Data_Complete = false;

void setup() {
  pinMode(LEDIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial_Data_Event();
  if (Is_Data_Complete == true)
  {
    if (StringCommand == "On")
    {
      digitalWrite(LEDIN, HIGH);
      delay(100);
      Serial.println("Data To Application LED IS ON");
    }
    else if (StringCommand == "Off")
    {
      digitalWrite(LEDIN, LOW);
      delay(100);
      Serial.println("Data To Application LED IS OFF");
    }
    Is_Data_Complete = false;
    StringCommand = "";
    Input_Data = "";
  }
}

void Serial_Data_Event()
{
  Serial.flush();
  while(Serial.available())
  {
    char inchar = (char)Serial.read();
    if (inchar == '\n')
    {
      Is_Data_Complete = true;
      StringCommand = Input_Data;
    }
    else Input_Data += inchar;
  }
}