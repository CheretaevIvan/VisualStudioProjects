#include "all_sort.h"

void radixsort(BaseType *a, BaseType n) {
	BaseType i, m = a[0], exp = 1;
	const BaseType base = 10;
	BaseType *b = (BaseType *)malloc(n * sizeof(BaseType));
	BaseType *bucket = (BaseType *)calloc(base, sizeof(BaseType));
	for (i = 1; i < n; i++) {
		if (a[i] > m)
			m = a[i];
	}
	while (m / exp > 0) {
		memset(bucket, 0, base * sizeof(BaseType));
		for (i = 0; i < n; i++) {
			bucket[(a[i] / exp) % base]++;
		}
		for (i = 1; i < base; i++) {
			bucket[i] += bucket[i - 1];
		}
		for (i = n - 1; i >= 0; i--) {
			b[--bucket[(a[i] / exp) % base]] = a[i];
		}
		for (i = 0; i < n; i++) {
			a[i] = b[i];
		}
		exp *= base;
	}
}