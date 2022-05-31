///week15-3 希望能撥放mp3
///MP3檔案小 vs WAV檔案大
///有壓縮/難    原始資料
#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("ozi.mp3");
    mp3.Play();
    printf("現在正在播放");
    int N;
    scanf("%d",&N);
}
