#include <stdio.h>
#include <malloc.h>
#include "Table.h"


int main() {
	
	int choice = 0, M = 0, z = 0;
	int* k = &z, * p_arr_k;
	double x = 0.0, e = 0.0, answer = 0.0, start = 0.0, stop = 0.0;
	double* p_arr_var, * p_arr_val;

	printf("Choose\n1. e^x\n2. sin(x)\n3. cos(x)\n4. ln(1+x)\n5. 1/(1-x)\n");
	scanf_s("%d", &choice);
	if (choice > 5 || choice < 1) {
		printf("Error");
	}

	printf("Input e: ");
	scanf_s("%lf", &e);

	printf("Input start, stop, M: ");
	scanf_s("%lf, %lf, %d", &start, &stop, &M);
	printf("\n");

	p_arr_var = (double*)calloc(M + 1, sizeof(double));
	p_arr_val = (double*)calloc(M + 1, sizeof(double));
	p_arr_k = (int*)calloc(M + 1, sizeof(int));

	table(start, stop, M, p_arr_var, p_arr_val, choice, e, k, p_arr_k);
	
	printf("   x\t\t|   f(x)\t\t|   N\t\t\n");
	printf("    \t\t|       \t\t|    \t\t\n");
	
	for (int i = 0; i <= M; i++) {
		printf(" %3lf\t| %3lf\t\t| %3d\t\n", p_arr_var[i], p_arr_val[i], p_arr_k[i]);
	}

	free(p_arr_var);
	free(p_arr_val);
	free(p_arr_k);

	return 0;
}