#include <iostream>
using namespace std;

int contFrec(int X[], int l, int r, int mayor){
    int contador = 0;
    for(int i = l; i <= r; i= i+1){
        if(X[i] == mayor){
            contador = contador + 1;
        }
    }
    return contador;
}

int getMayor(int X[], int l, int r){
    if(l == r){
        return X[l];
    }

    int medio = l + (r - l)/2;
    int mayoriaIzq = getMayor(X, l, medio);
    int mayoriaDer = getMayor(X, medio + 1, r);

    if (mayoriaIzq == mayoriaDer){
        return mayoriaIzq;
    }
    int contIzq = contFrec(X, l, r, mayoriaIzq);
    int contDec = contFrec(X, l, r, mayoriaDer);
    if(contIzq > contDec){
        return mayoriaIzq;
    }
    else{
        return mayoriaDer;
    }
}

int getElementoMayor(int X[], int n){
    return getMayor(X, 0, n-1);
}
int main(){
    int n = 10;
    int lista[n] = {1,3,4,5,2,3,4,8,9,0};
    cout<<getElementoMayor(lista, n);
}

//Complejidad de O(log n)
//Complejidad fuerza bruta de O(n^2)