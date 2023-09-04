#include <stdio.h>
#include <stdlib.h>

    // Merge sort
    // Merge sort is a divide and conquer algorithm that divides the array into two halves, calls itself for the two halves, and then merges the two sorted halves.
    // Time complexity: O(nlogn)
    // Space complexity: O(n)
    // Stable: Yes
    // In-place: No

    // Merge two subarrays of arr[]
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    void merge(float arr[], int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;
    
        /* create temp arrays */
        float L[n1], R[n2];
    
        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];
    
        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    
        /* Copy the remaining elements of L[], if there are any */
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
    
        /* Copy the remaining elements of R[], if there are any */
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    /* l is for left index and r is right index of the sub-array of arr to be sorted */
    void mergeSort(float arr[], int l, int r) {
        if (l < r) {
            // Same as (l+r)/2, but avoids overflow for large l and h
            int m = l+(r-l)/2;
    
            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
    
            merge(arr, l, m, r);
        }
    }

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
    

/* PERFORM MERGE SORT ON ARR */




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