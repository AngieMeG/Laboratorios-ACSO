#include <stdio.h>
#include <string.h>
#include <math.h>
char pasar[4000];
int parteEntera[4000];
int parteDecimal[4000];
int rta1[4000],lnumerador=1,ldenominador=1,ldenominador2=1;
int numerador[4000],denominador[4000];
int volverCero(int *lis){
    int ciclo=0;
    for(ciclo;ciclo<4000;ciclo++){
        lis[ciclo]=0;
    }
    return 0;
}

int division(int lis[],int dividir,int longitud){
    char lista[4000];
    int c=0;
    while(longitud!=0){
        int numero=0,ciclo,contar=0;
        for(ciclo=longitud-1;ciclo>=0;ciclo--){
                numero+=lis[ciclo];
                if(numero>=dividir){
                    lista[contar]=numero/dividir;
                    numero=(numero%dividir)*10;
                    contar+=1;
                }else{
                    if(contar!=0){
                        lista[contar]=0;
                        contar+=1;
                    }
                    numero*=10;
                }
        }
        parteEntera[c]=numero/10;
        c++;
        longitud=contar;
        contar=0;
        for(ciclo=longitud-1;ciclo>=0;ciclo--){
            lis[ciclo]=lista[contar];
            contar+=1;
        }
    }
    return c-1;
}
int multiplicacion(int multiplicar[],int *lista,int llista,int lmultiplicar){
        int ciclo,grda,controlador,ciclo2,suma,respuesta[4000];
        volverCero(respuesta);
        grda=0;
        for(ciclo=0;ciclo<lmultiplicar;ciclo++){
        	suma=ciclo;
        	
        	for(ciclo2=0;ciclo2<llista;ciclo2++){
        		controlador=multiplicar[ciclo]*lista[ciclo2]+grda;
        		respuesta[suma]+=controlador%10;
        		grda=controlador/10;
        		suma+=1;
			}
			while(grda>0){
				respuesta[suma]=grda%10;
				grda/=10;
				suma+=1;
			}
			
		}
		for(ciclo=0;ciclo<suma;ciclo++){
			lista[ciclo]=respuesta[ciclo];
		}
		return suma;
}
int sumar(int lis[],int longitud,int *rta1){
    int ciclo=0,numero,grda=0;
    for(ciclo;ciclo<longitud;ciclo++){
 
    		numero=rta1[ciclo]+lis[ciclo]+grda;
        	rta1[ciclo]=numero%10;
        	grda=numero/10;
		
        
    }
    while(grda!=0){
    	rta1[longitud]=grda%10;
    	grda=grda/10;
        longitud+=1;

    }
    return longitud;
}

