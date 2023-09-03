#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <chrono>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

int main(int argc, char *argv[]){
	std::string fileName = argv[1];
	std::ifstream file("datos/" + fileName);

	int array_size = 0;
	int value;
	while(file >> value){
		array_size++; 
	}
	file.close();
	file.open("datos/"+fileName);

	int* A = new int[array_size];

	for(int i=0; i<array_size; i++){
		file >> A[i];
	}
	file.close();

	if(*argv[2] == 'I'){
		std::cout<<"Ordenado con: InsertionSort"<<std::endl;

		double time = sort::get_time(sort::insertionSort, A, array_size);
	
		//std::cout<<"Tiempo de insertionSort (microsegundos): "<<time<<std::endl;
	}
	else if(*argv[2] == 'M'){
		std::cout<<"Ordenado con: MergeSort"<<std::endl;
		double time = sort::get_time(sort::mergeSortWrapper, A, array_size);

		//std::cout<<"Tiempo de MergeSort: "<<time<<std::endl;
	}
	else if(*argv[2] == 'R'){
		std::cout<<"Ordenado con: RadixSort"<<std::endl;
		double time = sort::get_time(sort::radixSort, A, array_size);

		//std::cout<<"Tiempo de radixSort: "<<time<<std::endl;
	}
	else if(*argv[2] == 'Q'){
		std::cout<<"Ordenado con: QuickSort"<<std::endl;
		
		double time = sort::get_time(sort::quickSort, A, array_size);

		//std::cout<<"Tiempo de QuickSort (microsegundos): "<<time<<std::endl;
	}

	std::ofstream outputFile(fileName + ".sorted");
	if(outputFile.is_open()){
		for(int i = 0; i<array_size; i++){
			outputFile << A[i] << "\n";
		}
		outputFile.close();
		std::cout<<"Archivo generado: "<<fileName + ".sorted"<<std::endl;
	}

	delete[] A;
	return 0;
}
