#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void subs_endavant(int n, double **matL){
	int i, k;	
	double sum, tol = 1e-8;

	for(i=0; i<n; i++) {
		sum = 0.;
		if(fabs(matL[i][i]) < tol) { printf("no podem dividir entre zero\n"); exit(1); }
		for(k=0; k<i; k++) 
			sum += matL[i][k]*matL[k][n];
		matL[i][n] = (matL[i][n] - sum)/matL[i][i];
	}

return;
}
