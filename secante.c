#include <stdio.h>

double function(double x){
	return (x * x) - 2;
}

void secante(double(*function)(double), double x, double xx, int max_rounds){
	for (int i = 0; i < max_rounds; i++){

		double fxx = function(xx);
		double fx  = function(x);

		if(fxx == fx){
			return;
		}

		double new_x = ((x * fxx) - (xx * fx)) / (fxx - fx);
		
		printf("%.16lf\n", new_x);

		x = xx;
		xx = new_x;
	}
}

int main(){
	secante(function, 2, 3, 10);

	return 0;
}

