#include <string>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "Diretorio.h"

using namespace std;

int Diretorio::binarioParaInt(string stringBin)
{
    int result = 0;
    char c;
    int i = 0;
    int j = stringBin.length() - 1;

    while (i < stringBin.length())
    {
        c = stringBin[i];
        result = result + ((c - '0') * (pow(2, j)));
        i++;
        j--;
    }

    return result;
}

Diretorio::Diretorio(int tamanhoBalde)
{
    this->profundidadeGlobal = 2;
    this->tamanhoBalde = tamanhoBalde;

    for (int i = 0; i < (1 << profundidadeGlobal); i++)
    {
        Balde *balde = new Balde(tamanhoBalde);
        this->baldes.push_back(balde);
    }
}

Diretorio::~Diretorio() {}

void Diretorio::Insere(string key)
{
    string bits = key.substr(0, profundidadeGlobal);

    int indice = binarioParaInt(bits);

    if (baldes[indice]->baldeCheio())
    {
        if (profundidadeGlobal == baldes[indice]->getProfundidade())
        {
            //duplicaDiretorio(indice);
        }

        else
        {
            duplicaBalde(indice);
            Insere(key);
        }
    }

    else
        baldes[indice]->insereChave(key);
}

void Diretorio::duplicaBalde(int indiceBalde)
{

    Balde *balde1 = new Balde(tamanhoBalde);
    Balde *balde2 = new Balde(tamanhoBalde);
    int profundidadeLocal = baldes[indiceBalde]->getProfundidade();
    string bits1 = "";
    string bits2 = "";

    vector<string> keys = baldes[indiceBalde]->getKeys();

    balde1->insereChave(keys[0]);

    for (int i = 1; i < tamanhoBalde; i++)
    {
        bits1 = balde1->getKeys()[0].substr(0, profundidadeLocal);
        bits2 = keys[i].substr(0, profundidadeLocal);
        if (bits1 == bits2)
        {
            balde1->getKeys().push_back(keys[i]);
        }
        else
            balde2->getKeys().push_back(keys[i]);
    }

    balde1->setProfundidade(profundidadeLocal + 1);
    balde2->setProfundidade(profundidadeLocal + 1);

    // aponta para novo balde
    baldes[indiceBalde] = balde2;
    baldes.push_back(balde1);
}

void Diretorio::duplicaDiretorio(int indiceBalde)
{
}

void Diretorio::imprimeDiretorio()
{
    int numBaldes = baldes.size();

    for (int i = 0; i < numBaldes; i++)
    {
        if (baldes[i]->getPreenchido() == 0)
        {
            cout << "Balde: " << i << " vazio" << endl;
        }

        else
        {
            cout << "Balde: " << i << endl;
            for (int j = 0; j < baldes[i]->getPreenchido(); j++)
            {
                cout << baldes[i]->getKeys()[j] << endl;
            }
        }
    }
}

void Diretorio::limpaDiretorio()
{
    for (int i = baldes.size()-1; i > 3; i--)
    {
        baldes.erase(baldes.begin()+i);
    }
}

bool Diretorio::busca(string str)
{
    int indice = binarioParaInt(str.substr(0, profundidadeGlobal));
    for (int i = 0; i < baldes[indice]->getPreenchido(); )
    {
        if (baldes[indice]->getKeys().empty())
        {
            i++;
        }
        else if (baldes[indice]->getKeys()[indice] == str)
        {
            return true;
        }
        else
            i++;
    }
    return false;
}