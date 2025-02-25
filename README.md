# C Data Structures
I wanted to implement commonly used data structures from scratch in C.
I'm sure this C code is pretty terrible, but im not very good at C and it works.

## Implemented
**Int Vector** (`ivec`)
* Could easily be translated to any other type, I just picked int since C doesnt have generics and I don't know how all the preprocessor macro stuff works.
* All the functions are prefixed with `ivec_` so I will be leaving that out for the explainations.
* Most of the functions take in a pointer to an `ivec` so I will be shortening that to just `v` for the explainations.
* `new()` allocates a vector on the heap and initializes it.
* `init(v)` initializes a vector with a heap allocated array, a capacity of 10 by default, and 0 length.
* `push(v, int element)` adds the `element` to the end of the array, if there is insufficient capacity the array will be reallocated with 1.5x the capacity. Both length & capacity (if needed) are updated.
* `remove(v, int i)` copies the value at `i` to be removed, moves every element after it back by 1, and returns the removed value.
* `set(v, int i, int element)` checks index bounds, then sets the value at `i` to `element`.
* `get(v, int i)` checks index bounds, then returns the DATA at `i`.
* `getp(v, int i)` checks index bounds, then returns the POINTER to the data at `i`.
* `cpy(v, int* arr)` copies all data from `v->array` to `arr`. There is no bounds checking done, so this is unsafe.
* `print(v)` prints all elements of `v` in standard array syntax, ex: `{ 1, 2, 3 }\n`.
* `free(v)` frees BOTH the underlying array AND `v` itself from memory.
