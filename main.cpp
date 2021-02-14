#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "Diretorio.h"

void randomKeys()
{
}

void bitsFixos()
{
}

void menu(Diretorio *dir)
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
            cout << "Opção inválida, digite novamente" << endl;
        }

        else if (escolha == 1)
        {
            randomKeys();
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

    Diretorio *dir = new Diretorio(numeroBits, tamanhoBalde);
    cout << "Diretorio Criado!" << endl;

    menu(dir);

    return 0;
}
