#include <stdlib.h>

#include "vector.h"

// Returns a malloced vector with the given size.
t_vector* vector_new(size_t size, size_t width) {
    t_vector* v = malloc(sizeof *v);
    if (v == NULL) return NULL;

    v->length = 0;
    v->width = width;
    v->size = size;
    v->array = malloc(v->size * v->width);
    return v;
}

// Frees the vector.
void vector_free(t_vector* v) {
    free(v->array);
    free(v);
}

// Frees each element of a vector with given deallocator, and frees itself.
void vector_freeA(t_vector* v, void(*elementFree)(void*)) {
    for (size_t i = 0; i < v->length; i++) {
        elementFree(v->array[i]);
    }
    free(v->array);
    free(v);
}

// Returns the element at the given index.
void* vector_at(const t_vector* v, size_t idx) {
    return v->array[idx];
}

// Resizes a vector to a given size and returns the vector in the new space.
t_vector* vector_realloc(t_vector* v, size_t newSize) {
    void* newArray = realloc(v->array, newSize * v->width);
    if (newArray == NULL) return NULL;
    v->array = newArray;
    v->size = newSize;
    return v;
}

// Pushes a new element on to the vector, expanding the size if necessary.
void* vector_pushback(t_vector* v, void* e) {
    if (v->length >= v->size && vector_realloc(v, v->size * 2) == NULL) {
        return NULL; 
    }

    v->array[v->length] = e;
    return v->array[v->length++];
}

// Pops an element off of the vector, shrinking the size if necessary.
void* vector_pop(t_vector* v) {
    if (v->length <= 0 || 
        (v->length < v->size / 4 && vector_realloc(v, v->size / 2) == NULL)) 
    {
        return NULL;
    }

    return v->array[--v->length];
}

// Sets the length of the vector to 0.
void vector_clear(t_vector* v) {
    v->length = 0;
}

