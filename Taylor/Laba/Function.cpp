#include "Function.h"

double my_Exp(double x, double e, int* k) {

	double x_0 = 0.0, x_n = e + 1, sum = 0.0;
	int n = 1;

	x_0 = 1;
	sum = x_0;
	while (x_n > e) {
		x_n = x_0 * (x / (n++));
		sum += x_n;
		x_0 = x_n;
	}
	*k = n;
	return sum;
}

double my_Sin(double x, double e, int* k) {

	double x_0 = 0.0, x_n = e + 1, sum = 0.0, n = 0.0;
	
	if (x > 6.28) {
		while (x > 6.28) {
			x -= 6.28;
		}
	}
	
	x_0 = x;
	sum = x_0;
	while (x_n > e) {
		x_n = x_0 * ((-1 * x * x) / ((2 * n + 2) * (2 * n + 3)));
		sum += x_n;
		x_0 = x_n;
		n++;
		x_n = x_n < 0 ? -1 * x_n : x_n;
	}
	*k = n;
	return sum;
}

double my_Cos(double x, double e, int* k) {

	double x_0 = 0.0, x_n = e + 1, sum = 0.0, n = 0.0;

	if (x > 6.28) {
		while (x > 6.28) {
			x -= 6.28;
		}
	}

	x_0 = 1;
	sum = x_0;
	while (x_n > e) {
		x_n = x_0 * ((-1 * x * x) / ((2 * n + 1) * (2 * n + 2)));
		sum += x_n;
		x_0 = x_n;
		n++;
		x_n = x_n < 0 ? -1 * x_n : x_n;
	}
	*k = n;
	return sum;
}

double my_Ln(double x, double e, int* k) {

	double x_0 = 0.0, x_n = e + 1, sum = 0.0, n = 0.0;

	x_0 = x;
	sum = x_0;
	while (x_n > e) {
		x_n = x_0 * ((-1 * x * (n + 1)) / (n + 2));
		sum += x_n;
		x_0 = x_n;
		n++;
		x_n = x_n < 0 ? -1 * x_n : x_n;
	}
	*k = n;
	return sum;
}

double my_Frac(double x, double e, int* k) {

	double x_0 = 0.0, x_n = e + 1, sum = 0.0, n = 0.0;

	x_0 = 1;
	sum = x_0;
	while (x_n > e) {
		x_n = x_0 * x;
		sum += x_n;
		x_0 = x_n;
		n++;
	}
	*k = n;
	return sum;
}