//DIRECT-MAPPED Caching (NOTE: code will seg fault with original file. The code has been tested with a file reduced to the first 80 elements of the original)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a CS1 concept (hashing) in a class that is based on the intro to C class. The pre-requisite to CDA 3103 is only the intro class COP 3223. I am not in CS1 and have completed this to the best of my abilities based on the intro class material.
*/

#define MAX_CHARS_PER_LINE 100
#define MAX_TOKENS_PER_LINE 10
#define HEX_PREFIX_LENGTH 2

// function to convert Hexadecimal to Binary Number
void HexToBin(char* hexdec, char* binary)
{
    long int i = 0;
    int j = 0;
 
    while (hexdec[i]) {
        switch (hexdec[i]) {
        case '0':
            binary[j++] = '0';
            binary[j++] = '0';
            binary[j++] = '0';
            binary[j++] = '0';
            break;
        case '1':
            binary[j++] = '0';
            binary[j++] = '0';
            binary[j++] = '0';
            binary[j++] = '1';
            break;
        case '2':
            binary[j++] = '0';
            binary[j++] = '0';
            binary[j++] = '1';
            binary[j++] = '0';
            break;
        case '3':
            binary[j++] = '0';
            binary[j++] = '0';
            binary[j++] = '1';
            binary[j++] = '1';
            break;
        case '4':
            binary[j++] = '0';
            binary[j++] = '1';
            binary[j++] = '0';
            binary[j++] = '0';
            break;
        case '5':
            binary[j++] = '0';
            binary[j++] = '1';
            binary[j++] = '0';
            binary[j++] = '1';
            break;
        case '6':
            binary[j++] = '0';
            binary[j++] = '1';
            binary[j++] = '1';
            binary[j++] = '0';
            break;
        case '7':
            binary[j++] = '0';
            binary[j++] = '1';
            binary[j++] = '1';
            binary[j++] = '1';
            break;
        case '8':
            binary[j++] = '1';
            binary[j++] = '0';
            binary[j++] = '0';
            binary[j++] = '0';
            break;
        case '9':
            binary[j++] = '1';
            binary[j++] = '0';
            binary[j++] = '0';
            binary[j++] = '1';
            break;
        case 'A':
        case 'a':
            binary[j++] = '1';
            binary[j++] = '0';
            binary[j++] = '1';
            binary[j++] = '0';
            break;
        case 'B':
        case 'b':
            binary[j++] = '1';
            binary[j++] = '0';
            binary[j++] = '1';
            binary[j++] = '1';
            break;
        case 'C':
        case 'c':
            binary[j++] = '1';
            binary[j++] = '1';
            binary[j++] = '0';
            binary[j++] = '0';
            break;
        case 'D':
        case 'd':
            binary[j++] = '1';
            binary[j++] = '1';
            binary[j++] = '0';
            binary[j++] = '1';
            break;
        case 'E':
        case 'e':
            binary[j++] = '1';
binary[j++] = '1';
binary[j++] = '0';
break;
case 'F':
case 'f':
binary[j++] = '1';
binary[j++] = '1';
binary[j++] = '1';
binary[j++] = '1';
break;
default:
printf("\nInvalid hexadecimal digit %c",
hexdec[i]);
}
i++;
}
}

int main() {int ct=-1;
// open file for reading
FILE* file = fopen("traces.txt", "r");
if (!file) {
    printf("Failed to open file\n");
    return 1;
}

// read each line from file
char line[MAX_CHARS_PER_LINE];
char bin_strings[MAX_TOKENS_PER_LINE][MAX_CHARS_PER_LINE*4 + 1];
int bin_strings_count = 0;
while (fgets(line, sizeof(line), file)) {
    // remove newline character
    line[strcspn(line, "\n")] = 0;

    // check if line starts with 0x prefix
    if (strncmp(line, "0x", HEX_PREFIX_LENGTH) != 0) {
        printf("Invalid input format\n");
        continue;
    }

    // convert hexadecimal number to binary
    printf("Hexadecimal: %s\nBinary: ", line);
    char binary[MAX_CHARS_PER_LINE*4 + 1];
    memset(binary, 0, sizeof(binary));
    printf("\nTag is: %.6s\n", line + HEX_PREFIX_LENGTH);
    HexToBin(line + HEX_PREFIX_LENGTH, binary);

    // check if binary string starts with "100111"
    if (strncmp(binary, "100111", 6) == 0) {
        // store binary string in array
        strcpy(bin_strings[bin_strings_count], binary);
        bin_strings_count++;
    }
}

// print stored binary strings
printf("Binary strings that start with '100111':\n");
for (int i = 0; i < bin_strings_count; i++) {
    printf("%s\n", bin_strings[i]);
}
						// compare binary strings and count hits
int hit = 0, miss=0;

    for (int i = 1; i <bin_strings_count ; i++) {
        if (strcmp(bin_strings[i], bin_strings[i-1]) == 0) {
            printf("Hit!\n");
            hit++;
        }
        else {
            miss++;
					printf("Miss!\n");
        }
    }
    // print number of hits and misses
    printf("Number of hits: %d\n", hit);
    printf("Number of misses: %d\n", miss);



// close file
fclose(file);

return 0;
					 }
