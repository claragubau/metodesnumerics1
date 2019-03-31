#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*gnuplot: plot "nomfitxer" u 1:2 w l, "nomfitxer" u 1:3 w l*/

double taylor(double, double, int);
double lagrange(double, double, int);

int main(void){
	double x0, x, d, error;
	int i, grau;
	FILE *punts;
	char fitxer1[50], fitxer2[50];
	
	/*procediments obligatoris*/
	printf("x0\n");
	scanf("%lf", &x0);
	d=((x0+0.5)-(x0-0.5))/99;

	/*---------apartat b--------------*/
	printf("nom fitxer sortida\n");
	scanf("%s", fitxer1);
	/*obrim fitxer per guardar valors*/
	punts = fopen(fitxer1, "w");
	if(punts == NULL) { printf("problema amb l'arxiu\n"); exit(1); }

	x = x0-0.5;
	for(i=0; i<100; i++) {
		fprintf(punts, "%23.15le\t%23.15le\t%23.15le\t%23.15le\t%23.15le\n", x, taylor(x, x0, 6), taylor(x,x0,7), taylor(x,x0,8), cos(x));
		x+=d;
	}

	fclose(punts);

	/*---------apartat c-------------*/
	printf("nom fitxer sortida 2\n");
	scanf("%s", fitxer2);
	punts = fopen(fitxer2, "w");
	if(punts==NULL) { printf("problema amb l'arxiu 2\n"); exit(1); }

	/*.................imposo que x0 = pi*9.4...................*/
	x0 = 4*atan(1)*9.4;
	x = x0-1.5;
	d = ((x0+1.5)-(x0-1.5))/99; 
	for(i=0; i<100; i++) {
		fprintf(punts, "%23.15le\t%23.15le\t%23.15le\t\n", x, fabs(cos(x)-taylor(x,x0,8)), fabs(lagrange(x,x0,8)));
		x+=d;
	}

	/*----------------apartat d-------------------*/
	/*.........esta calculant amb x0 = 31.4, també s'hauria d fer amb x0 = 0........*/
	x0 = 31.4;
	x = 9.4*4*atan(1);
	grau = 0;
	do {
		grau++;
		error = fabs(cos(x)-taylor(x,x0,grau));
		/*..........he triat 24 arbitrariament, es el maxim d'iteracions...............*/
	} while(error > 1.e-8 && grau < 24);
	
	if(grau == 24) printf("drama pq no ha arribat\n"); 
	else printf("grau = %d\n", grau);

fclose(punts);

return 0;
}


double taylor(double x, double x0, int n){
	double valorcos, productori=1.;
	int i;
	double vector[4] = { cos(x0), -sin(x0), -cos(x0), sin(x0) };

	valorcos = vector[0];	
	for(i=1; i<=n; i++) {
		productori *= (x-x0)/i;
		valorcos +=vector[i%4]*productori;
	}
	return valorcos;
}

double lagrange(double x, double x0, int n){
	double valorcos, productori = 1.;
	int i;
	double vector[4] = {cos(x0), -sin(x0), -cos(x0), sin(x0)};

	n = n+1;
	for(i=1; i<=n; i++) {
		productori *= (x-x0)/i;
	}
	valorcos = vector[n%4]*productori;

	return valorcos;
}
