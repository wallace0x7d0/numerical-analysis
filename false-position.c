#include <stdio.h>

double function(double x){
	return x * x - 2.0;
}

double false_position(double(*function)(double), double a, double b, int n){
	double fa = function(a);
	double fb = function(b);

	if(fa * fb < 0){
		for (int i = 0; i < n; i++){
			double x = ((a * fb) - (b * fa)) / (fb - fa);
			printf("x_%i = %.16f\n", i, x);

			double fx = function(x);

			if(fx == 0){
				printf("FIND!\n");
			
			}else if(fa * fx < 0){
				b  = x;
				fb = fx;
			
			}else {
				a  = x;
				fa = fx;
			}
		}
	}
}

int main(){
	false_position(function, 1.0, 2.0, 10);

	return 0;
}