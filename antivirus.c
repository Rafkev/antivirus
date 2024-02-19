#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MALWARE_SIGNATURE "malware_signature"

int scanFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file: %s\n", filename);
        return -1; // Error opening file
    }

    char line[MAX_LINE_LENGTH];
    int malwareFound = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, MALWARE_SIGNATURE)) {
            printf("Malware signature found in file: %s\n", filename);
            malwareFound = 1;
            break;
        }
    }

    fclose(file);

    if (!malwareFound) {
        printf("No malware signature found in file: %s\n", filename);
    }

    return 0; // Success
}

int main() {
    const char *filename = "file_to_scan.txt";
    int result = scanFile(filename);
    if (result != 0) {
        return 1; // Error occurred during scanning
    }
    return 0; // Success
}
