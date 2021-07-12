#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_mastermind_1.h"

int main(int argc, char** argv) { 

    int c = 0;
    int t = 0;
    int attempts = 10;
    int wpp;
    int mpp;

    /*checking if the user wrote the code and/or number of attempts*/

    for (int i = 0; i < argc; i++) {
        if (my_strcmp("-c", argv[i]) == 0) {
            c = i + 1;
        }
        if (my_strcmp("-t", argv[i]) == 0) {
            t = i + 1; 
            attempts = my_atoi(argv[t]);
        }
    }

    char num[4]; // this array will keep the code that the player has to guess
    
    if (c == 0) { //randomize the code

        srand(time(NULL));

        int i = 0;
        char randDigit;

        while (i < 4) {
            randDigit = (rand() % 8) + 48;
            int same = 0;
            for (int j = 0; j < i; j++){
                if (num[j] == randDigit){
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
    else { // taking code from input
        for (int i = 0; i < 4; i++){
            if (argv[c][i] != 34) {
                num[i] = argv[c][i];
            }
        }
    }

    /* STARTING THE GAME*/

    printf("Will you find the secret code?\n");
    char enteredNum[5];

    for (int i = 0; i < attempts; i++){

        mpp = 0;
        wpp = 0;

        printf("---\nRound %i\n", i);

        /*Check if input is correct (4 unique digits from 0 to 7)*/
        int correctInp;
        do {
            scanf("%s", enteredNum);
            correctInp = 1;
            for (int k = 0; k < 4; k++){
                if ((enteredNum[k] < 48) || (enteredNum[k] > 55)){
                    correctInp = 0;
                    break;
                }

                for (int j = 0; j < k; j++){
                    if (enteredNum[k] == enteredNum[j]){
                        correctInp = 0;
                        break;
                    }
                }
            }
            if (correctInp == 0) {
                printf("Wrong input. Please enter a number consisting of 4 not repeating digits from 0 to 7 inclusively\n");
            }
        } while (correctInp != 1);

        /*Check if the player guessed the number according to the rules of the game*/

        int correct = 1;
        for (int k = 0; k < 4; k++){
            if (enteredNum[k] != num[k]) {
                correct = 0;
                break;
            }
        }

        if (correct == 1) {
            printf("Congratz! You did it!\n");
            break;
        }

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

        printf("Well placed pieces: %i\nmisplaced pieces: %i\n", wpp, mpp);

        if (i == attempts - 1) {
            printf("It was the last attempt. The number was: %c%c%c%c\n", num[0], num[1], num[2], num[3]);
        }
    }
}