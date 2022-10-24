#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int cuadindex = 2;

int convertToASCII(string letter){
    
	for (int i = 0; i < letter.length(); i++){
	    
		char x = letter.at(i);
		return int(x);
	}
	return 255;
}

int quadratic(string nombre){
    
	int indice = 0;
	string a = "", b = "", c = "";
	a = nombre[0];
	b = nombre[1];
	c = nombre[2];
	indice += convertToASCII(a) + convertToASCII(b) + convertToASCII(c); // Se suma los valores ASCII
	return indice;
}
int quadindex(){
    
	cuadindex = pow(cuadindex,2);
	return cuadindex;
}

void cuadraticHashing(vector<string> &hash, string palabra){
    
	int index = quadindex();
	hash[index] = palabra;
	cout<<index<<endl;
}

void chain(vector<string> &hash, string palabra){
    
	int indice = quadratic(palabra);
	if (hash[indice] != ""){
	    
		int nuevo = indice;
		int i = 1;
		while (hash[nuevo] != ""){
		    
			nuevo = indice + i ^ 2;
		}
	}
	hash[indice] = palabra;
}

bool exist(vector<string> &hash, string palabra){
    
	int indice = quadratic(palabra);
	if (palabra == hash[indice]){
	    
		return true;
	}
	return false;
}

int main(){
    
	vector<string> hashtable(10000); // Para guardar 10000 elementos
	chain(hashtable, "Fernando");
	chain(hashtable, "Patricia");
	cout << exist(hashtable, "Fernando")<<endl;
	vector<string> hashtable2(10000);
	cuadraticHashing(hashtable2,"Hola");
	cout<<hashtable2[cuadindex]<<endl;
	cuadraticHashing(hashtable2,"Buenas");
	cout<<hashtable2[cuadindex]<<endl;
	cuadraticHashing(hashtable2,"Noches");
	cout<<hashtable2[cuadindex]<<endl;

	return 0;
}