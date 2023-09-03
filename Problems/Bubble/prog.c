#include <stdio.h>
#include <stdlib.h>

/*

Input files: input1, input2, etc.
Output files: output1, output2, etc.

Example: ./prog input1.txt output1.txt

*/
int main(int argc, char *argv[]) {

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_fd output_fd\n", argv[0]);
        return 1;
    }

    FILE *file;
    double *buffer;
    long file_size;

/* 1. OPEN FILE, READ FIRST LINE */
    file = fopen("input1.txt", "rb");
        if(file == NULL) {
            perror("Error: file not found");
            return 1;
        }

    // Determine size of buffer
    char initialVal[256];
    if(fgets(initialVal, sizeof(initialVal), file) == NULL) {
        perror("Error 2");
        fclose(file);
        return 1;
    }

    int fval;
    if(sscanf(initialVal, "%d", &fval) != 1) {
        perror("Error 3");
        fclose(file);
        return 1;
    }

/* 2. READ REMAINING LINES INTO DOUBLES BUFFER */

    // Create buffer
    buffer = (double *)malloc(fval);
    if (buffer == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return 1;
    }

    // Read the contents of the file into the buffer
    size_t newLen = fread(buffer, sizeof(double), fval, file);
    if (newLen == 0) {
        perror("Error 4");
        fclose(file);
        return 1;
    }
    // Print contents of newLen
    printf("newLen: %zu\n", newLen);

    /*
    if (fread(buffer, sizeof(double), fval, file) != fval) {
        perror("Buffer error lol");
        fclose(file);
        free(buffer); // free the allocated memory
        return 1;
    }
    */

/* 3. RUN SORTING ALGORITHM */

    int swapped;
    int x;
    printf("Your lucky number is: %d\n", fval);
    
    for (size_t i = 0; i < fval; i++) {
        printf("Element %zu: %lf\n", i, buffer[i]);
    }

    fclose(file);
    free(buffer); // free the allocated memory
    return 0;

}
