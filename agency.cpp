#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace std;
void shopping(struct user userr); void excursion(struct user userr); void relaxation(struct user userr);
void svne(); void evne(); void rvne(); void vne(); void admin(); void add(); void welcome(struct user userr);
void pay(struct user userr, struct vacation vacationn); int id(); void reg(); int log_in(); int main(bool isRunning);

struct sold {
	int id = {};
	char login[20] = {};
	char email[30] = {};
	char number[16] = {};
	int a = {};
};
struct user {
	int id = {};
	char login[20] = {};
	int md = {};
	int role = {};
	int times = {};
};
struct vacation {
	int idv = {};
	char name[20] = {};
	char description[150] = {};
	int price = {};
	bool isdelete = {};
};

int menu_start() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) cout << "-> Log in" << endl;
		else  cout << "   Log in" << endl;
		if (key == 1) cout << "-> Registration" << endl;
		else  cout << "   Registration" << endl;
		if (key == 2) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int options() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Pay" << endl;
		else  cout << "   Pay" << endl;
		if (key == 1) cout << "-> Choose another one" << endl;
		else  cout << "   Choose another one" << endl;
		if (key == 2) cout << "-> Chooe another type of vacation" << endl;
		else  cout << "   Chooe another type of vacation" << endl;
		if (key == 3) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int choise() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Shopping" << endl;
		else  cout << "   Shopping" << endl;
		if (key == 1) cout << "-> Excursion" << endl;
		else  cout << "   Excursion" << endl;
		if (key == 2) cout << "-> Relaxation" << endl;
		else  cout << "   Relaxation" << endl;
		if (key == 3) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int start_admin() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) cout << "-> View tours and edit" << endl;
		else  cout << "   View tours and edit" << endl;
		if (key == 1) cout << "-> Add new tours" << endl;
		else  cout << "   Add new tours" << endl;
		if (key == 2) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int changes() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Name" << endl;
		else  cout << "   Name" << endl;
		if (key == 1) cout << "-> Description" << endl;
		else  cout << "   Description" << endl;
		if (key == 2) cout << "-> Price" << endl;
		else  cout << "   Price" << endl;
		if (key == 3) cout << "-> Delete or return" << endl;
		else  cout << "   Delete or return" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int leftrotate(unsigned int x, int c)
{
	return (x << c) | (x >> (32 - c));
}
int md5(char* p, int n) {
	int s[64] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22, 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20, 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23, 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21 };
	unsigned int k[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee , 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 , 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c , 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 , 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };
	unsigned int a0 = 0x67452301;   //A
	unsigned int b0 = 0xefcdab89;   //B
	unsigned int c0 = 0x98badcfe;   //C
	unsigned int d0 = 0x10325476;   //D
	string ss;
	unsigned int** u = new unsigned int* [ceil((double)n / 64) + 1];
	for (int i = 0; i < ceil((double)n / 64) + 1; i++)
		u[i] = new unsigned int[16];
	int j, jui = ceil((double)n / 64);
	for (int i = 0; i < ceil((double)n / 64) + 1; i++)
		for (int j = 0; j < 16; j++)
			u[i][j] = 0;
	for (j = 0; j < ceil((double)n / 64 - 1); j++) {

		for (int i = 64 * j + 3; i < 64 * j + 64; i += 4) {
			int y = 0;
			for (int g = i + 4; g > i; g--) {

				y *= 256;
				y += p[g];
			}
			u[j][(i - 64 * j) / 4] = y;

		}

	}
	int tick = 0, ttick = 0;

	for (int i = 64 * j + 3; i < 64 * j + 64; i += 4) {
		int y = 0;
		tick = 0;
		for (int g = i; g > i - 4; g--) {

			y *= 256;
			if (g >= n) {
				tick = g - i + 3;
			}
			else y += p[g];
		}
		if (tick > 0) {

			y *= pow(256, 4 - tick);
			u[j][(i - 64 * j) / 4] = y + pow(256, 3 - tick);
			ttick++;
			break;
		}
		u[j][(i - 64 * j) / 4] = y;
	}

	if (ttick < 14) {
		u[j][14] = n / pow(2, 32);
		u[j][15] = n % ((int)pow(2, 32));
	}
	else {
		jui++;
		u[j + 1][14] = n / pow(2, 32);
		u[j + 2][15] = n % ((int)pow(2, 32));
	}

	int** uu = new int* [jui];
	int A, B, C, D, f, g;
	for (int j = 0; j < jui; j++) {

		A = a0;
		B = b0;
		C = c0;
		D = d0;
		for (int i = 0; i < 64; i++) {
			if (i < 16) {
				f = (B & C) | (~B & D);
				g = i;
			}
			else if (i < 32) {
				f = (D & B) | ((~D) & C);
				g = (5 * i + 1) % 16;
			}
			else if (i < 48) {
				f = (((~B & C) | (~C & B)) & ~D) | (~((~B & C) | (~C & B)) & D);
				g = (3 * i + 5) % 16;
			}
			else {
				f = (C & ~(B | ~D)) | (~C & (B | ~D));
				g = (7 * i) % 16;
			}
			f = f + A + k[i] + u[j][g];
			A = D;
			D = C;
			C = B;
			B = B + leftrotate(f, s[i]);
		}
		a0 = a0 + A;
		b0 = b0 + B;
		c0 = c0 + C;
		d0 = d0 + D;
	}
	return a0 + b0 + c0 + d0;
}

