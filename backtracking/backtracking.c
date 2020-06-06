#include "backtracking.h"
#include "utils.h"

void ombrelloni(int k, int n, unsigned int i, bool *vcurr, unsigned int cnt, unsigned int *nsol) {
	if (cnt == k) {
		for (unsigned int j = 0; j < i; j++) {
			unsigned int succ = j + 1;
			if (succ < i) {
				if (vcurr[j] && vcurr[succ])
					return;
			}

		}
		(*nsol)++;
		printf("\t%d) ", *nsol);

		for (unsigned int j = 0; j < i; j++) {
			printf("%d ", vcurr[j]);
		}
		for (int j = i; j < n; j++) {
			printf("0 ");
		}
		printf("\n");
		return;
	}
	if (i == n)	return;

	for (unsigned int j = 0; j < 2; j++) {
		vcurr[i] = j;
		ombrelloni(n, k, i + 1, vcurr, cnt, nsol);
		cnt++;
	}
}

void backtrackTutte(int n, int i, int k, int vcurr[], int *nsol) {
	if (i == n) {
		printf("%d) ", *nsol);
		(*nsol)++;
		for (int j = 0; j < n; j++) {
			printf("%d", vcurr[j]);
		}
		printf("\n");
		return;
	}

	for (int j = 0; j < n; j++) {
		vcurr[i] = j;
		backtrackTutte(n, i + 1, k, vcurr, nsol);
	}
}

void backtrackSubSet(int n, int i, int vcurr[], int *nsol) {
	if (i == n) {
		printf("%d) ", *nsol);
		(*nsol)++;
		for (int j = 0; j < n; j++) {
			printf("%d", vcurr[j]);
		}
		printf("\n");
		return;
		return;
	}

	for (int j = 0; j < 2; j++) {
		vcurr[i] = j;
		backtrackSubSet(n, i + 1, vcurr, nsol);
	}
}

void subSetK(int n, int i, int k, int vcurr[], int count, int *nsol) {
	if (count == k) {
		printf("%d) ", *nsol);
		(*nsol)++;
		for (int j = 0; j < i; j++) {
			printf("%d ", vcurr[j]);
		}
		for (int j = i; j < n; j++) {
			printf("0");
		}
		printf("\n");
		return;
	}
	if (i == n)	return;


	for (int j = 0; j < 2; j++) {
		vcurr[i] = j;
		subSetK(n, i + 1, k, vcurr, count, nsol);
		count++;
	}
}


void permutazioni(int n, int i, int vcurr[], int* nsol) {
	if (i == n) {
		printf("%d) ", *nsol);
		(*nsol)++;
		for (int j = 0; j < n; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	for (int j = i; j < n; j++) {
		scambia(&vcurr[i], &vcurr[j], sizeof(int));
		permutazioni(n, i + 1, vcurr, nsol);
		scambia(&vcurr[i], &vcurr[j], sizeof(int));
	}
}

void BabboNatale(int p, int const *pacchi, int n, unsigned int i, bool vcurr[], bool vbest[], unsigned int *max, unsigned int cnt, int sum) {
	if (i == n) {
		if (sum <= p && cnt > *max) {
			*max = cnt;
			memcpy(vbest, vcurr, n * sizeof(bool));
		}
		return;
	}

	for (unsigned int j = 0; j < 2; j++) {
		vcurr[i] = j;
		if (vcurr[i] == 1) {
			sum += pacchi[i];
			cnt++;
		}
		BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, cnt, sum);
	}
	if (i == 0) {
		for (int i = 0; i < n; i++) {
			printf("%d ", vbest[i]);
		}
		printf("\n");
	}
}