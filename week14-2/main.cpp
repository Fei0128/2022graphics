///Week14-2.cpp
///練習開檔 寫檔 Write 關檔
///練習開檔 讀檔 Read  關檔

#include <stdio.h>

int main()
{
    FILE * fout =fopen("file.txt","w+");
    fprintf(fout,"angle %d\n",999);
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt","r");
    fscanf(fin,"%s %d",line,&a);
    printf("讀到了字串:%s 及整數%d",line,a);
    fclose(fin);
}
