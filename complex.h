#include <stdlib.h>
#include <inttypes.h>
#include "rational.c"

typedef struct complex {
        PS_RATIONAL re;
        PS_RATIONAL im;
} complex_t;

#define PS_COMPLEX struct complex *

static/*const*/complex_t ZERO_COMPLEX = {&ZERO_RATIONAL, &ZERO_RATIONAL};
static/*const*/complex_t NEGATIVE_ONE_COMPLEX = {&NEGATIVE_ONE_RATIONAL, &ZERO_RATIONAL};

PS_COMPLEX init_complex(PS_COMPLEX c, PS_RATIONAL r, PS_RATIONAL i, int mkspc);

PS_COMPLEX array_init_complex(PS_COMPLEX c, PS_RATIONAL *r, int64_t *d, int mkspc); 

// c = a + b
PS_COMPLEX add_complex(PS_COMPLEX c, PS_COMPLEX a, PS_COMPLEX b);

// c = a - b
PS_COMPLEX sub_complex(PS_COMPLEX c, PS_COMPLEX a, PS_COMPLEX b);

// c = a * b
PS_COMPLEX mul_complex(PS_COMPLEX c, PS_COMPLEX a, PS_COMPLEX b);

// c = a / b
PS_COMPLEX div_complex(PS_COMPLEX c, PS_COMPLEX a, PS_COMPLEX b);

// the norm of c, squared
PS_RATIONAL norm_sq_complex(PS_RATIONAL r, PS_COMPLEX c);

// input*output=1
PS_COMPLEX mul_inv_complex(PS_COMPLEX o, PS_COMPLEX i); 

// string representation of c
char* string_complex(PS_COMPLEX c, char* s); 
