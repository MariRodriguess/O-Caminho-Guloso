#include "matriz.hpp"
 
using namespace std;

int main(){

    int** matriz;
    int tamanho=0;

    tamanho = tamanho_matriz();

    matriz = (int**)malloc (tamanho * sizeof (int*)) ;
    for (int i=0; i < tamanho; i++){
        matriz[i] = (int*)malloc (tamanho * sizeof (int)) ;
    }

    ler_andar_matriz(matriz, tamanho);

    return 0;
}