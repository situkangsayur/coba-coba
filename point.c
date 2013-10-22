/*  File 	: point.c				*/
/*  Dibuat Oleh : Alif Finandhita (23511034) 		*/
/*  Tanggal 	: 17 Oktober 2013			*/

#include <stdio.h>
#include "point.h"

POINT MakePOINT(int X, int Y) {
	POINT P;
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

POINT AssignPOINT(POINT P) {
	return MakePOINT(Absis(P), Ordinat(P));
}

void BacaPOINT(POINT* P) {
	int X, Y;
	scanf("%d %d\n", &X, &Y);
	(*P) = MakePOINT(X, Y);
}

void TulisPOINT(POINT P) {
	printf("(%d,%d)", Absis(P), Ordinat(P));
}

POINT PlusPOINT(POINT P1, POINT P2) {
	return MakePOINT(Absis(P1) + Absis(P2), Ordinat(P1) + Ordinat(P2));
}

boolean POINTEQ(POINT P1, POINT P2) {
	return ((Absis(P1) == Absis(P2))&&(Ordinat(P1)==Ordinat(P2)));
}

boolean IsOrigin(POINT P) {
	return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

int Kuadran(POINT P) {
	if ((Absis(P) > 0) && (Ordinat(P) > 0)) {
		return 1;
	} else if ((Absis(P) < 0) && (Ordinat(P) > 0)) {
		return 2;
	} else if ((Absis(P) < 0) && (Ordinat(P) < 0)) {
		return 3;
	} else if ((Absis(P) > 0) && (Ordinat(P) < 0)) {
		return 4;
	}
}

POINT MidPOINT(POINT P1, POINT P2) {
	return MakePOINT((Absis(P1) + Absis(P2))/2,(Ordinat(P1)+Ordinat(P2))/2);}

int ExactEQ(POINT P1, POINT P2) {
	return ((Absis(P1) == Absis(P2))&&(Ordinat(P1)==Ordinat(P2)));
}

int EQ(POINT P1, POINT P2, int d) {
	return ((abs(Absis(P1)) - Absis(P2))<=d&&((abs(Absis(P1))-Absis(P2))<=d));
}

void CopyPOINT(POINT* P1, POINT P2) {
	Absis(*P1) = Absis(P2);
	Ordinat(*P1) = Ordinat(P2);
}

void Move(POINT *P, int DeltaX, int DeltaY) {
	Absis(*P) = Absis(*P) + DeltaX;
	Ordinat(*P) = Ordinat(*P) + DeltaY;
}

void GetMinPOINT(POINT *P1,POINT  P2) {
	if (Absis(*P1) < Absis(P2)) {
		Absis(*P1) = Absis(P2);
	}
	if (Ordinat(*P1) < Ordinat(P2)) {
		Ordinat(*P1) = Ordinat(P2);
	}
}

void GetMaxPOINT(POINT *P1, POINT P2) {
	if (Absis(*P1) > Absis(P2)) {
		Absis(*P1) = Absis(P2);
	}
	if (Ordinat(*P1) > Ordinat(P2)) {
		Ordinat(*P1) = Ordinat(P2);
	}
}

