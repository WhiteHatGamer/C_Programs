#ifndef BIT_FIELDS_H
#define BIT_FIELDS_H

#include <stdint.h>

#pragma pack(push, 1)
struct bitField {
    uint8_t options;
    unsigned int small:2;
    unsigned int medium:4;
    unsigned int large:6;
    uint64_t bit64;
};
#pragma pack(pop)

#define SET_BIT(BF, N) BF |= ((uint64_t)0x0000000000000001 << N)
#define CLR_BIT(BF, N) BF &= ~((uint64_t)0x0000000000000001 << N)
#define IS_BIT_SET(BF, N) ((BF >> N) & 0x1)

typedef struct bitField bitfield_t;

// Initialize bit Fields to null
bitfield_t* initBitField();

#endif