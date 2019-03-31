#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
	double sumd, sumdinv;
	float sum, suminv;
	int i, j, n;

	n = 1e3;
	for(j=3; j<=6; j++) {
		sum = 0.;
		suminv = 0.;
		sumd = 0.;
		sumdinv = 0.;
		for(i = 1; i<=n; i++) {
			sum += (1./i)/i;
			suminv += (1./(n-i+1))/(n-i+1);
			sumd += (1./i)/i;
			sumdinv += (1./(n-i+1))/(n-i+1);
		}
		printf("suma de 1 fins a %d = %23.15e\nsuma de %d fins a 1 = %23.15e\nsuma de 1 fins a %d en double = %23.15le\nsuma de %d fins a 1 en double = %23.15le\n\n", n, sum, n, suminv, n, sumd, n, sumdinv);
		n*=10;
	}
return 0;
}
