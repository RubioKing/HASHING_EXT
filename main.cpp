#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <math.h>
#include "Diretorio.h"

#define NUM 20

string binMax(int numeroBits)
{
    string str;
    for (int i = 0; i < numeroBits; i++)
    {
        str.push_back('1');
    }

    return str;
}

int binarioParaInt(string stringBin)
{
    int result = 0;
    char c;
    int i = 0;
    int j = stringBin.length()-1;

    while (i < stringBin.length())
    {
        c = stringBin[i];
        result = result + ((c - '0')*(pow(2,j)));
        i++;
        j--;
    }
    
    return result;
}

string intParaBinario(int n, int numeroBits) 
{  
    vector<int> numeroBinario;
    string tmp;
    char const *num_char;
    char charr;
    string stringBin;

  
    int i = 0; 
    while (n > 0) { 
        
        numeroBinario.push_back(n % 2); 
        n = n / 2; 
        i++; 
    } 

    if (numeroBinario.size() < numeroBits)
        {
            for ( int i = 0; i < (numeroBits - numeroBinario.size()); i++)
            {
                stringBin.push_back('0');
            }
        }

    for (int j = i - 1; j >= 0; j--)
    {
            tmp = to_string(numeroBinario[j]);
            num_char = tmp.c_str();
            charr = num_char[0];
            stringBin.push_back(charr);        
    }

    return stringBin;
        
}

void chavesAleatorias(Diretorio *dir, int numeroBits)
{
    srand(time(NULL));

    string psdChave;
    int n = 0;
    int numMax = binarioParaInt(binMax(numeroBits));

    for (int i = 0; i < NUM;)
    {
        n = rand()%numMax  + 1;
        
        psdChave = intParaBinario(n, numeroBits);
        
        if (dir->busca(psdChave) == false)
        {
            dir->Insere(psdChave);
        }
        else
            i++;
    }
}

void bitFixo(Diretorio *dir, int numeroBits)
{
    srand(time(NULL));

    string psdChave;
    int n = 0;
    int numMax = binarioParaInt(binMax(numeroBits-1));

    for (int i = 0; i < NUM; i++)
    {
        psdChave = "0";

        n = rand()%numMax  + 1;
        
        psdChave = psdChave + intParaBinario(n, numeroBits - 1);
        
        if(dir->busca(psdChave) == false)
        {
            dir->Insere(psdChave);
        }
        
    }
}

void menu(Diretorio *dir, int numeroBits)
{
    int escolha = -1;

    cout << "--------- MENU ---------" << endl;
    cout << "[1] N Chaves Aleatorias" << endl;
    cout << "[2] N Chaves com padrao de bits" << endl;
    cout << "[0] Sair" << endl;

    while (escolha != 0)
    {
        cout << "Digite sua opcao: ";
        cin >> escolha;

        if (escolha < 0 || escolha > 2)
        {
            cout << "Opcao invalida, digite novamente" << endl;
        }

        else if (escolha == 1)
        {
            chavesAleatorias(dir , numeroBits);
            dir->imprimeDiretorio();
            dir->limpaDiretorio();
        }

        else if (escolha == 2)
        {
            bitFixo(dir , numeroBits);
            dir->imprimeDiretorio();
        }
    }
}

int main()
{
    int tamanhoBalde = 0;
    int numeroBits = 0;
    int escolha = -1;

    cout << "Digite o tamanho dos baldes: ";
    cin >> tamanhoBalde;
    cout << "Digite o numero de bits para as pseudo-chaves: ";
    cin >> numeroBits;

    Diretorio *dir = new Diretorio(tamanhoBalde);
    cout << "Diretorio Criado!" << endl;

    menu(dir, numeroBits);
    return 0;
}
