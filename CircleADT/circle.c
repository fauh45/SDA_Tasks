#include <stdio.h>
#include <math.h>
#include "circle.h"

/*KELOMPOK CREATOR */

void MakeCircle(Circle *P, int XX, int YY, float r)
/*Prosedur untuk membuat Circle dengan nilai dari user*/
{
    (*P).P.x = XX;
    (*P).P.y = YY;
    (*P).r = r;
}

Circle CreateCircle (int XX, int YY, float R)
/*Fungsi untuk menghasilkan sebuah Circle berdasarkan nilai-nilai dari user*/
{
    Circle C;
    C.P.x = XX;
    C.P.y = YY;
    C.r = R;
    return C;
}

/*KELOMPOK VALIDASI*/

/*KELOMPOK Get/Set */

float GetRadius(Circle C)
/* mengembalikan nilai radius dari sebuah Circle */
{
    return C.r;
}

void SetRadius(Circle *C1, float R)
/* Mengubah nilai Radius sebuah Circle */
{
    (*C1).r = R;
}

/*KELOMPOK PRINT/CETAK*/
void PrintCircle(Circle C)
/* Menampilkan Circle : Titik Pusat & Radius */
{
    printf("(%d, %d) %f", C.P.x, C.P.y, C.r);
}

/*KELOMPOK LAIN */
float Area(Circle C1)
/* menghasilkan nilai Luas dari Circle C1*/
{
    return M_PI * pow(C1.r, 2);
}

float Circumf(Circle C1)
/* menghasilkan nilai Keliling dari Circle */
{
    return C1.r / 2;
}

boolean CompareCircle(Circle C1, Circle C2)
/* menghasilkan True jika Luas C1 = C2, Gunakan fungsi Luas */
{
    return Area(C1) == Area(C2);
}

Circle CopyCircle(Circle C1)
/*Mengembalikan sebuah Circle */
{
    Circle C2;
    C2.P.x = C1.P.x;
    C2.P.y = C1.P.y;
    C2.r = C1.r;
    return C2;
}