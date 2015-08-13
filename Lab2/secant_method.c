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
	return x*log(x)-1.5;
}

double f4(double x){
	return cos(x)-x*exp(x);
}

double secant(double (*f)(double x),double first, double second, double error){
	double third=second-(second-first)*((*f)(second)/((*f)(second)-(*f)(first)));
	if(fabs((second)-((third)))<(error))
		return third;
	else{
		//printf("%lf\n",-(next)/pow(start,2));
		return secant(f,second,third,error);
	}
}


int main(){
	double (*f)(double x)=&f4;
	double first=0;
	double second=1;
	int decimal_accuracy=5;
	double error=pow(10,-decimal_accuracy);
	double answer;
	printf("The root of the function is: %.10lf\n", answer=secant(f,first,second,error));
	
	printf("The value of the function is: %.10lf\n", (*f)(answer));
//	printf("Bisection : %.10lf\n",iterative_bisection(f,3,start,error));
	return 0;
}
