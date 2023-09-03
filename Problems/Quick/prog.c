#include <stdio.h>
#include <stdlib.h>

/*

Input files: input1, input2, etc.
Output files: output1, output2, etc.

*/
int main() {
 FILE *file;
 char *buffer;
 long file_size;

// Open input file
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

// Boilerplate
 int swapped;
 int x;
 printf("Your lucky number is: %d\n", fval);
 
 fclose(file);
 return 0;

}
