#ifndef CUBO_H
#define CUBO_H

#include <QOpenGLWidget>
#include "stb_image.h"
#include <glm/glm.hpp>
#include<GL/gl.h>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<QKeyEvent>
#include "textura.h"
class cubo: public QOpenGLWidget
{
public:
    cubo(QWidget *parent);

    textura text1, text2;
    float aspecto;
    float angulo = 0;
    glm::vec3 sentido = glm::vec3 (0, 1, 0);

    void initializeGL();
    void paintGL();
    void keyPressEvent(QKeyEvent *event);
};

#endif // CUBO_H
