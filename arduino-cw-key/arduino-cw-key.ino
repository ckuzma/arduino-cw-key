// Set what pin we are keying on
#define KEY_PIN 2
#define DIT_PAUSE 60

// For serial reading
String inputString = "";
bool stringComplete = false;

/*
  [ Sounding intervals as-is: ]
  
  - DIT_PAUSE
    - Single unit, dits, intra-character spaces
  - 3*DIT_PAUSE
    - Three units, dahs, inter-character spaces
  - 7*DIT_PAUSE
    - Seven units, inter-word spaces
    
  [ A note on adjusting DIT_PAUSE above: ]
  - 240 =  5 wpm
  - 120 = 10 wpm
  - 60  = 20 wpm
  - 30  = 40 wpm (realistically as fast as the relay can move)
*/

// The Morse Code alphabet
const String A = ".-";
const String B = "-...";
const String C = "-.-.";
const String D = "-..";
const String E = ".";
const String F = "..-.";
const String G = "--.";
const String H = "....";
const String I = "..";
const String J = ".---";
const String K = "-.-";
const String L = ".-..";
const String M = "--";
const String N = "-.";
const String O = "---";
const String P = ".--.";
const String Q = "--.-";
const String R = ".-.";
const String S = "...";
const String T = "-";
const String U = "..-";
const String V = "...-";
const String W = ".--";
const String X = "-..-";
const String Y = "-.--";
const String Z = "--..";
const String N1 = ".----";
const String N2 = "..---";
const String N3 = "...--";
const String N4 = "....-";
const String N5 = ".....";
const String N6 = "-....";
const String N7 = "--...";
const String N8 = "---..";
const String N9 = "----.";
const String N0 = "-----";
const String PERIOD = ".-.-.-";
const String COMMA  = "--..--";
const String QUMARK = "..--..";
const String EXMARK = "-.-.--";
const String COLON  = "---...";
const String EQUALS = "-...-";
const String PLUS   = ".-.-.";
const String MINUS  = "-....-";
const String SPACE = "\n";

void setup() {
  Serial.begin(9600);
  inputString.reserve(200); // 200 bytes set aside
  pinMode(KEY_PIN, OUTPUT);
  Serial.println("READY");
}

void loop() {
  if(stringComplete) {
    // Convert to upper case
    inputString.toUpperCase();
    Serial.print("\n" + inputString);

    // Get the CW string and key it out
    keyCWText(getCWText(inputString));

    // Erase data, set boolean to false
    inputString = "";
    stringComplete = false;
    Serial.println("\nDONE");
  }
}

void keyCWText(String cwText) {
  for(int x=0; x<cwText.length(); x++) {
    String singleChar = String(cwText.charAt(x));
    if(singleChar == ".") {
      Serial.print(".");
      dit();
      delay(DIT_PAUSE);
    }
    if(singleChar == "-") {
      Serial.print("-");
      dah();
      delay(DIT_PAUSE);
    }
    if(singleChar == " ") {
      Serial.print(" ");
      delay(3*DIT_PAUSE);
    }
    if(singleChar == "\n") {
      Serial.print("| ");
      delay(7*DIT_PAUSE);
    }
  }
}

String getCWText(String inputText) {
  // Place to store the "CWText"
  String cwText = "";
  
  // Iterate through every character in the input
  for(int x=0; x<inputText.length(); x++) {
    String singleChar = String(inputText.charAt(x));
    
    // Messy if statements to convert each thing to its appropriate CW code
    if(singleChar == "A") cwText+= A + " ";
    if(singleChar == "B") cwText+= B + " ";
    if(singleChar == "C") cwText+= C + " ";
    if(singleChar == "D") cwText+= D + " ";
    if(singleChar == "E") cwText+= E + " ";
    if(singleChar == "F") cwText+= F + " ";
    if(singleChar == "G") cwText+= G + " ";
    if(singleChar == "H") cwText+= H + " ";
    if(singleChar == "I") cwText+= I + " ";
    if(singleChar == "J") cwText+= J + " ";
    if(singleChar == "K") cwText+= K + " ";
    if(singleChar == "L") cwText+= L + " ";
    if(singleChar == "M") cwText+= M + " ";
    if(singleChar == "N") cwText+= N + " ";
    if(singleChar == "O") cwText+= O + " ";
    if(singleChar == "P") cwText+= P + " ";
    if(singleChar == "Q") cwText+= Q + " ";
    if(singleChar == "R") cwText+= R + " ";
    if(singleChar == "S") cwText+= S + " ";
    if(singleChar == "T") cwText+= T + " ";
    if(singleChar == "U") cwText+= U + " ";
    if(singleChar == "V") cwText+= V + " ";
    if(singleChar == "W") cwText+= W + " ";
    if(singleChar == "X") cwText+= X + " ";
    if(singleChar == "Y") cwText+= Y + " ";
    if(singleChar == "Z") cwText+= Z + " ";
    if(singleChar == "1") cwText+= N1 + " ";
    if(singleChar == "2") cwText+= N2 + " ";
    if(singleChar == "3") cwText+= N3 + " ";
    if(singleChar == "4") cwText+= N4 + " ";
    if(singleChar == "5") cwText+= N5 + " ";
    if(singleChar == "6") cwText+= N6 + " ";
    if(singleChar == "7") cwText+= N7 + " ";
    if(singleChar == "8") cwText+= N8 + " ";
    if(singleChar == "9") cwText+= N9 + " ";
    if(singleChar == "0") cwText+= N0 + " ";
    if(singleChar == ".") cwText+= PERIOD + " ";
    if(singleChar == ",") cwText+= COMMA + " ";
    if(singleChar == "?") cwText+= QUMARK + " ";
    if(singleChar == "!") cwText+= EXMARK + " ";
    if(singleChar == ":") cwText+= COLON + " ";
    if(singleChar == "=") cwText+= EQUALS + " ";
    if(singleChar == "+") cwText+= PLUS + " ";
    if(singleChar == "-") cwText+= MINUS + " ";
    if(singleChar == " ") cwText += SPACE;
  }

  // Return it
  return cwText;
}

void dit() {
  digitalWrite(KEY_PIN, HIGH);
  delay(DIT_PAUSE);
  digitalWrite(KEY_PIN, LOW);
}

void dah() {
  digitalWrite(KEY_PIN, HIGH);
  delay(3*DIT_PAUSE);
  digitalWrite(KEY_PIN, LOW);
}

void serialEvent() {
  while(Serial.available()) {
    // Capture the new Byte
    char inChar = (char)Serial.read();
    
    // Add to our inputString
    inputString += inChar;

    // Set the flag to true if complete
    if(inChar == '\n') {
      stringComplete = true;
    }
  }
}
