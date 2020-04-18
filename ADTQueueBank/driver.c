/*
    Program         : driver.c
    Deskripsi       : Driver Untuk ADT Antrian Bank
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 18 April 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "antrianBank.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char cmdBuf;
    int valBuf;
    infotype temp;
    Bank b;

    initBank(&b);

    while (true)
    {
        printf("Inputkan 'a' untuk menambahkan antrian, 'c' untuk memanggil antrian, 's' untuk status antrian, dan 'q' untuk keluar.\n");
        scanf(" %c", &cmdBuf);

        switch (cmdBuf)
        {
        case 'a':
            printf("Inputkan 'c' untuk costumer service, 't' untuk teller, dan 'q' untuk cancel.\n");
            scanf(" %c", &cmdBuf);

            if (cmdBuf == 'c')
            {
                tambahAntrian(&b, 'C');
            }
            else if (cmdBuf == 't')
            {
                tambahAntrian(&b, 'T');
            }

            break;

        case 'c':
            printf("Inputkan 'c' untuk costumer service, 't' untuk teller, dilanjutkan dengan no. teller\ncontoh : c 1, 'q' untuk cancel.\n");
            scanf(" %c %d", &cmdBuf, &valBuf);

            if (cmdBuf == 'c')
            {
                if (valBuf > 2 || valBuf < 1)
                {
                    break;
                }

                temp = panggilAntrian(&b, 'C', valBuf);
                if (temp.kode != 'E')
                {
                    printf("%c-%d ke CS%d\n", temp.kode, temp.noAntrian, valBuf);
                }
            }
            else if (cmdBuf == 't')
            {
                if (valBuf > 3 || valBuf < 1)
                {
                    break;
                }

                temp = panggilAntrian(&b, 'T', valBuf);
                if (temp.kode != 'E')
                {
                    printf("%c-%d ke Teller%d\n", temp.kode, temp.noAntrian, valBuf);
                }
            }
            break;

        case 's':
            printStatus(b);
            break;

        default:
            break;
        }

        if (cmdBuf == 'q')
        {
            break;
        }
        }

    return 0;
}
