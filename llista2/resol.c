#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int pivot(int, int, double **);
int gauss(int, double **, int, double);
void subs_enrere(int, double**);

int main(void) {
	int i, j, numgauss, n;
	double **mat;
	FILE *in, *out;
	char nomentrada[50], nomsortida[50];

	/*fitxers*/
	printf("nom fitxer entrada\n");
	scanf("%s", nomentrada);
	in = fopen(nomentrada, "r");
	if(in == NULL) { printf("problemafitxer\n"); exit(1); }

	printf("nom fitxer sortida\n");
	scanf("%s", nomsortida);
	out = fopen(nomsortida, "w");
	if(out == NULL) { printf("problemafitxerout\n"); exit(1); }
	
	/*scan matriu*/
	fscanf(in, "%d", &n);
	mat = (double**)calloc(n,sizeof(double*));
	if(mat==NULL) { printf("dramat\n"); exit(1); }
	for(i=0; i<n; i++) {
		mat[i] = (double*)calloc((n+1), sizeof(double));
		if(mat[i] == NULL) { printf("dramat\n"); exit(1); }
	}
	for(i=0; i<n; i++) 
		for(j=0; j<n+1; j++) 
			fscanf(in, "%le", &mat[i][j]);

	/*comença el programa*/
	/*-----------gaussensepiv------------*/
	numgauss = gauss(n, mat, 0, 1e-8);
	fprintf(out, "gauss sense pivotatge\n");
	if(numgauss == 0) { printf("no s'ha pogut fer gaussensepiv\n"); exit(1); }
	else {
		subs_enrere(n, mat);
		for(i=0; i<n; i++) {
				fprintf(out, "%23.15le\t", mat[i][n]);
			fprintf(out,"\n");
		}
	}
	fclose(in);
	/*----------gausspiv------------------*/
	in = fopen(nomentrada, "r");
	if(in == NULL) { printf("problemafitxer\n"); exit(1); }
	        fscanf(in, "%d", &n);
        mat = (double**)calloc(n,sizeof(double*));
        if(mat==NULL) { printf("dramat\n"); exit(1); }
        for(i=0; i<n; i++) {
                mat[i] = (double*)calloc((n+1), sizeof(double));
                if(mat[i] == NULL) { printf("dramat\n"); exit(1); }
        }
        for(i=0; i<n; i++) 
                for(j=0; j<n+1; j++)
                        fscanf(in, "%le", &mat[i][j]);

	numgauss = gauss(n, mat, 1, 1e-8);
	fprintf(out, "\ngauss amb piv\n");
	if(numgauss == 0) { printf("no s'ha pogut fer gausspiv\n"); exit(1); }
	else {
		subs_enrere(n, mat);
		for(i=0; i<n; i++){ 
				fprintf(out, "%23.15le\t", mat[i][n]);
			fprintf(out, "\n");
		}
	}
return 0;
}

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
