#include "complex.c"

int64_t* lucas_numbers(int64_t* a, int pos, int end) { 
	for(; pos < end; pos++) 
		a[pos] = a[pos-1] + a[pos-2];
	return a; 
} 

int test_complex_as(PS_COMPLEX* c_arr); 

int test_complex_md(PS_COMPLEX* c_arr); 

// run tests on complex.c
int main() {
	// malloc for our test variables
	int64_t* i_arr = malloc(8*sizeof(int64_t)); 
        PS_RATIONAL* r_arr = malloc(4*sizeof(PS_RATIONAL));
        PS_COMPLEX* c_arr = malloc(3*sizeof(PS_COMPLEX));

	// set the values of the variables
        i_arr[0] = 2; i_arr[1] = 1; 
	i_arr = lucas_numbers(i_arr, 2, 8); 
        int i = 0;	
	for (; i < 4; i++) { 
		r_arr[i] = malloc(sizeof(rational_t)); 
		init_rational(r_arr[i], i_arr[i+4], i_arr[i+2]); 
	} for(i = 0; i < 3; i++) { 
		c_arr[i] = malloc(sizeof(complex_t)); 
		init_complex(c_arr[i], r_arr[i], r_arr[i+1], 1); 
	} // c_arr = { [(7/3)+(11/4)i], 
		// [(11/4)+(18/7)i], [(18/7)+(29/11)i] }

	test_complex_as(c_arr); 
	test_complex_md(c_arr); 

        for (i = 0; i < 3; i++)
                free_complex(c_arr[i], 1);
        free(c_arr);
        for (i = 0; i < 4; i++)
                free(r_arr[i]);
        free(r_arr);
	free(i_arr); 
        return 0;
}

int test_complex_as(PS_COMPLEX* c_arr) { 
	PS_COMPLEX res = malloc(sizeof(complex_t)); 
	res->re = malloc(sizeof(rational_t)); 
	res->im = malloc(sizeof(rational_t)); 
	char* str = malloc(0x100); 
	printf("===Complex Addition/Subtraction===");

	add_complex(res, c_arr[0], c_arr[1]); 
	printf("=====\nExpected:\t[(61/12)+(149/28)i]\nActual:\t\t%s\n", string_complex(res, str)); 
	sub_complex(res, c_arr[0], c_arr[1]); 
	printf("=====\nExpected:\t[(-5/12)+(5/28)i]\nActual:\t\t%s\n", string_complex(res, str)); 

	add_complex(res, c_arr[1], c_arr[2]); 
	printf("=====\nExpected:\t[(149/28)+(401/77)i]\nActual:\t\t%s\n", string_complex(res, str)); 
	sub_complex(res, c_arr[1], c_arr[2]); 
	printf("=====\nExpected:\t[(5/28)+(-5/77)i]\nActual:\t\t%s\n", string_complex(res, str)); 

	add_complex(res, c_arr[2], c_arr[0]); 
	printf("=====\nExpected:\t[(103/21)+(237/4)i]\nActual:\t\t%s\n", string_complex(res, str)); 
	sub_complex(res, c_arr[2], c_arr[0]); 
	printf("=====\nExpected:\t[(5/21)+(-5/44)i]\nActual:\t\t%s\n", string_complex(res, str)); 

	free(str); 
	free_complex(res, 1); 
	return 0; 
} 

int test_complex_md(PS_COMPLEX* c_arr) { 
	PS_COMPLEX* res = malloc(2*sizeof(complex_t));
	int i = 0; 
	for (; i < 2; i++) { 
		res[i] = malloc(sizeof(complex_t)); 
		res[i]->re = malloc(sizeof(rational_t)); 
		res[i]->im = malloc(sizeof(rational_t)); 
	} 
	char* str = malloc(0x200); 
	printf("===Complex Multiplication/Division===");

	mul_complex(res[0], c_arr[0], c_arr[1]); 
	printf("=====\nExpected:\t[(-55/84)+(217/16)i]\nActual:\t\t%s\n", string_complex(res[0], str)); 
	div_complex(res[1], res[0], c_arr[0]); 
	printf("=====\nExpected:\t%s\nActual:\t\t%s\n", 
		string_complex(c_arr[1], str), string_complex(res[1], &str[0x100])); 
	div_complex(res[1], res[0], c_arr[1]); 
	printf("=====\nExpected:\t%s\nActual:\t\t%s\n", 
		string_complex(c_arr[0], str), string_complex(res[1], &str[0x100])); 

	mul_complex(res[0], c_arr[1], c_arr[2]); 
	printf("=====\nExpected:\t[(45/154)+(2717/196)i]\nActual:\t\t%s\n", string_complex(res[0], str)); 
	div_complex(res[1], res[0], c_arr[1]); 
	printf("=====\nExpected:\t%s\nActual:\t\t%s\n", 
		string_complex(c_arr[2], str), string_complex(res[1], &str[0x100])); 
	div_complex(res[1], res[0], c_arr[2]); 
	printf("=====\nExpected:\t%s\nActual:\t\t%s\n", 
		string_complex(c_arr[1], str), string_complex(res[1], &str[0x100])); 

	mul_complex(res[0], c_arr[2], c_arr[0]); 
	printf("=====\nExpected:\t[(53/4)+(6109/462)i]\nActual:\t\t%s\n", string_complex(res[0], str)); 
	div_complex(res[1], res[0], c_arr[2]); 
	printf("=====\nExpected:\t%s\nActual:\t\t%s\n", 
		string_complex(c_arr[0], str), string_complex(res[1], &str[0x100])); 
	div_complex(res[1], res[0], c_arr[0]); 
	printf("=====\nExpected:\t%s\nActual:\t\t%s\n", 
		string_complex(c_arr[2], str), string_complex(res[1], &str[0x100])); 

	free(str); 
	for (i = 0; i < 2; i++) free_complex(res[i], 1); 
	return 0; 
} 
