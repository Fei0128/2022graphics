#include <GL/glut.h>
#include <stdio.h>///printf
int mouseX=0,mouseY=0,N=0;
int mx[100],my[100];///記錄用
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glBegin(GL_LINE_LOOP);///push備份矩陣
        for(int i=0;i<N;i++)
        {
            glVertex2f((mx[i]-150)/150.0,-(my[i]-150)/150.0);
        }

    glEnd();
    glutSwapBuffers();
}

void mouse(int button ,int state ,int x ,int y)///產生程式碼的工具
{
    //printf("%d %d %d %d\n",button,state,x,y );
    mouseX=x; mouseY=y;
    if(state==GLUT_DOWN)
    {
        printf("     glVertex2f((%d-150)/150.0,-(%d-150)/150.0);\n",x,y);
        N++;
        mx[N-1]=x; my[N-1]=y;///陣列備份座標
    }
}


int main(int argc, char**argv)
{

    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 mouse");

    glutDisplayFunc( display );
    glutMouseFunc( mouse );
    glutMainLoop();

}
