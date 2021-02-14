#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <math.h>
#include "Diretorio.h"

#define NUM 10

int binarioParaInt(string stringBin)
{
    int result = 0;
    char c;
    int i = 0;
    int j = stringBin.length()-1;

    while (i < stringBin.length())
    {
        c = stringBin[i];
        cout << c << endl;
        result = result + ((c - '0')*(pow(2,j)));
        cout << result << endl;
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

    cout << numeroBinario.size() << endl;

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

void chavesAleatorias(int numeroBits)
{
    srand(time(NULL));
    string psdChave;
    int num = 0;

    for (int i = 0; i < NUM; i++)
    {
        num = rand()% 17 + 1;
        for (int j = 0; j < numeroBits; j++)
        {
            psdChave = intParaBinario(num, numeroBits);
            cout << psdChave << endl;
        }
    }
}

void bitsFixos()
{
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
        cout << "Digite sua opção: ";
        cin >> escolha;

        if (escolha < 0 || escolha > 2)
        {
            cout << "Opcao invalida, digite novamente" << endl;
        }

        else if (escolha == 1)
        {
            chavesAleatorias(numeroBits);
        }

        else if (escolha == 2)
        {
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

    //menu(dir, numeroBits);
    binarioParaInt("11111");
    return 0;
}
