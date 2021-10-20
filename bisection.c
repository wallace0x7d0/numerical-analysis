#include <stdio.h>

long double function(long double x){
	return (x * x * x) - x - 1;
}

void bisection(long double(*function)(long double), long double a, long double b, int max_rounds){
	
	if(function(a) * function(b) >= 0){
		printf("Error!\n");

	}else {
		long double c = (a + b) / 2;
		printf("%.15llf\n", c);

		if(function(c) == 0){
			return;
		}else {

			if(function(a) * function(c) < 0){
				bisection(function, a, c, --max_rounds);
		
			}else if(function(c) * function(b) < 0){
				bisection(function, c, b, --max_rounds);
		
			}

		}
	}
}

int main(){

	bisection(function, -10, 4, 100);

	return 0;
}