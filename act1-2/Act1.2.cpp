#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int global = 0;

vector<int> ordenaIntercambio(vector<int> A){ //Complejidad O(n^2)
    int i, current, j, n = A.size();
    for (i = 1; i < n; i++){
        current = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > current){
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = current;
    }
		return A;
}


vector<int> ordenaBurbuja(vector<int> A){ //Complejidad O(n^2)
    int i, j, n = A.size();
    for(i = 0; i < n ; i++){
        for(j = 0; j < n - i -1 ; j++){
            global ++;
            if(A[j] > A[j + 1]){
                // Chambia A[j + 1] y A[j]
                int tmp_value = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp_value;
            }
        }
    }
    return A;
}


void mergeAlgorithm(vector<int> &A, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = A[l + i];
    }

    for (int j = 0; j < n2; j++){
        R[j] = A[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        A[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}


void ordenaMerge(vector<int> &arr, int l, int r){
    if (l < r){
        int m = (l + r) / 2;

        ordenaMerge(arr, l, m);
        ordenaMerge(arr, m + 1, r);

        mergeAlgorithm(arr, l, m, r);
    }
}

int busqSecuencial(vector<int> A, int req){ //Complejidad de O(n)
    int n = A.size();
    for(int i = 0; i < n ; i++){
				if(req <= A[i]){
						if(A[i] == req){
								int position = i + 1;
								cout << "Valor " << req << " encontrado en la posición  " << position << endl;
								return position;
						}else{
							cout << "Valor no encontrado" << endl;
							return -1;
						}
				}
		}
		return -1;
}


int busqBinaria(vector<int> A, int req){ //Complejidad de O(n)
		int izq = 0, der = sizeof(A) - sizeof(A[0]);
     		while (izq <= der){ 
        int mid = (izq + der)/2; 
        if (A[mid] == req) return mid; 
        if (A[mid] < req){
						izq = mid + 1;
				} else{
						der = mid - 1;
				} 
    }
    return -1; 
}


void printVector(vector<int> A){
    int i, n = A.size(); 
    for (i = 0; i < n; i++) 
        cout << A[i] << " "; 
}


int main(){
    int num_items;
    cout << "Tamaño del vector: ";
    cin >> num_items;
    vector<int> x(num_items, 0);
    // Use srand() for different outputs
    srand(time(0));
  
    // Generate value using generate function
    generate(x.begin(), x.end(), []() {
        return rand() % 100;
    });
    
    cout << "\nVector antes del ordenamiento:" << endl;
		printVector(x);

		cout << endl << "\nVector despues del ordenamiento:" << endl;

		// Bubble Sort
    vector<int> x_bubble = ordenaBurbuja(x);
    cout << "- Bubble sort:" << endl;
		cout << "\t";
    printVector(x_bubble);

		// Insertion Sort
		vector<int> x_insertion = ordenaIntercambio(x);
    cout << endl << "- Insertion sort:" << endl;
		cout << "\t";
    printVector(x_insertion);

		// Merge Sort
		int n = sizeof(x) / sizeof(x[0]); 
		vector<int> x_merge = x;
		ordenaMerge(x_merge, 0, n-1);
		cout << endl << "- Merge sort:" << endl;
		cout << "\t";
		printVector(x_merge);
		cout << endl;

		int requested_value;
		cout << endl << endl << "¿Qué valor quieres buscar?: ";
		cin >> requested_value;
		
		cout << "- Antes de la busqueda (seq): ";
		busqSecuencial(x, requested_value);
		int before_sorting = busqBinaria(x, requested_value); 
    if(before_sorting == -1){
				cout << "- Antes de la busqueda (binario): Valor no encontrado" << endl;
		} else {
				cout << "- Antes de la busqueda (binario): Valor " << requested_value << " encontrado en la posición " << before_sorting << endl;
		}



		cout << "- Bubble Sort (seq): ";
		busqSecuencial(x_bubble, requested_value);
		int bubble = busqBinaria(x_bubble, requested_value); 
    if(bubble == -1){
				cout << "- Bubble Sort (binario): Valor no encontrado" << endl;
		} else {
				cout << "- Bubble Sort (binario): Valor " << requested_value << " encontrado en la posición " << bubble+1 << endl;
		}

		cout << "- Insertion Sort (seq): ";
		busqSecuencial(x_insertion, requested_value);
		int insertion = busqBinaria(x_insertion, requested_value); 
    if(insertion == -1){
				cout << "- Insertion Sort (binario): Valor no encontrado" << endl;
		} else {
				cout << "- Insertion Sort (binario): Valor " << requested_value << " encontrado en la posición " << insertion+1 << endl;
		}

		cout << "- Merge Sort (seq): ";
		busqSecuencial(x_merge, requested_value);
		int mergeS = busqBinaria(x_merge, requested_value); 
    if(mergeS == -1){
				cout << "- Merge Sort (binario): Valor no encontrado";
		} else {
				cout << "- Merge Sort (binario): Valor " << requested_value << " encontrado en la posición " << mergeS+1 << endl;
		}
		

    return 0;
}


