#include "cli.h"

boolean argsEqual(const char* input,const char* test) {
  return strcmp(input,test)==0;
}

void printConsole(String message) {
  Serial.println(CONSOLE_HEADER+message);
}

void trimCmdLineArgs(String* input) {
  unsigned int firstValidChar=-1, lastValidChar=-1;
  for(unsigned int i=0;i<input->length();i++) { //Get start index
    if(input->charAt(i)!=' ') { //If not a space
      if(firstValidChar==-1) {
        firstValidChar=i; //If we hit first non space character, set it to start index
        break;
      }
    }
  }
  for(unsigned int i=input->length()-1;i>=0;i--) { //Get end index
    if(input->charAt(i)!=' ') {
      if(lastValidChar==-1) {
        lastValidChar=i;
        break;
      }
    }
  }
  String output = input->substring(firstValidChar,lastValidChar+1);
  *input = output;
}
void smartSpaceSplit(String line, String* output, unsigned int* outputLength) {
  boolean inQuotes=false;
  int last=0;
  for(unsigned int i=0;i<line.length();i++) {
    char c = line.charAt(i);
    switch(c) {
      case '"':
        inQuotes=!inQuotes;
        break;
      case ' ':
        if(!inQuotes && i>0) {
          String* newOutput;
          *outputLength++;
          if(*outputLength>0) newOutput=(String*)realloc(output,sizeof(String)*(*outputLength));
          else newOutput=(String*)malloc(sizeof(String)*(*outputLength));
          output=newOutput;
          output[*outputLength-1]=line.substring(last,i);
          last=i+1;
          break;
        }
      default: 
        if(i==line.length()-2) {
          String* newOutput;
          *outputLength++;
          if(*outputLength>0) newOutput=(String*)realloc(output,sizeof(String)*(*outputLength));
          else newOutput=(String*)malloc(sizeof(String)*(*outputLength));
          output=newOutput;
          output[*outputLength-1]=line.substring(last,i+2);
          return;
        }
      break;
    }
  }
  return;
}
void parseCmdLineArgs(String* input) {
  trimCmdLineArgs(input);
  
  unsigned int outputLength=0;
  String* output;
  smartSpaceSplit(*input,output,&outputLength);
  for(int i=0;i<outputLength;i++) {
    Serial.println(output[i]);
  }
  
  Serial.println();
  if(argsEqual(input->c_str(),"help")) {
    Serial.println("<--- Available commands --->");
    Serial.println("help                                            - show this page");
    Serial.println("gps status                                      - show GPS status");
    Serial.println("gps get all                                     - show all GPS data");
    Serial.println("gps get latitude                                - get GPS latitude");
    Serial.println("gps get longitude                               - get GPS longitude");
    Serial.println("gps get satellites                              - get GPS satellite count");
  } else if(argsEqual(input->c_str(),"")) {
    Serial.print("");
  } else {
    Serial.println("Unknown command. Type \'help\' for a help page.");
  }
  Serial.print(CONSOLE_HEADER);
}

void cli_init(void) {

    Serial.println(); //Spacer before prompt
    Serial.print(CONSOLE_HEADER); //Initial console characters on boot
}

static String current_input="";
void cli_run(void) {
    //Console input
  if(Serial.available()) {
    char c = Serial.read();
    if(c != '\n' && c != '\r') {
      current_input += c;
      Serial.print(c); //Print back to console to see what you're typing
    }
    if(c=='\n' || c=='\r') { //If incoming data is newline
      parseCmdLineArgs(&current_input); //Send input to be parsed
      current_input=""; //Reset input
    }
  }
}