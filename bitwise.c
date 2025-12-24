#include "bitwise.h"
#include <stdlib.h>

void bitwiseNOT(uint32_t num) {
    uint32_t size;
    uint32_t *binary = decimalToBinary(num, &size);

    printf("Original binary: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf("\nBinary number after bitwise NOT: ");
    for (uint32_t i = 0; i < size; i++) {
        if (binary[i] == 1) {
            binary[i] = 0;
        } else {
            binary[i] = 1;
        }
    }

    for (int i = size - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf("\n");
    free(binary);
}

void bitwiseAND(uint32_t num, uint32_t mask) {
    uint32_t size1, size2;
    uint32_t *numBinary = decimalToBinary(num, &size1);
    uint32_t *maskBinary = decimalToBinary(mask, &size2);

    printf("\nOriginal binary: ");
    for (int i = size1 - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\nMask: ");
    for (int i = size2 - 1; i >= 0; i--) {
        printf("%d", maskBinary[i]);
    }

    printf("\nBinary number after bitwise AND: ");
    for (uint32_t i = 0; i < size1; i++) {
        if (i < size2) {
            if (numBinary[i] == 1 && maskBinary[i] == 1) {
                numBinary[i] = 1;
            } else {
                numBinary[i] = 0;
            }
        } else {
            numBinary[i] = 0;
        }
    }

    for (int i = size1 - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\n");
    free(numBinary);
    free(maskBinary);
}

void bitwiseOR(uint32_t num, uint32_t mask) {
    uint32_t size1, size2;
    uint32_t *numBinary = decimalToBinary(num, &size1);
    uint32_t *maskBinary = decimalToBinary(mask, &size2);

    printf("\nOriginal binary: ");
    for (int i = size1 - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\nMask: ");
    for (int i = size2 - 1; i >= 0; i--) {
        printf("%d", maskBinary[i]);
    }

    printf("\nBinary number after bitwise OR: ");
    for (uint32_t i = 0; i < size1; i++) {
        if (i < size2) {
            if (numBinary[i] == 1 || maskBinary[i] == 1) {
                numBinary[i] = 1;
            } else if (numBinary[i] == 0 || maskBinary[i] == 1) {
                numBinary[i] = 1;
            } else if (numBinary[i] == 1 || maskBinary[i] == 0) {
                numBinary[i] = 1;
            } else {
                numBinary[i] = 0;
            }
        }
    }

    for (int i = size1 - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\n");
    free(numBinary);
    free(maskBinary);
}

void bitwiseXOR(uint32_t num, uint32_t mask) {
    uint32_t size1, size2;
    uint32_t *numBinary = decimalToBinary(num, &size1);
    uint32_t *maskBinary = decimalToBinary(mask, &size2);

    printf("Original binary: ");
    for (int i = size1 - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\nMask: ");
    for (int i = size2 - 1; i >= 0; i--) {
        printf("%d", maskBinary[i]);
    }

    printf("\nBinary number after bitwise XOR: ");
    for (uint32_t i = 0; i < size1; i++) {
        if (i < size2) {
            if (numBinary[i] == 1 && maskBinary[i] == 1) {
                numBinary[i] = 0;
            } else if (numBinary[i] == 1 && maskBinary[i] == 0) {
                numBinary[i] = 1;
            } else if (numBinary[i] == 0 && maskBinary[i] == 1) {
                numBinary[i] = 1;
            } else {
                numBinary[i] = 0;
            }
        }
    }

    for (int i = size1 - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\n");
    free(numBinary);
    free(maskBinary);
}

void bitwiseLeftShift(uint32_t num, uint32_t nbits) {
    if (nbits > BUF_WIDTH) {
        fprintf(stderr, "trying to get out of buffer boundaries.\n");
        exit(EXIT_FAILURE);
    }
    
    uint32_t size;
    uint32_t *numBinary = decimalToBinary(num, &size);

    printf("Original binary: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\nBits to shift to the left: %u\n", nbits);

    for (int i = size - 1; i >= 0; i--) {
        numBinary[i + nbits] = numBinary[i];
    }

    for (uint32_t i = 0; i < nbits; i++) {
        numBinary[i] = 0;
    }

    size += nbits;

    printf("After arithmetic left shift: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\n");

    BinaryToDecimal(numBinary, size);
}

void bitwiseRightShift(uint32_t num, uint32_t nbits) {
    if (nbits > BUF_WIDTH) {
        fprintf(stderr, "trying to get out of buffer boundaries.\n");
        exit(EXIT_FAILURE);
    }
    
    uint32_t size;
    uint32_t *numBinary = decimalToBinary(num, &size);

    if (nbits >= size) nbits = size;

    uint32_t sign = numBinary[size - 1];

    printf("Original binary: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\nBits to shift to the right: %u\n", nbits);

    for (int i = 0; i < (int)(size - nbits); i++) {
        numBinary[i] = numBinary[i + nbits];
    }

    for (int i = size - nbits; i < (int)size; i++) {
        numBinary[i] = sign;
    }

    printf("After arithmetic right shift: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", numBinary[i]);
    }

    printf("\n");

    BinaryToDecimal(numBinary, size);
}