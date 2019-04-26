#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void dif_div(int n, double *x, double *y, double *difer);

int main(void) {



return 0;
}

void dif_div(int n, double *x, double *y, double *difer) {
	int i, j;

	for(j=1; j<=n; j++) 
		for(i=n; i>0; i--) 
			difer[i] = (y[i]-x[i-1])/(x[i]-x[i-j]);
return ;
}

