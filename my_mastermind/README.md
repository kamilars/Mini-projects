# my_mastermind

## _Input format_

To start the game, the user enters a line in terminal in the following format:

```
./my_mastermind -c [code] -t [attempts]
```
* The game will also work if the number of attempts is written first and then goes the code
```
./my_mastermind -t [attempts] -c [code]
```
> [attempts] and [code] should be replaced with numbers

* The game will also work if the code and / or the number of attempts are not included in the command
```
./my_mastermind -c [code]

./my_mastermind -t [attempts]

./my_mastermind
```
> In this case, the code will be a random number and 10 attempts will be given
### Code requirements
1. It should be a 4-digit number
2. It should not contain repeating elements
3. The elements should be digits from 0 to 7

---

## _Input processing_
### Identifying if the attempts and code entered
  First, we check if the user entered the 4-digit code and the number of attempts by checking 
  ```
    for (int i = 0; i < argc; i++) {
        if (my_strcmp("-c", argv[i]) == 0) {
            c = i + 1;
        }
        if (my_strcmp("-t", argv[i]) == 0) {
            t = i + 1; 
            attempts = my_atoi(argv[t]);
        }
    }
  ```
  In the code above, we check if any of the arguments contain "-c" or / and "-t" to identify if the user entered the code and the number of attempts. If yes, we store their positions in __c__ and __t__ variables. Otherwise, these variables will be 0. If there is no "-t" among the arguments, the number of attempts (__attempts__ variable) will be kept as 10.

### Code: randomizing or copying from arguments

The code will be stored in an array of 4 char elements called __num__:
```
char num[4];
```
If the variable __c__ is equal to zero, which means that the user didn't enter the code, it will be randomized digit by digit:
```
if (c == 0) { 
    srand(time(NULL));

    int i = 0;
    char randDigit;

    while (i < 4) {
        randDigit = (rand() % 8) + 48;
        int same = 0;
        for (int j = 0; j < i; j++){
            if (num[j] == randDigit){ // elements should be unique
                same = 1;
                break;
            }
        }
        if (same == 1)
            continue;
        else {
            num[i] = randDigit;
            i++;
        }
    }
}
```
> the code above generates a code with unique elements.

Otherwise, the code will be copied from __argv[c]__ to __num__:
```
else {
    for (int i = 0; i < 4; i++){
        if (argv[c][i] != 34) {
            num[i] = argv[c][i];
        }
    }
}
```
---
## _Game_
### The game will repeat in the external _for_ loop __attempts__ times:
```
for (int i = 0; i < attempts; i++)
```

### Player input: correct or wrong
After the game received the code from the player, it cheks if the player entered the code correctly:
1. It includes digits from 0 to 7:
```
if ((enteredNum[k] < 48) || (enteredNum[k] > 55)){
    correctInp = 0;
    break;
}
```

2. It has no repeating elements:
```
for (int j = 0; j < k; j++){
    if (enteredNum[k] == enteredNum[j]){
        correctInp = 0;
        break;
    }
}
```
> __correctInp__ stores 0 if the input is wrong and 1 if correct. If it is 0, the program notifies the user that the input is incorrect and prompts the user to enter it until it is correct (__do while__ (correctInp != 1) loop).


### Checking if the player guessed the number
* We compare the secret number with the entered number digit by digit. If there are differences, __correct__ variable is assigned to 0. Initially, it was 1.
```
for (int k = 0; k < 4; k++){
    if (enteredNum[k] != num[k]) {
        correct = 0;
        break;
    }
}
```
* If the  __correct__ variable is 1, it means that the user guessed the number, so we congratulate him/her and break the external loop, and the game finishes.
```
if (correct == 1) {
    printf("Congratz! You did it!\n");
    break;
}
```
* In the final nested loop, we count the number of misplaced and well-placed pieces according to the positions of the digits in the __enteredNum__ and __num__ arrays.

```
for (int eni = 0; eni < 4; eni++){
    for (int ci = 0; ci < 4; ci++){
        if ((ci == eni) && (num[ci] == enteredNum[eni])){
            wpp++;
        }
        else if (num[ci] == enteredNum[eni]) {
            mpp++;
        }
    }
}
```

>__correct__ variable stores 0 if the player didn't guess and 1 otherwise.

> __mpp__ and __wpp__ variables stand for misplaced and well placed pieces.

