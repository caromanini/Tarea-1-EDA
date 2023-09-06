#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP

namespace sort{
	double get_time(void(*f)(int[], int), int A[], int n);
	void swap(int* A, int i, int j);
	int getRandomInt(int min, int max);
}

#endif
