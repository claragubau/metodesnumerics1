#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fg(double x) {
	x = x*x;
	return x;
}

double fk(double x, double t) {
	x = x*x + t*t;
	return x;
}

/*la columna n+1 de la matriu sera g(x)*/
double **trapezis(int n, double landa) {
	int i, j;
	double h = 1./n;
	double **mat;

	mat = (double**)calloc((n+1),sizeof(double*));
	if(mat == NULL) { printf("dramamat\n"); exit(1); }
	for(i=0; i<(n+1); i++) {
		mat[i] = (double*)calloc((n+2), sizeof(double));
		if(mat[i]==NULL) { printf("dramat\n"); exit(1); }
	}

	for(i=0; i<n+1; i++) {
		mat[i][i] = 1.;
		mat[i][0] -= (landa*fk(i*h, 0)/2);
		mat[i][n] -= (landa*fk(i*h, 1)/2);
		mat[i][n+1] = fg(i*h);
		for(j=1; j<n; j++) 
			mat[i][j] = -landa*fk(i*h, j*h);
	}
return mat;
}
