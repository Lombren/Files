#include<iostream>// input/output : stream
#include<fstream>//file stream
#include<conio.h>
#include<Windows.h>
using namespace std;
#define delimiter "\n--------------------------------------------------\n"
//#define INTRODUCTION_TO_FILES

void main()
{
	setlocale(LC_ALL, "");
#ifdef INTRODUCTION_TO_FILES
	//cout << "Hello World" << endl;
	//1)Создаем поток вывода в файл:
	ofstream fout("File.txt", ios::app);
	fout << "Hello World" << endl;
	fout.close();
	//system("notepad File.txt");

	ifstream fin("File.txt");
	if (fin.is_open())
	{
		const int n = 256;
		char sz_buffer[n]{};
		while (!fin.eof())
		{
			//fin >> sz_buffer;
			fin.getline(sz_buffer, n);
			cout << sz_buffer << endl;
		}
	}
	fin.close();
#endif // INTRODUCTION_TO_FILES
	const int n = 256;
	char filename_before[n] = {};
	char filename_after[n] = {};
	cout << "Введите название файла: ";
	cin.getline(filename_before, n);
	cout << "Введите название конечного файла: ";
	cin.getline(filename_after, n);
	
	ifstream fin(filename_before);
	ofstream fout(filename_after);
	if (fin.is_open())
	{
		char sz_buffer[n]{};
		char sz_ip[n]{};
		char sz_mac[n]{};
		while (!fin.eof())
		{
			fin>>sz_ip;
			fin >> sz_mac;
			
			fout << sz_mac << "\t";
			fout << sz_ip << "\n";
			
			
			//cout << sz_buffer << endl;
			//cout << delimiter << "ip" << endl;;
			//cout << delimiter << "mac" << endl;;
		}
		
	}
	fout.close();
	fin.close();
	system(filename_after);
}