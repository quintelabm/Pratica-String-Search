#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Exemplo
// GAGATAAGAGG
// Padrao encontrado no indice 157779!

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
    vector<char> texto; // utiliza um vector para armazenar cada caractere
    char temp;
    ifstream ftexto;
    ftexto.open(caminho); // abre arquivo para obter o texto
    ftexto >> temp; // utiliza char temporaria para obter os caracteres
    while(!ftexto.eof()){ // inicia a leitura
        //cout << temp; // impressao para verificacao
        texto.push_back(temp); // armazena no vector
        ftexto >> temp; // le o proximo caractere
    }
    ftexto.close(); // fecha o arquivo
    cout << "Chegou ao final do arquivo..." << endl;

    // retorna texto como string
    string s(texto.begin(), texto.end());
    return s;
}

// funcao para buscar padrao em string usando força bruta
int forcaBruta(string texto, string padrao){
    cout << "Busca utilizando força bruta iniciou..." << endl;
    //cout << texto;
    int t_size = texto.length();
    int p_size = padrao.length();

    // nao precisa ir ate o final do arquivo
    for(int i = 0; i < (t_size-p_size); i++){
        int j;
        // pois aqui tem a outra repeticao que compara o padrao
        for(j = 0; j < p_size; j++){
            if(texto[i+j] != padrao[j])
                break;
        }
        if(j==p_size){
            cout << "Padrao encontrado no indice " << i << "!" << endl;
            return i;
        }
    }
    //cout << "Tamanho da string: " << t_size << endl;
    //cout << "Tamanho do padrao: " << p_size << endl;

    cout << "Busca utilizando força bruta terminou!" << endl;
    return -1;
}

// funcao auxiliar para calcular os prefixos do KMP
void calculaPrefixos(string padrao, int p_size, int* prefixos){
    int tam = 0; // tamanho do maior prefixo-sufixo atual
    prefixos[0] = 0; // primeiro é sempre zero
    int i = 1;
    while(i<p_size){
        if(padrao[i] == padrao[tam]){
            tam++;
            prefixos[i] = tam;
            i++;
        }else{ // padrao[i] != padrao[tam]
            if (tam != 0){
                tam = prefixos[tam-1];
                // aqui nao incrementa o i
            }else{ // tam == 0
                prefixos[i] = 0;
                i++;
            }
        }
    }
}

// funcao para buscar padrao em string usando algoritmo KMP
int kmp(string texto, string padrao){
    int t_size = texto.length();
    int p_size = padrao.length();

    // calcula funcao de prefixo
    int prefixos[p_size];
    cout << "Calculando prefixos..." << endl;
    calculaPrefixos(padrao, p_size, prefixos);
    
    cout << "Busca utilizando KMP iniciou..." << endl;
    int i=0, j=0;
    while(i < t_size){
        if(padrao[j] == texto[i]){
            j++; i++;
        }
        if(j==p_size){
            cout << "Padrao encontrado no indice " << i-j << "!" << endl;
            return i-j;
        }else if(i < t_size && padrao[j] != texto[i]){
            if(j != 0)
                j = prefixos[j-1];
            else
                i = i + 1;
        }
    }

    cout << "Busca utilizando KMP terminou!" << endl;

    return -1;
}

int main(int argc, char** argv){

    // verifica os argumentos para caminho do texto e padrao a ser buscado
    if (argc<3){
        cout << "O programa requer dois argumentos (caminho do texto e o padrao a ser buscado)"<< endl;
        exit(1);
    }

    string padrao, caminho; // variaveis auxiliares    

    // recebe o padrao a ser buscado
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

