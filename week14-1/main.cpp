///Week14-1.cpp step01-1
///?m?߶}?? Ū?? ?g??

#include <stdio.h>

int main()
{
    FILE * fout =fopen("file.txt","w+");

    printf("Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);
}
