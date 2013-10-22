/*  File 	: arrpos.c				*/
/*  Dibuat Oleh : Alif Finandhita (23511034) 		*/
/*  Tanggal 	: 17 Oktober 2013			*/

#include <stdlib.h>
#include "arrpos.h"

int IsEmpty (ArrPOS TP){
	return(TP.NBPoint==0);
}

void CreateArr (ArrPOS * TP, int N){
	if(N>0){
		(*TP).T=(POINT*)malloc(N*sizeof(POINT));
		(*TP).NBPoint=N;
	}else{
		(*TP).T==NULL;
	}
}

void DeallocArr (ArrPOS * TP){
	if((*TP).T!=NULL){
		free((*TP).T);
	}	
}

int GetNB (ArrPOS TP){
	return TP.NBPoint;
}

POINT GetPos (ArrPOS TP, int i){
	return (TP.T[i]);
}

void SetPOINT(ArrPOS *TP, POINT IN, int index){
	(*TP).T[index] = IN;
}

