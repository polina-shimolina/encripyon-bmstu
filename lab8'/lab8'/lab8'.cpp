
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	string mas[256];
	int newlet; //новая буква в int
	string st; //начальная строка
	getline(cin, st);
	int j; //номер буквы в ct
	char* arr = new char[st.size() + 1]; //строка итоговая
	char* ar = new char[st.size() + 1]; //строка итоговая в цифрах
	char* starr = new char[st.size() + 1];//первоначальная строка
	string ct = "aaaaaaaaa gagrwjt dstgreyt vfmfter jtdygdrht rdjyrj";
	int f = 1;
	for (int i = 0; i < ct.size(); i++) {
		if (ct[i] == 32)f++;
	}
	int* newmas = new int[f];
	int k = 0;
	for (int i = 0; i < ct.size(); i++) {
		if (ct[i] != 32) {
			newmas[k] += (int)ct[i];
			/*cout << (int)ct[i] << " ";*/
		}
		else {
			k++;
			/*cout << "    ";*/
		}
	}
	/*for (int i = 0; i < f; i++) {
		cout << (int)newmas[i] << " ";
	}*/
	cout << endl;
	for (int i = 0; i < st.size(); i++) {

		j = i;
		if (i <= k) {
		}
		else
			while (j > k) {
				j -= k;
			}
		newlet = ((int)st[i] + newmas[j] % 256) % 256;
		arr[i] = newlet + '0';
		ar[i] = newlet;

	}
	arr[st.size()] = 0;
	ar[st.size()] = 0;
	cout << arr << endl;
	for (int i = 0; i < st.size(); i++) {
		j = i;
		if (i <= k) {
		}
		else
			while (j > k) {
				j -= k;
			}
		int f = (int)ar[i] - (int)newmas[j] + 256 - 48;
		starr[i] = f + '0';
	}
	starr[st.size()] = 0;
	cout << starr;
	// двумерная матрица 256*256 слева исходный символ, сверху как зашифрован на пересечениях прибавлять 1, вывести все не равное нулю
	int a[256][256] = {};
	for (int i = 0; i < st.size(); i++) {
		a[(int)st[i]][(int)arr[i]]++;
	}
	for (int i = 0; i < 256; i++) {
		cout << (char)i;
		for (int j = 0; j < 256; j++) {
			if (a[i][j] != 0) {
				cout << "  " << (char)j << " (" << a[i][j] << ")        ";
			}
		}
		cout << endl;
	}
	return 0;

}

