
#include <stdio.h>
int main()
{
    FILE* pFile;
    char abc[] = "ana are mere";
    pFile = fopen("file.dat", "wb");
    fwrite(abc, 2,sizeof(abc), pFile);
    fclose(pFile);
    return 0;
}
