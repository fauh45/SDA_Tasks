// Program : Date.h
// Deskripsi : Spesifikasi ADT Point
// oleh    : Ani Rahmani
// Tgl/Version 
//

#ifndef DATE_h
#define DATE_h

#include "boolean.h"

/***************************/
/*  Type data */
/***************************/
/* Kamus */
typedef struct {int Tgl; 
                int Bln; 
                int Thn;
               } DATE;

                                                                                                    
/***************************/
/*  S P E S I F I K A S I  */
/***************************/

/*********** Operasi Primitif ************/
void MakeDate (DATE * D);
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */

DATE CreateDate(int Tanggal, int Bulan, int Tahun);
/* Constructor Membentuk sebuah DATE, dengan nilai dari user, melalui fungsi */


/******* Selector komponen -- Get/Set **********/
int GetTgl (DATE D);
/* Mengambil bagian Tgl dari date */

int GetBln (DATE D);
/* Mengambil bagian Bln dari date */

int GetThn (DATE D);
/* Mengambil bagian Thn dari date */

/****** Pengubah komponen ******/
void SetTgl (int NewTgl, DATE * D);
/* Memberi nilai untuk Tgl */

void SetBln (int NewBln, DATE * D);
/* Memberi nilai untuk Bln */

void SetThn (int NewThn, DATE * D);
/* Memberi nilai untuk Thn */

/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
void BacaDate (DATE * D);
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */

boolean isValid(DATE D);
/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */

void PrintDate (DATE D);
/* Print nilai D dengan format dd/mm/yyyy */

/****** Operator Relasional ******/
boolean isKabisat (DATE D);
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja */

/***** Predikat lain *******/
int TglAkhir (DATE D);
/* Memberikan tanggal terakhir dari sebuah bulan */

void DateBefore (DATE D);
/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */

void NextDate (DATE D);
/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */

void SelisihDate (DATE D1, DATE D2);
/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */

#endif
