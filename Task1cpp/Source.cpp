#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {
	int i = 0,n=0;string mass[256];
	fstream inOut;
	std::string str;
	inOut.open("file.txt", ios::in);
	while (inOut) {
		std::getline(inOut, str);
		n++;
	}
	//	cout << n << endl;
	
	while (inOut) {
		for (i; i < n; i++) {
			std::getline(inOut, str);
			mass[i] = str;
			i++;
		}
	}
	for (i = 0; i < n; i++)
		cout << mass[i] << endl;
	system("pause");
	return 0;
}