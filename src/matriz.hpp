#ifndef MATRIZ_HPP 
#define __MATRIZ_HPP 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std; 

int tamanho_matriz();
int quantidade(int tamanho);

void ler_andar_matriz(int** matriz, int tamanho);    
int verificar_matriz(int** matriz, int tamanho, int linha, int coluna, int quant);

short int valor_maior_geral(int** matriz, int i, int j);
short int valor_maior_cantos(int** matriz, int i, int j, int aux);

int direita(int** matriz, int i, int j);
int esquerda(int** matriz, int i, int j);
int diagonal_direita(int** matriz, int i, int j);
int diagonal_esquerda(int** matriz, int i, int j);
int abaixo(int** matriz, int i, int j);

#endif