#include <stdio.h>
#include <string.h>
#include <math.h>
float conv(char num[],int bias,int exponent){
	int i = 1,exponente = 0,len = exponent - 1;
	int mantisa = strlen(num) - exponent - 1;
	while (exponent--){
		exponente += (num[i]-48)*pow(2,len--);
	}
	exponente -= bias;
	if (exponente < 0){char fin[mantisa + 3 + exponente];}
	else if (mantisa + 1 < exponente){char fin[exponente];}
	else { char fin[mantisa + 2]
	}
	}
	printf("%d\n",exponente);
	return 0.1;
}

int main(){
	int precision, bias, exponent,fixed,agregar,cases;
	float res;
	scanf("%d %d %d %d %d",&precision,&bias,&exponent,&fixed,&cases);
	char entrada[1001],segundo[1001];
	while (cases--){
		scanf("%s",&entrada);
		int len = strlen(entrada);
		if (len < precision){
			agregar = precision - len;
			int i = 0;
			while (agregar--){
				segundo[i] = '0';
				i++;
			}
			int j = 0;
			while(len--){
				segundo[i] = entrada[j];
				j++;i++;
			}
			res = conv(segundo,bias,exponent);
		}
		else {res = conv(entrada,bias,exponent);}
		//int len = strlen(entrada);
		//printf("%d\n",len);
	}
	return 0;
}
