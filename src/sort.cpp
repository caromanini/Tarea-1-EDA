#include <iostream>
#include "sort/sort.hpp"
#include "sort/utils.hpp"

namespace sort{

	void insertionSort(int* A, int n){
		for(int i = 1; i<n; i++)
		{
			int elem = A[i];
			int j = i-1;
			
			while(j >= 0 && elem < A[j])
			{
				A[j+1] = A[j];
				j = j-1;
			}
			A[j+1] = elem;
		}
	}
	
	int split_qs(int* A, int i, int j){
		/***
		 * split for quicksort
		 * i,j are the endpoints
		 */
		int p = getRandomInt(i, j);

		while (i  < j) {

			while ( i < p && A[i] <= A[p]){
				i = i + 1;
			}

			while ( j > p && A[j] >= A[p]){
				j = j - 1;
			}

			swap(A, i, j);

			if (i == p){
				p = j;
			}
			else if (j == p){
				p = i;
			}
		}
		return p;
	}	
	
	void quickSort(int* A, int i, int j){
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}

	void quickSort(int* A, int n){
		quickSort(A, 0, n - 1);
	}

	void merge(int* A, int i, int j, int k){
		int n = j-i+1;
		int* aux = new int[n];

		int q = 0;
		int p1 = i;
		int p2 = k+1;

		while(p1<=k && p2<=j){
			if(A[p1] <= A[p2]){
				aux[q] = A[p1];
				p1++;
			}
			else{
				aux[q] = A[p2];
				p2++;
			}
			q++;
		}
		while(p1<=k){
			aux[q] = A[p1];
			p1++;
			q++;
		}
		while(p2<=j){
			aux[q] = A[p2];
			p2++;
			q++;
		}
		for(int x=0; x<n; x++){
			A[i+x] = aux[x];
		}

		delete[] aux;
	}

	void mergeSortWrapper(int *A, int n){
		mergeSort(A, 0, n-1);
	}

	void mergeSort(int* A, int i, int j){
		int k = (i+j)/2;

		if(i<j){
			mergeSort(A, i, k);
			mergeSort(A, k+1, j);
			merge(A, i, j, k);
		}
	}

	int getMax(int* A, int n){
		int max = A[0];

		for(int i=0; i<n; i++){
			if(A[i] > max){
				max = A[i];
			}
		}
		return max;
	}

	void countSort(int* A, int n, int exp){
		int output[n];
		int i, count[10] = {0};

		for(i=0; i<n; i++){
			count[(A[i]/exp)%10]++;
		}

		for(i=1; i<10; i++){
			count[i] += count[i-1];
		}

		for(i=n-1; i>=0; i--){
			output[count[(A[i]/exp)%10]-1] = A[i];
			count[(A[i]/exp)%10]--;
		}

		for(i=0; i<n; i++){
			A[i]=output[i];
		}
	}

	void radixSort(int* A, int n){
		int m = getMax(A,n);

		for(int exp=1; m/exp > 0; exp*=10){
			countSort(A, n, exp);
		}
	}	
}
