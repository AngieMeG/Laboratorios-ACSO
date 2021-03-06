#include<stdio.h>
int main(){
	printf("3. Minimo de un vector de reales.\nLongitud del vector:\n");
	int n,i = 0;
	float m;
	scanf("%d",&n);
	float vec[n];
	printf("Contenido del vector:\n");
	while(n){
		scanf("%f",&vec[i]);
		if (i == 0 || vec[i] < m){m = vec[i];}
		i++;n--;
	}
	printf("Respuesta = %.2f\n",m);
	return 0;
}
