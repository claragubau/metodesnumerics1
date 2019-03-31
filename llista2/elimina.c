#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int pivot(int n, int k, double **mat) {
        int i, fila=0;
        double piv=0;

        for(i=k; i<n; i++)
                if(fabs(mat[k][i])>fabs(piv)) {
                        piv = mat[i][k];
                        fila = i;
                }
return fila;
}

int gauss(int n, double **a, int pivotem, double tol){
	int i, j, k, piv;
	double *aux;
	
	if(pivotem == 1) {
		for(k=0; k<n-1; k++) {
			piv = pivot(n, k, a);
			if(piv!=k) { 
				aux = a[k];
				a[k] = a[piv];
				a[piv] = aux;
			}
			if(fabs(a[k][k])<tol) { printf("div entre zero\n"); return 0; }
			for(i=k+1; i<n; i++){
				a[i][k]=a[i][k]/a[k][k];
				for(j=k+1; j<=n; j++) {
					a[i][j] = a[i][j] - a[i][k]*a[k][j];
				}
			}
		}
	} else {
		for(k=0; k<n-1; k++) {
			if(fabs(a[k][k])<tol) { printf("div entre zero\n"); return 0; }
			for(i=k+1; i<n; i++){
				a[i][k]=a[i][k]/a[k][k];
				for(j=k+1; j<=n; j++) {
					a[i][j] = a[i][j] - a[i][k]*a[k][j];
				}
			}
		}
	}
	return 1;
}
