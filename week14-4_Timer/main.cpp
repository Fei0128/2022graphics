#include <GL/glut.h>
#include <stdio.h>

void timer(int t)///t�����Oms
{
    printf("�ڰ_�ɤF");///t�����
    ///1000�N��1�� 1500�N��1.5��
    printf("�]�w�U�@�Ӿx��\n");///�_�ɰ���
    glutTimerFunc(1000,timer,t+1);
    printf("�]�n�x���A�A�^�h��\");
}
void display()
{

}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayModel(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12 timer");

    glutTimerFunc(3000,timer,0);///3���stimer
    glutDisplayFunc(display);
    glutMainLoop();
}
