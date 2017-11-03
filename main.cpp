#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

void create(double * &mass, unsigned int &size, unsigned int &schet) {
	string stroka1, stroka2;
	
	getline(cin, stroka1);
	istringstream stream1(stroka1);

	stream1 >> size;

	getline(cin, stroka2);
	istringstream stream2(stroka2);

	mass = new double[size];
	for (int i = 0; i < size; i++) {
		if (stream2 >> mass[i]) {
			schet++;
		}
	}

}

void obmen(double * & mass, unsigned int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i - 1; j > -1; j--) {
			
			if (mass[j] > mass[j + 1]) {
				swap(mass[j], mass[j + 1]);
			}
		}
	}
}

void write(double * mass, unsigned int size) {
	for (int i = 0; i < size; i++) {
		cout << mass[i] << " ";
	}
}

int main()
{
	unsigned int size = 0;
	unsigned int schet = 0;

	double * mass;

	create(mass, size, schet);

	if (schet < size) {
		cout << "error";

		cin.get();
		return 0;
	}
	
	obmen(mass, size);
	write(mass, size);

	cin.get();
	delete[] mass;
    return 0;
}
