#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
    if (ac - 1 == 2) {
    int x = atoi(av[1]);
    int y = atoi(av[2]);

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++){
            if ((i == 0 && (j == 0 || j == x-1)) || (i == y-1  && (j == 0 || j == x-1))) {
                printf("o");
            }
            else if (i == 0 || i == y-1){
                printf("-");
            }
            else if (j == 0 || j == x-1) {
                printf("|");
            } 
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    }
}
