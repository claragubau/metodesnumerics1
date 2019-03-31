#include<stdio.h>
#include<stdlib.h>

double **prodmat(double **a, int filA, int colA, double **b, int colB) {
	int i, j, k;
	double **mat;

	mat = (double**)calloc(filA,sizeof(double*));
	if(mat == NULL) { printf("problemes amb memoria mat\n"); exit(1); }
	for(i=0; i<filA; i++) {
		mat[i] = (double*)calloc(colB,sizeof(double));
		if(mat[i]==NULL) { printf("problemes memoria mat\n"); exit(1); }
	}

	for(i = 0; i < filA; i++) 
		for(j = 0; j < colB; j++) 
			for(k = 0; k < colA; k++)
				mat[i][j] += a[i][k]*b[k][j];
return mat;
}
