#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

const char* filename = "input.txt";

int main(int argc, char *argv[])
{
    FILE *in_file = fopen(filename, "r");
    // throw an error if failed to open the file
    if (!in_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // get file size
    char *file_contents = malloc(sb.st_size);

    // get the offset size from the input.txt
    fscanf(in_file, "%[^\n] ", file_contents);
    int n = atoi(file_contents);

    // decimal representation of 16 1-bits
    // this is equal to 2^16
    int offsetMask = 65535;
    int pageMask = 65535;

    int shiftRight = 16 - n;
    offsetMask =  offsetMask >> shiftRight;

    printf("The offset size is: %d\n", n);
    printf("The page number size is: %d\n", pageMask);

    // read line by line 
    while (fscanf(in_file, "%[^\n] ", file_contents) != EOF) {
        int virtualAdd = atoi(file_contents);
        printf("virtual address %s is in page number %d and offset %d\n", file_contents, virtualAdd >> n, virtualAdd & offsetMask);
    }

    fclose(in_file);
    exit(EXIT_SUCCESS);
}