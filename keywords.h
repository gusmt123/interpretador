#include <iostream>
#include <vector>


class keywords
{
    private: 
        std::string palavra_chave;
        std::vector<std::string> palavras_chave = {"se" , "repetir"};

    public:
        void set_Palavra_Chave(std::string palavra_chave);
        std::string get_Palavra_Chave();
        keywords(std::string palavra_chave);
        bool verifica_Palavra_Chave();

};