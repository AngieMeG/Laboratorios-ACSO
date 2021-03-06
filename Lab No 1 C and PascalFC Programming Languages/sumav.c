#include<stdio.h>
int main(){
	printf("4. Suma de un vector de enteros\nLongitud del vector:\n");
	int n,i = 0,res = 0;
	scanf("%d",&n);
	int vec[n];
	printf("Contenido del vector:\n");
	while(i < n){scanf("%d",&vec[i]);res+= vec[i];i++;}
	i = 0;
	printf("\n");
	while(i < n){
		printf("%d",vec[i]);
		if(i!= n-1){printf("+");}
		i++;
	}
	printf(" = %d\n",res);
	return 0;
}
