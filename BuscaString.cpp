#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void fileNameCheck(string caminho){
    ifstream ftexto; 
    ftexto.open(caminho); // abre o arquivo
    if(!ftexto){ // testa se arquivo eh valido
        cerr << "Erro: arquivo não pode ser aberto!" << endl;
        exit(1);
    }
    ftexto.close(); // fecha o arquivo
}

// função que recebe um caminho para arquivo e retorna o conteudo em uma string
string getText(string caminho){
    // Adiciona codigo que faz a leitura do arquivo e retorna o conteudo em uma string
}

// funcao para buscar padrao em string usando força bruta
int forcaBruta(string texto, string padrao){
    // Adicionar o codigo do algoritmo naive
}

// funcao auxiliar para calcular os prefixos do KMP
void calculaPrefixos(string padrao, int p_size, int* prefixos){
    // TODO: Adicionar o codigo do calculo de prefixos
}

// funcao para buscar padrao em string usando algoritmo KMP
int kmp(string texto, string padrao){
    // Adicionar o codigo do algoritmo KMP
}

int main(int argc, char** argv){

    // verifica os argumentos para caminho do texto e padrao a ser buscado
    if (argc<3){
        cout << "O programa requer dois argumentos (caminho do texto e o padrao a ser buscado)"<< endl;
        exit(1);
    }

    string padrao, caminho; // variaveis auxiliares    

    // armazena o padrao a ser buscado na variavel padrao
    padrao = argv[2];

    // recebe e confere os dados do texto
    caminho = argv[1];
    fileNameCheck(caminho);

    // obtem o texto na forma de string
    string texto = getText(caminho);
    
    // chama a funcao para buscar o padrao no texto usando força bruta
    int indice = forcaBruta(texto, padrao);

    // chama a funcao para buscar o padrao no texto usando algoritmo KMP
    indice = kmp(texto, padrao);
    
    return 0;
}

