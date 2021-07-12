#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Plan:
// 1 - count the number of unique characters
// 2 - malloc 2 arrays (first: char, second: int) with the size found previously
// 3 - iterate through the inputs to count the number of each unique character
// 4 - sort the array arr_char alphanumerically (and second array arr_amount respectively)

int count_unique_characters(int argc, char **argv) {
    char *ch_considered;
    char *ch_before;
    int amount = 0;

    for (int i=1; i<argc; i++) {
        // COUNTING AMOUNT OF UNIQUE CHARACTERS
        ch_considered = argv[i];
        int iteration_elements_considered = 0;
        
        while (*(ch_considered + iteration_elements_considered) != '\0') {
            if (*(ch_considered + iteration_elements_considered) != '"') {
                bool flag_repeated = false;

                // checking if the character was mentioned before
                for (int j=1; j<=i; j++) {
                    ch_before = argv[j];
                    int iteration_elements_before = 0;

                    while ((ch_before + iteration_elements_before) != (ch_considered + iteration_elements_considered)) {
                        if (*(ch_before + iteration_elements_before) == *(ch_considered + iteration_elements_considered)) {
                            flag_repeated = true;
                            break;
                        }
                        iteration_elements_before++;   
                    }

                    if (flag_repeated) {
                        break;
                    }
                    
                }

                if (!flag_repeated) {
                    amount++;
                }
            }

            iteration_elements_considered++;
        }
    }

    return amount;
}

char* fill_arr_char(int argc, char **argv, int amount_unique_characters) {
    // arr_char should be like ["b", "a", "c"]
    char *arr_char = (char*)malloc(amount_unique_characters * sizeof(char));

    char *ch;
    int arr_char_index = 0;

    for (int i=1; i<argc; i++) {
        int len = 0;
        ch = argv[i];

        while (*(ch + len) != '\0') {
            if (*(ch + len) != '"') {
                bool flag_repeated_2 = false;
                for (int j=0; j<amount_unique_characters; j++) {
                    if (*(ch + len) == arr_char[j]) {
                        flag_repeated_2 = true;
                        break;
                    }
                }

                if (!flag_repeated_2) {
                    arr_char[arr_char_index] = *(ch + len);
                    arr_char_index++;
                }
            }
            

            len++;
        }
    }

    return arr_char;
}

void sorting(int amount_unique_characters, char *arr_char, int *arr_amount) {
    int j;
    char key_char;
    int key_amount;

    // INSERTION SORTING
    for (int i=1; i<amount_unique_characters; i++) {
        key_char = arr_char[i];
        key_amount = arr_amount[i];
        j = i-1;

        while (j >= 0 && (int)arr_char[j] > (int)key_char) {
            arr_char[j+1] = arr_char[j];
            arr_amount[j+1] = arr_amount[j];
            j--;
        }
        arr_char[j+1] = key_char;
        arr_amount[j+1] = key_amount;
    }
}

int main(int argc, char **argv) {
    int amount_unique_characters;
    amount_unique_characters = count_unique_characters(argc, argv);

    // MALLOC TWO ARRAYS
    char *arr_char = fill_arr_char(argc, argv, amount_unique_characters);
    int *arr_amount = (int*)malloc(amount_unique_characters * sizeof(int));

    // COUNT AMOUNT OF UNIQUE CHARACTERS
    char *ch;
    for (int i=0; i<amount_unique_characters; i++) {
        int amount = 0;
        for (int j=1; j<argc; j++) {
            ch = argv[j];
            int len = 0;
            while (*(ch + len) != '\0') {
                if (*(ch + len) == arr_char[i]) {
                    amount++;
                }
                len++;
            }
        }

        arr_amount[i] = amount;
    }

    if (amount_unique_characters > 1) {
        sorting(amount_unique_characters, arr_char, arr_amount);
    }

    for (int k=0; k<amount_unique_characters; k++) {
        printf("%c:%i\n", arr_char[k], arr_amount[k]);
    }

    return 0;
}