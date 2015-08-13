#include<stdio.h>
#include<math.h>
#include<omp.h>

static long num_steps=100000000;
double step;

int main(){
int i;
double x,pi,sum=0.0;
step=1.0/num_steps;

#pragma omp parallel  
{
long start,end;

start=((num_steps/omp_get_num_threads())*omp_get_thread_num());
end=((num_steps/omp_get_num_threads())*(omp_get_thread_num()+1));
int i;
double temp_sum=0.0;
for(i=start;i<end;i++){
	double x=(i+0.5)*step;
	temp_sum+=4.0/(1+x*x);
	
}
#pragma omp critical
	{
		printf("%d %.20lf\n",omp_get_thread_num(),temp_sum*step);
		sum+=temp_sum;;
	}
}

pi=sum*step;

printf("The value of pi is: %.20lf\n", pi);
}
