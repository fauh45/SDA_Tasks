#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"

void MakePoint(POINT *P, int XX, int YY)
/*Prosedur untuk membuat POINT dengan nilai dari user*/
{
    (*P).x = XX;
    (*P).y = YY;
}

POINT CreatePoint(int XX, int YY)
/*Fungsi untuk menghasilkan sebuah POINT berdasarkan nilai-nilai dari user*/
{
    POINT P;
    P.x = XX;
    P.y = YY;
    return P;
}

/*KELOMPOK VALIDASI*/

/*KELOMPOK PRINT/CETAK*/
void PrintPoint(POINT P)
/* Menampilkan POINT */
{
    printf("(%d, %d)\n", P.x, P.y);
}

/* KELOMPOK GET / SET */

int GetX(POINT P)
/*Mengembalikan nilai x dari sebuah POINT */
{
    return P.x;
}

void SetX(POINT *P, int newX)
/* Mengubah nilai X dari sebuah POINT */
{
    (*P).x = newX;
}

int GetY(POINT P)
/*Mengembalikan nilai y dari sebuah POINT */
{
    return P.y;
}

void SetY(POINT *P, int newY)
/* Mengubah nilai Y dari sebuah POINT */
{
    (*P).y = newY;
}

void ReSet(POINT *P)
/* Mengubah koordinat sebuah POINT menjadi 0,0 */
{
    (*P).x = 0;
    (*P).y = 0;
}

/*KELOMPOK LAIN */
int Kuadran(POINT P)
/* menghasilkan kuadran dari POINT P*/
{
    if (P.x == 0 || P.y == 0)
    {
        return -1;
    }
    else
    {
        if (P.x > 0)
        {
            if (P.y > 0)
            {
                return 1;
            }
            else
            {
                return 4;
            }
        }
        else if (P.y > 0)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}

boolean IsOnSumbuX(POINT P)
/* Mengirimkan True jika P ada di sumbu X  */
{
    return !P.y;
}

boolean IsOnSumbuY(POINT P)
/* Mengirimkan True jika P ada di sumbu Y  */
{
    return !P.x;
}

boolean IsOrigin(POINT P)
/* Mengirimkan True jika P ada di titik pusat */
{
    return !P.x && !P.y;
}

void NextX(POINT *PP)
/* Menggeser P 1 koordinat ke kanan*/
{
    ++(*PP).x;
}

void NextX_N(POINT *PP, int N)
/* Menggeser P, sejauh N koordinat ke kanan*/
{
    (*PP).x += N;
}

void PrevX(POINT *P)
/* Menggeser P 1 koordinat ke kiri*/
{
    --(*P).x;
}

void PrevX_N(POINT *P, int N)
/* Menggeser P, sejauh N koordinat ke kiri */
{
    (*P).x -= N;
}

/*MENGHITUNG JARAK DUA POINT */
int Jarak(POINT P1, POINT P2)
/*Menghasilkan jarak P1 dan P2 */
{
    return sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
}