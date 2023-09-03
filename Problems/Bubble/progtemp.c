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

// // print contents of inputFile to console
//     char c;
//     while ((c = fgetc(inputFile)) != EOF) {
//         printf("%c", c);
//     }

//     rewind(inputFile);

// print contents of inputFile to buffer
    char *buffer = (char* )malloc( 80 );
    size_t len = 0;
    ssize_t read;

// print contents of buffer
    while ((read = getline(&buffer, &len, inputFile)) != -1) {
        printf("%s", buffer);
    }

// convert all elements of buffer to float
    char *ptr;
    float fval = strtof(buffer, &ptr);
    printf("%f\n", fval);


    // Perform file operations using inputFile and outputFile
    printf("Hello world!!!\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;

}