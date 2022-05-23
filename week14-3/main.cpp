#include<GL/glut.h>
#include<stdio.h>

float angle[20],oldX=0;
int angleID=0;
FILE * fout =NULL,*fin=NULL;

void myWrite()
{
    if(fout == NULL) fout = fopen("file.txt" , "w+");
    for(int i=0;i<20;i++)
    {
        printf("0.2%f",angle[i]);
        fprintf(fout, "%.2f",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void myRead()
{
    if(fout!=NULL) { fclose(fout); fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0 ; i<20; i++)
    {
        fscanf(fin, "%f",&angle[i]);
    }
}

void keyboard(unsigned char key,int x,int y)
{
    if(key=='r')
    {
        myRead();
    }
    if(key=='0') angleID=0;///預設這一個
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}///用keyboard的按鍵，決定等一下

void mouse(int button,int state, int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID] += (x-oldX);
    myWrite();
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3, 0.5, -0.3, -0.2);///身體
    ///右手
    glPushMatrix();
        glTranslatef(0.3,0.5,0);///掛在0.5 0.5
        glRotatef(angle[0],0,0,1);
        glTranslatef( -0.3, -0.4, 0);///旋轉中心放到正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3, 0.5, 0.8, 0.3);///手臂

        glPushMatrix();
            glTranslatef(0.8,0.4,0);///(3)把下手肘掛在關節上
            glRotatef(angle[1],0,0,1);///(2)旋轉
            glTranslatef(-0.8,-0.4,0);///再畫下手肘///(1)把下手肘的旋轉中心，放在正中心
            glColor3f(0,1,0);///綠色
            glRectf(0.8,0.5,1.1,0.3);
        glPopMatrix();

    glPopMatrix();
    ///左手 (把X的座標都乘上副號，以Y座標為對稱軸 )
    glPushMatrix();
        glTranslatef(-0.3,0.5,0);///掛在0.5 0.5
        glRotatef(angle[2],0,0,1);
        glTranslatef( 0.3,-0.4, 0);///旋轉中心放到正中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3, 0.5,-0.8, 0.3);///手臂

        glPushMatrix();
            glTranslatef(-0.8,0.4,0);///(3)把下手肘掛在關節上
            glRotatef(angle[3],0,0,1);///(2)旋轉
            glTranslatef(0.8,-0.4,0);///再畫下手肘///(1)把下手肘的旋轉中心，放在正中心
            glColor3f(0,1,0);///綠色
            glRectf(-0.8,0.5,-1.1,0.3);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(600,600);
    glutCreateWindow("week14");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutDisplayFunc( display );
    glutMainLoop();
}
