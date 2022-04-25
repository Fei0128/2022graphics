/*#include <opencv/highgui.h>///使用OpenCV 2.1
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h";
GLMmodel * pmodel = NULL;
//GLUquadric * sphere = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img,CV_BGR2RGB);///OpenCV轉色彩
    glEnable(GL_TEXTURE_2D);///開啟貼圖功能
    GLuint id;///產生Generate貼圖ID
    glGenTextures(1,&id);///綁定bin 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);///貼圖參數 超過包裝範圍T 就重複貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);///貼圖參數 超過包裝範圍S 就重複貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);///貼圖參數 放大時的內插 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);///貼圖參數 放小時的內插 用最近點

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
    angle+=0.1;///angle++ 會轉太快 跟電腦效能有關
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
