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

	scanf("%d\n", &nTP);
	CreateArr(&TP, nTP);
	max = MakePOINT(-1, -1);
	min = MakePOINT(sizeof(int), sizeof(int));
	for (i = 0; i < nTP; i++) {
		scanf("%d %d %d\n", &no, &X, &Y);
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


	scanf("%d\n", &nRI);
	CreateArr(&RI, nRI);
	for (i = 0; i < nRI; i++) {
		scanf("%d %d %d\n", &no, &X, &Y);
		SetPOINT(&RI, MakePOINT(X, Y), no);
	}

	if (!IsEmpty(TP) && !IsEmpty(RI)) {
		printf("not empty\n");
		if (GetNB(TP) != GetNB(RI)) {
			printf("jumlah tidak sama\n");
			if ((ExactEQ(TP.T[0], RI.T[0]) == 1)
					&& (ExactEQ(TP.T[GetNB(TP) - 1], RI.T[GetNB(TP) - 1]) == 1)) {
				printf("TP & RI sama\n");
				for (i = 1; i < GetNB(RI) - 2; i++) {
					status = true;
					if ((RI.T[i].X > max.X) || (RI.T[i].Y > max.Y)
							|| (RI.T[i].X < min.X) || (RI.T[i].Y < min.Y)) {
						status = false;
						printf("break\n");
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
			printf("else\n");
			if (ExactEQ(TP.T[0], RI.T[0])
					&& ExactEQ(TP.T[GetNB(TP) - 1], RI.T[GetNB(TP) - 1])) {
				printf("ujungnya sama\n");
				for (i = 0; i < GetNB(RI) - 1; i++) {

					printf("cek setiap point\n");
					if (ExactEQ(TP.T[i], RI.T[i]) == 1) {
						countPass++;
						printf("pas\n");
					} else if (EQ(TP.T[i], RI.T[i], d) == 1) {
						countPass++;
						toleran = true;
						printf("toleran\n");
					} else if ((RI.T[i].X > max.X) || (RI.T[i].Y > max.Y)
							|| (RI.T[i].X < min.X) || (RI.T[i].Y < min.Y)) {
						pass++;
						printf("passing\n");
						if (pass == 2) {
							printf("pass break <2\n");
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

	printf("%s \n",result);

	return 0;
}

