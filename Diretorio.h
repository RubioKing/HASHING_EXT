#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Balde.h"

using namespace std;

class Diretorio {

    private: 

    int profundidadeGlobal;
    int tamanhoBalde;
    vector<Balde*> baldes;

    public:

    Diretorio(int profundidadeGlobal, int tamanhoBalde);
    ~Diretorio();

    void Insere(string key);
    Balde* Busca();

};