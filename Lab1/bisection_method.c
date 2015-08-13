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

double bisection(double (*f)(double x), double start, double end,double error){
	if((*f)(start)*(*f)(end)<0){
		double mid=(start+end)/2;
//		printf("Mid: %lf\n", mid);
		if(fabs((*f)(mid))<error)
			return mid;
		if((*f)(mid)*(*f)(start)<0)
			return bisection(f, start,mid,error);
		else
			return bisection(f, mid,end,error);
	}
	printf("Even (possibly 0) number of roots exist in [%lf, %lf]\n",start,end);
}

double iterative_bisection(double (*f)(double x), double start, double end,double error){
	if((*f)(start)*(*f)(end)>0){
		printf("Even (possibly 0) number of roots exist in [%lf, %lf]\n",start,end);
		return 0;
	}
	int n=ceil((log((end-start)/error)/(log(2))));double mid;
	printf("Number of iterations: %d\n",n);
	while(n--){
		mid=(start+end)/2;
//		printf("Mid: %lf\n", mid);
//		if(fabs((*f)(mid))<error)
//			return mid;
		if((*f)(mid)*(*f)(start)<0)
			end=mid;
		else
			start=mid;
	}
	return mid;
}

int main(){
	double (*f)(double x)=&f2;
	double start=0;
	double end=1.5;
	int decimal_accuracy=5;
	double error=pow(10,-decimal_accuracy);
	
	printf("The root of the function is: %.10lf\n", bisection(f,start,end,error));
	printf("The root of the function is: %.10lf\n", iterative_bisection(f,start,end,error));
	return 0;
}
