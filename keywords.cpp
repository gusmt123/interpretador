#include "keywords.h"
#include <iostream>
#include <string>

keywords::keywords(std::string palavra_chave)
{
    this->palavra_chave = palavra_chave;
};

std::string keywords::get_Palavra_Chave()
{
    return palavra_chave;
}
void keywords::set_Palavra_Chave(std::string palavra_chave)
{
    this->palavra_chave = palavra_chave;
}
bool keywords::verifica_Palavra_Chave()
{

    for(const std::string& palavra : palavras_chave)
    {
        if(palavra == palavra_chave)
        {
            return true;
        }
    }

    return false;
}