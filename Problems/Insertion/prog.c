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

    // convert initialVal to intVal
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

    float *arr = (float *)malloc(intVal * sizeof(float));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // print contents of buffer
    size_t sizeValue = (size_t)intVal;
    for (int i = 0; i < intVal; i++) {
            read = getline(&buffer, &sizeValue, inputFile);
            // convert all elements of buffer to float
            char *ptr;
            float fval = strtof(buffer, &ptr);
            //printf("%f\n", fval);
            arr[i] = fval;
    }

    //printf("final test:\n");
    for (int i = 0; i < intVal; i++) {
        printf("%f\n", arr[i]);
    }
    

/* PERFORM INSERTION SORT ON ARR */

    // Insertion sort
    for (int i = 1; i < intVal; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            // swap arr[j+1] and arr[j]
            float temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
    }

/* WRITE SORTED ARRAY TO OUTPUT FILE */

    // Write the sorted array to outputFile
    for (int i = 0; i < intVal; i++) {
        fprintf(outputFile, "%f\n", arr[i]);
    }

    // Close files, free memory
    fclose(inputFile);
    fclose(outputFile);
    free( buffer );
    free( arr );
    return 0;

}