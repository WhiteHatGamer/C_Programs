#include "queue.h"
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    linkedlist_t* front;
    linkedlist_t* rear;
}queue_t;
