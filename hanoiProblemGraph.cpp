#include <iostream>

using namespace std;

int total = 0;
void toh(int n, char from, char to, char aux){
        if(n==1){

                cout<<"\nMOVE DISK "<<n<<" FROM TOWER "<<from<<" TO TOWER "<<aux;
                total += 1;
                cout<<"\nMOVE DISK "<<n<<" FROM TOWER "<<aux<<" TO TOWER "<<to;
                total += 1;
        }
        else{
                toh(n-1,from,aux,to);
                cout<<"\nMOVE DISK "<<n<<" FROM TOWER "<<from<<" TO TOWER "<<aux;
                total += 1;
                toh(n-1,aux,to,from);
                cout<<"\nMOVE DISK "<<n<<" FROM TOWER "<<aux<<" TO TOWER "<<to;
                total += 1;
                toh(n-1,aux,to,from);
            
                
        } 
}

int main()
{
        int n;
 
        cout<<"NUMBER OF DISKS: ";
        cin >>n;
        toh(n,'A','C','B');
        cout<<endl;
        cout<<"Numero de movimientos: "<<total;
        return 0;
}