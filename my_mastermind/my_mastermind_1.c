#include "my_mastermind_1.h"
#include <stdio.h>
#include <stdlib.h>

int my_strcmp(char* param_1, char* param_2)
{
    while ((*param_1 != '\0') || (*param_2 != '\0')) {
        if (*param_1 != *param_2) {
            return *param_1 - *param_2;
        }
        param_1++;
        param_2++;
    }
    return 0;
}

int my_atoi(char str[]){
    int i = 0;
    int num = 0;

    while (str[i] != '\0') {
        i++;
    }

    i--;
    int tenPow = 1;

    for (int j = i; j >= 0; j--){
        if (str[j] != 34) {
            num = num + tenPow * (str[j] - 48);
            tenPow *= 10;
        }
    }

    return num;
}

char* my_rand() {

    static char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    char* num;


    for (int i = 0; i < 4; i++) {
        int index = rand() % (sizeof digits / sizeof digits[1]);
        num[i] = digits[index];
        num++;
    }

    num[4] = '\0';
    num = num - 4;

    return num;

}

char* my_strcpy(char* param_1, char* param_2)
{
    while (*param_2 != '\0') {
        *param_1 = *param_2;
        param_2++;
        param_1++;
    }
    return param_1;
}