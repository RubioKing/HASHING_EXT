#include <string>
#include <cstdlib>
#include "Diretorio.h"

using namespace std;

Diretorio::Diretorio()
{
    this->pseudo_chave;
}

Diretorio::~Diretorio(){}

string& Registro::getKey(){
    return this->pseudo_chave;
}

void Diretorio::setKey(string pseudo_chave)
{
    this->pseudo_chave = pseudo_chave;
}