#include "utils.h"


void scambia(void *a, void *b, size_t data_size) {
	char tmp;
	char *pa = a;
	char *pb = b;
	while (data_size--) {
		tmp = pa[data_size];
		pa[data_size] = pb[data_size];
		pb[data_size] = tmp;
	}
}