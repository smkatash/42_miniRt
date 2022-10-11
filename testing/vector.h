#ifndef VECTOR_H
#define VECTOR_H

#include "rt.h"

// Returns a malloced vector with the given size.
t_vector* vector_new(size_t size, size_t width);

// Frees the vector.
void vector_free(t_vector* v);

// Frees each element of a vector with given deallocator, and frees itself.
void vector_freeA(t_vector* v, void(*elementFree)(void*));

// Returns the element at the given index.
void* vector_at(const t_vector* v, size_t idx);

// Resizes a vector to a given size and returns the vector in the new space.
t_vector* vector_realloc(t_vector* v, size_t newSize); 

// Pushes a new element on to the vector, expanding the size if necessary.
void* vector_pushback(t_vector* v, void* e);

// Pops an element off of the vector, shrinking the size if necessary.
void* vector_pop(t_vector* v);

// Sets the length of the vector to 0.
void vector_clear(t_vector* v);

#endif
