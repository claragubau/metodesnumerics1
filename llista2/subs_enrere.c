#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void subs_enrere(int n, double **matU){
	int i, k;
	double sum, tol = 1e-8;

	for(i=n-1; i >= 0; i--) {
		sum = 0.;
		if(fabs(matU[i][i]) < tol) { printf("subsenrere div entre zero\n"); exit(1); }
		for(k = n-1; k > i; k--) sum += matU[i][k]*matU[k][n];
		matU[i][n] = (matU[i][n] - sum)/matU[i][i];
	}
return;
}
