#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "sort/utils.hpp"
#include <chrono>

namespace sort{

	double get_time(void(*f)(int[], int), int A[], int n){
		auto start = std::chrono::steady_clock::now();

		f(A,n);
		auto end = std::chrono::steady_clock::now();
		return std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	}

	void swap(int* A, int i, int j){
		int aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	int getRandomInt(int min, int max){
		float a = rand() / static_cast<float>(RAND_MAX);
		return static_cast<int>(a * (max - min) + min + 0.5);
	}
}
