#include <stdio.h>                    //Libraries are imported
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
char Operation[100];                   //Variables are initialized
char Choice[100];
char advChoice[100];

float memory[1000];

char Mode;

int spot=0;
int valid=0;
int decimal =0;
int len=0;
char a[100]; 
char b[100];
float num1;
float num2;
float vara=0;
float varb=0;
float varc=0;
float vard=0;
float vare=0;
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float Select(){
  valid=0;
  while(valid!=1){
    printf("Welcome to my Command-Line Calculator (CLC)\nDeveloper: Ali Ghosn\nVersion: 1\n-----------------------------------------------------------\nPlease select one of the following items:\nB) - Binary Mathematical Operations such as addition and subtraction.\nU) - Unary Mathematical Operations, such as square root, and log.\nA) - Advances Mathematical Operations, using variables, arrays.\nV) – Define variables and assign them values.\nM) - Access Memory.\nR) - Reset memory.\nX) - Exit\n");//Prints the menu
    scanf("%s", Choice);//Gets the users choice of operation
    Choice[0] = tolower(Choice[0]);
    if(strlen(Choice)!=1)
      valid=0;
    else if(Choice[0]=='b' || Choice[0]=='u' || Choice[0]=='a' || Choice[0]=='v' || Choice[0]=='m'|| Choice[0]=='r'|| Choice[0]=='x')
      valid =1;
  }
  valid=0;
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float addMemory(float a){
  memory[spot] = a;
  spot++;
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float mainSelect(){
  valid=0;
  while(valid!=1){
    printf("Please select your option ( B (Binary operation), U (Unary operation) , A (Advanced), V (Variables), M (Memory), R (Reset), X (Exit))\n");
    scanf("%s", Choice);//Gets the users choice of operation
    Choice[0] = tolower(Choice[0]);
    if(strlen(Choice)!=1)
      valid=0;
    else if(Choice[0]=='b' || Choice[0]=='u' || Choice[0]=='a' || Choice[0]=='v' || Choice[0]=='m' || Choice[0]=='r' || Choice[0]=='x')
      valid =1;
  }
  valid=0;
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float firstNum(){
  valid=0;
  while(valid != 1){
    valid=1;
    printf("Please enter the first number: ");                     
    scanf("%s", a);
    len = strlen(a);
    while (len > 0){                                 //Makes sure the user input is a valid number
      len--;
      if(!isdigit(a[len])){
        if(valid==1){
          if(len==0 && a[len]=='-')
            valid=1;
          else if(decimal==0 && a[len]=='.'){
            valid=1;
            decimal=1;
          }
          else
            valid=0;
        }
      }
    }
  }
  decimal=0;         //Variables to check if input is valid are reset
  valid = 0; 
  return num1 = strtof(a,NULL); 
}

//|-----------------------------------------------------------------------------------------------------------------------------------------------|
char binaryOperation(){
  valid =0;
  while(valid != 1){                      //Makes sure the user inputs a valid operator
    printf("Please enter the operation ( + , - , * , /, %%, ^(for power)): ");
    scanf("%s", Operation);
    len = strlen(Operation);
    if(len==1){
      if(Operation[0]=='+' || Operation[0]=='-' || Operation[0]=='*' || Operation[0]=='/' || Operation[0]=='%' || Operation[0]=='^')
        valid=1;
    }
  }
  valid = 0;
  return Operation[0];
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float secondNum(){
  while(valid != 1){
    valid=1;
    if(Operation[0]=='/' || Operation[0]=='%'){                   //The denom cant be 0 in both these cases so they are grouped
      printf("Please enter the second number(not 0): ");
      scanf("%s", b);
      len = strlen(b);
      if(len==1 && b[0]=='0')                                     //Makes sure the user input is a number that is not 0
        valid=0;
      else{
        while (len > 0){
          len--;
          if(!isdigit(b[len])){
            if(valid==1){
              if(len==0 && b[len]=='-')
                valid=1;
              else if(decimal==0 && b[len]=='.'){
                valid=1;
                decimal=1;
              }
              else
                valid=0;
            }
          }
        }
      }  
    }
    else{
      printf("Please enter the second number: ");      //All other cases are grouped because there are minimal restrictions
      scanf("%s", b);
      len = strlen(b);
      while (len > 0){                                //Makes sure a valid number is taken
        len--;
        if(!isdigit(b[len])){
          if(valid==1){
            if(len==0 && b[len]=='-')
              valid=1;
            else if(decimal==0 && b[len]=='.'){
              valid=1;
              decimal=1;
            }
            else
              valid=0;
          }
        }
      }
      if(Operation[0]=='^' && strtof(a,NULL)==0 && strtof(b,NULL)<=0)   //Special case to decline 0^(0 or any negative number)
        valid=0;
    } 
  } 
  decimal=0;       //Checking variables are reset
  valid = 0;
  return num2 = strtof(b,NULL);
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float binaryOption(float x,char y,float z){
  if(y=='+'){                         //Statement is printed based on the operator
    printf("The result is: %.2f\n",x+z);  
    addMemory(x+z);
  }

  else if(y=='-'){
    printf("The result is: %.2f\n",x-z);  
    addMemory(x-z);
  }
  
  else if(y=='*'){
    printf("The result is: %.2f\n",x*z);  
    addMemory(x*z);
  }
  
  else if(y=='/'){
    printf("The result is: %.2f\n",x/z);
    addMemory(x/z);  
  }

  else if(y=='%'){
    printf("The result is: %.2f\n",fmod(x,z)); 
    addMemory(fmod(x,z)); 
  }

  else if(y=='^'){
    printf("The result is: %.2f\n",pow(x,z));
    addMemory(pow(x,z));  
  }
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
char unaryOperation(){
  valid =0;
  while(valid != 1){
    printf("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ): ");
    scanf("%s", Operation);                //Takes the operation from user               
    Operation[0] = tolower(Operation[0]);                                  
    len = strlen(Operation);
    if(len==1){      //Makes sure a valid input is given for the operation
      if(Operation[0]=='s' || Operation[0]=='l' || Operation[0]=='e' || Operation[0]=='c' || Operation[0]=='f')
        valid=1;
    }
  }
  valid=0;
  return Operation[0];
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float unaryNumber(){
  valid=0;
  while(valid != 1){
    valid=1;
    if(Operation[0]=='s'){           //If sqrt is chosen
      printf("Enter a positive value: ");
      scanf("%s", a);
      len = strlen(a);
      while (len > 0){                    //Makes sure the number is not negative and is a valid number
        len--;
        if(!isdigit(a[len])){
          if(valid==1){
            if(decimal==0 && a[len]=='.'){
              valid=1;
              decimal=1;
            }
            else
              valid=0;
          }
        }
      }
    }
    if(Operation[0]=='l'){         //If log is chosen
      valid=1;
      printf("Enter a value bigger than 0: "); 
      scanf("%s", a);
      len = strlen(a);
      while (len > 0){             //Makes sure the input is a number bigger than 0
        len--;
        if(!isdigit(a[len])){
          if(valid==1){
            if(decimal==0 && a[len]=='.'){
              valid=1;
              decimal=1;
            }
            else
              valid=0;
          }
        }
      }
      if(a[0]=='0' && strlen(a)==1)
        valid=0;
    }
    if(Operation[0]=='c' || Operation[0]=='f' || Operation[0]=='e'){ //Other cases with no restrictions are grouped
        valid=1;
        printf("Enter a value: ");
        scanf("%s", a);
        len = strlen(a);
        while (len > 0){             //Makes sure the input is a number
          len--;
          if(!isdigit(a[len])){
            if(valid==1){
              if(len==0 && a[len]=='-')
                valid=1;
              else if(decimal==0 && a[len]=='.'){
                valid=1;
                decimal=1;
              }
              else
                valid=0;
            }
          }
        }
    }
  }
  decimal=0;   //Checking variables are checked
  valid = 0;
  return num1 = strtof(a,NULL);
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float unaryOption(char x, float y){
  if(x=='s'){
    printf("The result is: %.2f\n",sqrt(y));
    addMemory(sqrt(y));
  }
  else if(x=='l'){
    printf("The result is: %.2f\n",log10(y));
    addMemory(log10(y));
  }
  else if(x=='e'){
    printf("The result is: %.2f\n",exp(y));
    addMemory(exp(y));
  }
  else if(x=='c'){
    printf("The result is: %.2f\n",ceil(y));
    addMemory(ceil(y));
  }
  else if(x=='f'){
    printf("The result is: %.2f\n",floor(y));
    addMemory(floor(y));
  }
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float isVariable(char* num){
  num[0] = tolower(num[0]);   //Makes sure user input is valid
  len = strlen(num);
  if(len==1){
    if(num[0]=='a' || num[0]=='b' || num[0]=='c' || num[0]=='d' || num[0]=='e')
      return 1;
  }
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
char variable(){
  valid=0;
  while(valid != 1){
    printf("Please enter the name of the variable ( A single character between 'a' to 'e' ): ");
    scanf("%s", Operation);
    valid = isVariable(Operation);
  }
  valid = 0;
  return Operation[0];
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float setVariable(char var, float num){
  if(var=='a')               //Number is assigned to variable
    vara=num;

  else if(var=='b')
    varb=num;

  else if(var=='c')
    varc=num;
  
  else if(var=='d')
    vard=num;
  
  else if(var=='e')
    vare=num;
  printf("Variable %c is set to: %.2f\n",var,num); //Prints the preformed assignment
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float variableValue(){
  valid=0;
  while(valid!=1){    //Value of variable is taken
    valid = 1;
    printf("Please enter a value to assign to the variable: ");
    scanf("%s", a);
    len = strlen(a);
    while (len > 0){                               //Makes sure the input is a number
          len--;
          if(!isdigit(a[len])){
            if(valid==1){
              if(len==0 && a[len]=='-')
                valid=1;
              else if(decimal==0 && a[len]=='.'){
                valid=1;
                decimal=1;
              }
              else
                valid=0;
            }
          }
        }
  }
valid=0;
return strtof(a,NULL); 
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float advancedStartMenu(){
  valid =0;
  while(valid!=1){//Loop until valid input is given
    printf("Select one of the following items:\n");                                     //prints the table selection
    printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
    printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
    printf("X) - Exit and back to the main menu\n");
    scanf("%s", advChoice);//Gets the users choice of operation
    advChoice[0] = tolower(advChoice[0]);
    if(strlen(advChoice)!=1)                  //Makes sure valid input is given
      valid=0;
    else if(advChoice[0]=='b' || advChoice[0]=='u' || advChoice[0]=='x')
      valid =1;
  } 
  valid=0;
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float firstAdvancedNum(){
  valid=0;
  while(valid != 1){//Loops until valid input
    valid=1;
    printf("Please enter the first number or a variable name ('a' to 'e'): ");
    scanf("%s", a);
    len = strlen(a);
    if(isVariable(a))  //Checks if a variable is input
      valid=1;
    else{                                     //Checks if a valid number is input
      while (len > 0){
        len--;
        if(!isdigit(a[len])){
          if(valid==1){
            if(len==0 && a[len]=='-')
              valid=1;
            else if(decimal==0 && a[len]=='.'){
              valid=1;
              decimal=1;
            }
            else
              valid=0;
          }
        }
      }         
    }
  }
  decimal=0;
  valid = 0;

  if(a[0]=='a')                //num1 is assigned to later be compared
    num1=vara;
  else if(a[0]=='b')
    num1=varb;
  else if(a[0]=='c')
    num1=varc;
  else if(a[0]=='d')
    num1=vard;
  else if(a[0]=='e')
    num1=vare;
  else
    num1 = strtof(a,NULL); 
  return num1;    
}

//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float secondAdvancedNum(){
  valid=0;
  while(valid != 1){//loops until valid input
    valid=1;
    if(Operation[0]=='/' || Operation[0]=='%'){       //These 2 are grouped because input cant be 0
      printf("Please enter the second number or a variable name ('a' to 'e'): ");
      scanf("%s", b);
      len = strlen(b);          //If a variable is input, checks to make sure that variable is not 0
      if(b[0]=='a'){
        if(len==1 && vara!=0)
          valid=1;
        else
          valid =0;
      }
      else if(b[0]=='b'){
        if(len==1 && varb!=0)
          valid=1;
        else
          valid =0;
      }
      else if(b[0]=='c'){
        if(len==1 && varc!=0)
          valid=1;
        else
          valid =0;
      }
      else if(b[0]=='d'){
        if(len==1 && vard!=0)
          valid=1;
        else
          valid =0;
      }
      else if(b[0]=='e'){
        if(len==1 && vare!=0)
          valid=1;
        else
          valid =0;
      }
  
      else{                    //If a normal number is input, makes sure it is valid and not 0
        while (len > 0){
          len--;
          if(!isdigit(b[len])){
            if(valid==1){
              if(len==0 && b[len]=='-')
                valid=1;
              else if(decimal==0 && b[len]=='.'){
                decimal=1;
              }
              else
                valid=0;
            }
          }
        }  
        if(b[0]=='0' && strlen(b)==1)
          valid=0;   
      }
  
      if(valid != 1)        //Error message
          printf("Denominator can't be zero.\n");  
      }
      
  
    else{//Other cases are grouped due to minimal restrictions
        printf("Please enter the second number or a variable name ('a' to 'e'): ");
        scanf("%s", b);
        len = strlen(b);
  
        if(b[0]=='a' || b[0]=='b' || b[0]=='c' || b[0]=='d' || b[0]=='e'){//checks to see if a variable is input by the user
          if(len==1)
            valid=1;
        }
        else{//If a non variable is input
          while (len > 0){
            len--;
            if(!isdigit(b[len])){                        //Checks to make sure user input is a valid number
              if(valid==1){
                if(len==0 && b[len]=='-')
                  valid=1;
                else if(decimal==0 && b[len]=='.'){
                  valid=1;
                  decimal=1;
                }
                else
                  valid=0;
              }
            }
          }         
      }
      if(Operation[0]=='^' && num1==0 && num2<=0) //Makes sure 0^(0 or anything less) never occurs
        valid=0;
      } 
    }
  if(b[0]=='a')           //num2 is assigned
    num2=vara;
  else if(b[0]=='b')
    num2=varb;
  else if(b[0]=='c')
    num2=varc;
  else if(b[0]=='d')
    num2=vard;
  else if(b[0]=='e')
    num2=vare;
  else
    num2 = strtof(b,NULL);
  decimal=0;  //Checking variables are reset
  valid = 0;
  return num2;
}

//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float advBinaryOperation(float a,char b, float c){//Takes 2 floats and an operation and depending on the operation prints out a statement
  if(b=='+'){                               //Output based on the operation
    printf("The result is: %.2f\n",a+c);
    addMemory(a+c);  
  }

  else if(b=='-'){
    printf("The result is: %.2f\n",a-c); 
    addMemory(a-c);  
  }
  
  else if(b=='*'){
    printf("The result is: %.2f\n",a*c);  
    addMemory(a*c);  
  }
  
  else if(b=='/'){
    printf("The result is: %.2f\n",a/c);
    addMemory(a/c);  
  }

  else if(b=='%'){
    printf("The result is: %.2f\n",fmod(a,c));
    addMemory(fmod(a,c));  
  }
  else if(b=='^'){
    printf("The result is: %.2f\n",pow(a,c));
    addMemory(pow(a,c));  
  }
return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float advUnaryNumber(){//Makes sure a valid number is given depending on the unary operation
  while(valid != 1){
    valid=1;
    if(Operation[0]=='s'){//if sqrt is chosen
      printf("Please enter a positive number or a variable name ('a' to 'e'): ");//Takes user input
      scanf("%s", a);
      len = strlen(a);  //If a variable is given
      if(a[0]=='a' || a[0]=='b' || a[0]=='c' || a[0]=='d' || a[0]=='e'){
        if(len==1)
          valid=1;
      }
      else{                           //Makes sure a valid number is given
        while (len > 0){
            len--;
            if(!isdigit(a[len])){
              if(valid==1){
                if(decimal==0 && a[len]=='.'){
                  valid=1;
                  decimal=1;
                }
                else
                  valid=0;
              }
            }
          }
      }
      if(a[0]=='a')          //Num1 is assigned to check if valid for sqrt
        num1=vara;
      else if(a[0]=='b')
        num1=varb;
      else if(a[0]=='c')
        num1=varc;
      else if(a[0]=='d')
        num1=vard;
      else if(a[0]=='e')
        num1=vare;
      else
        num1 = strtof(a,NULL);

      if(num1<0)     //Number cant be less than 0 for sqrt
        valid=0;
    }

    if(Operation[0]=='l'){//If log is chosen
      valid=1;
      printf("Enter a value bigger than 0: ");//Takes user input
      scanf("%s", a);
      len = strlen(a);

      if(a[0]=='a' || a[0]=='b' || a[0]=='c' || a[0]=='d' || a[0]=='e'){  //If variable is given
          if(len==1)
            valid=1;
        }

      else{          // If number is given
        while (len > 0){
          len--;
          if(!isdigit(a[len])){
            if(valid==1){
              if(decimal==0 && a[len]=='.'){
                valid=1;
                decimal=1;
              }
              else
                valid=0;
            }
          }
        }
      }

      if(a[0]=='a')          //Assigns the num to be compared
          num1=vara;
      else if(a[0]=='b')
          num1=varb;
      else if(a[0]=='c')
          num1=varc;
      else if(a[0]=='d')
          num1=vard;
      else if(a[0]=='e')
          num1=vare;
      else
          num1 = strtof(a,NULL);
                
      if(num1<=0)     //Num for log must be > 0
            valid=0;
  }

  if(Operation[0]=='c' || Operation[0]=='f' || Operation[0]=='e'){//  No restrictions so cases are grouped
      valid=1;
      printf("Enter a value: ");//Input is taken from user
      scanf("%s", a);
      len = strlen(a);

      if(a[0]=='a' || a[0]=='b' || a[0]=='c' || a[0]=='d' || a[0]=='e'){//Checks to see if a variable is input
        if(len==1)
          valid=1;
      }

      else{                    //Checks to see if input is valid
        while (len > 0){
          len--;
          if(!isdigit(a[len])){
            if(valid==1){
              if(len==0 && a[len]=='-')
                valid=1;
              else if(decimal==0 && a[len]=='.'){
                valid=1;
                decimal=1;
              }
              else
                valid=0;
            }
          }
        }
      }
  }
}

  decimal=0; //Check variables are reset
  valid = 0;

  if(a[0]=='a')      //Assigns variable num1
    num1=vara;
  else if(a[0]=='b')
    num1=varb;
  else if(a[0]=='c')
    num1=varc;
  else if(a[0]=='d')
    num1=vard;
  else if(a[0]=='e')
    num1=vare;
  else
    num1 = strtof(a,NULL);
  return num1;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float advUnaryOperation(char b, float c){
  if(b=='s'){                          //Prints output based off of operation given
    printf("The result is: %.2f\n",sqrt(c));
    addMemory(sqrt(c));
  }
  else if(b=='l'){
    printf("The result is: %.2f\n",log10(c));
    addMemory(log10(c));
  }
  else if(b=='e'){
    printf("The result is: %.2f\n",exp(c));
    addMemory(exp(c));
  }
  else if(b=='c'){
    printf("The result is: %.2f\n",ceil(c));
    addMemory(ceil(c));
  }
  else if(b=='f'){
    printf("The result is: %.2f\n",floor(c));
    addMemory(floor(c));
  }
  valid = 0;//Check variables are reset
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float advmenu(){//Used to take inputs from user in advanced mode
  valid =0;
  while(valid != 1){
    printf("Please select your option ( B (Binary operation), U (Unary operation), X (Exit and back to the main menu)):\n");//Takes the next input from user for advanced mode
    scanf("%s", advChoice);
    advChoice[0] = tolower(advChoice[0]);//Checks if the input is valid
    if(strlen(advChoice)!=1)
      valid=0;
    else if(advChoice[0]=='b' || advChoice[0]=='u' || advChoice[0]=='x')
      valid =1;
  } 
  valid=0;//check variables are reset
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float advancedMode(){
  advancedStartMenu();
  while(advChoice[0] != 'x'){
    if(advChoice[0] == 'b')
      advBinaryOperation(firstAdvancedNum(),binaryOperation(),secondAdvancedNum());
    else if(advChoice[0]=='u') //If unary is chosen in advanced mode
      advUnaryOperation(unaryOperation(),advUnaryNumber());
    advmenu();
  }
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float memoryUser(){
  printf("The length of the memory list is %d.\n",spot);
  while(Choice[0] == 'm'){
    valid = 0;
    while(valid!=1){
      valid=1;
      printf("Please enter the index spot you want(0 to display the whole list, X to exit): ");
      scanf("%s", b);
      len = strlen(b);
      if(!isdigit(b[0]))
        b[0] = tolower(b[0]);
      if(len==1 && b[0]=='x'){
        valid=0;
        break;
      }
      else{
        while (len > 0){
          len--;
          if(!isdigit(b[len])){
            valid=0;
          }
        }
        if(valid ==1){
          num1 = strtof(b,NULL);
          if(num1<0 || num1>spot)
            valid=0;
        }
      }
    }
    if(len==1 && b[0]=='x')
        break;
    num1 = strtof(b,NULL);
    if(num1==0){
      printf("[");
      for(int i=0;i<spot;i++)
        if(i==spot-1)
          printf("%0.3f",memory[i]);
        else
          printf("%0.3f,",memory[i]);
      printf("]\n");
    }
    else{
      printf("%0.3f\n",memory[(int)num1-1]);
    }  
  }
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
float memoryReset(){
  memset(memory, 0, 100);
  printf("Memory Reset.\n");
  spot=0;
  return 0;
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|
int main(void) {           //Title message is displayed and input is checked until valid
  Select();
  while(Choice[0] != 'x'){//While the user doesnt input exit

    if(Choice[0] == 'b')//If binary is chosen
      binaryOption(firstNum(),binaryOperation(),secondNum());

    else if(Choice[0] == 'u')  //If unary is chosen
      unaryOption(unaryOperation(),unaryNumber());

    else if(Choice[0] == 'v')  //If the user selects variable mode
      setVariable(variable(),variableValue());

    else if(Choice[0] == 'a')//If advanced mode is chosen
      advancedMode();

    else if(Choice[0] == 'm')
      if(spot!=0)
        memoryUser();
      else
        printf("Memory is empty.\n");

    else if(Choice[0]=='r')
      memoryReset();
      
    mainSelect();
  }
printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!");//Exit message
}
//|-----------------------------------------------------------------------------------------------------------------------------------------------|