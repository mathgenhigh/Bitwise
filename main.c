#include <bitwise_utils.h>

int main(void) {
    uint32_t num = 57;
    uint32_t mask = 34;
    uint32_t nbits = 8;
    printf("---------------------\n");
    bitwiseNOT(num);
    printf("---------------------\n");
    bitwiseAND(num, mask);
    printf("---------------------\n");
    bitwiseOR(num, mask);
    printf("---------------------\n");
    bitwiseXOR(num, mask);
    printf("---------------------\n");
    bitwiseLeftShift(num, nbits);
    printf("---------------------\n");
    bitwiseRightShift(num, nbits);
    return 0;
}