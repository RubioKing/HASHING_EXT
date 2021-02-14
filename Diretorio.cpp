#include <string>
#include <cstdlib>
#include "Diretorio.h"

using namespace std;

Diretorio::Diretorio(int profundidadeGlobal, int tamanhoBalde)
{
    this->baldes;
    this->profundidadeGlobal = profundidadeGlobal;
    this->tamanhoBalde = tamanhoBalde;

    Balde *balde = new Balde(tamanhoBalde, 0);

    for (int i = 0; i < (1 << profundidadeGlobal); i++)
    {
        baldes.push_back(balde);
    }
}

Diretorio::~Diretorio(){}
