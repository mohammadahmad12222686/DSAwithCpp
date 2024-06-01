#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main() {
    int sourceFile, destinationFile;
    ssize_t bytesRead, bytesWritten;
    char buffer[BUF_SIZE];

    // Open the source file for reading
    sourceFile = open("input.txt", O_RDONLY);
    if (sourceFile == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Create the destination file for writing
    destinationFile = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destinationFile == -1) {
        perror("Error creating destination file");
        close(sourceFile);
        return 1;
    }

    // Find the size of the source file
    off_t fileSize = lseek(sourceFile, 0, SEEK_END);
    lseek(sourceFile, 0, SEEK_SET);

    // Calculate the size of the first half
    off_t firstHalfSize = fileSize / 2;

    // Read and write the first half of the file
    while ((bytesRead = read(sourceFile, buffer, BUF_SIZE)) > 0 && firstHalfSize > 0) {
        if (bytesRead > firstHalfSize) {
            bytesRead = firstHalfSize;
        }
        bytesWritten = write(destinationFile, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to destination file");
            close(sourceFile);
            close(destinationFile);
            return 1;
        }
        firstHalfSize -= bytesRead;
    }

    // Close the files
    close(sourceFile);
    close(destinationFile);

    printf("First half of the file copied successfully.\n");

    return 0;
}
