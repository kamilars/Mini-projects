#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 50

int main(int argc, char **argv){

    FILE *file;
    char ch;

    for (int i = 1; i < argc; i++) {
        file = fopen (argv[i], "r");

        while((ch = getc(file)) != EOF)
            printf("%c", ch);
        fclose(file);
    }

}
