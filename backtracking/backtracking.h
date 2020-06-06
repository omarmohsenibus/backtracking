#if !defined BACKTRACKING_H
#define BACKTRACKING_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
   • k: il numero di ragazzi da posizionare;
   • n : il numero di posti disponibili in prima fila;
   • i : la posizione attuale.Si noti che questo valore corrisponde al livello dell'albero di backtrack che la funzione corrente sta esplorando;
   • vcurr : un array che indica lo stato degli ombrelloni in prima fila(ad esempio 1 =
	   occupato, 0 = libero).All'inizio dovranno essere tutti liberi:
   • cnt : un contatore che memorizza il numero di ragazzi posizionati nella soluzione corrente;
   • nsol : il numero totale di soluzioni trovate;
*/
extern void ombrelloni(int k, int n, unsigned int i, bool *vcurr, unsigned int cnt, unsigned int *nsol);

extern void backtrackTutte(int n, int i, int k, int vcurr[], int *nsol);

extern void backtrackSubSet(int n, int i, int vcurr[], int *nsol);

extern void subSetK(int n, int i, int k, int vcurr[], int count, int *nsol);

extern void permutazioni(int n, int i, int vcurr[], int* nsol);

#endif //BACKTRACKING_H