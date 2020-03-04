#include <stdio.h>
#include "Time.h"

/** Konstruktor membentuk ADT TIME **/
void CreateTIME(TIME *J, int HH, int MM, int SS)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid 
     Pre condition : HH,MM,SS valid untuk membentuk TIME
     I.S : J tidak terdefinisi, tidak diketahui nilainya
     F.S : membentuk sebuah TIME dari komponen-komponennya dengan J diinisialisasi nilainya dengan 
	   Hour = HH, Minute = MM, Second = SS 
*/
{
    if (!IsJValid(HH, MM, SS))
    {
        return;
    }

    J->Hour = HH;
    J->Minute = MM;
    J->Second = SS;
}

/*****************************************************************/

/** { Operasi terhadap komponen : selektor Get dan Set } **/
/* Selektor TIME **/
int GetHour(TIME J)
// Mengirimkan komponen Hour dari J
{
    return J.Hour;
}

int GetMinute(TIME J)
// Mengirimkan komponen Hour dari J
{
    return J.Minute;
}

int GetSecond(TIME J)
// Mengirimkan komponen Hour dari J
{
    return J.Second;
}

/* Set nilai komponen */
void SetHour(TIME *J, int newHour)
// Mengirimkan komponen Hour dari J
{
    J->Hour = newHour;
}

void SetMinute(TIME *J, int newMinute)
// Mengirimkan komponen Hour dari J
{
    J->Minute = newMinute;
}

void SetSecond(TIME *J, int newSecond)
// Mengirimkan komponen Hour dari J
{
    J->Second = newSecond;
}
/*****************************************************************/

