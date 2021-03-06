from time import time 
cont,cont2=0,0
#fail = [15, 24, 35, 48, 63, 80]
def main():
    for i in range (1,32259):
        #if i in fail: x = 25
        x = i 
        #x=float(input())
        b,h,aux,cont=x,1,0,0
        value = 0
        temp = 0
        while aux!=abs(h-b) and temp != 2:
            aux=abs(h-b)
            b=div2(h+b)
            if value == 0 and cont > 100: value = x // b; temp +=1
            elif value == x//b: temp+=1
            #print(value, temp)
            print('test : ',x,b,x//b)
            #input()
            h=div(x,b)
            cont+=1
        print(b,x**(1/2),cont)

def div2(n):
    rta=0
    while n-1>0:
        m=pow2(n)
        n-=m
        rta+=n
        n=m-n
    return rta

def div(x,b):
    cont=0
    while x-b>=0:
        x-=b
        cont+=1
    return cont

def pow2(n):
    aux,m=1,1
    while m-n<0:
        aux=m
        m+=aux
    m=m-aux
    return m
main()
