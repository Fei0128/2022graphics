#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
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
void myTexture()
{
    IplImage * img = cvLoadImage("earthmap.jpg");
    cvShowImage("img",img);
    cvWaitKey(0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    //glutSolidTeapot( 0.3 );
    glBegin(GL_POLYGON);
            glTexCoord2f(0,1); glVertex2f(-1,-1);
            glTexCoord2f(1,1); glVertex2f(+1,-1);
            glTexCoord2f(1,0); glVertex2f(+1,+1);
            glTexCoord2f(0,0); glVertex2f(-1,+1);
    glEnd();

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week10 texture background");
    glutDisplayFunc( display );
    myTexture("earthmap.jpg");
    glutMainLoop();
}
