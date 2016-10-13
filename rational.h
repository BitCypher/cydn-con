#include <stdint.h> 

typedef struct rational { 
	int64_t num; 
	int64_t den; 
} rational_t; 

#define PS_RATIONAL struct rational * 

PS_RATIONAL init_rational(PS_RATIONAL r, int64_t n, int64_t d); 

PS_RATIONAL add_rational(PS_RATIONAL r, PS_RATIONAL a, PS_RATIONAL b); 

PS_RATIONAL sub_rational(PS_RATIONAL r, PS_RATIONAL a, PS_RATIONAL b); 

PS_RATIONAL mul_rational(PS_RATIONAL r, PS_RATIONAL a, PS_RATIONAL b); 

PS_RATIONAL div_rational(PS_RATIONAL r, PS_RATIONAL a, PS_RATIONAL b); 
