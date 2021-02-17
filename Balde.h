#include <string>
#include <vector>

using namespace std;

class Balde {

    private: 

    int profundidadeLocal;
    int tamanho;
    int preenchido;

    vector<string> pseudoChaves;

    public:

    Balde(int tamanho);
    ~Balde();

    void setProfundidade (int profundidade);
    void setTamanho (int tamanho);

    int getProfundidade();
    int getTamanho();
    int getPreenchido();
    vector<string> getKeys();
    bool baldeCheio();
    void insereChave(string key);


};