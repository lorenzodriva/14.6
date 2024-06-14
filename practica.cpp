#include <iostream>
#include <vector>

using namespace std;

// Funcion para intercambiar
void cambio(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

// Funcion para encontrar el pivote
int particion(vector<int>arr, int primerElemento, int ultimoElemento){
    int pivote = arr[ultimoElemento];
    int i = (primerElemento - 1);
    for (int j = primerElemento; j<= ultimoElemento - 1; j++){
        if(arr[j] < pivote){
            i++;
            cambio(arr[i], arr[j]);
        }
    }
    cambio(arr[i+1], arr[ultimoElemento]);
    return (i+1);
}

// Funcion del quicksort
void quicksort(vector<int>arr, int primerElemento, int ultimoElemento){
    if(primerElemento < ultimoElemento){
        int pivotDelSort = particion(arr, primerElemento, ultimoElemento);
        quicksort(arr, primerElemento, pivotDelSort-1);
        quicksort(arr, pivotDelSort+1, ultimoElemento);
    }
}

void mostrarArray(vector<int>arr){
    for(int i = 0; arr.size(); i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    vector<int>arr = {0, 2, 6, 4, 10, 8};
    mostrarArray(arr);
    int primerElemento = arr[0];
    int ultimoElemento = arr[5];
    quicksort(arr, primerElemento, ultimoElemento);
    cout << endl<< endl;
    mostrarArray(arr);
    return 0;
}
