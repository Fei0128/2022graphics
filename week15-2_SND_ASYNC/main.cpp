#include <windows.h>
#include <stdio.h>
int main()
{
    printf("現在在PlaySound()前\n");
    PlaySound("game.wav",NULL,SND_ASYNC);
    printf("PlaySound()後\n");
    int N;
    scanf("%d",&N);///等待輸入數字
}
