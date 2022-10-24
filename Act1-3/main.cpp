//Este es un programa que acomoda y busca los datos de una
//bitacora
//Leonardo Millán Velázquez-A01639823
//Alexa Serrano
//Luis Manuel Orozco Yáñez - A01707822


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

void fillVector(vector<string> &Bitacora, string fileName);
void sortingValue(double segundosInicio, double segundosFinal);
void printVector();
void transformacion();
void bubbleSort();
int partition(vector<string> &Bitacora, int Inicio, int Fin);
void swap(vector<string> &Bitacora, int i, int j);
int global = 0;
// vectores de bitácora en string y nuevo vector
vector<double> BitRell;
vector<string> Bitacora;
vector<double> BitacoraInt;

double TOTAL;
int main(){

	fillVector(Bitacora, "bitacora.txt");
	cout << "Tamano de la Bitácora: " << Bitacora.size() << endl;

	int inicioM, inicioD, finalM, finalD; 
  
  cout << "Ingresa el mes de inicio de búsqueda: \t";
	cin >> inicioM;
  if(inicioM <= 12){
	  cout << "Ingresa el día de inicio de búsqueda: \t";
	  cin >> inicioD;
    if(inicioD <=30){
      	cout << "Ingresa el mes de fin de búsqueda: \t";
        cin >> finalM;
        if(finalM >= inicioM && finalM <= 12){
          	cout << "Ingresa el día de fin de búsqueda: \t";
	          cin >> finalD;
            if(finalD < inicioD && finalD > 30){
              cout<<"Inserte un dia valido";
            } 
        } 
        else{
          cout<<"Inserte un mes valido";
        }
    }
    else{
      cout<<"Inserte un dia valido";
    }
  }
  else{
    cout<<"Inserte un mes valido";
  }



	
	// PARA SACAR LOS SORTEADOS, CONVERTIR EL RANGO A SEGUNDOS Y EVALUAR EN FUNCIÓN DE LO QUE SE HIZO ABAJO.
	int segundosInicio , segundosFinal ;
	segundosInicio = (inicioM * 2592000) + (inicioD *108000);
	segundosFinal = (finalM * 2592000) + (finalD *108000);
	
  cout << "\nSORTEADO:" << endl;

  
	


	transformacion();
	bubbleSort();


	sortingValue(segundosInicio, segundosFinal);
  

} // cierra main

// DECLARACIÓN DE FUNCIONES
void fillVector(vector<string> &Bitacora, string fileName){
  string B;
  ifstream in(fileName);
  while (getline(in, B)){
    Bitacora.push_back(B+'\n');
  }
}

/* Función que devuelve un valor con el cual se pueda comparar la diferencia de tiempo entre dos entradas. Con este valor devuelto se lleva a cabo un sorting.
Parámetros: 
    1. vector<string> &Bitacora: referencia al vector que contiene las entradas.
    2. int Index: indice de entradas a calcular su valor de sorteo.
Valores de retorno: 
    TOTAL: valor que se utilizará para sortear los vectores.
Mientras mayor sea el valor, más tarde se hizo la entrada con respecto al tiempo.*/
void transformacion(){
	
	for(int i = 0; i < 16807; i++){
		string Entry = Bitacora[i];
		
		map<string, int> MonthToNum = { {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
			{"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10},
			{"Nov", 11}, {"Dec", 12}};
		double Mes = MonthToNum.at(Entry.substr(0, 3));
		double Dia = stoi(Entry.substr(4, 6));
		double Horas, Minutos, Segundos;
		/* Primero, se revisa si el número del día tiene 1 o 2 dígitos. Dependiendo de la 
		condición, el substring cambia debido al desplazo de carácteres a la derecha.*/
		if(Dia <= 9){
				Horas = stoi(Entry.substr(6, 8));
				Minutos = stoi(Entry.substr(9, 11));
				Segundos = stoi(Entry.substr(12, 14));
		}
		else{
				Horas = stoi(Entry.substr(7, 9));
				Minutos = stoi(Entry.substr(10, 12));
				Segundos = stoi(Entry.substr(13, 15));
		}

		Minutos = Minutos *60;
		Horas = Horas *3600;
		Dia = Dia *108000;
		Mes = Mes * 2592000;
		TOTAL = Mes + Dia + Horas + Minutos + Segundos; 
		BitacoraInt.push_back(TOTAL);
	}
}

void sortingValue(double segundosInicio, double segundosFinal)
{
	int i;
	for(i = 0; i < 16807; i++)
	{
		if(segundosInicio < BitacoraInt[i])
		{
			break;
		}
	}
	for(int j = i; j < 16807; j++)
	{
		if(segundosFinal > BitacoraInt[j])
		cout<<Bitacora[j]<<'\n';
		else break;

	}
}
//Función que recibe strings y cambia de lugar 2 elementos de un vector o arreglo.
void swap(vector<string> &Bitacora, int i, int j){
	string aux;
	aux = Bitacora[i];
	Bitacora[i] = Bitacora[j];
	Bitacora[j] = aux;
}


void bubbleSort(){
  int n = 16807;
  for(int i = 0; i < n - 1 ; i++){
    for(int j = 0; j < n-i-1; j++){
      if (BitacoraInt[j]>BitacoraInt[j+1]){
        swap(Bitacora[j],  Bitacora[j+1]);

				swap(BitacoraInt[j],  BitacoraInt[j+1]);

      }
    }
  }
}

void printVector(){

	for (int i = 0; i < 16807; i++){
		cout << Bitacora[i];
    
	}
	cout << endl;
}