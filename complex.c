#include "complex.h"

PS_COMPLEX init_complex(PS_COMPLEX c, PS_RATIONAL r, PS_RATIONAL i, int mkspc) { 
	// make hard copies of init variables (i.e. actual values instead of addresses)
	if (mkspc) { 
		c->re = malloc(sizeof(rational_t)); 
		c->im = malloc(sizeof(rational_t)); 
	}
	init_rational(c->re, r->num, r->den); 
	init_rational(c->im, i->num, i->den); 
	return c; 
} 

//in: 1 complex structure, 2 rational structure, 4 int64_ts
//	put the ints in the rationals, then put the rationals in the complex
PS_COMPLEX array_init_complex(PS_COMPLEX c, PS_RATIONAL *r, int64_t *d, int mkspc) { 
	int i = 0; 
	for (; i < 4; i=i+2) 
		init_rational(r[i/2], d[i], d[i+1]); 
	return init_complex(c, r[0], r[1], mkspc); 
}

int free_complex(PS_COMPLEX c, int all) { 
	free(c->re); 
	free(c->im); 
	if (all) free(c); 
	return 0; 
} 

// c = a + b
PS_COMPLEX add_complex(PS_COMPLEX c, PS_COMPLEX a, PS_COMPLEX b) { 
	return init_complex(c, 
		add_rational(c->re, a->re, b->re), 
		add_rational(c->im, a->im, b->im), 0); 
} 

// c = a - b
PS_COMPLEX sub_complex(PS_COMPLEX c, PS_COMPLEX a, PS_COMPLEX b) {
	return init_complex(c, 
		sub_rational(c->re, a->re, b->re), 
		sub_rational(c->im, a->im, b->im), 0); 
} 

// c = a * b
PS_COMPLEX mul_complex(PS_COMPLEX c, PS_COMPLEX a, PS_COMPLEX b) { 
	PS_RATIONAL *arr = malloc(4*sizeof(PS_RATIONAL)); 
	int i = 0; 
	for (; i < 4; i++) { arr[i] = malloc(sizeof(rational_t)); }
	init_complex(c, 
		sub_rational(c->re, 
			mul_rational(arr[0], a->re, b->re), 
			mul_rational(arr[1], a->im, b->im)), 
		add_rational(c->im, 
			mul_rational(arr[2], a->re, b->im), 
			mul_rational(arr[3], a->im, b->re)), 0);
	for (i = 0; i < 4; i++) { free(arr[i]); }
	free(arr); 
	return c; 
}


// c = a / b
PS_COMPLEX div_complex(PS_COMPLEX c, PS_COMPLEX a, PS_COMPLEX b) { 
	PS_COMPLEX d = malloc(sizeof(complex_t)); 
	d->re = malloc(sizeof(rational_t)); 
	d->im = malloc(sizeof(rational_t)); 
	mul_complex(c, a, mul_inv_complex(d, b)); 
	free(d); 
	return c; 
}

// o will be the complex conjugate of i
PS_COMPLEX conjugate_complex(PS_COMPLEX o, PS_COMPLEX i) { 
	o->im = mul_rational(o->im, i->im, &NEGATIVE_ONE_RATIONAL);
	return init_complex(o, i->re, o->im, 0); 
} 

// the norm of c, squared
PS_RATIONAL norm_sq_complex(PS_RATIONAL r, PS_COMPLEX c) { 
	PS_RATIONAL a = malloc(sizeof(rational_t)); 
	PS_RATIONAL b = malloc(sizeof(rational_t)); 
	add_rational(r, mul_rational(a, c->re, c->re), mul_rational(b, c->im, c->im)); 
	free(a); free(b); 
	return r; 
}

// input*output=1
PS_COMPLEX mul_inv_complex(PS_COMPLEX o, PS_COMPLEX i) { 
	PS_RATIONAL *arr = malloc(4*sizeof(PS_RATIONAL)); 
	int j = 0; 
	for (; j < 4; j++) { arr[j] = malloc(sizeof(rational_t)); }
	conjugate_complex(i, i); 
	norm_sq_complex(arr[0], i); 
	div_rational(arr[1], i->re, arr[0]); 
	div_rational(arr[2], i->im, arr[0]); 
	init_complex(o, arr[1], arr[2], 0); 
	for (j = 0; j < 4; j++) { free(arr[j]); }
	free(arr); 
	return o; 
}

char* string_complex(PS_COMPLEX c, char* s) { 
	char* r = malloc(0x100); 

	sprintf(s, "[%s+%si]", 
		string_rational(c->re, r), 
		string_rational(c->im, &r[0x80])); 


	free(r); 
	return s; 
} 
