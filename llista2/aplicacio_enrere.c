#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void subs_enrere(int, double**);

/*lo unic q s'ha de fer es posar una matriu amb una c qualsevol i el vector es el (0....01) de dimensio n*/
int main(void) {



	mat = (double**)calloc(n,sizeof(double*));
	if(mat == NULL) { printf("drama matriu\n"); exit(1); }
	for(i=0; i<n; i++) {
		mat[i] = (double*)calloc((n+1),sizeof(double));
		if(mat[i] == NULL) { printf("drama matriu\n"); exit(1); }

	}

	
