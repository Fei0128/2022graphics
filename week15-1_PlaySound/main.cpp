///week15-1_PlaySound.cpp
///#include <mmsystem.h>
#include <windows.h>///另一種寫法,結果一樣
int main()
{
            ///先放不存在的檔
    PlaySound("game.wav",NULL,SND_SYNC);
}
///complier 成功，但link失敗
///.c .cpp
