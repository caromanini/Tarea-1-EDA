#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort {
	void insertionSort(int* A, int n);
	void radixSort(int* A, int n);
	int getMax(int* A, int n);
	void countSort(int* A, int n, int exp);
	void mergeSort(int* A, int i, int j);
	void merge(int* A, int n, int j, int k);
	void mergeSortWrapper(int* A, int n);
	int split_qs(int* A, int i, int j);
	void quickSort(int* A, int i, int j);
	void quickSort(int* A, int n);
}

#endif
