/*  File 	: point.c				*/
/*  Dibuat Oleh : Alif Finandhita (23511034) 		*/
/*  Tanggal 	: 17 Oktober 2013			*/

#include <stdio.h>
#include "arrpos.h"

int main() {
	int i, nRI, nTP, X, Y, no, countPass = 0, pass = 0;
	POINT min, max;
	const int d = 1;
	ArrPOS TP, RI, bound;
	boolean toleran = false, status = false;
	char *result = "Tidak-OK";

	//sample
	POINT rute[] = { MakePOINT(5, 5), MakePOINT(6, 6), MakePOINT(8, 7),
			MakePOINT(9, 9) };
	POINT rute2[] = { MakePOINT(5, 5), MakePOINT(8, 7), MakePOINT(9, 9) };

	//jika ingin menggunakan scanf, buka komen scanf dan hilangkan 1 code dibawahnya
//	scanf("%d", &nTP);
	nTP = sizeof(rute) / sizeof(rute[0]);

	CreateArr(&TP, nTP);
	max = MakePOINT(-1, -1);
	min = MakePOINT(sizeof(int), sizeof(int));
	for (i = 0; i < nTP; i++) {

//		scanf("%d %d %d\n", &no, &X, &Y);
//		jika ingin menggunakan scanf uncomment 1 line diatas komen ini
//		dan hapus 3 line dibawah komen ini
		no = i;
		X = rute[i].X;
		Y = rute[i].Y;

		if ((max.X == -1) && (min.X == sizeof(int))) {
			max.X = X;
			max.Y = Y;
			CopyPOINT(&min, max);
		} else {
			GetMaxPOINT(&max, MakePOINT(X, Y));
			GetMinPOINT(&min, MakePOINT(X, Y));
		}

		SetPOINT(&TP, MakePOINT(X, Y), no);
	}

//jika ingin menggunakan scanf, buka komen scanf dan hilangkan 1 code dibawahnya
//	scanf("%d", &nRI);
	nRI = sizeof(rute2) / sizeof(rute2[0]);

	CreateArr(&RI, nRI);
	for (i = 0; i < nRI; i++) {

//		scanf("%d %d %d\n", &no, &X, &Y);
//		jika ingin menggunakan scanf uncomment 1 line diatas komen ini
//		dan hapus 3 line dibawah komen ini
		no = i;
		X = rute2[i].X;
		Y = rute2[i].Y;

		SetPOINT(&RI, MakePOINT(X, Y), no);
	}

	if (!IsEmpty(TP) && !IsEmpty(RI)) {

		if (GetNB(TP) != GetNB(RI)) {

			if ((ExactEQ(TP.T[0], RI.T[0]) == 1)
					&& (ExactEQ(TP.T[GetNB(TP) - 1], RI.T[GetNB(RI) - 1]) == 1)) {

				for (i = 0; i < GetNB(RI); i++) {
					status = true;
					if ((RI.T[i].X > max.X) || (RI.T[i].Y > max.Y)
							|| (RI.T[i].X < min.X) || (RI.T[i].Y < min.Y)) {
						status = false;

						break;
					}

				}
				if (status) {
					result = "OK-1\n";
				} else {
					result = "Tidak-OK-1\n";
				}
			}
		} else {

			if (ExactEQ(TP.T[0], RI.T[0])
					&& ExactEQ(TP.T[GetNB(TP) - 1], RI.T[GetNB(RI) - 1])) {

				for (i = 0; i < GetNB(RI); i++) {

					if (ExactEQ(TP.T[i], RI.T[i]) == 1) {
						countPass++;

					} else if (EQ(TP.T[i], RI.T[i], d) == 1) {
						countPass++;
						toleran = true;

					} else if ((RI.T[i].X > max.X) || (RI.T[i].Y > max.Y)
							|| (RI.T[i].X < min.X) || (RI.T[i].Y < min.Y)) {
						pass++;
						if (pass == 2) {
							break;
						}
					}
				}
				if (countPass == GetNB(RI)) {
					result = "OK-9\n";
				} else if ((countPass == GetNB(RI)) && (toleran)) {
					result = "OK-8\n";
				} else if (pass == 2) {
					result = "Tidak-OK-8\n";
				}
			} else {
				result = "Tidak-OK-3\n";
			}
		}
	}

	printf("%s \n", result);

	return 0;
}

