#include <GL/glut.h>
#include <stdio.h>
int N=0;
int x[1000],y[1000];///最多1000個點
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        glVertex2f( (x[i]-150)/150.0, -(y[i]-150)/150.0);
    }
    glEnd();

    glutSwapBuffers();
}
void mouse(int button, int state, int mouseX, int mouseY)
{
    if(state==GLUT_DOWN)///如果按下mouse
    {
        N++;///就多一個頂點
        x[N-1]=mouseX;///最後新增的頂點x的座標
        y[N-1]=mouseY;///最後新增的頂點y的座標
        printf("現在按下滑鼠，得到新座標 %d %d\n",x[N-1],y[N-1]);
    }
    display();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week05 複習mouse");

    glutDisplayFunc( display );
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
