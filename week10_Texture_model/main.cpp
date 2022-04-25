/*#include <opencv/highgui.h>///�ϥ�OpenCV 2.1
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h";
GLMmodel * pmodel = NULL;
//GLUquadric * sphere = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img,CV_BGR2RGB);///OpenCV���m
    glEnable(GL_TEXTURE_2D);///�}�ҶK�ϥ\��
    GLuint id;///����Generate�K��ID
    glGenTextures(1,&id);///�j�wbin �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);///�K�ϰѼ� �W�L�]�˽d��T �N���ƶK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);///�K�ϰѼ� �W�L�]�˽d��S �N���ƶK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);///�K�ϰѼ� ��j�ɪ����� �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);///�K�ϰѼ� ��p�ɪ����� �γ̪��I

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

        glRotatef(angle,0,1,0);
        if( pmodel==NULL)
        {
            pmodel=glmReadOBJ("data/Gundam.obj");
            glmUnitize(pmodel);
            glmFacetNormals(pmodel);
            glmVertexNormals(pmodel,90);
        }
        glmDraw(pmodel,GLM_MATERIAL | GLM_TEXTURE);


    //glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;///angle++ �|��ӧ� ��q���į঳��
}

int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week10 texture background");

    glutIdleFunc(display);
    glutDisplayFunc( display );

    myTexture("data/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

}
*/
