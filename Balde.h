#include <string>
#include <vector>

using namespace std;

class Balde {

    private: 

    int profundidadeLocal;
    int tamanho;

    vector<string> pseudoChaves;

    public:

    Balde(int tamanho, int profundidadeLocal);
    ~Balde();

    void setProfundidade (int profundidade);
    void setTamanho (int tamanho);

    int getProfundidade();
    int getTamanho();
    vector<string> getKeys();


};