#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int i, j;
	double mat[5][6];
	FILE *fsortida;

	fsortida = fopen("matA.txt", "w");

	for(i=1; i<6; i++) 
		for(j=1; j<6; j++) 
			mat[i-1][j-1] = 1./(i+j-1);
	for(i=0; i<5; i++) mat[i][5] = 0;
	mat[1][5] = 1;

	fprintf(fsortida, "5\n");
	for(i=0; i<5; i++) {
		for(j=0; j<6; j++) 
			fprintf(fsortida, "%+le\t", mat[i][j]);
		fprintf(fsortida, "\n");
	}

	fclose(fsortida);

return 0;
}
