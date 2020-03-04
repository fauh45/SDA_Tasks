#include <stdio.h>
#include "date.h"

/*********** Operasi Primitif ************/
void MakeDate(DATE *D)
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
{
	D->Tgl = 1;
	D->Bln = 1;
	D->Thn = 1900;
}

DATE CreateDate(int Tanggal, int Bulan, int Tahun)
/* Constructor Membentuk sebuah DATE, dengan nilai dari user, melalui fungsi */
{
	DATE date;
	date.Tgl = 1;
	date.Bln = 1;
	date.Thn = 1900;

	return date;
}

/******* Selector komponen -- Get/Set **********/
int GetTgl(DATE D)
/* Mengambil bagian Tgl dari date */
{
	return D.Tgl;
}

int GetBln(DATE D)
/* Mengambil bagian Bln dari date */
{
	return D.Bln;
}

int GetThn(DATE D)
/* Mengambil bagian Thn dari date */
{
	return D.Thn;
}

/****** Pengubah komponen ******/
void SetTgl(int NewTgl, DATE *D)
/* Memberi nilai untuk Tgl */
{
	DATE temp;
	temp.Tgl = NewTgl;
	D->Tgl = isValid(temp) ? NewTgl : D->Tgl;
}

void SetBln(int NewBln, DATE *D)
/* Memberi nilai untuk Bln */
{
	if (NewBln > 12)
	{
		return;
	}

	D->Bln = NewBln;
}

void SetThn(int NewThn, DATE *D)
/* Memberi nilai untuk Thn */
{
	D->Thn = NewThn;
}

/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
void BacaDate(DATE *D)
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
{
	DATE temp;
	printf("Tanggal : ");
	scanf("%d", &temp.Tgl);
	printf("Bulan : ");
	scanf("%d", &temp.Bln);
	printf("Tahun : ");
	scanf("%d", &temp.Bln);

	D = isValid(temp) ? &temp : D;
}

boolean isValid(DATE D)
/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
{
	if (D.Bln > 12)
	{
		return false;
	}

	switch (D.Bln)
	{
	case 2:
		return isKabisat(D) ? (D.Tgl < 29) : (D.Tgl < 28);
		break;

	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return D.Tgl < 31;
		break;

	default:
		return D.Tgl < 30;
		break;
	}
}

void PrintDate(DATE D)
/* Print nilai D dengan format dd/mm/yyyy */
{
	printf("%02d/%02d/%04d", D.Tgl, D.Bln, D.Thn);
}

/****** Operator Relasional ******/
boolean isKabisat(DATE D)
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja */
{
	if (D.Thn % 400 == 0)
	{
		return true;
	}
	else if (D.Thn % 100 == 0)
	{
		return false;
	}
	else if (D.Thn % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/***** Predikat lain *******/
int TglAkhir(DATE D)
/* Memberikan tanggal terakhir dari sebuah bulan */
{
	switch (D.Bln)
	{
	case 2:
		return isKabisat(D) ? 29 : 28;
		break;

	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;

	default:
		return 30;
		break;
	}
}

void DateBefore(DATE D)
/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */
{
	if (D.Bln == 1 && D.Tgl == 1)
	{
		D.Thn--;
		D.Bln = 12;
		D.Tgl = 31;

		PrintDate(D);
	}
	else if (D.Tgl == 1)
	{
		D.Bln--;
		D.Tgl = TglAkhir(D);

		PrintDate(D);
	}
	else
	{
		D.Tgl--;

		PrintDate(D);
	}
}

void NextDate(DATE D)
/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */
{
	if (D.Bln == 12 && D.Tgl == 31)
	{
		D.Thn++;
		D.Bln = 1;
		D.Tgl = 1;

		PrintDate(D);
	}
	else if (D.Tgl == TglAkhir(D))
	{
		D.Bln++;
		D.Tgl = 1;

		PrintDate(D);
	}
	else
	{
		D.Tgl++;

		PrintDate(D);
	}
}

void SelisihDate(DATE D1, DATE D2)
/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */
{
	if (D2.Thn > D1.Thn)
	{
		DATE temp;
		temp = D1;
		D1 = D2;
		D2 = temp;
	} else if (D2.Thn == D1.Thn && D2.Bln > D1.Bln)
	{
		DATE temp;
		temp = D1;
		D1 = D2;
		D2 = temp;
	}
	
	int dayDiff = (D1.Thn - D2.Thn) * 365;

	while (D2.Bln != D1.Bln)
    {
        dayDiff += TglAkhir(D2);
        D2.Bln++;
    }

	printf("%d Hari", dayDiff);
}