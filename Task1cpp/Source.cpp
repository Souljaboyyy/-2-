#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {
	fstream inOut;
	string str, line;
	int CountStrings = 0, i = 0;
	inOut.open("file.txt", ios::in);
	while (!inOut.eof()) {
		getline(inOut, str);
		CountStrings++;
	}
	inOut.seekg(0, ios_base::beg);
	inOut.close();
	inOut.open("file.txt", ios::in);
	cout << "Your strings : " << endl;
	string* massLines = new string[CountStrings];
	for (i; i < CountStrings; i++) {
		getline(inOut, massLines[i]);
		cout << massLines[i] << endl;
	}
	cout << endl;
	for (i = 0; i < CountStrings; i++)
		for (int j = 0; j < CountStrings - 1; j++)
			if (massLines[j] > massLines[j + 1]) {
				std::swap(massLines[j], massLines[j + 1]);
			}
	
	int count = 0;
	for (i = 0; i < CountStrings-1 ; i++)
		if (massLines[i] != massLines[i + 1])
			count++;
	count++;
	string* NewMassLines = new string[count];
	for (int j = 0, k = 0; k < CountStrings - 1; k++)
	{
		if (massLines[k] != massLines[k + 1])
		{
			NewMassLines[j] = massLines[k];
			++j;
		}
		if (k + 1 == CountStrings - 1)
		{
			NewMassLines[j] = massLines[k+1];
		}
	}
	cout << endl;
	cout << "You want : " << endl;
	for (i = 0; i < count; i++)
		cout << NewMassLines[i] << endl;
	delete[] massLines;
		
	system("pause");
	return 0;
}