/* Sample string splitters for Adruino
 * written by Balazs Pekar
 * 
 * Developer's Notes:
 * This code is far from perfect. I just wanted to split some text with delimiters into an array.
 * If you want to make your array bigger please change the values of slicedStringLength and slicedString variables.
 */

String rawString = "Sample text|with some delimiters|in a short|yet useful code.";
String splitString[32];
byte splitStringLength = 32;

void setup() {
  delay(2000);
  Serial.begin(9600);
}

void loop() {
  splitter();    
  arrayPrinter();
  delay(2000);
}


void splitter() {
  // cleaning up the array
  for (byte i = 0; i < splitStringLength; i++) {
      splitString[i] = "";
  }  

  // filling the array with delimited text
  int arrayIndexCount = 0;
  for (byte i = 0; i <= rawString.length()+1; i++) {
    if (rawString[i] != '|') {
      splitString[arrayIndexCount] += rawString[i];
      }
     else {
     arrayIndexCount++;
     }
   }
}


void arrayPrinter() {
  for (byte i = 0; i < splitStringLength; i++) {
    Serial.println(splitString[i]);
  }
}
