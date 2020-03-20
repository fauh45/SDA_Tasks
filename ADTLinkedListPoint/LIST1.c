/* File :  list1.c   					*/
/* Desk :  body list  berkait dgn representasi fisik    */
/*         pointer; 					*/
/* 	   Representasi address dgn pointer 		*/
/*	   infotype adalah integer			*/
/* Oleh :  ANI RAHMANI / 23501007 	  		*/
/* Tgl  :  25/10/01					*/
/* Dimodifikasi : 20/03/20 */

/* body dari List1.h   */

#ifndef list1_C
#define list1_C

#include "boolean.h"
#include "list1.h"
#include <stdlib.h>
#include <stdio.h>

/* ** Prototype   **  */
/* ** Test List Kosong **  */
boolean ListEmpty(List L)
{ /*  Mengirim true jika List kosong  */

	return (First(L) == Nil);
}

/* Pembuatan  List Kosong  */
void CreateList(List *L)
{ /* I.S  :  Sembarang    		*/
	/* F.S  :  Terbentuk  List kosong  	*/
	First(*L) = Nil;
}

/* ********  MANAJEMEN MEMORY  ********* */
address Alokasi(infotype X)
{ /* Mengirimkan  address  hasil alokasi    sebuah elemen */
	/* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
	/* menghasilkan   P,  maka info(P)=X,  Next(P)=Nil;               */
	/* Jika alokasi  gagal,  mengirimkan  Nil 			   */
	address P;
	P = (address)malloc(sizeof(ElmtList));
	if (P != Nil)
	{ /* Berhasil  */
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi(address *P)
{ /* I.S  : P terdefinisi      				*/
	/* F.S  : P dikembalikan ke  sistem 			*/
	/*   	    Melakukan dealokasi, pengembalian address P */
	Next(*P) = Nil;
	free(*P);
}

/*   ** PENCARIAN SEBUAH ELEMEN LIST **   */
address Search1(List L, infotype X)
{ /* Mencari apakah  ada elemen list dengan info(P)=X   */
	/* Jika ada, mengirimkan  address dgn info(P)=X       */
	/* Jika  tidak ada, mengirimkan Nil 			 */
	/* Skema dengan boolean. Berlaku untuk List kosong  	 */
	address P = First(L);
	boolean found = false;

	while ((P != Nil) && (!found))
	{
		if (pointEQ(Info(P), X))
		{
			{
				found = true;
			}
		}
		else
		{
			P = Next(P);
		}
	} /*P=Nil or  found  */
	return P;
}

address Search2(List L, infotype X)
{ /* Mencari apakah  ada elemen list dengan info(P)=X   */
	/* Jika ada, mengirimkan  address dgn info(P)=X       */
	/* Jika  tidak ada, mengirimkan Nil 			 */
	/* Skema tanpa boolean. Tdk berlaku u/ List kosong  	 */
	address P;
	if (First(L) != Nil)
	{
		return Nil;
	}
	else
	{
		P = First(L);
		while ((Next(P) != Nil) && (!(pointEQ(Info(P), X))))
		{
			P = Next(P);
		} /* Next(P)==Nil or Info(P)==X */
		if (pointEQ(Info(P), X))
		{
			return P;
		}
		else
		{
			return Nil;
		}
	}
	return P;
}

boolean FSearch(List L, address P)
{ /* Mencari apakah ada elemen List yang beralamat P  */
	/* Mengirimkan true jika ada, false jika tidak ada  */
	/* List Tidak mungkin kosong  */

	address PTemp = First(L);
	boolean found = false;

	while ((PTemp != Nil) && (!found))
	{
		if (PTemp == P)
		{
			found = true;
		}
		else
		{
			PTemp = Next(PTemp);
		}

	} /* PTemp==Nil or found / ketemu */
	return found;
}

address SearchPrec(List L, infotype X)
{ /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
	/* Mencari apakah ada elemen List dengan info(P)=X	       */
	/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P   */
	/* dan Info(P)=X; Jika tidak ada mengirimkan Nil	       */
	/* Jika P adalah  elemen pertama, maka Prec=Nil	       */
	address Prec;
	address P1;

	P1 = First(L);
	if (Next(P1) == Nil)
	{ /* List hanya berisi 1 elemen */
		Prec = Nil;
	}
	else
	{
		P1 = First(L);
		while ((Next(P1) != Nil) && (!(pointEQ(Info(P1), X))))
		{
			Prec = P1;
			P1 = Next(P1);
		} /* Next(P)==Nil or Info(P)==X */

		if (pointEQ(Info(P1), X))
		{ /* Ketemu Info (P)== X */
			return Prec;
		}
		else
		{
			return Nil; /* tidak ada X di List */
		}
	} /* else */
}

/* ** PRIMITIF BERDASARKAN NILAI ** */

/* ** Penambahan Elemen ** */
void InsVFirst(List *L, infotype X)
{ /* I.S  : L mungkin kosong          */
	/* F.S  : Melakukan alokasi sebuah elemen dan             */
	/*        menambahkan elemen pertama dengan nilai X jika  */
	/*        Alokasi berhasil 				     */
	address P = Alokasi(X);
	if (P != Nil)
	{ /* Alokasi Berhasil */
		InsertFirst(&(*L), P);
	}
}

void InsVLast(List *L, infotype X)
{ /* I.S  : L mungkin kosong          */
	/* F.S  : Melakukan alokasi sebuah elemen dan                */
	/*        menambahkan elemen list di akhir; elemen terakhir  */
	/*        yang baru bernilai X jika alokasi berhasil,        */
	/*	    Jika alokasi gagal: I.S = F.S		       */

	address P = Alokasi(X);
	if (P != Nil)
	{
		InsertLast(&(*L), P);
	}
}

/* *** Penghapusan Elemen  ***  */

void DelVFirst(List *L, infotype *X)
{ /* I.S    : List tidak kosong  		                 */
	/* F.S    : Elemen pertama List dihapus, nilai info disimpan   */
	/*	      pada X dan alamat elemen pertama  di-dealokasi 	 */
	/* Kamus */
	address P;

	DelFirst(&(*L), &P); /* Hapus elemem pertama, blm didealokasi */
	*X = Info(P);		 /* info dari First disimpan di X       */
	Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
{ /* I.S    : List tidak kosong  		                 */
	/* F.S    : Elemen terakhir list dihapus, nilai info disimpan */
	/*	      pada X dan alamat elemen terakhir di-dealokasi 	 */
	address P;
	DelLast(&(*L), &P);
	/* Hapus Elemen Terakhir, addressnya disimpan di P, */
	/* Belum diDealokasi, masih bisa dibaca isinya      */
	*X = Info(P); /* Info dari address P, ditampung  */
	Dealokasi(&P);
}

/* *******  PRIMITIF BERDASARKAN ALAMAT ********	*/
/* Penambahan Elemen Berdasarkan Alamat 		*/

void InsertFirst(List *L, address P)
{ /* I.S   : Sembarang, P sudah dialokasi		*/
	/* F.S   : Menambahkan elemen ber-address P, sebagai  */
	/*         elemen pertama				*/
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
{ /* I.S   : Prec pastilah elemen  dan bukan elemen terakhir  */
	/*         P sudah dialokasi 					  */
	/* F.S   : Insert P sebagai elemen sesudah elemen beralamat Prec*/
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast(List *L, address P)
{ /* I.S   : Sembarang, P sudah dialokasi			*/
	/* F.S   : P ditambahkan  sebagai elemen terakhir yang baru	*/

	address Last;
	if (ListEmpty(*L))
	{ /* Jika kosong, Insert elemen pertama */
		InsertFirst(&(*L), P);
	}
	else
	{ /* tdk kosong */
		Last = First(*L);
		while (Next(Last) != Nil)
		{ /* menuju ke last */
			Last = Next(Last);
		} /* Next(Last)==Nil */

		Next(Last) = P;
	}
}

/* ****** PENGHAPUSAN SEBUAH ELEMEN	*********   */
void DelFirst(List *L, address *P)
{ /* I.S   : List tidak kosong 	*/
	/* F.S   : P adalah alamat elemen pertama list sebelum penghapusan */
	/*         Elemen List berkurang satu (mungkin menjadi kosong)     */
	/* First elemen yang baru adalah suksesor elemen pertama yang lama */

	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}

void DelP(List *L, infotype X)
{ /* I.S   : Sembarang  */
	/* F.S   : Jika ada elemen  list beraddress P,dengan info (P)=X    */
	/*         Maka P dihapus dari List dan di-dealokasi		     */
	/*	     Jika tidak ada elemen List dengan info(P)=X, maka list  */
	/*         tetap. List mungkin menjadi kosomg karena penghapusan   */
	address P = First(*L);

	while ((Next(P) != Nil) && (!(pointEQ(Info(P), X))))
	{
		P = Next(P);
	} /*Next(P)=Nil or Info(P)= X */

	if (pointEQ(Info(P), X))
	{
		Dealokasi(&P);
	}
}

void DelLast(List *L, address *P)
{ /* I.S   : List tidak kosong  */
	/* F.S   : P adalah alamat elemen terakhir list sebelum penghapusan */
	/*	     Elemen list berkurang 1 (mungkin menjadi kosong)	      */
	/*         Last elemen baru adalah predessesor elemen pertama yang  */
	/*         lama, jika  ada					      */

	/* Kamus */
	address Last, PrecLast;

	Last = First(*L);
	/* dari catatan di kelas */
	if (Next(Last) == Nil)
	{ /* hanya 1 elemen */
		DelFirst(&(*L), &(Last));
	}
	else
	{ /* Lebih dr 1 elemen */
		PrecLast = Nil;
		while (Next(Last) != Nil)
		{ /* Maju sampai elemen terakhir */
			PrecLast = Last;
			Last = Next(Last);
		} /* Next(Last)=Nil */
		*P = Last;
		Next(PrecLast) = Nil;
	}
}

void DelAfter(List *L, address *Pdel, address Prec)
{ /* I.S   : List tidak kosong, Prec adalah anggota List	*/
	/* F.S   : Menghapus Next(Prec) :				*/
	/*         Pdel adalah alamat elemen List yang dihapus	*/
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
}

/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(List L)
{ /* I.S   : List mungkin kosong 	*/
	/* F.S   : Jika list tidak kosong, semua info yang disimpan pada */
	/*         elemen list di-print			  	   */
	/*         Jika list kosong, hanya menuliskan "List Kosong"	   */
	int i;
	address P = First(L);
	if (P == Nil)
	{
		printf("List Kosong !\n");
	}
	else
	{ /* List tidak kosong */
		printf("[ ");
		do
		{
			PrintPoint(Info(P));
			P = Next(P);
			i++;
		} while (P != Nil);
		printf("]");
	}
	printf("\n");
}

int NbElmt(List L)
{ /* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */
	address P;
	int NbEl = 0;
	if (ListEmpty(L))
	{
		return 0;
	}
	else
	{ /* Tidak kosong */
		P = First(L);
		do
		{
			NbEl++;
			P = Next(P);
		} while (P != Nil);
	}
	return NbEl;
}

infotype Max(List L)
{ /* Mengirimkan nilai info(P) yang maksimum */

	address P;
	infotype MMax;
	if (!ListEmpty(L))
	{
		P = First(L);
		MMax = Info(P);
		while (Next(P) != Nil)
		{
			P = Next(P);
			if (pointBT(Info(P), MMax))
			{
				MMax = Info(P);
			}
		} /* Next(P)==Nil */
	}
	return MMax;
}

address AdrMax(List L)
{ /* mengirimkan address P, dengan info (P) yang maksimum */

	address PMax, P;
	infotype Max;
	if (!ListEmpty(L))
	{
		P = First(L);
		Max = Info(P);
		while (Next(P) != Nil)
		{
			P = Next(P);
			if (pointBT(Info(P), Max))
			{
				Max = Info(P);
				PMax = P;
			}
		} /* Next(P)==Nil */
	}
	return PMax;
}

infotype Min(List L)
{ /* mengirimkan nilai info(P), yang minimum    */

	address P;
	infotype MMin;
	if (!ListEmpty(L))
	{
		P = First(L);
		MMin = Info(P);
		while (Next(P) != Nil)
		{
			P = Next(P);
			if (pointLT(Info(P), MMin))
			{
				MMin = Info(P);
			}
		} /* Next(P)==Nil */
	}
	return MMin;
}

address AdrMin(List L)
{ /* mengirimkan address P, dengan info(P) yang minimum */

	address PMin, P;
	infotype Min;
	if (!ListEmpty(L))
	{
		P = First(L);
		Min = Info(P);
		while (Next(P) != Nil)
		{
			P = Next(P);
			if (pointLT(Info(P), Min))
			{
				Min = Info(P);
				PMin = P;
			}
		}
	}
	return PMin;
}

float Average(List L)
{ /* mengirimkan nilai rata-rata info(P)	*/
	address P;
	infotype Count;
	int NbEl;
	float avg;

	if (!ListEmpty(L))
	{ /* Tidak kosong */
		P = First(L);
		Count = Info(P);
		NbEl = 1;
		while (Next(P) != Nil)
		{
			P = Next(P);
			Count.x = Count.x + Info(P).x;
			Count.y = Count.y + Info(P).y;
			NbEl++;
		} /*Next(P) == Nil */
		avg = (float)(Count.x + Count.y) / (float)(NbEl * 2);
	}
	return avg;
}

unsigned int jmlDiKuadran(List L, int K)
/* mengrimkan banyak point di K */
{
	if (K < 1 || K > 4)
	{
		return 0;
	}

	address P;
	int count = 0;

	if (!ListEmpty(L))
	{
		P = First(L);
		while (Next(P) != Nil)
		{
			if (Kuadran(Info(P)) == K)
			{
				PrintPoint(Info(P));
				count++;
			}

			P = Next(P);
		}
	}
	else
	{
		printf("List Kosong!");
	}

	return count;
}
/******************************************************/
/***   		PROSES TERHADAP LIST		    ***/
/******************************************************/
void DelAll(List *L)
{ /* Delete semua elemen list, dan alamat elemen di-dealokasi */
	infotype X;
	while (!ListEmpty(*L))
	{
		DelVFirst(&(*L), &X);
	} /* kosong */
}

void InversList(List *L)
{ /* I.S   : sembarang  			*/
	/* F.S   : elemen list  dibalik		*/
	/*	   elemen terakhir menjadi elemen pertama, dst    */
	/*	   Membalik elemen list, tanpa alokasi/dealokasi  */

	/* Kamus */
	List LTemp;
	address P;

	/* Algoritma */
	CreateList(&LTemp);
	while (First(*L) != Nil)
	{
		DelFirst(&(*L), &P);
		Next(P) = Nil;
		InsertFirst(&LTemp, P);
	}
	First(*L) = First(LTemp);
}

List FInversList(List L)
{ /* mengirimkan list baru (LB), hasil invers dari L 	*/
	/* dengan Alokasi 					*/

	/* List L tidak kosong ; min 1 elemen				*/

	/* Kamus */
	List LB;
	address P, PB;
	infotype X;

	/* Algoritma */
	P = First(L);
	CreateList(&LB);
	do
	{
		X = Info(P);
		PB = Alokasi(X);
		if (PB != Nil)
		{ /* berhasil alokasi */
			InsertLast(&LB, PB);
			P = Next(P);
		}
		else
		{ /* alokasi gagal */
			DelAll(&LB);
			First(LB) = Nil;
		}
	} while (P != Nil);
	return LB;
}

void CopyList(List L1, List *L2)
{ /* I.S   : L1 sembarang 				*/
	/* F.S   : L1 dan L2 menunjuk ke list yang sama 	*/
	/*         tidak ada alokasi/dealokasi 		*/
	*L2 = L1;
}

List FCopyList(List L)
{ /* Mengirimkan list yang merupakan salinan L  	*/
}

List FCopyListCustomCondition(List L1, boolean (*condition)(infotype P))
/* Mengirimkan list yang merupakan salinan L dan memenuhi kondisi dari fungsi*/
{
	List L;
	CreateList(&L);
	address P = First(L1);

	if (P == Nil)
	{
		printf("List kosong!\n");
	}
	else
	{
		do
		{
			if (condition(Info(P)))
			{
				InsVLast(&L, Info(P));
			}

			P = Next(P);
		} while (P != Nil);
	}

	return L;
}

void CpAlokList(List Lin, List *Lout)
{ /* I.S   : Lin sembarang				    */
	/* F.S   : Jika semua alokasi berhasil, maka Lout berisi  */
	/*         hasil copy Lin. Jika ada alokasi yang  gagal   */
	/*         maka Lout=Nil, dan semua elemen yang terlanjur */
	/*	   dialokasi, didealokasi dengan melakukan alokasi  */
	/*	   elemen. Lout adalah List kosong, jika ada alokasi*/
	/*	   elemen yang gagal				    */

	/* Kamus */
	address P, Pout;
	infotype X;

	/* ALgoritma */
	if (!ListEmpty(Lin))
	{ /* tidak kosong */

		CreateList(&(*Lout));
		P = First(Lin);
		do
		{
			X = Info(P);
			Pout = Alokasi(X);
			if (Pout != Nil)
			{ /* Alokasi berhasil */
				InsertLast(&(*Lout), Pout);
				P = Next(P);
			}
			else
			{ /* Alokasi Pout gagal */
				DelAll(&(*Lout));
				First(*Lout) = Nil;
				break;
			}
		} while (Next(P) != Nil);
	}
}

void konkat(List L1, List L2, List *L3)
{ /* I.S   : L1 dan L2 sembarang			      */
	/* F.S   : L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 &  */
	/*	   L2. Jika semua alokasi berhasil, maka L3  adalah   */
	/*	   hasil konkatenasi. Jika ada alokasi yang gagal,    */
	/*	   semua elemen yang sudah dialokasi, di-dealokasi dan*/
	/*	   L3=Nil					      */
	/*		
/*      L1, dan L2 tidak kosong */

	/* Kamus */
	address P1, P2, P3;
	infotype X1, X2;

	/* Algoritma */
	CreateList(&(*L3));

	/* Mengisi L3 dengan L1 */
	P1 = First(L1);
	do
	{ /* L1 minimal 1 elemen */
		X1 = Info(P1);
		P3 = Alokasi(X1);
		if (P3 != Nil)
		{ /* Alokasi L3 berhasil */
			InsertLast(&(*L3), P3);
			P1 = Next(P1);
		}
		else
		{ /* Alokasi gagal ; L3 di-dealokasi semua */
			DelAll(&(*L3));
			First(*L3) = Nil;
			break;
		}
	} while (Next(P1) != Nil);

	/* Mengisi L3 dengan L2 */
	P2 = First(L2);
	do
	{ /* L2 minimal 1 elemen */
		X2 = Info(P2);
		P3 = Alokasi(X2);
		if (P3 != Nil)
		{
			InsertLast(&(*L3), P3);
			P2 = Next(P2);
		}
		else
		{ /* Alokasi L3 gagal */
			DelAll(&(*L3));
			First(*L3) = Nil;
			break;
		}
	} while (Next(P2) != Nil);
}

void konkat1(List *L1, List *L2, List *L3)
{ /* I.S  : L1 dan L2 sembarang	; 			  */
	/* F.S  : L1 dan L2 kosong,  L3 adalah hasil konkatenasi*/
	/*	  L1 & L2, 					  */
	/* Konkatenasi 2 buah list : L1 dan L2 menghasilkan L3  */
	/* yang baru (dengan elemen list L1 dan L2 menjadi      */
	/* List kosong. Tidak ada alokasi/dealokasi  		  */

	address P1, P2, P3;
	infotype X1, X2, X3;

	CreateList(&(*L3));

	while (First(*L1) != Nil) /* L1 belum kosong */
	{
		DelFirst(&(*L1), &P1);
		InsertLast(&(*L3), P1);
	} /* First(L1) == Nil ; Kosong */

	while (First(*L2) != Nil) /* L2 belum kosong */
	{
		DelFirst(&(*L2), &P2);
		InsertLast(&(*L3), P2);
	} /* First (L2) == Nil ; kosong */
}

void PecahList(List *L1, List *L2, List L)
{ /* I.S  : L mungkin kosong  */
	/* F.S  : Berdasarkan L, dibentuk 2 buah list L1 dan L2     */
	/*        L tidak berubah. Untuk membentuk L1 dan L2 harus  */
	/*	  alokasi. L1 berisi separuh elemen  L dan L2 berisi  */
	/*	  sisa elemen L. Jika elemen L ganjil, maka separuh   */
	/* 	  adalah NbElmt(L)div 2				      */

	/* Kamus */
	address P, P1, P2;
	infotype X1, X2;

	int Nb, tengah;

	/* ALgoritma */
	if (!ListEmpty(L))
	{ /* tidak kosong ; minimal 1 elemen    */
		CreateList(&(*L1));

		if (NbElmt(L) == 1)
		{ /* Hanya L1 yang dapat diisi 1 elm, dari L */
			First(*L1) = First(L);
		}
		else /* L1 beirisi > 1 elemen */
		{
			tengah = NbElmt(L) / 2;
			P = First(L);
			Nb = 1;

			do /* mengisi L1 */
			{
				X1 = Info(P);
				P1 = Alokasi(X1);
				if (P1 != Nil)
				{
					InsertLast(&(*L1), P1);
					P = Next(P);
					Nb++;
				}
				else
				{ /* alokasi gagal; semua di-dealokasi */
					DelAll(&(*L1));
					First(*L1) = Nil;
					break;
				}
			} while (Nb <= tengah);

			do /* Mengisi L2 */
			{
				X2 = Info(P);
				P2 = Alokasi(X2);
				if (P2 != Nil)
				{
					InsertLast(&(*L2), P2);
					P = Next(P);
				}
				else
				{
					DelAll(&(*L2));
					First(*L2) = Nil;
					break;
				}
			} while (Next(P) != Nil);
		} /* End ; L > 1 elemen */
	}
	else
	{ /* First(L) == Nil */
		printf("List tidak dapat dipecah ! Kosong !\n");
	}
}
#endif
