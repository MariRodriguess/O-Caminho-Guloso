#include "matriz.hpp"

using namespace std;

int tamanho_matriz(){
    ifstream arquivoE;
    string linha, aux_tamanho;
    int tamanho=0;
    short int linha_arq=0;

    arquivoE.open("dataset/input.data", ios::in);

    if (arquivoE.is_open()){
        while(getline(arquivoE, linha)){
            if (linha_arq==0){
                linha_arq=1;
                for (int i=0; i<=(int)linha.size(); i++){
                    if ((linha[i] != '\0')){
                        if (linha[i] != ' '){  
                            aux_tamanho += linha[i];
                        }else{
                            tamanho =  atoi(aux_tamanho.c_str());
                            aux_tamanho.clear();
                        }
                    }else{
                        break;
                    }
                }
            }else{
                break;
            }
        } 
        arquivoE.close();   
    }else{
        cout << "\nNao foi possível abrir o arquivo.\n";
    }
    return tamanho;
}

int quantidade(int tamanho){

    ifstream arquivoE;
    string linha;
    int quantidade=0, linha_arq=0;
    arquivoE.open("dataset/input.data", ios::in);

    if (arquivoE.is_open()){
        while(getline(arquivoE, linha)){
            if (linha_arq!=0){
                for(int i=0; i<=(int)linha.size(); i++){
                    if (linha[i] == ' '){
                        quantidade++;   
                    }
                }
            }
            linha_arq=1;
        } 
        quantidade = (quantidade/(tamanho*tamanho));
        arquivoE.close();
    }    
    else{
        cout << "\nNao foi possível abrir o arquivo.\n";
    }
    return quantidade;
}

void ler_andar_matriz(int** matriz, int tamanho){
    
    string linha, aux_elemento;
    int elemento=0, lin=0, col=0, inicio_matriz=1, fim_matriz=tamanho, j=0, k=0, cont_linha_matriz=0;
    int aux_soma=0, soma_total=0, linha_arq=0, aux_quant=0, aux=0;
    int quant = quantidade(tamanho);
    
    ifstream arquivoE;
    arquivoE.open("dataset/input.data", ios::in);
    
    if (arquivoE.is_open()){
        cout << "\nExistem " << quant << " matrizes de tamanho " << tamanho << "x" << tamanho << " no arquivo.";
        while(getline(arquivoE, linha)){
            if (linha_arq!=0){  
                if ((linha_arq == fim_matriz+1) && (aux_quant<quant)){
                    inicio_matriz = fim_matriz+2;
                    fim_matriz = inicio_matriz+(tamanho-1);
                }
                if ((linha_arq>=inicio_matriz) && (linha_arq<=fim_matriz)){

                    for (int i=0; i<=(int)linha.size(); i++){
                        if ((linha[i] != '\0') && (linha[i] != '\n')){
                            if (linha[i] != ' '){  
                                aux_elemento += linha[i];
                            }else{
                                elemento =  atoi(aux_elemento.c_str());
                                matriz[j][k] = elemento;
                                k++;

                                if (k == tamanho){
                                    j++;
                                    k=0;
                                    cont_linha_matriz++;
                                }
                                if (cont_linha_matriz == tamanho){
                                    j=0;
                                    k=0;  
                                    cont_linha_matriz=0;
                                }  
                                aux_elemento.clear();      
                            }
                        }else{
                            break;
                        }
                    }
                }
            }
            if (linha_arq==fim_matriz){
                aux_quant++;
                if (aux_quant == 1){
                    do{
                        if (aux==1){
                            cout << "\nTamanho inválido. Permitido de 1 até " << tamanho << ". Tente novamente.";
                        }
                        cout << "\n\nPor qual ponto das matrizes voce deseja começar a percorrer? (de 1 até " << tamanho << ")\n\nLinha: ";
                        cin >> lin;
                        cout << "\nColuna: ";
                        cin >> col;
                        aux=1;
                    }while((lin>tamanho) || (lin<=0) || (col>tamanho) || (col<=0));
                }        
                cout << "\n\t----- MATRIZ NÚMERO " << aux_quant << " -----\t\n";
                for (int i=0; i<tamanho; i++){
                    for (int j=0; j<tamanho; j++){
                        cout << matriz[i][j] << " ";
                    }   
                    cout << endl;
                }
                cout << "\nCaminho percorrido marcado com '-1' : \n";
                aux_soma = verificar_matriz(matriz, tamanho, lin-1, col-1, aux_quant);
                soma_total+=aux_soma;
                cout << endl;
            }
            linha_arq++; 
        }
        cout << "\nSoma total do caminho percorrido em todas as matrizes: " << soma_total << "\n\n";
    }else{
        cout << "\nNao foi possível abrir o arquivo.\n";
    }
}

