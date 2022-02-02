#include "Function.h"
#include "Table.h"

void Loop(int M, double* p_arr_val, double* p_arr_var, int* p_arr_k, int* k, double e, double (*func)(double, double, int*));

void table(double start, double stop, int M, double* p_arr_var, double* p_arr_val, int choice, double e, int *k, int* p_arr_k) {

	int gaps = M;
	double distance = stop - start;
	double difference = distance / gaps;


	p_arr_var[0] = start;
	p_arr_var[M] = stop;

	for (int i = 0; i < M - 1; i++) {
		p_arr_var[i + 1] = p_arr_var[i] + difference;
	}

	if (choice == 1) {
		Loop(M, p_arr_val, p_arr_var, p_arr_k, k, e, my_Exp);
	}
	else if (choice == 2) {
		Loop(M, p_arr_val, p_arr_var, p_arr_k, k, e, my_Sin);
	}
	else if (choice == 3) {
		Loop(M, p_arr_val, p_arr_var, p_arr_k, k, e, my_Cos);
	}
	else if (choice == 4) {
		Loop(M, p_arr_val, p_arr_var, p_arr_k, k, e, my_Ln);
	}
	else {
	Loop(M, p_arr_val, p_arr_var, p_arr_k, k, e, my_Frac);
	}
}

void Loop(int M, double* p_arr_val, double* p_arr_var, int* p_arr_k, int* k, double e, double (*func)(double, double, int*)) {

	for (int i = 0; i <= M; i++) {
		p_arr_val[i] = func(p_arr_var[i], e, k);
		p_arr_k[i] = *k;
	}
}