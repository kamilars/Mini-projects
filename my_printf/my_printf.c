#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/*string length*/

int my_strlen(char* param_1)
{
    int i = 0;
    while (*param_1 != '\0') {
        i++;
        param_1++;
    }

    return i;
}


/*Printing char*/

int put_char(char c){

    write(1, &c, 1);
    return 1;

}


/*Printing string*/

int put_str(char *str){

    int len = my_strlen(str);
    write(1, str, len);
    return len;

}


/*Printing octal*/

int printOct(int param) {

    unsigned int num = (unsigned int)param;

    char* a = (char*)malloc(100 * sizeof(char));
    int i = 0;
    int count = 0;

    if (num == 0) {
        *a = 48;
        write(1, a, 1);
        count++;
    }
    else{
        while(num != 0) {
            *a = 48 + (num % 8);
            a++; i++;
            num = num / 8;
        }

        for (int k = 0; k < i; k++){
            a--;
            write(1, a, 1);
            count++;
        }
    }

    free(a);
    return count;

}


/*Printing unsigned decimal*/

int printUDec(int param) {
  
    unsigned int num = (unsigned int)param;
    char* a = (char*)malloc(100 * sizeof(char));
    int i = 0;
    int count = 0;
  
    if (num == 0) {
        *a = 48;
        write(1, a, 1);
        count++;
    }
    else{
        while(num != 0) {
            *a = 48 + (num % 10);
            a++; i++;
            num = num / 10;
        }

        for (int k = 0; k < i; k++){
            a--;
            write(1, a, 1);
            count++;
        }
    } 

    free(a);
    return count;

}

/*Printing decimal*/

int printSDec(int num) {
  
    char* a = (char*)malloc(100 * sizeof(char));
    int i = 0;
    int count = 0;

    if (num < 0) {
        char sign = '-';
        write(1, &sign, 1);
        num = num * (-1);
        count++;
    }
  
    if (num == 0) {
        *a = 48;
        write(1, a, 1);
        count++;
    }
    else{
        while(num != 0) {
            *a = 48 + (num % 10);
            a++; i++;
            num = num / 10;
        }

        for (int k = 0; k < i; k++){
            a--;
            write(1, a, 1);
            count++;
        }
    }

    free(a);
    return count;

}


/*Printing hexadecimal*/

int printHexa(int param) {
  
    unsigned int num = (unsigned int)param;

    char* a = (char*)malloc(100 * sizeof(char));
    int i = 0;
    int count = 0;
    const char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    if (num == 0) {
        *a = 48;
        write(1, a, 1);
        count++;
    }
    else{
        while(num != 0) {
            *a = hexDigits[num % 16];
            a++; i++;
            num = num / 16;
        }

        for (int k = 0; k < i; k++){
            a--;
            write(1, a, 1);
            count++;
        }
    }

    free(a);
    return count;

}


/*Printing pointers*/

int printPoint(void * point) {

    unsigned long num = (unsigned long)point;
  
    char* a = (char*)malloc(100 * sizeof(char));
    int i = 0;
    int count = 0;
    const char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    put_char('0');
    put_char('x');

    if (num == 0) {
        *a = 48;
        write(1, a, 1);
        count++;
    }
    else{
        while(num != 0) {
            *a = hexDigits[num % 16];
            a++; i++;
            num = num / 16;
        }

        for (int k = 0; k < i; k++){
            a--;
            write(1, a, 1);
            count++;
        }
    }

    free(a);
    return count + 2;

}


/* My_printf */

int my_printf(char * restrict format, ...) {

    int num_char_printed = 0;
    int curPos = 0;

    va_list args;

    va_start(args, format);

    while (format[curPos]) {
        if (format[curPos] == '%') {
            curPos++;
            switch (format[curPos]) {
                case 'd' :
                    num_char_printed += printSDec(va_arg(args, int));
                    break;
                case 'o' :
                    num_char_printed += printOct(va_arg(args, int));
                    break;
                case 'u' :
                    num_char_printed += printUDec(va_arg(args, int));
                    break;
                case 'x' :
                    num_char_printed += printHexa(va_arg(args, int));
                    break;
                case 'c' :
                    num_char_printed += put_char(va_arg(args, int));
                    break;
                case 's' :
                    num_char_printed += put_str(va_arg(args, char*));
                    break;
                case 'p' :
                    num_char_printed += printPoint(va_arg(args, char*));
                    break;
                default :
                    put_str("Wrong input!!!");
            }
            
            curPos++;
            continue;
        }

        put_char(format[curPos]);
        num_char_printed++;
        curPos++;

    }

    va_end(args);
    return num_char_printed;

}

/*
int main(void){


    int k;
    k = 5;
    int a;

    a = my_printf("Hello, I am my_printf: %o %u %d %c %s %p\n", -15, 20, 456, 56, "12351 35123", &k);
    my_printf("Total symbols printed: %d\n", a);
    a = printf("Hello, I am printf: %o %u %d %c %s %p\n", -15, 20, 456, 56, "12351 35123", &k);
    printf("Total symbols printed: %d\n", a);

    return 0;

}
*/