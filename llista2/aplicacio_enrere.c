#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void subs_enrere(int, double**);

/*lo unic q s'ha de fer es posar una matriu amb una c qualsevol i el vector es el (0....01) de dimensio n*/
int main(void) {
	int i, j, n;
	double c;
	double **mat;
	FILE *resultat;
	char nomfitxer[50];

	printf("valor de c\n");
	scanf("%le", &c);
	printf("nom fitxer sortida\n");
	scanf("%s", nomfitxer);

	resultat = fopen(nomfitxer, "w");
	if(resultat == NULL) {
		printf("problema amb el fitxer\n");
		exit(1);
	}
	
	for(n=50; n<=1600; n=n*2) {
		mat = (double**)calloc(n,sizeof(double*));
		if(mat == NULL) { printf("drama matriu\n"); exit(1); }
		for(i=0; i<n; i++) {
			mat[i] = (double*)calloc((n+1),sizeof(double));
			if(mat[i] == NULL) { printf("drama matriu\n"); exit(1); }

		}

		for(i=0; i<n; i++) {
			mat[i][i] = 1.;
			for(j=i+1; j<n; j++) 
				mat[i][j]=c;
		}
		mat[n-1][n]=1;

		subs_enrere(n, mat);

		fprintf(resultat, "n = %d\n\n", n);
		for(i=0; i<n; i++){
			fprintf(resultat, "%le\t", mat[i][n]);
			}
		fprintf(resultat, "\n\n\n");
	for(i=0; i<n; i++) free(mat[i]); 
	free(mat);
	}
	fclose(resultat);
return 0;
}
