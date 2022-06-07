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
float NewAngle[20],OldAngle[20];
void myRead()
{
    if(fout!=NULL) { fclose(fout); fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0 ; i<20; i++)
    {
        OldAngle[i] = NewAngle[i];
        fscanf(fin, "%f",&NewAngle[i]);
        ///fscanf(fin, "%f",&angle[i]);
    }
    glutPostRedisplay();
}

///float alpha=0;
void myInterpolate(float alpha)
{
    for(int i=0;i<20;i++)
    {
        angle[i]=alpha*NewAngle[i]+(1-alpha)*OldAngle[i];
        printf("%.2f",angle[i]);
    }
    printf("/n");
    glutPostRedisplay();
}

void timer(int t)
{
    float alpha=(t%100)/100.0;
    if(t%100==0) myRead();
    myInterpolate(alpha);
    glutTimerFunc(33,timer,t+1);
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='p')
    {
        myRead();
        glutTimerFunc(0,timer,0);
        ///myInterpolate(alpha);
        ///alpha=(alpha+0.01);
        ///if(alpha>1) alpha=alpha-1;
    }
    if(key=='s') myWrite();///save
    if(key=='0') angleID=0;///�w�]�o�@��
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}///��keyboard������A�M�w���@�U

void mouse(int button,int state, int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID] += (x-oldX);
    ///myWrite();
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ⪺
    glRectf(0.3, 0.5, -0.3, -0.2);///����
    ///�k��
    glPushMatrix();
        glTranslatef(0.3,0.5,0);///���b0.5 0.5
        glRotatef(angle[0],0,0,1);
        glTranslatef( -0.3, -0.4, 0);///���त�ߩ�쥿����
        glColor3f(1,0,0);///���⪺
        glRectf(0.3, 0.5, 0.8, 0.3);///���u

        glPushMatrix();
            glTranslatef(0.8,0.4,0);///(3)��U��y���b���`�W
            glRotatef(angle[1],0,0,1);///(2)����
            glTranslatef(-0.8,-0.4,0);///�A�e�U��y///(1)��U��y�����त�ߡA��b������
            glColor3f(0,1,0);///���
            glRectf(0.8,0.5,1.1,0.3);
        glPopMatrix();

    glPopMatrix();
    ///���� (��X���y�г����W�Ƹ��A�HY�y�Ь���ٶb )
    glPushMatrix();
        glTranslatef(-0.3,0.5,0);///���b0.5 0.5
        glRotatef(angle[2],0,0,1);
        glTranslatef( 0.3,-0.4, 0);///���त�ߩ�쥿����
        glColor3f(1,0,0);///���⪺
        glRectf(-0.3, 0.5,-0.8, 0.3);///���u

        glPushMatrix();
            glTranslatef(-0.8,0.4,0);///(3)��U��y���b���`�W
            glRotatef(angle[3],0,0,1);///(2)����
            glTranslatef(0.8,-0.4,0);///�A�e�U��y///(1)��U��y�����त�ߡA��b������
            glColor3f(0,1,0);///���
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
    glutCreateWindow("week16_interpolation");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutDisplayFunc( display );
    glutMainLoop();
}