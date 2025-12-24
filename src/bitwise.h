#ifndef BITWISE_H
#define BITWISE_H

#include "conversions.h"

void bitwiseNOT(uint32_t num);
void bitwiseAND(uint32_t num, uint32_t mask);
void bitwiseOR(uint32_t num, uint32_t mask);
void bitwiseXOR(uint32_t num, uint32_t mask);
void bitwiseLeftShift(uint32_t num, uint32_t nbits);
void bitwiseRightShift(uint32_t num, uint32_t nbits);

#endif // BITWISE_H