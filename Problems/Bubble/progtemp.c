#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
/* GET INPUT/OUTPUT FILES */
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_fd output_fd\n", argv[0]);
        return 1;
    }

    const char *inputFilePath = argv[1];
    const char *outputFilePath = argv[2];

    FILE *inputFile = fopen(inputFilePath, "r");
    FILE *outputFile = fopen(outputFilePath, "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Failed to open file");
        return 1;
    }

// print contents of inputFile to console
    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        printf("%c", c);
    }

    rewind(inputFile);


// Read floating points from inputFile into malloc'd buffer

    // Determine size of buffer
    char initialVal[256];
    if(fgets(initialVal, sizeof(initialVal), inputFile) == NULL) {
        perror("Error 2");
        fclose(inputFile);
        return 1;
    }

    int fval;
    if(sscanf(initialVal, "%d", &fval) != 1) {
        perror("Error 3");
        fclose(inputFile);
        return 1;
    }

    // Create buffer
    float *buffer = (float *)malloc(fval);
    if (buffer == NULL) {
        perror("Memory allocation error");
        fclose(inputFile);
        return 1;
    }

    // Read the contents of the file into the buffer
    size_t newLen = fread(buffer, sizeof(float), fval, inputFile);
    if (newLen == 0) {
        perror("Error 4");
        fclose(inputFile);
        return 1;
    }

    // Print contents of buffer to outputFile
    for (int i = 0; i < fval; i++) {
        fprintf(outputFile, "%f\n", buffer[i]);
    }

    // Perform file operations using inputFile and outputFile
    printf("Hello world!!!\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;

}