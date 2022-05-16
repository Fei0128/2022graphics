#include<GL/glut.h>

float angle=45,oldX=0;
void mouse(int button,int state, int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle += (x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.5, 0.5, -0.5, -0.5);///身體
    glPushMatrix();
        glTranslatef(0.5,0.5,0);
        glRotatef(angle,0,0,1);
        glTranslatef(-0.5,-0.4,0);///旋轉中心放到正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.5,0.5,1.0,0.3);///手臂
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutDisplayFunc( display );
    glutMainLoop();
}
