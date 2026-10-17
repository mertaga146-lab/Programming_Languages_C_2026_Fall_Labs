// week5_task1_file_io.c
// Name: Mert  Surname: Aga  Student ID: 241ADB159
//
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
//
// Build: make lab5   Run: ./bin/week5_task1_file_io

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    const char *filename = DEFAULT_FILENAME;
    char line[LINE_LEN];
    int line_count = 0;

    // BONUS: use the file name from the command line if one was given
    if (argc > 1) {
        filename = argv[1];
    }

    // 1. Announce and open the file for writing
    printf("Writing lines to %s...\n", filename);
    fp = fopen(filename, "w");

    // 2. Always check fopen() for NULL
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 3. Write a few lines of text
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");

    // 4. Close the file
    fclose(fp);

    // 5. Open the same file again, this time for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 6. Read line by line with fgets() and print each line
    printf("Reading contents:\n");
    while (fgets(line, LINE_LEN, fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    // 7. Close the file
    fclose(fp);

    // BONUS: report how many lines were read
    printf("Lines read: %d\n", line_count);

    return EXIT_SUCCESS;
}
