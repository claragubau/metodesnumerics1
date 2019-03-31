#include<stdio.h>
#include<stdlib.h>

void subs_endavant(int, double**);

int main(void){
	int i, j, n;
	double **mat;


	printf("dimmat\n");
	scanf("%d", &n);

	mat=(double**)calloc(n,sizeof(double*));
	if(mat==NULL) { printf("dramamatriu\n"); exit(1); }
	for(i=0; i<n; i++) {
		mat[i]=(double*)calloc((n+1),sizeof(double));
		if(mat[i]==NULL) { printf("dramatriu\n"); exit(1); }
	}

	printf("introdueix matriu\n");
	for(i=0; i<n; i++) 
		for(j=0; j<n+1; j++) 
			scanf("%le", &mat[i][j]);

	subs_endavant(n, mat);

	printf("matriu despres de subs_enrere\n");
	for(i=0; i<n; i++) {
		for(j=0; j<n+1; j++) 
			printf("%23.15le\t", mat[i][j]);
		printf("\n");
	}

	for(i=0; i<n; i++) free(mat[i]); 
	free(mat);
return 0;
}