int verificar_matriz(int** matriz, int tamanho, int linha, int coluna, int quant){
    int soma=0, aux_soma=0;
    short int andei=0;
    soma += matriz[linha][coluna];
    matriz[linha][coluna] = -1;

    for (int i=linha; i<tamanho; i++){
        for (int j=coluna; j<tamanho; j++){

            if ((j!=0) && (i!=tamanho-1) && (j!=tamanho-1)){
                andei = valor_maior_geral(matriz, i, j);
            }
            else if ((j==0) && (i!=tamanho-1)){
                andei = valor_maior_cantos(matriz, i, j, 10);
            }
            else if ((j==tamanho-1) && (i!=tamanho-1)){
                andei = valor_maior_cantos(matriz, i, j, 01);
            }
            else if ((j!=tamanho-1) && (i==tamanho-1)){
                andei = 1;
            }
 
            if(andei==1){
                aux_soma = direita(matriz, i, j);
                soma+=aux_soma;
            }else if(andei==2){
                aux_soma = diagonal_direita(matriz, i, j);
                i+=1;
                soma+=aux_soma;
            }else if(andei==3){
                aux_soma = abaixo(matriz, i, j);
                i+=1;
                j-=1;
                soma+=aux_soma;
            }else if (andei==4){
                aux_soma = diagonal_esquerda(matriz, i, j);
                i+=1;
                j-=2;
                soma+=aux_soma;
            }else if (andei==5){
                aux_soma = esquerda(matriz, i, j);
                j-=2;
                soma+=aux_soma;
            }
            aux_soma=0;
            andei=0;
        }
    }

    for (int i=0; i<tamanho; i++){
        for (int j=0; j<tamanho; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    } 
    cout << "\nSoma da matriz número " << quant << " = " << soma;    
    cout << "\n-----------------\n";   
    return soma;
}

short int valor_maior_geral(int** matriz, int i, int j){
    short int andei=0;
    int di = matriz[i][j+1];
    int es = matriz[i][j-1];
    int d_d = matriz[i+1][j+1];
    int d_e = matriz[i+1][j-1];
    int b = matriz[i+1][j];

    if ((es!=-1) && (es>=di) && (es>=d_d) && (es>=d_e) && (es>=b)){
        andei=5;
    }
    else if ((di!=-1) && (di>es) && (di>=d_d) && (di>=d_e) && (di>=b)){
        andei=1;
    }
    else if ((d_e!=-1) && (d_e>di) && (d_e>es) && (d_e>=d_d) && (d_e>=b)){
        andei=4;
    }
    else if ((b!=-1) && (b>di) && (b>es) && (b>=d_d) && (b>d_e)){
        andei=3;
    }
    else if ((d_d!=-1) && (d_d>di) && (d_d>es) && (d_d>d_e) && (d_d>b)){
        andei=2;
    }
     
    return andei;   
}

short int valor_maior_cantos(int** matriz, int i, int j, int aux){
    short int andei=0;
    int di = matriz[i][j+1];
    int es = matriz[i][j-1];
    int d_d = matriz[i+1][j+1];
    int d_e = matriz[i+1][j-1];
    int b = matriz[i+1][j];

    if (aux == 10){
        if ((di!=-1) && (di>=d_d) && (di>=b)){
            andei=1;
        }
        else if ((b!=-1) && (b>di) && (b>=d_d)){
            andei=3;
        }
        else if ((d_d!=-1) && (d_d>di) && (d_d>b)){
            andei=2;
        }    
    }

    if (aux == 01){
        if ((es!=-1) && (es>=d_e) && (es>=b)){
            andei=5;
        }
        else if ((d_e!=-1) && (d_e>es) && (d_e>=b)){
            andei=4;
        }
        else if ((b!=-1) && (b>es) && (b>d_e)){
            andei=3;
        }
    }
    return andei; 
}

int direita(int** matriz, int i, int j){
    int elemento = matriz[i][j+1];
    matriz[i][j+1] = -1;
    return elemento;
}

int esquerda(int** matriz, int i, int j){
    int elemento = matriz[i][j-1];
    matriz[i][j-1] = -1;
    return elemento;
}

int diagonal_direita(int** matriz, int i, int j){
    int elemento = matriz[i+1][j+1];
    matriz[i+1][j+1] = -1;
    return elemento;
}

int diagonal_esquerda(int** matriz, int i, int j){
    int elemento = matriz[i+1][j-1];
    matriz[i+1][j-1] = -1;
    return elemento;
}

int abaixo(int** matriz, int i, int j){
    int elemento = matriz[i+1][j];
    matriz[i+1][j] = -1;
    return elemento;
} 