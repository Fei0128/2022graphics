///Week14-2.cpp
///�m�߶}�� �g�� Write ����
///�m�߶}�� Ū�� Read  ����

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
    printf("Ū��F�r��:%s �ξ��%d",line,a);
    fclose(fin);
}