int potencia(int expon,int veces,int lisp[],int *rta1,int lisD[],int llisD){
    int n=veces-1,lista[4000],lista2[4000],llista2=0,otroDenominador[4000],n1=1;
    volverCero(lista2);
    int llista=1;
    int ciclo;
    lista[0]=1;
    otroDenominador[0]=expon;
    denominador[0]=1;
    int l1[4000]; 
	volverCero(l1);
    while(n>=0 || n1<llisD){
		l1[0]=lisp[n];
        if(n>=0 && lisp[n]!=0){
	        for(ciclo=0;ciclo<llista;ciclo++){
	            lista2[ciclo]=lista[ciclo];
	        }
	        llista2=multiplicacion(l1,lista2,llista,1);
			llista2=sumar(lista2,llista2,rta1);  
	    }
	    l1[0]=expon;
	    llista=multiplicacion(l1,lista,llista,1);
		if(n1<llisD){
			
	    	
			if(lisD[n1]!=0){
				for(ciclo=0;ciclo<llista;ciclo++){
	        		denominador[ciclo]=lista[ciclo];
				}
				ldenominador2=llista;
				lnumerador=multiplicacion(otroDenominador,numerador,lnumerador,ldenominador);
				int p[4000];
				p[0]=lisD[n1];
				lnumerador=sumar(p,lnumerador,numerador);
				ldenominador=1;
				volverCero(otroDenominador);
				otroDenominador[0]=1;
			}n1++;
			ldenominador=multiplicacion(l1,otroDenominador,ldenominador,1);
		}
        n--;
    }
    
    return llista2;
}
int separar(char pasar[],int *numeros,int comienzo){
    int ciclo=0;
    while((ciclo+comienzo)<strlen(pasar) && pasar[ciclo+comienzo]!='.'){
        if(pasar[ciclo+comienzo]<59){
            numeros[ciclo+1]=pasar[ciclo+comienzo]-48;
        }else{
            numeros[ciclo+1]=pasar[ciclo+comienzo]-55;
        }
        ciclo++;
    }
    return ciclo+1;
}
int mayor(int l[],int l1[],int longitud){
	int ciclo=0;

	for(ciclo=longitud-1;ciclo>=0;ciclo--){
		if(l[ciclo]>l1[ciclo]){
			return 1;
		}if(l[ciclo]<l1[ciclo]){
			return 0;
		}
	}
	return 1;
}
int sonIguales(int l[],int l1[],int longitud){
	int ciclo=0;
	for(ciclo;ciclo<longitud;ciclo++){
		if(l[ciclo] != l1[ciclo]){
			return 1;
		}
	}
	return 0;
}
int resta(int l[],int longitud,int *l1){
	int ciclo=0,n=0,cuenta=0;
	for(ciclo;ciclo<longitud;ciclo++){
		if(l[ciclo]>l1[ciclo]){
			l1[ciclo]+=10;
			l1[ciclo+1]-=1;
		}l1[ciclo]=l1[ciclo]-l[ciclo];
		if(l1[ciclo]>0){
			cuenta=ciclo;
		}
	}cuenta++;
	return cuenta;
}
imprimirDecimales(int contar,int numero){
	int count,count2[4000],lis[4000],grda[4000],ciclo,grda2=0,lcount2=1;
//	for(ciclo=0;ciclo<lnumerador;ciclo++){
//		printf("%i",numerador[ciclo]);
//	}printf("\n");
//	for(ciclo=0;ciclo<ldenominador2;ciclo++){
//		printf("%i",denominador[ciclo]);
//	}printf("----------------------\n");
	volverCero(grda);
	if (ldenominador2>1 || (ldenominador2==1 && denominador[0]!=1)){
		contar+=1;
		if (contar<1000){
			printf(".");
		}

		
	}
	volverCero(lis);
	for(ciclo=0;ciclo<ldenominador2;ciclo++){
			lis[ciclo]=denominador[ciclo];
		}
	int	lisl=ldenominador2;
	int lis2[4000];
	volverCero(lis2);
	lis2[0]=numero;
	
	while (contar<1000 && (lnumerador>1 || (lnumerador==1 && numerador[0]!=0))){
		grda2=ldenominador2;
		count=0;lcount2=1;
		count2[0]=0;
		volverCero(grda);
		lnumerador=multiplicacion(lis2,numerador,lnumerador,1);	
//		for(ciclo=0;ciclo<lnumerador;ciclo++){
//			printf("%i",numerador[ciclo]);
//		}printf("\n-------------------------------------------------------------------");		
		while(lnumerador>ldenominador2 || (lnumerador==ldenominador2 && mayor(numerador,denominador,lnumerador))){
			for(ciclo=0;ciclo<ldenominador2;ciclo++){
				grda[ciclo]=denominador[ciclo];
			}
			grda2=ldenominador2;
			ldenominador2=sumar(lis,ldenominador2,denominador);
			//for(ciclo=0;ciclo<lnumerador;ciclo++){
			//		printf("%i",numerador[ciclo]);
			//}printf("\n");
		//	for(ciclo=0;ciclo<ldenominador2;ciclo++){
		//			printf("%i",denominador[ciclo]);
		//	}printf("     ");
			count+=1;
		//	printf("%i %i  \n",lnumerador,ldenominador2);		
		}
	//	printf("%i ------------------------------------------------------------\n",count );
	//	for(ciclo=0;ciclo<lnumerador;ciclo++){
			//printf("aaaaaaaaaaa %i",numerador[ciclo]);
	//	}//printf("\n");
		contar+=1;
		if (count>0){
			int lis3[4000];lis3[0]=1;
			if(grda2<=lnumerador){
				lnumerador=resta(grda,lnumerador,numerador);
				}
			//for(ciclo=0;ciclo<lnumerador;ciclo++){
				//	printf("%i",numerador[ciclo]);
				//}printf("...........\n");
			//for(ciclo=0;ciclo<lcount2;ciclo++){
				//	printf("%i",count2[ciclo]);
			//	}//printf("\n");
			ldenominador2=lisl;
			for(ciclo=0;ciclo<ldenominador2;ciclo++){
				denominador[ciclo]=lis[ciclo];
			}

		}
	//	printf("%i %i\n---------------------------------------------------------------------------------------------------------------------------",count2,count);
		if(count>=10){
		        printf("%c",count+55);
		    }else{
		        printf("%i",count);
		    }
		    
		
	}printf("\n");
}
int main(){
    int n1,n2,casos,longLista,punto,longEntera,longDecimal,longDecimal2,ciclo,contar;
	scanf("%d",&casos);
	int h =casos;
	for(casos;casos>0;casos--){

		lnumerador=1,ldenominador=1,ldenominador2=1;
		
	    volverCero(rta1);
	    volverCero(parteEntera);
	    volverCero(parteDecimal);
		volverCero(numerador);
		volverCero(denominador);
		scanf("%d",&n1);
		scanf("%s",pasar);
		scanf("%d",&n2);
		longEntera=separar(pasar,parteEntera,0);
		longDecimal=separar(pasar,parteDecimal,longEntera);

		longEntera=potencia(n1,longEntera,parteEntera,rta1,parteDecimal,longDecimal);
		/*for(ciclo=0;ciclo<=longEntera;ciclo++){
			printf("%i ",parteEntera[ciclo]);
		}printf("\n");*/
		longEntera=division(rta1,n2,longEntera);
		/*for(ciclo=0;ciclo<=longEntera;ciclo++){
			printf("%i ",parteEntera[ciclo]);
		}printf("\n");*/
		volverCero(rta1);
		contar=0;
		
		for(ciclo=longEntera;ciclo>=0;ciclo--){
			
		    if(parteEntera[ciclo]>=10){
		       printf("%c",parteEntera[ciclo]+55);
		    }else{
		        printf("%i",parteEntera[ciclo]);
		    }
		    contar+=1;
		    if(contar==1000){
		    	break;
			}
		}if(contar==0){
			contar+=1;
			printf("%i",0);
		}
		imprimirDecimales(contar,n2);
	}
	return 0;
}


//1111111111111111111111111111010100101010100000000000001010101010101111111111111111111111111001010101010010101010101.1111111111111
//ZZZZZZZZZZZZZZZZZZZZZZZZZ

