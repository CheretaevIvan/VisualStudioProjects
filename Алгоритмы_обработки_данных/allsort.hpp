template<class T> void InsertionSort(T *, int);

template<class T> void InsertionSort(T *A, int N)
{
    if (N < 2) return;
 
    for (int i = 1, j; i < N; i++)
		if (A[i]>A[i - 1])
		{
			T temp = A[i];
			for (j = i; j && A[j] < A[j - 1]; j--)
				A[j] = A[j - 1];
			A[j] = temp;
		}
}