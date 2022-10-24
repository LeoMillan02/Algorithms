//Leonardo Miilán Velázquez-A01639823
#include <bits/stdc++.h>
#include <fstream> 
#include <string> 
#include <cmath> 
#include <vector>
using namespace std;

template <class T>class priorityQueue{
    public:
        vector<pair<T, int>> arrHeap;
        int key;

        priorityQueue(){

        }

        priorityQueue(T data, int key){
          arrHeap[0] = make_pair(data, key);
          
        }
        
        int top(vector<int> &heapTree){ //Complejidad O(1)
  	        if(!empty(heapTree)){
    	        return heapTree[0];
            } else {
            return -1;
            }
        }


        bool empty(vector<int> &heapTree) { //Complejidad O(1)
	    return !(heapTree.size() > 0);
        }
        
        int padre(int i){
          return (i-1)/2;
        }
        
        int hijo_izq(int i){
          return (2*i) + 1;
        }
        
        int hijo_der(int i){
          return (2*i) + 2;
        }
        int size(){ //Complejidad O(1)

          return arrHeap.size()-1;
        }
        void push(T data,int key){ //Complejidad O(1)
          arrHeap.push_back(make_pair(data,key));
          int pos = arrHeap.size()-1;
          while(pos!=0 && arrHeap[pos].second > padre(pos)){
            swap(arrHeap[pos], arrHeap[padre(pos)]);
            pos = padre(pos);
          }
        }

        void printArr(){
          for (int i = 0; i < arrHeap.size(); i++){
            cout<<arrHeap[i].first<<endl;
          }
        }
        
        int maximum(int index){
          int nuevaPosPadre;
          int nuevoPadre = max(arrHeap[hijo_izq(index)].second,arrHeap[hijo_der(index)].second);
          if(nuevoPadre == arrHeap[hijo_izq(index)].second) nuevaPosPadre = hijo_izq(index);
          if(nuevoPadre == arrHeap[hijo_der(index)].second) nuevaPosPadre = hijo_izq(index);
          return nuevaPosPadre;
        }

        void pop(int index){ //Complejidad O(log n)
          int size = arrHeap.size()-1;
          if(hijo_izq(index)>size && hijo_der(index)>size){
            arrHeap.pop_back();
            return;
          }
          
          swap(arrHeap[index], arrHeap[maximum(index)]);
          pop(maximum(index));
        }
      
};

int main(){
    priorityQueue<int> Test;
    Test.push(1,1);
    Test.push(2,2);
    Test.push(3,3);
    Test.push(4,4);

    Test.printArr();

    Test.pop(0);
    Test.size();



    Test.printArr();

}



