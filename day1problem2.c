#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "data2.txt"

// PLEASE NOTE: This code wasn't able to solve the problem with the given input data.
//              However, I tested against some of the sample inputs and it worked
//              I believe there must be a more optimal algorithm to solve this that
//              I wasn't able to figure out.

struct Node {

    int key;
    struct Node * next;

};

int listContains(struct Node * list, int value);

void freeList(struct Node * list);

int listLength (struct Node * list);

int main() {

    // Pointer to the data file that is being read
    FILE * dataFile;

    // The current value of the frequency
    int freq = 0;

    // Used to count the number of frequency changes in the data file
    int numChanges = -1;

    // The code that is returned from reading the data
    int readCode;

    // stores the changes
    int * changeArray;

    // stores the past values of the frequency as a linked list
    struct Node * pastFreq = NULL;

    // Used for appending to the array
    struct Node * new;

    // Read the file to figure out how many changes there are, store in numChanges
    dataFile = fopen(FILE_NAME, "r");

    do {

        numChanges++;

        // Don't care what the value is, just that there is one
        //  So why not just put it in something convenient?
        readCode = fscanf(dataFile , "%d", &readCode);

    } while (readCode != EOF);

    fclose(dataFile);


    // MALLOC for the array of changes
    changeArray = malloc(numChanges * sizeof(int));


    // Open the file for a second reading, this time putting the
    //  change values in the malloc'd array
    dataFile = fopen(FILE_NAME, "r");

    int i; // Used to index the changes array

    for (i = 0; i < numChanges; i++) {

        readCode = fscanf(dataFile , "%d", changeArray + i);       

    }

    fclose(dataFile);


    // Now I is going to be used in order to keep track of which change we are supposed to read
    i = 0;

    // Go through the frequency changes until frequency matches a past value
    while(!listContains(pastFreq, freq)) {

        // Malloc for a new node
        new = malloc(sizeof(struct Node));

        // Set the key to the current value of frequency
        new->key = freq;

        // Set the next to the list
        new->next = pastFreq;

        // Make it the new start of the list
        pastFreq = new;

        freq += changeArray[i];

        // DEBUG
        printf("\fFrequency: %d\nList length: %d\n", freq, listLength(pastFreq));

        // Increment `i` and make sure it is at most the last index of the array
        i++;
        i %= numChanges;

    }

    // Free the changes array
    free(changeArray);

    // Free the past frequencies list
    freeList(pastFreq);

    // Print out the first frequency that occurs twice
    printf("First frequency that occurs twice: %d\n", freq);

    return 0;

}

/**
 * Returns 1 if the value is in the linked list and 0 if it isn't
*/
int listContains(struct Node * list, int value) {

    if (list == NULL) {

        return 0;

    } else if (list->key == value) {

        return 1;

    } else {
        
        return listContains(list->next, value);

    }

}

/**
 * Free the generated linked list
*/
void freeList(struct Node * list) {

    if (list == NULL)
        return;

    struct Node * next = list -> next;

    free(list);

    freeList(next);

}


int listLength (struct Node * list) {

    if (list == NULL) {
        return 0;
    }

    return 1 + listLength(list->next);

}