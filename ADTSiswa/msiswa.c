#include "siswa.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N;
    kelas kls;
    printf("Berapa banyak siswa? maks %d\n", MAX);
    scanf("%d", &N);

    createKelas(&kls);
    siswa temp;
    char nama[25];
    char NIM[10];
    char hobi[25];
    for (int i = 0; i < N; i++)
    {
        printf("Nama Dari Siswa : \n");
        scanf(" %[^\n]s", nama);
        printf("NIM dari siswa : \n");
        scanf(" %[^\n]s", NIM);
        createSiswa(&temp, nama, NIM);

        while (1)
        {
            printf("Tambahkan hobi, inputkan q untuk selesaikan\n");
            scanf(" %[^\n]", hobi);

            if (strcmp(hobi, "q") == 0)
            {
                break;
            }

            addHobi(&temp, hobi);
        }
        
        addSiswa(&kls, temp);
    }

    printf("\nIsi Kelas :\n");
    printKelas(kls);   
    printf("\n");
    return 0;
}
