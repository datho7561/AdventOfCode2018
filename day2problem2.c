// pick the first and second strings. Check how many characters are the same.  If it is word length - 1, then it is solution.
// If not check first, third ....
// If not check second against third ...

#include <stdio.h>
#include <string.h>

#define FILE_NAME "input.txt"



int is_match(char* str1, char*str2) {

    int sum = 0, length = strlen(str1), i;

    for (i = 0; i < length; i++) {

        sum += str1[i] == str2[i];

    }

    return (sum + 1) == length;

}

void print_matching(char* str1, char* str2) {

    int length = strlen(str1), i;

    for (i = 0; i < length; i++) {

        if (str1[i] == str2[i])
            printf("%c", str1[i]);

    }

    puts("");

}

int main() {

    int first_line_num = 1;
    int match_found = 0;

    int occur[26];
    char line1[50];
    char line2[50];
    
    int read_return;

    for(;;) {

        FILE* file = fopen(FILE_NAME, "r");

        // Read the line continuously until the desired first line is reached
        int i;
        for(i = 0; i < first_line_num; i++)
            read_return = fscanf(file, "%s", line1);
        
        if (read_return == EOF) {
            break;
        }

        // COMAPRE FIRST STRING AGAINST REST OF THEM
        for (;;) {

            read_return = fscanf(file, "%s", line2);
            if (read_return == EOF) {
                break;
            }
            if(is_match(line1, line2)) {
                match_found = 1;
                break;
            }

        }

        // Now either all the strings for this iteration have been checked or a match has been found

        // If in the second case, no need to loop, just finish up
        if (match_found) {
            break;
        }

        // set up for next iteration
        first_line_num++; // To start at next string next time

    }


    if (match_found) {

        // COMPARE CODES AND PRINT SAME CHARACTERS
        // maybe in its own function
        print_matching(line1, line2);

    } else {

        puts("Match not found in file");

    }

    return 0;

}