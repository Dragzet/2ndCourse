#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>
#include <bitset>

using namespace std;

void makeTask(){

	const int bytes = 8;
	int arraySize = pow(10, 7) / bytes + 1;
	vector<unsigned char> bitmap(arraySize, 0);
	ifstream inputFile("input.txt");
	int number;
	while (inputFile >> number){
		bitmap[number / bytes] = bitmap[number / bytes] | (1ULL << number % bytes);
	}
	
	inputFile.close();
	ofstream outputFile("output.txt");	
	
	

	for (int i = 0; i < arraySize * bytes; i++){
		if (bitmap[i / bytes] & (1ULL << i % bytes)){
			outputFile << i << endl;
		}
	}
}

int main(){
	
	auto start = chrono::high_resolution_clock::now();

	makeTask();

	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double> timeGone = end - start;

	cout << "TIME - " << timeGone.count() << endl;
}
