#include <string>
#include <cstdlib>
#include <iostream>
#include "Balde.h"

using namespace std;

Balde::Balde(int tamanho)
{
    this->tamanho = tamanho;
    this->profundidadeLocal = 0;
    this->preenchido = 0;
}

Balde::~Balde()
{
    
}

void Balde::setProfundidade(int profundidade)
{
    this->profundidadeLocal = profundidade;
}

void Balde::setTamanho(int tamanho)
{
    this->tamanho = tamanho;
}

int Balde::getProfundidade()
{
    return this->profundidadeLocal;
}

int Balde::getPreenchido()
{
    return this->preenchido;
}

int Balde::getTamanho()
{
    return this->tamanho;
}

vector<string> Balde::getKeys()
{
    return this->pseudoChaves;
}

bool Balde::baldeCheio()
{
    if (this->preenchido == tamanho)
    {
        return true;
    }
    return false;
}

void Balde::insereChave(string key)
{
    this->pseudoChaves.push_back(key);
    this->preenchido++;
}