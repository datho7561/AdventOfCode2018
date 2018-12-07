
// Checksunm consists of two variables check1, check2

// An array of size 26 to keep track of occurence of letters for current entry

// Initialize array to 0, go through the list of characters, incrementing corresponding counts

// after all counted, check for a 2 in the array, and if there is one, increment check1
// ditto but with 3 and check2

#include <stdio.h>

#define FILE_NAME "input.txt"
#define LINE_LEN 50

int main() {

    int check1 = 0, check2 = 0;

    int occur[26];
    char line[50];
    char * line_ptr;
    
    int read_return;

    

    FILE* file = fopen(FILE_NAME, "r");

    // Read data
    for(;;) {

        // Reset occurences array
        int i;
        for (i = 0; i < 26; i++)
            occur[i] = 0;

        read_return = fscanf(file, "%s", line);

        // Exit when the file is read
        if (read_return == EOF)
            break;

        line_ptr = line;

        // While not at the end of the character
        while(*line_ptr != '\0') {

            // Increment the current character being read
            occur[*line_ptr - 'a']++;

            // Move to the next character
            line_ptr++;

        }

        // Check if the number 2 occurs, and if so increment check1
        for (i = 0; i < 26; i++) {

            if (occur[i] == 2) {
                check1++;
                break;
            }

        }

        // Other checksum part
        for (i = 0; i < 26; i++) {

            if (occur[i] == 3) {
                check2++;
                break;
            }

        }
        

    }

    fclose(file);

    printf("The checksum is:\t%d", check1*check2);

    return 0;

}