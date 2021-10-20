#include <stdio.h>

double function(double x){
	return (x * x) - 2;
}

double dfunction(double x){
	return 2 * x;
}

void newton(double(*function)(double), double(*dfunction)(double), double x, double max_rounds){
	for (int i = 0; i < max_rounds; i++){
		double new_x = x - function(x) / dfunction(x);
		printf("%.12lf\n", new_x);
		x = new_x;
	}
}

int main(){
	newton(function, dfunction, 5, 10);

	return 0;
}