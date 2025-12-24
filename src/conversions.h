#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include <stdio.h>

#define BUF_WIDTH 32

typedef unsigned int uint32_t;

uint32_t power(uint32_t base, uint32_t n);
uint32_t* decimalToBinary(uint32_t num, uint32_t *size);
char* decimalToHex(uint32_t num, uint32_t *size);
uint32_t BinaryToDecimal(uint32_t *buffer, uint32_t size);
uint32_t HexToDecimal(char *buffer, uint32_t size);

#endif // CONVERSIONS_H