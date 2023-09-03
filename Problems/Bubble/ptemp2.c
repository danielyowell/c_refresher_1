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

    // Read the integer in the first line of inputFile
    char initialVal[256];
    if(fgets(initialVal, sizeof(initialVal), inputFile) == NULL) {
        perror("Error 2");
        fclose(inputFile);
        return 1;
    }

    // convert initialVal to int
    int intVal;
    if(sscanf(initialVal, "%d", &intVal) != 1) {
        perror("Error 3");
        fclose(inputFile);
        return 1;
    }
    // print fval to console
    printf("%d\n", intVal);

    // Each line of inputFile contains a float. Read each line into a buffer, convert to float, and store in array
    char *buffer = (char* )malloc( 80 );
    size_t len = 0;
    ssize_t read;

    // print contents of buffer
    size_t sizeValue = (size_t)intVal;
    while ((read = getline(&buffer, &sizeValue, inputFile)) != -1) {
            // convert all elements of buffer to float
            char *ptr;
            float fval = strtof(buffer, &ptr);
            printf("%f\n", fval);
    }



    

    // Perform file operations using inputFile and outputFile
    printf("Hello world!!!\n");

    // Close files, free memory
    fclose(inputFile);
    fclose(outputFile);
    free( buffer );
    
    return 0;

}