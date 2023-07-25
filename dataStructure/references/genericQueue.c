#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int front, rear, size;
    unsigned capacity;
    void** array;
} generic_queue_t;

// Function to create a new generic queue
generic_queue_t* createGenericQueue(unsigned capacity) {
    generic_queue_t* queue = (generic_queue_t*)malloc(sizeof(generic_queue_t));
    // ...
    return queue;
}

// Function to enqueue an element into the generic queue
void enqueue(generic_queue_t* queue, void* data) {
    // ...
}

// Function to dequeue an element from the generic queue
void* dequeue(generic_queue_t* queue) {
    // ...
}

// Example usage
int main() {
    generic_queue_t* intQueue = createGenericQueue(5);
    int value1 = 42;
    int value2 = 10;
    enqueue(intQueue, &value1);
    enqueue(intQueue, &value2);

    // Dequeue and cast back to int
    int* dequeuedValue1 = (int*)dequeue(intQueue);
    int* dequeuedValue2 = (int*)dequeue(intQueue);

    // Now you have the values back as int variables
    printf("%d %d\n", *dequeuedValue1, *dequeuedValue2);

    // Clean up
    free(intQueue->array);
    free(intQueue);
    return 0;
}
