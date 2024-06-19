# Input Handler

## Description 🔍

A function that handles user input length and condition errors.

## Purpose 🎯

Offer a simpler, more efficient solution for input error handling, replacing repetitive while-loop approaches.

## How does it work? 🤔

### Parameters

Basically, it has 3 parameters:

- the prompt

- the error prompt
  
- the condition function

Its function prototype is:

```c
char* answer = inputHandler("Prompt", "Error prompt", functionCondition);
```

The condition function has 3 possible cases:

- charCondition: there are only strings in the condition

EX: if answer == “1”, then true

```c
int charCondition(char* input){
  if(strcmp("1", input) == 0){
    return 1;
  }
  return 0;
}
```

- numConditionNo0: there are numbers in the condition but no 0

EX: if answer ≥ 20, then true

```c
int numConditionNo0(char* input){
  int num = atoi(input);
  if(num >= 20){
    return 1;
  }
  return 0;
}
```

- numConditionWith0: there are numbers in the condition with a 0

EX: if answer ≤ 20, then true

```c
int numConditionWith0(char* input){
  int num = atoi(input);
  //(your condition && num != 0) || (num == 0 && strcmp("0", input) == 0)
  if((num <= 20 && num != 0) || (num == 0 && strcmp("0", input) == 0)){
    return 1;
  }
  return 0;
}
```

### Why does the 0 matter?

In C, the atoi function (which converts a string to a number) returns 0 if the input string doesn’t contain a number.

EX: the string is “abc”

```c
int num = atoi("abc");
printf("the string 'abc' converted to a number prints out: %d", num);

//it will print 0
```

See the problem here? It returns the same result as the string “0” would.

### Menu example

The menu is the most common use case for the inputHandle function, if you want the user to input a choice for a menu (where the prompt would be 1-Start 2-Quit ), you would need to write something like this:

```c
char* answer = inputHandler("1-Start\n2-Quit\nEnter your choice:\n", "Error! Please enter a number between 1 and 2:\n", menuCondition);
```

The user input is stored in the variable “answer”.

## Demo 👁️

# https://onlinegdb.com/PoeLtN-ea
