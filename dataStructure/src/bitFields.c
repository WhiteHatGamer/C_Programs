#include "bitFields.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

bitfield_t* initBitField(){
    bitfield_t* tmp = (bitfield_t*)malloc(sizeof(bitfield_t));
    tmp->bit64 = 0;
    tmp->small = 0;
    tmp->medium = 0;
    tmp->large = 0;
    tmp->options = 0;
}