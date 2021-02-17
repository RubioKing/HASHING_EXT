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
    int binarioParaInt(string stringBin);

    public:

    Diretorio(int tamanhoBalde);
    ~Diretorio();

    void Insere(string key);
    bool busca(string str);
    bool baldeCheio(Balde balde);
    void duplicaBalde(int indiceBalde);
    void duplicaDiretorio(int indiceBalde);
    void limpaDiretorio();
    void imprimeDiretorio();
    Balde* Busca();

};