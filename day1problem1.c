#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * dataFile = fopen("data.txt", "r");

    int freq = 0;

    int freqChange = 0;

    int readCode;

    do {

        freq += freqChange;

        readCode = fscanf(dataFile , "%d", &freqChange);        

    } while (readCode != EOF);

    fclose(dataFile);

    printf("End frequency: %d", freq);

    return 0;
}

