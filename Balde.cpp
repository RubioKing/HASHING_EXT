#include <string>
#include <cstdlib>
#include "Balde.h"

using namespace std;

Balde::Balde(int tamanho, int profundidadeLocal)
{
    this->tamanho = tamanho;
    this->profundidadeLocal = profundidadeLocal;
    this->pseudoChaves.resize(tamanho);
}

Balde::~Balde()
{
    
}

void Balde::setProfundidade (int profundidade)
{
    this->profundidadeLocal = profundidade;
}

void Balde::setTamanho (int tamanho)
{
    this->tamanho = tamanho;
}

int Balde::getProfundidade()
{
    return this->profundidadeLocal;
}

int Balde::getTamanho()
{
    return this->tamanho;
}

vector<string> Balde::getKeys()
{
    return this->pseudoChaves;
}
