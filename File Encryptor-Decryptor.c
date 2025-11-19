#include <stdio.h>

// Function to encrypt/decrypt a file using XOR
void encryptDecrypt(const char *inputFile, const char *outputFile, char key) {
    // read input file
    FILE *fin = fopen(inputFile, "r");  
    // write output file
    FILE *fout = fopen(outputFile, "w"); 

    if (!fin || !fout) {
        printf("Error opening files!\n");
        return;
    }

    char ch;
    // Read each character and XOR with key
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key, fout);
    }

    fclose(fin);
    fclose(fout);

    printf("Operation successful! Output saved to %s\n", outputFile);
}

int main() {
    int choice;
    char key = 7;  // XOR encryption key

    printf("1. Encrypt File\n2. Decrypt File\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        encryptDecrypt("input.txt", "encrypted.txt", key);
    else if (choice == 2)
        encryptDecrypt("encrypted.txt", "decrypted.txt", key);
    else
        printf("Invalid option!\n");

    return 0;
}

