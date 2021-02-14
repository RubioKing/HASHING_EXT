#include <string>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Diretorio.h"

using namespace std;

Diretorio::Diretorio(int tamanhoBalde)
{
    this->baldes;
    this->profundidadeGlobal = 2;
    this->tamanhoBalde = tamanhoBalde;

    Balde *balde = new Balde(tamanhoBalde, 0);

    for (int i = 0; i < (1 << profundidadeGlobal); i++)
    {
        baldes.push_back(balde);
    }
}

Diretorio::~Diretorio(){}

void Diretorio::Insere(string key)
{
    string bits = key.substr(0, profundidadeGlobal);
    cout << bits << endl;
}
