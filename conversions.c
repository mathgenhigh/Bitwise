#include "conversions.h"
#include <stdlib.h>

uint32_t power(uint32_t base, uint32_t n) {
    uint32_t result = 1;
    if (n == 0) return 1; 

    for (uint32_t i = 0; i < n; i++)
        result *= base; 

    return result;
}

uint32_t* decimalToBinary(uint32_t num, uint32_t *size) {
    // initialize buffer to represent 32-bit register
    uint32_t *buffer = (uint32_t*)malloc(BUF_WIDTH * sizeof(uint32_t));         
    uint32_t i = 0;               

    printf("Number %d from decimal to bin: 0b", num);

    // iterate over a number, dividing it at each step by 2 until it's base is 0
    // add 1 to buffer at current index if modulus of number to 2 is equal to 1
    // add 0 to buffer at current index if modulus of number to 2 is equal to 0
    // pruint32_t each element at current index during loop execution
    while (num != 0) {           
        if (num % 2 == 1) {     
            buffer[i] = 1;
            printf("%d", buffer[i]);
        } 
        
        if (num % 2 == 0) {
            buffer[i] = 0;
            printf("%d", buffer[i]);
        }

        num /= 2;
        i++;
    }

    uint32_t min_bits = 8;
    while (i < min_bits) {
        buffer[i] = 0;
        i++;
    }

    *size = i;
    printf("\n");
    return buffer;
}

// calculate remainder from a quotient for hexadecimal conversion
float calcQuotientRemainder(float quotient) {
    // receive uint32_teger part       
    uint32_t integerPart = (uint32_t)quotient;
    // receive fractional part         
    float fractionalPart = quotient - integerPart;
    return fractionalPart;
}

char* decimalToHex(uint32_t num, uint32_t *size) {
    // initialize char array for later uint32_teger range assignment (0-9 & A-F) for hexadecimal  
    char *buffer = (char*)malloc(sizeof(char) * BUF_WIDTH);
    float quotient;

    printf("Number %d from decimal to hex: ", num);
    
    uint32_t i = 0;
    // iterate over a number until it's 0
    // divide it by 16, casting it to float first to get the quotient with base and fractional part 
    // then take only the fractional part using 'calcQuotientRemainder' function
    // after calculate the specific 'remForHex' for the hexadecimal representation
    // go to buffer at current index and depending on the value of the 'remForHex' add either '0', either 55 to it's value
    while (num > 0) {
        quotient = (float)num / 16.0;
        float remFromQuotient = calcQuotientRemainder(quotient);
        float remForHex = remFromQuotient * 16;

        if (remForHex < 10) {
            buffer[i] = remForHex + '0';
        } else {
            buffer[i] = remForHex + 55;
        }

        num /= 16;
        i++;
    }

    printf("0x");

    *size = i;

    // pruint32_t numbers in reverse order to implement the rule: MSD -> LSD
    for (uint32_t j = i - 1; j >= 0; j--) {
        printf("%c", buffer[j]);
    }

    printf("\n");
    return buffer;
}


uint32_t BinaryToDecimal(uint32_t *buffer, uint32_t size) {
    uint32_t decimal = 0;

    for (uint32_t i = 0; i < size; i++) {
        decimal += buffer[i] * power(2, i);
    }

    printf("After converting from binary to decimal: %d\n", decimal);

    free(buffer);
    return decimal;
}

uint32_t hexCharToValue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return 0;
}

uint32_t HexToDecimal(char *buffer, uint32_t size) {
    uint32_t decimal = 0;

    for (uint32_t i = 0; i < size; i++) {
        uint32_t value = hexCharToValue(buffer[i]);
        decimal += value * power(16, i);
    }

    printf("After converting from hex to decimal: %d\n", decimal);

    free(buffer);
    return decimal;
}