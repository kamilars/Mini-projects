#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[]) {

    char uniqueArr[100];
    int counter[100];
    uniqueArr[0] = '\0';
    int alreadyExists = 0;

    for (int m = 1; m < argc; m++) {
        for (int i = 0; i < strlen(argv[m]); i++) {
            if (argv[m][i] != '\"') {
                int j = 0;
                for (j = 0; j < strlen(uniqueArr); j++){
                    if (uniqueArr[j] == argv[m][i]){
                        alreadyExists = 1;
                        continue;
                    }
                }
                if (alreadyExists == 0) {
                    uniqueArr[j] = argv[m][i];
                }
                alreadyExists = 0;
                uniqueArr[j+1] = '\0';
            }
        }
    }
  // Sorting
    char temp;
    for ( int f = 0; f < strlen(uniqueArr)-1; f++) {
        for ( int h = f+1; h < strlen(uniqueArr); h++) {
            if (uniqueArr[f] > uniqueArr[h]) {
                temp = uniqueArr[f];
                uniqueArr[f] = uniqueArr[h];
                uniqueArr[h] = temp;
            }
        }
    }
    
    
    for (int i = 0; i < strlen(uniqueArr); i++) {
        counter[i] = 0;
    }

     for (int m = 1; m < argc; m++){
        for (int i = 0; i < strlen(uniqueArr); i++) {
            for (int k = 0; k < strlen(argv[m]); k++){
                if ((uniqueArr[i] == argv[m][k]) && (argv[m][k] != '\"'))
                    counter[i]++;
            }
        }
    }
    

    for (int i = 0; i < strlen(uniqueArr); i++) {
        printf("%c:%i\n", uniqueArr[i], counter[i]);
    }
}

