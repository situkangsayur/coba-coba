/*  File 	: arrpos.h				*/
/*  Dibuat Oleh : Alif Finandhita (23511034) 		*/
/*  Tanggal 	: 17 Oktober 2013			*/

#ifndef _ARRPOS_H
#define _ARRPOS_H
#include "point.h"
#include <stdlib.h>

typedef struct { 
		POINT * T; /* dimanfaatkan mulai indeks 0..(NBPoint-1) */
		int NBPoint; 
} ArrPOS;

int IsEmpty (ArrPOS TP);
/* sebuah TP bertype ArrPOS disebut kosong jika NBPoint=0 */
/* mengirimkan 1 jika TP kosong, atau 0 jika tidak kosong */

void CreateArr (ArrPOS * TP, int N);
/* I.S. sembarang */
/* F.S. jika alokasi berhasil, menghasilkan TP dengan NBPoint = N */
/* jika alokasi gagal, menghasilkan TP dengan NBPoint = 0*/
/* Proses : jika N>0 alokasi array T sebesar N dan set NBPoint=N */
/* jika N<=0 atau alokasi gagal, hasilkan array T bernilai NULL */


void DeallocArr (ArrPOS * TP);
/* I.S. sembarang */
/* F.S. jika TP != NULL maka melakukan dealokasi array T */
/* jika TP== NULL tidak melakukan apa-apa*/

int GetNB (ArrPOS TP);
/* menghasilkan banyaknya point (ukuran) TP */

POINT GetPos (ArrPOS TP, int i);

/* menghasilkan sebuah POINT pada posisi array T[i] dari TP */
/* untuk menentukan bidang merah */
/* jika anda memerlukan tambahan fungsi, silahkan buat di sini */

void SetPOINT(ArrPOS *TP, POINT IN, int index);
/*tambah point dengan index tertentu


/* tambahan konstrain */
/* POINT pada persoalan ini selalu positif nilai X dan nilai Y nya */
/* artinya semua titik berada di kuadran-1 */

int ExactEQ (POINT P1, POINT P2);
/* P1 sama persis dengan P2 */
/* mengirim 1 jika Absis (P1)= Absis (P2) dan Ordinat(P1)= Ordinat(P2) */
/* mengirim 0 jika */

int EQ (POINT P1, POINT P2, int d);
/* P1 berdekatan dengan toleransi d dengan P2, yaitu : */
/* mengirim 1 jika |Absis(P1)-Absis(P2)| <= d dan |Ordinat(P1)-Ordinat(P2)| dengan |x| adalah nilai absolut(x)*/

#endif



