#include <stdio.h>
#include <string.h>
#include <math.h>
#define max 4000
int enteros[max],decimales[max],temp[max],numeradores[max],denominadores[max];
int lnumeradores = 1, ldenominadores = 1,ldenominadores2 = 1;
char num[max];
int change(char array[],int *numeros,int origen){
    int i = 0;
    while((i + origen) < strlen(array) && array[i + origen] != '.'){
        if(num[i + origen] < 59){numeros[i + 1] = array[i + origen] - 48;}
		else{numeros[i + 1] = num[i + origen] - 55;}
        i ++;
    }
    i++;
    return i;
}
void clear(int *array){
    int i = 0;
    for(;i < max; i++){array[i] = 0;}
}
int mayor(int a1[],int a2[],int len){
	len--;
	for(;len >= 0;len--){
		if(a1[len] > a2[len]){return 1;}
		if(a1[len] < a2[len]){return 0;}
	}
	return 1;
}
int add(int array[],int len,int *temp){
    int i = 0,number,band = 0;
    for(;i < len;i ++){
    		number = temp[i] + array[i] + band;
        	temp[i] = number%10;
        	band = number/10;
    }
    while(band){
    	temp[len] = band%10;
    	band /= 10;
        len ++;
    }
    return len;
}
int subt(int array[],int len,int *a1){
	int i = 0,cont = 0;
	for(;i < len;i++ ){
		if(array[i] > a1[i]){
			a1[i] +=  10;
			a1[i+1]-= 1;
		}
		a1[i] = a1[i] - array[i];
		if(a1[i] > 0){cont = i;}
	}
	cont ++;
	return cont;
}
int multy(int mult[],int *array,int len_a,int len_mult){
        int i,cont,j,sum,band = 0;
        int res[max];
        clear(res);
        for(i = 0;i < len_mult;i++ ){
        	sum = i;
        	for(j = 0;j < len_a;j++){
        		cont = mult[i]*array[j]+band;
        		res[sum] +=  cont%10;
        		band = cont/10;
        		sum ++;
			}
			while(band > 0){
				res[sum] = band%10;
				band /= 10;
				sum ++;
			}
			
		}
		for(i = 0;i<sum;i ++ ){array[i] = res[i];}
		return sum;
}
int division(int array[],int div,int len){
    char lis[max];
    int k = 0;
    while(len != 0){
        int i,number = 0,cont = 0;
        for(i = len-1;i >= 0; i--){
                number +=  array[i];
                if(number >= div){
                    lis[cont] = number/div;
                    number = (number%div)*10;
                    cont ++;
                }
				else{
                    if(cont){lis[cont] = 0;cont ++;}
                    number *= 10;
                }
        }
        enteros[k] = number/10;
        k ++;
        len = cont;
        cont = 0;
        for(i = len-1;i >= 0;i--){
            array[i] = lis[cont];
            cont ++;
        }
    }
    k--;
    return k;
}

int b_decimal(int base,int times,int arrayp[],int *temp,int arrayD[],int larrayD){
	times--;
    int lis[max],lis2[max],help[max],l1[max];
    int llis2 = 0, n = 1,i,llis = 1;
    clear(lis2);
    lis[0] = 1;
    help[0] = base;
    denominadores[0] = 1;
	clear(l1);
    while(times >= 0 || n < larrayD){
		l1[0] = arrayp[times];
        if(times >= 0 && arrayp[times] != 0){
	        for(i = 0; i < llis; i++ ){lis2[i] = lis[i];}
	        llis2 = multy(l1,lis2,llis,1);
			llis2 = add(lis2,llis2,temp);  
	    }
	    l1[0] = base;
	    llis = multy(l1,lis,llis,1);
		if(n < larrayD){
			if(arrayD[n] != 0){
				for(i = 0; i < llis;i ++ ){denominadores[i] = lis[i];}
				ldenominadores2 = llis;
				lnumeradores = multy(help,numeradores,lnumeradores,ldenominadores);
				int t1[max];
				t1[0] = arrayD[n];
				lnumeradores = add(t1,lnumeradores,numeradores);
				ldenominadores = 1;
				clear(help);
				help[0] = 1;
			}
			n ++;
			ldenominadores = multy(l1,help,ldenominadores,1);
		}
        times--;
    }
    return llis2;
}

void p_decimales(int contar,int numf){
	int cont,i,hcont = 0,lcount2 = 1;
	int array[max],band[max];
	clear(band);
	if (ldenominadores2 > 1 || (ldenominadores2 == 1 && denominadores[0] != 1)){
		contar ++;
		if (contar<1000){printf(".");}
	}
	clear(array);
	for(i = 0;i < ldenominadores2;i ++){array[i] = denominadores[i];}
	int array2[max];
	int arrayl = ldenominadores2;
	clear(array2);
	array2[0] = numf;
	while (contar < 1000 && (lnumeradores > 1 || (lnumeradores == 1 && numeradores[0] != 0))){
		hcont = ldenominadores2;
		cont = 0;
		clear(band);
		lnumeradores = multy(array2,numeradores,lnumeradores,1);	
		while(lnumeradores > ldenominadores2 || (lnumeradores == ldenominadores2 && mayor(numeradores,denominadores,lnumeradores))){
			for(i = 0;i < ldenominadores2;i ++ ){band[i] = denominadores[i];}
			hcont = ldenominadores2;
			ldenominadores2 = add(array,ldenominadores2,denominadores);
			cont ++;
		}
		contar ++;
		if (cont > 0){
			if(hcont <= lnumeradores){lnumeradores = subt(band,lnumeradores,numeradores);}
			ldenominadores2 = arrayl;
			for(i = 0;i < ldenominadores2;i ++ ){denominadores[i] = array[i];}
		}
	
		if(cont >= 10){printf("%c",cont + 55);}
			else{printf("%d",cont);}
	}
	printf("\n");
}
int p_enteros(int enteros[],int lene,int cont){
	int i;
	for(i = lene;i >= 0;i--){
		    if(enteros[i] >= 10){printf("%c",enteros[i]+55);}
			else{printf("%d",enteros[i]);}
		    cont ++;
		    if(cont == 1000){break;}
		}
		if(cont == 0){printf("%d",0);cont ++;}
	return cont;
}
int main(){
	int cases, origen, destino, lene,lend,cont;
	scanf("%d",&cases);
	while(cases--){
		lnumeradores = 1,ldenominadores = 1,ldenominadores2 = 1;
	    clear(temp);clear(enteros);clear(decimales);clear(numeradores);clear(denominadores);
		scanf("%d %s %d",&origen,&num,&destino);
		lene = change(num,enteros,0);
		lend = change(num,decimales,lene);
		lene = b_decimal(origen,lene,enteros,temp,decimales,lend);
		lene = division(temp,destino,lene);
		clear(temp);
		cont = p_enteros(enteros,lene,0);
		p_decimales(cont,destino);
	}
	return 0;
}

