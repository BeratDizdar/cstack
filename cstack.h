#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    void* data;
    size_t element_size;
    int top;
    int max_size;
} stack_t;

static inline stack_t* createStack(size_t element_size, int max_elements) {
    stack_t* new_stack = (stack_t*)malloc(sizeof(stack_t));
    if (!new_stack) return NULL;

    new_stack->data = malloc(element_size * max_elements);
    if (!new_stack->data) {
        free(new_stack);
        return NULL;
    }

    new_stack->element_size = element_size;
    new_stack->top = -1;
    new_stack->max_size = max_elements;
    
    return new_stack;
}

static inline int push(stack_t* stack, const void* element) {
    if (stack->top >= stack->max_size - 1) {
        fprintf(stderr, "Stack overflow!\n");
        return 0;
    }

    stack->top++;
    memcpy((char*)stack->data + (stack->top * stack->element_size), element, stack->element_size);
    return 1;
}

static inline int peek(const stack_t* stack, void* out_element) {
    if (stack->top < 0) {
        fprintf(stderr, "Stack is empty!\n");
        return 0;
    }

    memcpy(out_element, (char*)stack->data + (stack->top * stack->element_size), stack->element_size);
    return 1;
}

static inline int pop(stack_t* stack, void* out_element) {
    if (stack->top < 0) {
        fprintf(stderr, "Stack underflow!\n");
        return 0;
    }

    memcpy(out_element, (char*)stack->data + (stack->top * stack->element_size), stack->element_size);
    stack->top--;
    return 1;
}

static inline int isEmpty(const stack_t* stack) {
    return stack->top == -1;
}

static inline void freeStack(stack_t* stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}
