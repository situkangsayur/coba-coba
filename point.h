/*  File 	: point.h				*/
/*  Dibuat Oleh : Alif Finandhita (23511034) 		*/
/*  Tanggal 	: 17 Oktober 2013			*/


#ifndef _POINT_H
#define _POINT_H
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#include "boolean.h"

/*Definisi ABSTRACT DATA TYPE POINT */
typedef struct { int X;  /* absis  */
                int Y;  /* ordinat*/ 
               } POINT;
       
/* DEFINISI PROTOTIP PRIMITIF      */
/** Konstruktor membentuk POINT **/
POINT MakePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/** Destruktor/Dealokator: tidak perlu **/

/* Assignment Point */
POINT AssignPOINT (POINT P);
/* menghasilkan salinan Point P) */

/*** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  ***/                                               
void BacaPOINT (POINT* P);
/* Makepoint(x,y,P) membentuk P dari x dan y yang dibaca  */           
void TulisPOINT(POINT P);
/* Nilai P ditulis ke layar dg format “(X,Y)"  */             

/** Kelompok operasi aritmatika terhadap POINT */
POINT PlusPOINT(POINT P1,POINT P2);
/*Mengirimkan true jika P1 = P2: absis dan ordinatnya sama */

/** Kelompok operasi relasional terhadap POINT */
boolean POINTEQ(POINT P1, POINT P2);
/*Mengirimkan true jika P1 = P2: absis dan ordinatnya sama */

/* ** Kelompok menentukan di mana P berada*/
boolean IsOrigin (POINT P) ;
/* Menghasilkan true jika P adalah titik origin */
int Kuadran(POINT P);
/* Menghasilkan kuadran dari P: 1,2,3, atau 4*/
/* Precondition : P bukan Titik Origin, dan P tidak terletak di salah satu sumbu*/

/* ** KELOMPOK OPERASI LAIN TERHADAP TYPE */                         
POINT MidPOINT (POINT P1,POINT P2);
/* Menghitung  titik tengah antara P1 dan P2, dibulatkan ke bawah, jadi pakailah pembagian int */

void CopyPOINT (POINT* P1, POINT P2);
/* menyalin P1 ke P2, assignment P1<-- P2 */

void Move (POINT *P, int DeltaX, int DeltaY);
/*I.S. P terdefinisi*/
/*F.S. P digeser sebesar DeltaX dan ordinatnya sebesar Delta Y*/

int ExactEQ (POINT P1, POINT P2);
/* P1 sama persis dengan P2 */
/* mengirim 1 jika Absis (P1)= Absis (P2) dan Ordinat(P1)= Ordinat(P2) */
/* mengirim 0 jika */

int EQ (POINT P1, POINT P2, int d);
/* P1 berdekatan dengan toleransi d dengan P2, yaitu : */
/* mengirim 1 jika |Absis(P1)-Absis(P2)| <= d dan |Ordinat(P1)-Ordinat(P2)| dengan |x| adalah nilai absolut(x)*/

void GetMaxPOINT(POINT *P1, POINT P2);
void GetMinPOINT(POINT *P1,POINT  P2);

#endif 
