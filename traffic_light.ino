// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2; // the number of the pushbutton pin

// variables will change:
int n = 0; // variable for reading the pushbutton status
int firstGreen = 13;
int firstRed = 8;
int firstYellow = 12;
int secondRed = 2;
int secondYellow = 4;
int secondGreen = 7;

long timer = 0;

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  Serial.print("\n\ndigite um dado");
  Serial.println();

  pinMode(firstGreen, OUTPUT);
  pinMode(firstYellow, OUTPUT);
  pinMode(firstRed, OUTPUT);
  pinMode(secondYellow, OUTPUT);
  pinMode(secondRed, OUTPUT);
  pinMode(secondGreen, OUTPUT);
}

void loop()
{ 
  if (Serial.available() > 0)
  {
    
    n = Serial.read();

    switch (n)
    {
    case 115:

		timer = millis();
		
		digitalWrite(firstRed, HIGH);
		digitalWrite(secondRed, HIGH);
	  
		while (true){
		
		//first cycle
		
		if ((millis()-timer)==1000){
			digitalWrite(firstRed, LOW);
			digitalWrite(firstGreen, HIGH);
		}
		
		if ((millis()-timer)==7000){
			digitalWrite(firstGreen, LOW);
			digitalWrite(firstYellow, HIGH);
		}
		
		if ((millis()-timer)==13000){
			digitalWrite(firstRed, HIGH);
			digitalWrite(firstYellow, LOW);
		}
		
		
		
		//second cycle
		
		if ((millis()-timer)==14000){
			digitalWrite(secondRed, LOW);
			digitalWrite(secondGreen, HIGH);
		}
		
		if ((millis()-timer)==20000){
			digitalWrite(secondGreen, LOW);
			digitalWrite(secondYellow, HIGH);
		}
		
		if ((millis()-timer)==24000){
			digitalWrite(secondRed, HIGH);
			digitalWrite(secondYellow, LOW);
			timer = millis();
		}

      }

    case 114:

      while(true){
          int randomValue = random(1,6);
          digitalWrite(randomValue,HIGH);
          int randomDelay = random(200,400);
          delay(randomDelay); 
        }
      break;

    case 10:
      break;
     
    default:
		break;
     }

    Serial.print("\n\nValor digitado: ");
    Serial.println(n, BIN);
    Serial.print("Valor lido: ");
    Serial.println(n);
    
  }
  Serial.flush();
}