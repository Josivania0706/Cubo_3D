#include "cubo.h"
#include "textura.h"
cubo::cubo(QWidget *parent) : QOpenGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

void cubo::initializeGL()
{
    glClearColor(0.5,0.5,0.5,1);
    glEnable(GL_DEPTH_TEST);
    glCullFace(GL_BACK);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    text1.load("C:/Qt/dado.jpeg");
}

void cubo::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float largura = width();
    float altura = height();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glm::mat4 projecao = glm::mat4(1.0);
    projecao = glm::perspective(glm::radians(20.0f),
                                largura/altura,
                                1.0f,
                                100.0f);

    glLoadMatrixf(glm::value_ptr(projecao));
    glMatrixMode(GL_MODELVIEW);
    glm::mat4 cameraMatrix = glm::lookAt( glm::vec3(5,4,5), glm::vec3(0), glm::vec3(0,1,0) );  //crir matrix de came
    glLoadMatrixf(glm::value_ptr(cameraMatrix));

    textura* tex1;
    tex1 = &text1;

    glm::vec3 vert1 = { 0.5,  0.5,  0.5};
    glm::vec3 vert2 = {-0.5,  0.5,  0.5};
    glm::vec3 vert3 = { 0.5, -0.5,  0.5};
    glm::vec3 vert4 = {-0.5, -0.5,  0.5};
    glm::vec3 vert5 = { 0.5,  0.5, -0.5};
    glm::vec3 vert6 = {-0.5,  0.5, -0.5};
    glm::vec3 vert7 = { 0.5, -0.5, -0.5};
    glm::vec3 vert8 = {-0.5, -0.5, -0.5};

    glRotatef(angulo, sentido.x, sentido.y, sentido.z);
    glColor3f(1, 0, 0);
    tex1->bind();
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);
        glVertex3f(vert6.x, vert6.y, vert6.z);
        glTexCoord2f(0, 0.5);
        glVertex3f(vert8.x, vert8.y, vert8.z);
        glTexCoord2f(0.333, 0.5);
        glVertex3f(vert7.x, vert7.y, vert7.z);
        glTexCoord2f(0.333, 1);
        glVertex3f(vert5.x, vert5.y, vert5.z);

        glTexCoord2f(0, 0.5);
        glVertex3f(vert8.x, vert8.y, vert8.z);
        glTexCoord2f(0, 0);
        glVertex3f(vert4.x, vert4.y, vert4.z);
        glTexCoord2f(0.333, 0);
        glVertex3f(vert3.x, vert3.y, vert3.z);
        glTexCoord2f(0.333, 0.5);
        glVertex3f(vert7.x, vert7.y, vert7.z);

        glTexCoord2f(0.333, 0.5);
        glVertex3f(vert7.x, vert7.y, vert7.z);
        glTexCoord2f(0.333, 0);
        glVertex3f(vert3.x, vert3.y, vert3.z);
        glTexCoord2f(0.666, 0);
        glVertex3f(vert1.x, vert1.y, vert1.z);
        glTexCoord2f(0.666, 0.5);
        glVertex3f(vert5.x, vert5.y, vert5.z);

        glTexCoord2f(0.666, 0.5);
        glVertex3f(vert8.x, vert8.y, vert8.z);
        glTexCoord2f(0.666, 0);
        glVertex3f(vert6.x, vert6.y, vert6.z);
        glTexCoord2f(1, 0);
        glVertex3f(vert2.x, vert2.y, vert2.z);
        glTexCoord2f(1, 0.5);
        glVertex3f(vert4.x, vert4.y, vert4.z);

        glTexCoord2f(0.333, 1);
        glVertex3f(vert6.x, vert6.y, vert6.z);
        glTexCoord2f(0.333, 0.5);
        glVertex3f(vert5.x, vert5.y, vert5.z);
        glTexCoord2f(0.666, 0.5);
        glVertex3f(vert1.x, vert1.y, vert1.z);
        glTexCoord2f(0.666, 1);
        glVertex3f(vert2.x, vert2.y, vert2.z);

        glTexCoord2f(0.666, 1);
        glVertex3f(vert2.x, vert2.y, vert2.z);
        glTexCoord2f(0.666, 0.5);
        glVertex3f(vert4.x, vert4.y, vert4.z);
        glTexCoord2f(1, 0.5);
        glVertex3f(vert3.x, vert3.y, vert3.z);
        glTexCoord2f(1, 1);
        glVertex3f(vert1.x, vert1.y, vert1.z);
    glEnd();
    tex1->unBind();
    glRotatef(-angulo, sentido.x, sentido.y, sentido.z);

    update();
}

void cubo::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_R){
        angulo += 10;
        sentido = glm::vec3 (0, 1, 0);
    }

    if(event->key() == Qt::Key_T){
        angulo += 10;
        sentido = glm::vec3 (1, 0, 0);
    }
}
