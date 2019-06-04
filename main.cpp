#include<iostream>// input/output : stream
#include<fstream>//file stream
#include<conio.h>
#include<Windows.h>
using namespace std;
#define delimiter "\n--------------------------------------------------\n"
//#define INTRODUCTION_TO_FILES
//#define EXCHANGE

bool isMac(char sz_mac[]);
bool isIP(char sz_ip[]);
void checkExtension(char filename_before[], char filename_after[]);//должно дописывать расширени€

void main()
{
	setlocale(LC_ALL, "");
#ifdef INTRODUCTION_TO_FILES
	//cout << "Hello World" << endl;
	//1)—оздаем поток вывода в файл:
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
#ifdef EXCHANGE

	const int n = 256;
	char filename_before[n] = {};
	char filename_after[n] = {};
	cout << "¬ведите название файла: ";
	cin.getline(filename_before, n);
	checkExtension(filename_before, filename_after);
	cout << "¬ведите название конечного файла: ";
	cin.getline(filename_after, n);
	checkExtension(filename_before, filename_after);
	ifstream fin(filename_before);
	ofstream fout(filename_after);
	if (fin.is_open())
	{
		char sz_buffer[n]{};
		char sz_ip[n]{};
		char sz_mac[n]{};
		while (!fin.eof())
		{
			fin >> sz_ip;
			cout << isIP(sz_ip) << endl;
			fin >> sz_mac;
			cout << isMac(sz_mac) << endl;

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
#endif // EXCHANGE
	const int n = 20;
	char sz_mac[n] = "";
	cout << "Input MAC address: ";
	cin >> sz_mac;
	cout << sz_mac << endl;
	cout << isMac(sz_mac)<<endl;
	}

bool isMac(char sz_mac[])
{
	if (strlen(sz_mac) != 17)return false;
	for (int i = 0; sz_mac[i]; i++)
	{
		if (!(sz_mac[i] >= '0'&&sz_mac[i] <= '9') && !(sz_mac[i] >= 'a'&&sz_mac[i] <= 'f') && !(sz_mac[i] >= 'A'&&sz_mac[i] <= 'F') && sz_mac[i] != '-' && sz_mac[i] != ':')return false;
	}
	return true;
}
bool isIP(char sz_ip[])
{
	for (int i = 0; sz_ip[i]; i++)
	{
		if (!(sz_ip[i] >= '0'&&sz_ip[i] <= '9') && sz_ip[i] != '.' && sz_ip[i] != ':')return false;
	}
	return true;
}
void checkExtension(char filename_before[], char filename_after[])
{
	for (int i = 0; filename_before[i]; i++)
	{
		if (filename_before[i] != '.')
		{
		
		}
	}
}