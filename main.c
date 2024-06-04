#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes

char* inputHandle(char* prompt, char* error_prompt, int (*condition)(char* input));
int numConditionNo0(char* input);
int numConditionWith0(char* input);
int charCondition(char* input);

int main(void){

  char* answer = inputHandle("prompt:\n", "error prompt:\n", charCondition);
  return 0;
}


/*
input handle function
*/

char* inputHandle(char* prompt, char* error_prompt, int (*condition)(char* input))
{
  //choose initial buffer size
  size_t buffer_size = 300;

  //allocate dynamically memory input buffer
  char* input = (char*)malloc(buffer_size * sizeof(char));
  if (input == NULL)
  {
      fprintf(stderr, "Memory allocation failed!");
      exit(1);
  }

  //display prompt
  printf("%s", prompt);
  fflush(stdout);

  //read input in stdin
  fgets(input, buffer_size, stdin);
  input[strlen(input) - 1] = '\0';

  //handle length error
  while((strlen(input) + 2) >= buffer_size){
    //clear buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    //change text color to red in terminal
    printf("\033[1;31m");
    //length error prompt
    printf("Length error! Input exceeds maximum input limit. Please enter a shorter input:\n");
    fflush(stdout);
    //reset to black color in terminal
    printf("\033[0m");

    fgets(input, buffer_size, stdin);
    input[strlen(input) - 1] = '\0';
  }

  //handle condition error
  while(condition(input) == 0)
  {
    printf("\033[1;31m");
    //error prompt
    printf("%s", error_prompt);
    fflush(stdout);
    printf("\033[0m");
    
    fgets(input, buffer_size, stdin);
    input[strlen(input) - 1] = '\0';

    //handle length error again inside condition error
    while((strlen(input) + 2) >= buffer_size){
      int c;
      while ((c = getchar()) != '\n' && c != EOF);

      printf("\033[1;31m");
      printf("Length error! Input exceeds maximum input limit. Please enter a shorter input:\n");
      fflush(stdout);
      printf("\033[0m");

      fgets(input, buffer_size, stdin);
      input[strlen(input) - 1] = '\0';
    }
  }
  return input;
}


//all condition templates sorted from simplest to most complex

int charCondition(char* input){
  if(strcmp("1", input) == 0){
    return 1;
  }
  return 0;
}

int numConditionNo0(char* input){
  int num = atoi(input);
  if(num >= 20){
    return 1;
  }
  return 0;
}

int numConditionWith0(char* input){
  int num = atoi(input);
  //normal condition && num != 0) || (num == 0 && strcmp("0",input) == 0))
  if((num <= 20 && num != 0) || (num == 0 && strcmp("0", input) == 0)){
    return 1;
  }
  return 0;
}

