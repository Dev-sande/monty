#include <stdio.h>
#include <stdlib.h>

int entry() {
    FILE *file;
    char *buffer;
    int numBytes;
    size_t bytesRead;
    int i;

    file = fopen("input.bin", "rb");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Enter the number of bytes to read: ");
    scanf("%d", &numBytes);

    buffer = (char *) malloc(numBytes);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    bytesRead = fread(buffer, 1, numBytes, file);
    if (bytesRead != (size_t) numBytes) {
        printf("Error reading the file.\n");
        free(buffer);
        fclose(file);
        return 1;
    }

    printf("Bytes read: ");
    
    for (i = 0; i < numBytes; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    free(buffer);
    fclose(file);

    return 0;
}

