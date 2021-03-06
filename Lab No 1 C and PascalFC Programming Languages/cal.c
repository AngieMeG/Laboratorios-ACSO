#include<stdio.h>
int op;

int suma(int a, int b){return a+b;}
int resta(int a, int b){return a-b;}
int multiplicacion(int a, int b){return a*b;}
int division(int a, int b){return a/b;}

void menu(){
	op = 6;
	while (op > 5 || op <1) {
		printf("1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n5. Salir\n");
		scanf("%d",&op);
	}
}
int main(){
	printf("5. Calculadora sencilla\n\n");
	int a,b;
	menu();
	while (op != 5){
		printf("Ingrese dos numeros: ");
		scanf("%d %d",&a,&b);
		if (op == 1){printf("Respuesta = %d\n",suma(a,b));}
		else if (op == 2){printf("Respuesta = %d\n",resta(a,b));}
		else if (op == 3){printf("Respuesta = %d\n",multiplicacion(a,b));}
		else if (op == 4){printf("Respuesta = %d\n",division(a,b));}
		else if (op == 5){break;}
		menu();
	}
	return 0;
}
