#include <stdio.h> 
#include <stdlib.h> 
#include <inttypes.h>
#include "rational.c" 

int main() { 
	// run tests on rational.c
	PS_RATIONAL* r_arr = malloc(10*sizeof(PS_RATIONAL)); 
	int64_t  l_num1=2, l_num2=1; 
	int i = 0; 
	while (i < 10) { 
		l_num1 = l_num1 + l_num2; 
		r_arr[i] = malloc(sizeof(rational_t)); 
		init_rational(r_arr[i++], l_num1, l_num2); 
		/* printf("r_arr[%d]: %d/%d\n", i-1, 
			(int)r_arr[i-1]->num, (int)r_arr[i-1]->den); */ 
		l_num2 = l_num2 + l_num1; 
		r_arr[i] = malloc(sizeof(rational_t)); 
		init_rational(r_arr[i++], l_num2, l_num1); 
		/* printf("r_arr[%d]: %d/%d\n", i-1, 
			(int)r_arr[i-1]->num, (int)r_arr[i-1]->den); */
	} // r_arr = [3/1, 4/3, 7/4, 11/7, 18/11, 
		// 29/18, 47/29, 76/47, 123/76, 199/123]

	PS_RATIONAL res = malloc(sizeof(rational_t)); 
	// Addition and Subtraction
	printf("\n===Addition/Subtraction Tests===\n"); 
	add_rational(res, r_arr[0], r_arr[1]); 
	printf("Expected: 17/6; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	sub_rational(res, r_arr[2], r_arr[1]); 
	printf("Expected: 5/12; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	add_rational(res, r_arr[2], r_arr[3]); 
	printf("Expected: 93/28; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	sub_rational(res, r_arr[4], r_arr[3]); 
	printf("Expected: 5/77; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	add_rational(res, r_arr[4], r_arr[5]); 
	printf("Expected: 643/198; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	sub_rational(res, r_arr[6], r_arr[5]); 
	printf("Expected: 5/522; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	// Multiplication and Division 
	printf("\n===Multiplication/Division Tests===\n"); 
	mul_rational(res, r_arr[7], r_arr[6]); 
	printf("Expected: 76/29; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	div_rational(res, r_arr[6], r_arr[7]); 
	printf("Expected: 2209/2204; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	mul_rational(res, r_arr[7], r_arr[8]); 
	printf("Expected: 123/47; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	div_rational(res, r_arr[8], r_arr[7]); 
	printf("Expected: 5781/5776; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	mul_rational(res, r_arr[9], r_arr[8]); 
	printf("Expected: 199/76; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 
	div_rational(res, r_arr[8], r_arr[9]); 
	printf("Expected: 15129/15124; Actual: %" PRId64 "/%" PRId64 "\n", res->num, res->den); 

	for (i = 0; i < 10; i++) 
		free(r_arr[i]); 
	free(r_arr); 
	free(res); 
	return 0; 
}
