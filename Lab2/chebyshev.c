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

double chebyshev(double (*f)(double x),double start, double step, double error){
//	double third=second-(second-first)*((*f)(second)/((*f)(second)-(*f)(first)));
	double next=start-(step*(*f)(start)/((*f)(start+step)-(*f)(start))-0.5*(step*pow((*f)(start),2)*((*f)(start+step)-2*(*f)(start)+(*f)(start-step))/pow((*f)(start+step)-(*f)(start),3)));
	if(fabs((start)-((next)))<(error))
		return next;
	else{
		//printf("%lf\n",-(next)/pow(start,2));
		return chebyshev(f,next,step,error);
	}
}



int main(){
	double (*f)(double x)=&f4;
	double start=1;
	int decimal_accuracy=5;
	double error=pow(10,-decimal_accuracy);
	double answer;
	printf("The root of the function is: %.10lf\n", answer=chebyshev(f,start,error/10,error));
	
	printf("The value of the function is: %.10lf\n", (*f)(answer));
//	printf("Bisection : %.10lf\n",iterative_bisection(f,3,start,error));
	return 0;
}











/*
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

*/

