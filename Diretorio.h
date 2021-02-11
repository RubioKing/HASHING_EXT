#include <string>

using namespace std;

class Diretorio {

    private: 

    string pseudo_chave;

    public:

    Diretorio();
    ~Diretorio();

    void setKey(string pseudo_chave);

    string& getKey();

};