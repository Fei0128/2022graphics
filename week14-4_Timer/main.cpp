#include <GL/glut.h>
#include <stdio.h>

void timer(int t)///t的單位是ms
{
    printf("我起床了");///t的單位
    ///1000代表1秒 1500代表1.5秒
    printf("設定下一個鬧鐘\n");///起床做事
    glutTimerFunc(1000,timer,t+1);
    printf("設好鬧鐘，再回去睡\");
}
void display()
{

}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayModel(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12 timer");

    glutTimerFunc(3000,timer,0);///3秒後叫timer
    glutDisplayFunc(display);
    glutMainLoop();
}
