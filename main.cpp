#include<iostream>// input/output : stream
#include<fstream>//file stream
#include<conio.h>
#include<Windows.h>
using namespace std;
#define delimiter "\n--------------------------------------------------\n"
//#define INTRODUCTION_TO_FILES
#define EXCHANGE
//#define MAC_IP_CHECK

bool isMac(char sz_mac[]);
bool isIP(char sz_ip[]);
void add_file_extension(char filename_before[]);//должно дописывать расширения
void add_file_dhcpd(char filename_after[]);

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
#ifdef EXCHANGE

	const int n = 256;
	char filename_before[n] = {};
	char filename_after[n] = {};
	
	cout << "Введите название файла: ";
	cin.getline(filename_before, n);
	add_file_extension(filename_before);
	cout << filename_before << endl;
	cout << "Введите название конечного файла: ";
	cin.getline(filename_after, n);
	add_file_dhcpd(filename_after);
	//add_file_extension(filename_after);
	
	
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
			//cout << isIP(sz_ip) << endl;
			fin >> sz_mac;
			//cout << isMac(sz_mac) << endl;


			if(isMac(sz_mac))fout << sz_mac << "\t";
			if (isIP(sz_ip))fout << sz_ip << "\n";
			if (isMac(sz_mac))std:: cout << sz_mac << "\t";
			if (isIP(sz_ip))std::cout << sz_ip << "\n";


			//cout << sz_buffer << endl;
			//cout << delimiter << "ip" << endl;;
			//cout << delimiter << "mac" << endl;;
		}

	}
	fout.close();
	fin.close();
	system(filename_after);
#endif // EXCHANGE
#ifdef MAC_IP_CHECK
	/*const int n = 20;
char sz_mac[n] = "";*/
	const int n = 20;
	char sz_ip[n] = "";
	/*cout << "Input MAC address: ";
	cin >> sz_mac;
	cout << sz_mac << endl;
	cout << isMac(sz_mac)<<endl;*/
	cout << "Input IP address: ";
	cin >> sz_ip;
	cout << sz_ip << endl;
	cout << isIP(sz_ip) << endl;
#endif // MAC_IP_CHECK
	

	}

bool isMac(char sz_mac[])
{
	if (strlen(sz_mac) != 17)return false;
	for (int i = 0; sz_mac[i]; i++)
	{
		if (!(sz_mac[i] >= '0'&&sz_mac[i] <= '9') && 
			!(sz_mac[i] >= 'a'&&sz_mac[i] <= 'f') && 
			!(sz_mac[i] >= 'A'&&sz_mac[i] <= 'F') && 
			!((sz_mac[i] == '-' || sz_mac[i] == ':')&&(i+1)%3==0)
			)return false;
	}
	return true;
}
bool isIP(char sz_ip[])
{
	if (strlen(sz_ip) > 15 || strlen(sz_ip) < 7)return false;
	int number_of_dots = 0;
	int bytes[4] = {}; // числовые значения байтов  IP адреса.
	for (int i = 0,j=0; sz_ip[i]; i++)
	{
		if (sz_ip[i] == '.')number_of_dots++;
		if (sz_ip[i] == '.'&& sz_ip[i + 1] == 0)return false;
		if (!(sz_ip[i] >= '0'&&sz_ip[i] <= '9') && sz_ip[i] != '.')return false;
		if (sz_ip[i] == '.')
		{
			if (bytes[j] > 255||number_of_dots>3)return false;
			j++;
			continue;
		}
		bytes[j] *= 10;
		bytes[j] += (sz_ip[i] - 48);
	}
	if (number_of_dots != 3|| bytes[3] > 255)return false;
	return true;
}
void add_file_extension(char filename_before[])//должно дописывать расширения
{
	int size = strlen(filename_before);
	if (strcmp(filename_before + size - 4, ".txt")==0)return;
	strcat(filename_before, ".txt");//Конкатенация строк.(слияние строк)
}
void add_file_dhcpd(char filename_after[])
{
	
	int size = strlen(filename_after);
	if (strcmp(filename_after + size - 6, ".dhcpd") == 0)return;
	strcat(filename_after, ".dhcpd");//Конкатенация строк.(слияние строк)
}