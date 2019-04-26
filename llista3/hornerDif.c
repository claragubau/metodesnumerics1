#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double aval(int n, double *x, double *difer, double z);

int main (void) {


return 0;
}

double aval(int n, double *x, double *difer, double z) {
	int i;
	double pol;

	for(i=n; i>0; i--) {
		pol += difer[i];
		pol *= (z-x[i-1]);
	}
	pol += difer[0];

return pol;
}
