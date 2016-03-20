template<class T> void InsertionSort(T *A, int N)
{
    if (N < 2) return;
 
    for (int i = 1; i < N; i++)
        for (int j = i; j && A[j] < A[j-1]; j--)
            std::swap(A[j], A[j-1]);
}