void add() {
	system("cls");
	cout << "What type of tour do you want to add? " << endl;
	int answer = 0;
	answer = choise();
	switch (answer)
	{
	case 0:
	{
		system("cls");
		int idv = 0;
		vacation vacationn;
		ifstream shop1("shopping.dat");
		if (shop1.tellg())
		{
			idv = 1;
		}
		else
		{
			while (!shop1.eof())
			{
				shop1.read((char*)& vacationn, sizeof(vacation));
				idv++;
			}
		}
		vacationn.idv = idv;
		shop1.close();
		ofstream shop("shopping.dat", ios::app, ios::binary);
		cout << "Name: ";
		cin.ignore(); cin.getline(vacationn.name, 20);
		cout << "Description: ";
		cin.ignore(); cin.getline(vacationn.description, 150);
		cout << "Price: ";
		cin >> vacationn.price;
		cout << "SHOW(0) or HIDE(1)";
		cin >> vacationn.isdelete;
		shop.write((char*)& vacationn, sizeof(vacation));
		shop.close();
		break;
	}

	case 1:
	{
		system("cls");
		int idv = 0;
		vacation vacationn;
		ifstream ex1("excursion.dat", ios::binary);
		if (ex1.tellg())
		{
			idv = 1;
		}
		else {
			while (!ex1.eof())
			{
				ex1.read((char*)& vacationn, sizeof(vacation));
				idv++;
			}
		}
		vacationn.idv = idv;
		ex1.close();
		ofstream ex("excursion.dat", ios::app, ios::binary);
		cout << "Name: ";
		cin.ignore(); cin.getline(vacationn.name, 20);
		cout << "Description: ";
		cin.ignore(); cin.getline(vacationn.description, 150);
		cout << "Price: ";
		cin >> vacationn.price;
		cout << "SHOW(0) or HIDE(1)";
		cin >> vacationn.isdelete;
		ex.write((char*)& vacationn, sizeof(vacation));
		ex.close();
		break;
	}

	case 2:
	{
		system("cls");
		int idv = 0;
		vacation vacationn;
		ifstream relax1("relaxation.dat", ios::binary);
		if (relax1.tellg())
		{
			idv = 1;
		}
		else {
			while (!relax1.eof())
			{
				relax1.read((char*)& vacationn, sizeof(vacation));
				idv++;
			}
		}
		vacationn.idv = idv;
		relax1.close();
		ofstream relax("relaxation.dat", ios::app, ios::binary);
		cout << "Name: ";
		cin.ignore(); cin.getline(vacationn.name, 20);
		cout << "Description: ";
		cin.ignore(); cin.getline(vacationn.description, 150);
		cout << "Price: ";
		cin >> vacationn.price;
		cout << "SHOW(0) or HIDE(1)";
		cin >> vacationn.isdelete;
		relax.write((char*)& vacationn, sizeof(vacation));
		relax.close();
		break;
	}

	}
	admin();
}
void svne() {
	system("cls");
	int count = 0;
	int key = 0, num = 0;
	vacation vacationn;
	ifstream shop1("shopping.dat", ios::binary);
	while (!shop1.eof())
	{
		shop1.read((char*)& vacationn, sizeof(vacation));
		if (shop1.eof()) { break; }
		key++;
		count++;
		cout << key << ". " << vacationn.name << endl;
		cout << vacationn.description << endl;
		cout << vacationn.price << endl;
		cout << vacationn.isdelete << endl;
	}
	cout << "If you want back, press SPACE. Continue-ENTER" << endl;
	do {
		key = _getch();
		if (key == 13) { break; }
		else if (key == 32) { return vne(); }
	} while (key != 32 || key != 13);
	cout << "Enter the number of your choise which you want to edit" << endl;
	cin >> key;
	shop1.close();
	ifstream shop2("shopping.dat", ios::binary);
	while (!shop2.eof())
	{
		shop2.read((char*)& vacationn, sizeof(vacation));
		num++;
		if (num == key) { break; }

	}
	shop2.close();
	system("cls");
	cout << "You have choosed:" << endl;
	cout << vacationn.name << endl;
	cout << vacationn.description << endl;
	cout << vacationn.price << endl;
	cout << vacationn.isdelete << endl;
	vacation* mas = new vacation[count];
	ifstream shop3("shopping.dat", ios::binary);
	for (int j = 0; j < count; j++)
	{
		shop3.read((char*)(&mas[j]), sizeof(vacation));
	}
	shop3.close();
	ofstream shop4("shopping.dat", ios::binary);
	for (int j = 0; j < count; j++)
	{
		if (j == num - 1)
		{
			cout << "What do you want to change?" << endl;
			int answer = 0;
			answer = changes();
			switch (answer)
			{
			case 0:cout << "New name: "; cin.ignore(); cin.getline(mas[j].name, 20); break;
			case 1:cout << "New description: "; cin.ignore(); cin.getline(mas[j].description, 150); break;
			case 2:cout << "New price: "; cin >> mas[j].price; break;
			case 3: cout << "Deleted returns, not deleted delets."; if (mas[j].isdelete == 0) { mas[j].isdelete = 1; }
					else(mas[j].isdelete = 0); break;
			}
			shop4.write((char*)(&mas[j]), sizeof(vacation));
		}
		else(shop4.write((char*)(&mas[j]), sizeof(vacation)));
	}
	shop4.close();
	delete[]mas;
}
void evne() {
	system("cls");
	int count = 0;
	int key = 0, num = 0;
	vacation vacationn;
	ifstream ex1("excursion.dat", ios::binary);
	while (!ex1.eof())
	{
		ex1.read((char*)& vacationn, sizeof(vacation));
		if (ex1.eof()) { break; }
		key++;
		count++;
		cout << key << ". " << vacationn.name << endl;
		cout << vacationn.description << endl;
		cout << vacationn.price << endl;
		cout << vacationn.isdelete << endl;
	}
	cout << "If you want back, press SPACE. Continue-ENTER" << endl;
	do {
		key = _getch();
		if (key == 13) {}
		else if (key == 32) { return vne(); }
	} while (key != 32 || key != 13);
	cout << "Enter the number of your choise which you want to edit" << endl;
	cin >> key;
	ex1.close();
	ifstream ex2("excursion.dat", ios::binary);
	while (!ex2.eof())
	{
		ex2.read((char*)& vacationn, sizeof(vacation));
		num++;
		if (num == key) { break; }

	}
	ex2.close();
	system("cls");
	cout << "You have choosed:" << endl;
	cout << vacationn.name << endl;
	cout << vacationn.description << endl;
	cout << vacationn.price << endl;
	cout << vacationn.isdelete << endl;
	vacation* mas = new vacation[count];
	ifstream ex3("excursion.dat", ios::binary);
	for (int j = 0; j < count; j++)
	{
		ex3.read((char*)(&mas[j]), sizeof(vacation));
	}
	ex3.close();
	ofstream ex4("excursion.dat", ios::binary);
	for (int j = 0; j < count; j++)
	{
		if (j == num - 1)
		{
			cout << "What do you want to change?" << endl;
			int answer = 0;
			answer = changes();
			switch (answer)
			{
			case 0:cout << "New name: "; cin.ignore(); cin.getline(mas[j].name, 20); break;
			case 1:cout << "New description: "; cin.ignore(); cin.getline(mas[j].description, 150); break;
			case 2:cout << "New price: "; cin >> mas[j].price; break;
			case 3: cout << "Deleted returns, not deleted delets."; if (mas[j].isdelete == 0) { mas[j].isdelete = 1; }
					else(mas[j].isdelete = 0); break;
			}
			ex4.write((char*)(&mas[j]), sizeof(vacation));
		}
		else(ex4.write((char*)(&mas[j]), sizeof(vacation)));
	}
	ex4.close();
	delete[]mas;
}
void rvne() {
	system("cls");
	int count = 0;
	int key = 0, num = 0;
	vacation vacationn;
	ifstream relax1("relaxation.dat", ios::binary);
	while (!relax1.eof())
	{
		relax1.read((char*)& vacationn, sizeof(vacation));
		if (relax1.eof()) { break; }
		key++;
		count++;
		cout << key << ". " << vacationn.name << endl;
		cout << vacationn.description << endl;
		cout << vacationn.price << endl;
		cout << vacationn.isdelete << endl;
	}
	cout << "If you want back, press SPACE. Continue-ENTER" << endl;
	do {
		key = _getch();
		if (key == 13) { break; }
		else if (key == 32) { return vne(); }
	} while (key != 32 || key != 13);
	cout << "Enter the number of your choise which you want to edit" << endl;
	cin >> key;
	relax1.close();
	ifstream relax2("relaxation.dat", ios::binary);
	while (!relax2.eof())
	{
		relax2.read((char*)& vacationn, sizeof(vacation));
		num++;
		if (num == key) { break; }

	}
	relax2.close();
	system("cls");
	cout << "You have choosed:" << endl;
	cout << vacationn.name << endl;
	cout << vacationn.description << endl;
	cout << vacationn.price << endl;
	cout << vacationn.isdelete << endl;
	vacation* mas = new vacation[count];
	ifstream relax3("relaxation.dat", ios::binary);
	for (int j = 0; j < count; j++)
	{
		relax3.read((char*)(&mas[j]), sizeof(vacation));
	}
	relax3.close();
	ofstream relax4("relaxation.dat", ios::binary);
	for (int j = 0; j < count; j++)
	{
		if (j == num - 1)
		{
			cout << "What do you want to change?" << endl;
			int answer = 0;
			answer = changes();
			switch (answer)
			{
			case 0:cout << "New name: "; cin.ignore(); cin.getline(mas[j].name, 20); break;
			case 1:cout << "New description: "; cin.ignore(); cin.getline(mas[j].description, 150); break;
			case 2:cout << "New price: "; cin >> mas[j].price; break;
			case 3: cout << "Deleted returns, not deleted delets."; if (mas[j].isdelete == 0) { mas[j].isdelete = 1; }
					else(mas[j].isdelete = 0); break;
			}
			relax4.write((char*)(&mas[j]), sizeof(vacation));
		}
		else(relax4.write((char*)(&mas[j]), sizeof(vacation)));
	}
	relax4.close();
	delete[]mas;
}
void vne() {
	cout << "Choose which one do you want to view" << endl;
	bool isRunning;
	int answer = 0;
	answer = choise();
	switch (answer)
	{
	case 0:svne(); break;
	case 1:evne(); break;
	case 2:rvne(); break;
	case 3: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false; main(isRunning);
	}
}
void admin() {
	system("cls");
	cout << "What do you wish to do, my Lord." << endl;
	bool isRunning;
	int answer = 0;
	answer = start_admin();
	switch (answer)
	{
	case 0:vne(); break;
	case 1:add(); break;
	case 2: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false; main(isRunning);
	}
}
void welcome(struct user userr) {
	system("cls");
	cout << "Hi, " << userr.login << "!" << "What type of weekend would you choose?" << endl;
	bool isRunning;
	int answer = 0;
	answer = choise();
	switch (answer)
	{
	case 0:relaxation(userr); break;
	case 1:excursion(userr); break;
	case 2:shopping(userr); break;
	case 3: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false; main(isRunning);
	}
}
void pay(struct user userr, struct vacation vacationn) {
	system("cls");
	sold soldd;
	char cvv[3];
	int y, m;
	soldd.id = userr.id;
	cout << "How many people?" << endl;
	cin >> soldd.a;
	if (userr.times > 5)                                                                             //МЕНЯЮЩАЯСЯ СКИДКА
	{
		cout << "You bought more than 5 tours, so we give you a 10% discount";
		vacationn.price = soldd.a * (vacationn.price - (vacationn.price * 10 / 100));
	}
	else(vacationn.price = soldd.a * vacationn.price);
	cout << "You have to pay:" << vacationn.price << endl;
	cout << "Your login: "<<endl;
	_memccpy(soldd.login, userr.login, '\0', 20);
	cout << soldd.login;
	cout << "Enter your email: ";
	cin >> soldd.email;
	cout << "Enter number of you card: ";
	cin >> soldd.number;
	cout << "Enter valid until(month year): ";
	cin >> m >> y;
	cout << "Enter cvv code";
	cin.ignore();
	cin.getline(cvv, 3);
	cout << "You will get your tickets and futher information on your email";
	ofstream list("sold.txt", ios::app);
	list.write((char*)& soldd, sizeof(sold));
	list << "\n";
	ifstream users1("users.dat", ios::binary);
	int count = 0;
	while (!users1.eof())
	{
		users1.read((char*)& userr, sizeof(user));
		if (users1.eof()) { break; }
		count++;
	}
	user* mas = new user[count];
	users1.close();
	ifstream users3("users.dat", ios::binary);
	for (int j = 0; j < count; j++)
	{
		users3.read((char*)(&mas[j]), sizeof(user));
	}
	users3.close();
	ofstream users2("users.dat", ios::binary);
	for (int j = 0; j < count; j++)
	{
		if (!strcmp(soldd.login, mas[j].login))
		{
			mas[j].times++;
			users2.write((char*)(&mas[j]), sizeof(user));
		}
		else(users2.write((char*)(&mas[j]), sizeof(user)));
	}
	users2.close();
	list.close();
}                                                  //СДЕЛАТЬ ЗАЩИТУ ОТ ДАУНОВ
void shopping(struct user userr) {
	system("cls");
	int key = 0, num = 0;
	vacation vacationn;
	ifstream shop1("shopping.dat");
	while (!shop1.eof())
	{
		shop1.read((char*)& vacationn, sizeof(vacation));
		if (shop1.eof()) { break; }
		if (vacationn.isdelete == 0) {
			key++;
			cout << key << ". " << vacationn.name << endl;
			cout << vacationn.description << endl;
			cout << vacationn.price << endl;
		}
	}
	cout << "Enter the number of your choise" << endl;
	cin >> key;
	shop1.close();
	ifstream shop2("shopping.dat", ios::binary);
	while (!shop2.eof())
	{
		shop2.read((char*)& vacationn, sizeof(vacation));
		if (vacationn.isdelete == 0) {
			num++;
			if (num == key) { break; }
		}
	}
	system("cls");
	cout << "You have choosed:" << endl;
	cout << vacationn.name << endl;
	cout << vacationn.description << endl;
	cout << vacationn.price << endl;
	bool isRunning;
	int answer = 0;
	answer = options();
	switch (answer)
	{
	case 0:pay(userr, vacationn); break;
	case 1:shopping(userr); break;
	case 2:welcome(userr); break;
	case 3: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false; main(isRunning);
	}
	shop2.close();
}
void excursion(struct user userr) {
	system("cls");
	int key = 0; int num = 0;
	vacation vacationn;
	ifstream ex1("excursion.dat");
	while (!ex1.eof())
	{
		ex1.read((char*)& vacationn, sizeof(vacation));
		if (ex1.eof()) { break; }
		if (vacationn.isdelete == 0)
		{
			key++;
			cout << key << ". " << vacationn.name << endl;
			cout << vacationn.description << endl;
			cout << vacationn.price << endl;
		}
	}
	cout << "Enter the number of your choise" << endl;
	cin >> key;
	ex1.close();
	ifstream ex2("excursion.dat");
	while (!ex2.eof())
	{
		ex2.read((char*)& vacationn, sizeof(vacation));
		if (vacationn.isdelete == 0) {
			num++;
			if (num == key) { break; }
		}
	}
	system("cls");
	cout << "You have choosed:" << endl;
	cout << vacationn.name << endl;
	cout << vacationn.description << endl;
	cout << vacationn.price << endl;
	bool isRunning;
	int answer = 0;
	answer = options();
	switch (answer)
	{
	case 0:pay(userr, vacationn); break;
	case 1:excursion(userr); break;
	case 2:welcome(userr); break;
	case 3: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false; main(isRunning);
	}
	ex2.close();
}                                                                      //СДЕЛАТЬ ЗАЩИТУ ОТ ДАУНОВ
void relaxation(struct user userr) {
	system("cls");
	int num = 0;
	int key = 0;
	vacation vacationn;
	ifstream relax1("relaxation.dat", ios::binary);
	while (!relax1.eof())
	{
		relax1.read((char*)& vacationn, sizeof(vacation));
		if (relax1.eof()) { break; }
		if (vacationn.isdelete == 0)
		{
			key++;
			cout << key << ". " << vacationn.name << endl;
			cout << vacationn.description << endl;
			cout << vacationn.price << endl;
		}
	}
	cout << "Enter the number of your choise" << endl;
	cin >> key;
	relax1.close();
	ifstream relax2("relaxation.dat");
	while (!relax2.eof())
	{
		relax2.read((char*)& vacationn, sizeof(vacation));
		if (vacationn.isdelete == 0)
		{
			num++;
			if (num == key) { break; }
		}
	}
	system("cls");
	cout << "You have choosed:" << endl;
	cout << vacationn.name << endl;
	cout << vacationn.description << endl;
	cout << vacationn.price << endl;
	bool isRunning;
	int answer = 0;
	answer = options();
	switch (answer)
	{
	case 0:pay(userr, vacationn); break;
	case 1:relaxation(userr);; break;
	case 2:welcome(userr); break;
	case 3: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false; main(isRunning);
	}
	relax2.close();
}
int id() {
	user userr;
	int id = 0;
	ifstream users("users.dat", ios::binary);
	if (users.tellg())
	{
		id = 1;
	}
	else {
		while (!users.eof())
		{

			users.read((char*)& userr, sizeof(user));
			id++;
		}
	}
	users.close();
	return id;
}                                                                                                                 //СДЕЛАТЬ ЗАЩИТУ ОТ ДАУНОВ
void reg() {
	system("cls");
	cout << "Registration(if you see this again, we already have one like this. try again)" << endl;
	user userr;
	char login[20], password[20];
	cout << id();
	userr.id = id();
	cout << "login: ";
	cin >> login;
	ifstream users3("users.dat", ios::binary);
	if (!users3.tellg())
	{
		while (!users3.eof())
		{
			users3.read((char*)& userr, sizeof(user));
			if (!strcmp(login, userr.login)) { reg(); }
		}
	}
	strcpy_s(userr.login, login);
	users3.close();
	cout << "password: ";
	cin >> password;
	userr.md = md5(password, strlen(password));
	cout << "role(0-user; 1-admin): ";
	cin >> userr.role;
	userr.times = 0;
	ofstream users("users.dat", ios::app, ios::binary);
	users.write((char*)& userr, sizeof(user));
	users.close();
	menu_start();
}
int log_in() {
	system("cls");
	user userr;
	int countl = 0, countp = 0;
	int key;
	int md;
	char login[20], password[20];
	ifstream users("users.dat");
	cout << "login: ";
	cin >> login;
	cout << "password: ";
	cin >> password;
	while (!users.eof())
	{
		users.read((char*)& userr, sizeof(user));
		if (!strcmp(userr.login, login))
		{
			countl++;
			md = md5(password, strlen(password));
			if (md == userr.md)
			{
				countp++; break;
			}
		}
	}
	if (countl == 0)
	{
		cout << "Maybe you want to register? If YES press SPACE. If you want try one more time press ENTER" << endl;
		do {
			key = _getch();
			if (key == 13) { log_in(); }
			else if (key == 32) { reg(); }
		} while (key != 32 || key != 13);
	}
	if (countp == 0) {
		cout << "Look's like your password is wrong.  If you want try one more time press ENTER. Exit-SPACE" << endl;
		do {
			key = _getch();
			if (key == 13) { return log_in(); }
			else if (key == 32) { cout << "You will return"; return 0; }
		} while (key != 32 || key != 13);
	}
	if (countl == 1 && countp == 1)
	{
		if (userr.role == 0) { welcome(userr); }
		else(admin());
	}
	users.close();
}


int main(bool isRunning)
{
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_start();
		switch (answer)
		{
		case 0:log_in(); break;
		case 1:reg(); break;
		case 2: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}