/** {Kelompok Baca/Tulis} **/
void ReadTIME(TIME *J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan TIME yang valid */
/* Proses : mengulangi membaca komponen H,M,S sehingga membentuk J yang valid.*/
/* Tidak mungkin menghasilkan J yang tidak valid */
{
    if (J->Second > 59)
    {
        J->Second -= 60;
        J->Minute++;
    }

    if (J->Minute > 59)
    {
        J->Minute -= 60;
        J->Hour++;
    }

    if (J->Hour > 23)
    {
        J->Hour -= 24;
    }
}

void PrintTIME(TIME J)
/* I.S. : J sembarang */
/* F.S. : Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar */
/*****************************************************************/
{
    printf("%02d:%02d:%02d", J.Hour, J.Minute, J.Second);
}

/** { kelompok Validasi Type } **/
boolean IsJValid(int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah TIME */
/* Konstruktor: Membentuk sebuah TIME dari komponen-komponennya */
/*****************************************************************/
{
    return H < 24 && M < 60 && S < 60;
}

/** {Operator Relasional} **/
boolean JEQ(TIME J1, TIME J2)
/* Mengirimkan true jika Jl=J2, false jika tidak */
{
    return J1.Hour == J2.Hour && J1.Minute == J2.Minute && J1.Second == J2.Second;
}

boolean JNEQ(TIME J1, TIME J2)
/* Mengirimkan true jika Jl tidak sama dengan J2 */
{
    return !(JEQ(J1, J2));
}
boolean JLT(TIME J1, TIME J2)
/* Mengirimkan true jika J1<J2 , false jika tidak */
{
    return J2.Hour > J1.Hour ? true : (J2.Hour == J2.Hour && J2.Minute > J1.Minute) ? true : (J2.Minute == J2.Minute && J2.Second > J1.Second) ? true : false;
}

boolean JGT(TIME J1, TIME J2)
/* Mengirimkan true jika Jl>J2, false jika tidak*/
{
    return !(JLT(J1, J2)) && JNEQ(J1, J2);
}

/*****************************************************************/

/** { operator aritmatika } **/
void Reset(TIME *J)
/* I.S. J sembarang; F.S. J bernilai �nol� yaitu semua komponennya bernilai 0*/
/* Me-reset nilai J menjadi 0:0:0 */
{
    J->Hour = 0;
    J->Minute = 0;
    J->Second = 0;
}

TIME NextDetik(TIME J)
/* Mengirim 1 detik setelah J dalam bentuk TIME */
{
    if (J.Second == 59)
    {
        J.Second = 0;

        if (J.Minute == 59)
        {
            J.Minute = 0;

            if (J.Hour == 23)
            {
                J.Hour = 0;
            }
            else
            {
                J.Hour++;
            }
        }
        else
        {
            J.Minute++;
        }
    }
    else
    {
        J.Second++;
    }

    return J;
}

TIME PrevDetik(TIME J)
/* Mengirim 1 detik sebelum J dalam bentuk TIME */
{
    if (J.Second == 0)
    {
        J.Second = 59;

        if (J.Minute == 0)
        {
            J.Minute = 59;

            if (J.Hour == 0)
            {
                J.Hour = 23;
            }
            else
            {
                J.Hour--;
            }
        }
        else
        {
            J.Minute--;
        }
    }
    else
    {
        J.Second--;
    }

    return J;
}

TIME JPlus(TIME J1, TIME J2)
/* Menghasilkan Jl+J2, clalam bentuk TIME */
{
    TIME temp;

    temp.Second = J1.Second + J2.Second;
    temp.Minute = J1.Minute + J2.Minute;
    temp.Hour = J1.Hour + J2.Hour;

    if (temp.Second > 59)
    {
        temp.Second -= 59;
        temp.Minute++;
    }

    if (temp.Minute > 59)
    {
        temp.Minute -= 59;
        temp.Hour++;
    }

    if (temp.Hour > 23)
    {
        temp.Hour -= 23;
    }

    return temp;
}

TIME JMinus(TIME J1, TIME J2)
/* Menghasilkan Jl�J2, dalam bentuk TIME */
/* Precond : Jl<:J2 */
{
    if (!JLT(J1, J2))
    {
        return;
    }

    TIME temp;

    temp.Hour = J2.Hour - J1.Hour;

    if (J1.Minute > J2.Minute)
    {
        temp.Hour--;
        J2.Minute += 60;
    }

    temp.Minute = J2.Minute - J1.Minute;

    if (J1.Second > J2.Second)
    {
        temp.Minute--;
        J2.Minute += 60;
    }

    temp.Second = J2.Second - J1.Second;

    return temp;
}

TIME NextNDetik(TIME J, int N)
/* Mengirim N detik setelah J dalam bentuk TIME */
{
    J.Second += N;

    if (J.Second > 59)
    {
        J.Second = 0;
        J.Minute++;
    }

    if (J.Minute > 59)
    {
        J.Minute -= 60;
        J.Hour++;
    }

    if (J.Hour > 23)
    {
        J.Hour -= 24;
    }

    return J;
}

TIME PrevNDetik(TIME J, int N)
/* Mengirim N detik sebelum J dalam bentuk TIME */
{
    J.Second -= N;

    if (J.Second < 0)
    {
        J.Second += 60;
        J.Minute--;

        if (J.Minute < 0)
        {
            J.Minute += 60;
            J.Hour--;

            if (J.Hour < 0)
            {
                J.Hour += 24;
            }
            else
            {
                J.Hour--;
            }
        }
        else
        {
            J.Minute--;
        }
    }
    else
    {
        J.Second--;
    }

    return J;
}

long int Durasi(TIME Jaw, TIME JAkh)
/* Mengirim JAkh �JAw dlm Detik, dengen kalkulasi */
/* Hasilnya negatif jika Jaw > JAkhir */
/*****************************************************************/
{
    if (JLT(JAkh, Jaw))
    {
        TIME temp = JMinus(Jaw, JAkh);
        return (temp.Hour * 3600) + (temp.Minute * 60) + temp.Second;
    }
    else
    {
        TIME temp = JMinus(JAkh, Jaw);
        return -((temp.Hour * 3600) + (temp.Minute * 60) + temp.Second);
    }
}

/** {Kelompok Konversi Terhadap Type} **/
long int TimeToDetik(TIME J)
/* Diberikan sebuah TIME, mengkonversi menjadi Detik */
/* Rumus : detik = 3600*hour+menit*60 + detik */
/* nilai maksimum = 3600*23+59*60+59*60 */
/* hati-hati dengan representasi integer pada bahasa implementasi */
/* kebanyakan sistem mengimplementasi integer, */
/* bernilai maksimum kurang dari nilai maksimum hasil konversi */
{
    long int seconds;

    seconds = (long int) (J.Hour * 3600) + (J.Minute * 60) + J.Second;

    return seconds;
}

TIME DetikToTIME(long int N)
/* Mengirim konversi detik ke TIME. Pada beberapa bahasa, representasi integer tidak cukup untuk menampung N */
{
    TIME temp;
    temp.Hour = (int) N / 3600;
    int remainder = (int) N - (temp.Hour * 3600);
    temp.Minute = remainder / 60;
    remainder -= temp.Minute * 60;
    temp.Second = remainder;

    return temp;
}
/*****************************************************************/