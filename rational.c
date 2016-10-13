//#include <stdio.h> 
//#include <stdlib.h> 
#include <inttypes.h> 
#include "rational.h" 

int64_t gcd(int64_t a, int64_t b) { 
	if (a < b) { 
		int64_t t = a; 
		a = b; 
		b = t; 
	} 
	if (a%b==0) 
		return b; 
	return gcd(b, a%b); 
}

PS_RATIONAL init_rational(PS_RATIONAL r, int64_t n, int64_t d) { 
	int64_t g = gcd((n>0)?n:n*-1, (d>0)?d:d*-1);
	r->num = n/g; 
	r->den = d/g; 
	return r; 
}

PS_RATIONAL add_rational(PS_RATIONAL r, PS_RATIONAL a, PS_RATIONAL b) { 
	return init_rational(r, a->num*b->den + b->num*a->den, a->den*b->den); 
}

PS_RATIONAL sub_rational(PS_RATIONAL r, PS_RATIONAL a, PS_RATIONAL b) { 
	return init_rational(r, a->num*b->den - b->num*a->den, a->den*b->den); 
}

PS_RATIONAL mul_rational(PS_RATIONAL r, PS_RATIONAL a, PS_RATIONAL b) { 
	return init_rational(r, a->num*b->num, a->den*b->den);
}

PS_RATIONAL div_rational(PS_RATIONAL r, PS_RATIONAL a, PS_RATIONAL b) { 
	return init_rational(r, a->num*b->den, a->den*b->num);
}

/*void test_as(PS_RATIONAL* r_arr) { 
        PS_RATIONAL res;
        // Addition and Subtraction
        rational_add(res, r_arr[0], r_arr[1]);
        printf("Expected: 17/6; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_sub(res, r_arr[2], r_arr[1]);
        printf("Expected: 5/12; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_add(res, r_arr[2], r_arr[3]);
        printf("Expected: 93/28; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_sub(res, r_arr[4], r_arr[3]);
        printf("Expected: 5/77; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_add(res, r_arr[4], r_arr[5]);
        printf("Expected: 643/198; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_sub(res, r_arr[6], r_arr[5]);
        printf("Expected: 5/522; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
}

void test_md(PS_RATIONAL* r_arr) { 
	PS_RATIONAL res; 
        // Multiplication and Division
        rational_mul(res, r_arr[7], r_arr[6]);
        printf("Expected: 76/29; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_div(res, r_arr[6], r_arr[7]);
        printf("Expected: 2204/2209; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_mul(res, r_arr[7], r_arr[8]);
        printf("Expected: 123/47; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_div(res, r_arr[8], r_arr[7]);
        printf("Expected: 5781/5776; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_mul(res, r_arr[9], r_arr[8]);
        printf("Expected: 199/76; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
        rational_div(res, r_arr[8], r_arr[9]);
        printf("Expected: 15124/15129; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den);
}

int main() {
        // run tests on rational.c
        PS_RATIONAL r_arr[10];
        int64_t  l_num1=2, l_num2=1;
        int i = 0;
        for (; i < 10; i++) {
                l_num1 = l_num1 + l_num2;
                rational_init(r_arr[i++], l_num2, l_num1);
                l_num2 = l_num2 + l_num1;
                rational_init(r_arr[i], l_num2, l_num1);
        } // r_arr = [3/2, 4/3, 7/4, 11/7, 18/11,
                // 29/18, 47/29, 76/47, 123/76, 199/123]
	printf("Commencing rational number \"type\" tests...\n"); 
	test_as(r_arr); 
	test_md(r_arr); 
	printf("Rational number \"type\" tests complted!\n"); 
	return 0; 
}*/
