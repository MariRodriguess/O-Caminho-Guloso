#ifndef MATRIZ_HPP 
#define __MATRIZ_HPP 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std; 

int tamanho_matriz();
void limpar_matriz(int** matriz, int tamanho);
int quantidade(int** matriz, int tamanho);

void ler_andar_matriz(int** matriz, int tamanho);    
int verificar_matriz(int** matriz, int tamanho, int linha, int coluna, int quant);

int direita(int** matriz, int i, int j, int tamanho);
int esquerda(int** matriz, int i, int j, int tamanho);
int diagonal_direita(int** matriz, int i, int j, int tamanho);
int diagonal_esquerda(int** matriz, int i, int j, int tamanho);
int abaixo(int** matriz, int i, int j, int tamanho);

short int valor_maior_geral(int** matriz, int soma, int i, int j, int tamanho);
short int valor_maior_canto_1(int** matriz, int soma, int i, int j, int tamanho);
short int valor_maior_canto_2(int** matriz, int soma, int i, int j, int tamanho);

#endif