#ifndef TEXTURA_H
#define TEXTURA_H

#include <iostream>

class textura
{
private:
    unsigned int id;
    int largura, altura, canais;

public:
    textura();
    ~textura();

    //Funções para carregar, fazer o bind e o unbind
    void load(std::string filePath);    //Carrega textura

    void bind();                        //Vincular

    void unBind();                      //Desvincular para não ocorrer problemas de cor
};

#endif // TEXTURA_H
