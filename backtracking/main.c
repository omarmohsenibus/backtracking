#include "backtracking.h"

int main(void) {
	bool vcurr[] = { false, false, false, false };
	unsigned int nsol = 0;
	ombrelloni(2, 4, 0, vcurr, 0, &nsol);
	return 0;
}