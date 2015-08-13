#include<stdio.h>
#include<math.h>

static long num_steps=100000000;
double step;

int main(){
int i;
double x,pi,sum=0.0;
step=1.0/num_steps;
for(i=0;i<num_steps;i++){
		x=(i+0.5)*step;
		sum+=4.0/(1+x*x);
}

pi=sum*step;

printf("The value of pi is: %.20lf\n", pi);
}
