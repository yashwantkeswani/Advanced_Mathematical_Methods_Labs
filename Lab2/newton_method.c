#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

double f1(double x){
	return x*x*x - 35.0;
}

double f2(double x){
	return sin(2*M_PI*x)+exp(1.2*x)+x-2.5;
}

double volume(double R,double h){
	return M_PI*pow(h,2)*(3*R-h)/3;
}

double f3(double x){
	return volume(3,x)-30;
}

double d3(double x){
	return M_PI*(6*x-pow(x,2));
}


double f4(double x){
	return 1-exp(-1*pow(x,2));
}

double d4(double x){
	return exp(-1*pow(x,2))*2*x;
} 
double newton_raphson(double (*f)(double x), double (*d)(double x),double start, double error){
	double next=start-((*f)(start)/(*d)(start));
	if(fabs((start)-((next)))<(error))
		return next;
	else{
		printf("%lf\n",-(next)/pow(start,2));
		return newton_raphson(f,d,next,error);
	}
}




int main(){
	double (*f)(double x)=&f3;
	double (*d)(double x)=&d3;
	double start=3;
	//double end=1.5;
	int decimal_accuracy=5;
	double error=pow(10,-decimal_accuracy);
	double answer;
	printf("The root of the function is: %.10lf\n", answer=newton_raphson(f,d,start,error));
	
	printf("The value of the function is: %.10lf\n", (*f)(answer));
//	printf("Bisection : %.10lf\n",iterative_bisection(f,3,start,error));
	return 0;
}
