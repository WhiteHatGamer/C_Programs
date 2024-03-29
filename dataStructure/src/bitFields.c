#include "bitFields.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

bitfield_t* initBitField(){
    bitfield_t* tmp = (bitfield_t*)malloc(sizeof(bitfield_t));
    if (!tmp){
        //NULL Validation
        return NULL;
    }
    tmp->bit64 = 0;
    tmp->small = 0;
    tmp->medium = 0;
    tmp->large = 0;
    tmp->options = 0;
    return tmp;
}

void freeBitfield(bitfield_t* _bit){
    free (_bit);
}

void printBin(int _int, int _bit){
    for (int i = 0; i < _bit; i++) {
        int bitValue = (_int >> (_bit - i - 1)) & 1;
        printf("%d", bitValue);
    }
}

void Print64Bit(uint64_t _bit64){
    for (int i = 0; i < 64; i++)
    {
        if(IS_BIT_SET(_bit64, i)){
            printf("+");
        }else{
            printf(".");
        }
        //printf("\n");
    }
    
}