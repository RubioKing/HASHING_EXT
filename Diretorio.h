#include <string>
#include <vector>
#include "balde.h"

using namespace std;

class Diretorio {

    private: 

    int profundidadeGlobal;
    int tamanhoBalde;
    vector<Balde*> baldes;

    public:

    Diretorio(int profundidadeGlobal, int tamanhoBalde);
    ~Diretorio();

};