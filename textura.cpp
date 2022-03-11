#include "textura.h"
#include <Windows.h>
#include <gl/GL.h>
#include "stb_image.h"

textura::textura() : id(0), largura(0), altura(0), canais(0)
{

}

textura::~textura()
{
    glDeleteTextures(1, &id);
}

void textura::load(std::string filePath)
{
    unsigned char* imgData;

    stbi_set_flip_vertically_on_load(true);
    imgData = stbi_load(filePath.c_str(), &largura, &altura, &canais, 3);

    if(imgData)
    {
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, largura, altura, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

        std::cout << "SUCESSO: A textura foi carregada!" << filePath.c_str() << std::endl;
        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(imgData);
    }
    else
    {
        std::cout << "ERRO: Nao foi possivel carregar a textura!" << filePath.c_str() << std::endl;
    }
}

void textura::bind()
{
    glBindTexture(GL_TEXTURE_2D, id);
}

void textura::unBind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
