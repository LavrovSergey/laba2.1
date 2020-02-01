#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace std;
void shopping(struct user userr); void excursion(struct user userr); void relaxation(struct user userr); 
void svne(); void evne(); void rvne(); void vne(); void admin(); void add(); void welcome(struct user userr);
void pay(struct user userr, struct vacation vacationn); int id(); int reg(); int log_in();

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
	char password[20] = {};
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

void add() {
	system("cls");
	int key=0;
	cout << "What type of tour do you want to add? "<<endl;
	cout << "1. Shopping" << endl;
	cout << "2. Excursion" << endl;
	cout << "3. Relaxation" << endl;
	cin >> key;
	if(key==1)
	{
		system("cls");
		int idv=0;
		vacation vacationn;
		ifstream shop1("shopping.db");
		if (shop1.tellg())
		{
			idv = 1;
		}
		else {
			while (!shop1.eof())
			{
				shop1.read((char*)& vacationn, sizeof(vacation));
				idv++;
			}
		}
		vacationn.idv = idv;
		shop1.close();
		ofstream shop("shopping.db", ios::app || ios::binary);
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
	}
	else if (key == 2) 
	{
		system("cls");
		int idv = 0;
		vacation vacationn;
		ifstream ex1("excursion.db", ios::binary);
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
		ofstream ex("excursion.db", ios::binary || ios::app);
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
	}
	else if (key == 3){
		system("cls");
		int idv = 0;
		vacation vacationn;
		ifstream relax1("relaxation.db", ios::binary);
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
		ofstream relax("relaxation.db", ios::binary || ios::app);
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
	}
}
void svne() {
	system("cls");
	char back;
	int count = 0;
	int key = 0, num = 0;
	vacation vacationn;
	ifstream shop1("shopping.db", ios::binary);
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
	cout << "If you want back, press SPACE" << endl;
	cin >> back;
	if (back == 32) { admin(); }
	cout << "Enter the number of your choise which you want to edit" << endl;
	cin >> key;
	shop1.close();
	ifstream shop2("shopping.db", ios::binary);
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
	ifstream shop3("shopping.db", ios::binary);
	for (int j = 0; j < count; j++)
	{
		shop2.read((char*)(&mas[j]), sizeof(user));
	}
	shop3.close();
	ofstream shop4("shopping.db", ios::binary);
	for(int j = 0; j < count; j++)
	{
		if (j==num-1)
		{
			cout << "What do you want to change?" << endl;
			cout << "1.Name" << endl;
			cout << "2.Description" << endl;
			cout << "3.Price"<< endl;
			cout << "4.Delete or return" << endl;
			cin >> key;
			if (key == 1) { cout << "New name: "; cin.ignore(); cin.getline(mas[j].name, 20); }
			else if (key == 2) { cout << "New description: "; cin.ignore(); cin.getline(mas[j].description, 150); }
			else if (key == 3) { cout << "New price: "; cin >> mas[j].price;}
			else if (key == 4) { cout << "Deleted returns, not deleted delets."; if (mas[j].isdelete == 0) { mas[j].isdelete = 1; } else(mas[j].isdelete = 0); }
			shop4.write((char*)(&mas[j]), sizeof(user));
		}
		else(shop4.write((char*)(&mas[j]), sizeof(user)));
	}
	shop4.close();
	delete[]mas;
}
void evne() {
	system("cls");
	char back;
	int count = 0;
	int key = 0, num = 0;
	vacation vacationn;
	ifstream ex1("excursion.db", ios::binary);
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
	cout << "If you want back, press SPACE" << endl;
	cin >> back;
	if (back == 32) { admin(); }
	cout << "Enter the number of your choise which you want to edit" << endl;
	cin >> key;
	ex1.close();
	ifstream ex2("excursion.db", ios::binary);
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
	ifstream ex3("excursion.db", ios::binary);
	for (int j = 0; j < count; j++)
	{
		ex3.read((char*)(&mas[j]), sizeof(user));
	}
	ex3.close();
	ofstream ex4("excursion.db", ios::binary);
	for (int j = 0; j < count; j++)
	{
		if (j == num - 1)
		{
			cout << "What do you want to change?" << endl;
			cout << "1.Name" << endl;
			cout << "2.Description" << endl;
			cout << "3.Price" << endl;
			cout << "4.Delete or return" << endl;
			cin >> key;
			if (key == 1) { cout << "New name: "; cin.ignore(); cin.getline(mas[j].name, 20); }
			else if (key == 2) { cout << "New description: "; cin.ignore(); cin.getline(mas[j].description, 150); }
			else if (key == 3) { cout << "New price: "; cin >> mas[j].price; }
			else if (key == 4) { cout << "Deleted returns, not deleted delets."; if (mas[j].isdelete == 0) { mas[j].isdelete = 1; } else(mas[j].isdelete = 0); }
			ex4.write((char*)(&mas[j]), sizeof(user));
		}
		else(ex4.write((char*)(&mas[j]), sizeof(user)));
	}
	ex4.close();
	delete[]mas;
}
void rvne() {
	system("cls");
	char back;
	int count = 0;
	int key = 0, num = 0;
	vacation vacationn;
	ifstream relax1("relaxation.db", ios::binary);
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
	cout << "If you want back, press SPACE" << endl;
	cin >> back;
	if (back == 32) { admin(); }
	cout << "Enter the number of your choise which you want to edit" << endl;
	cin >> key;
	relax1.close();
	ifstream relax2("relaxation.db", ios::binary);
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
	ifstream relax3("relaxation.db", ios::binary);
	for (int j = 0; j < count; j++)
	{
		relax3.read((char*)(&mas[j]), sizeof(user));
	}
	relax3.close();
	ofstream relax4("relaxation.db", ios::binary);
	for (int j = 0; j < count; j++)
	{
		if (j == num - 1)
		{
			cout << "What do you want to change?" << endl;
			cout << "1.Name" << endl;
			cout << "2.Description" << endl;
			cout << "3.Price" << endl;
			cout << "4.Delete or return" << endl;
			cin >> key;
			if (key == 1) { cout << "New name: "; cin.ignore(); cin.getline(mas[j].name, 20); }
			else if (key == 2) { cout << "New description: "; cin.ignore(); cin.getline(mas[j].description, 150); }
			else if (key == 3) { cout << "New price: "; cin >> mas[j].price; }
			else if (key == 4) { cout << "Deleted returns, not deleted delets."; if (mas[j].isdelete == 0) { mas[j].isdelete = 1; } else(mas[j].isdelete = 0); }
			relax4.write((char*)(&mas[j]), sizeof(user));
		}
		else(relax4.write((char*)(&mas[j]), sizeof(user)));
	}
	relax4.close();
	delete[]mas;
}
void vne() {
	int a;
	cout << "Choose which one do you want to view" << endl;
	cout << "1. Shopping" << endl;
	cout << "2. Excursion" << endl;
	cout << "3. Relaxation" << endl;
	cin >> a;
	if (a == 1) { svne(); }
	else if (a == 2) { evne(); }
	else if (a == 3) { rvne(); }
}
void admin() {
	system("cls");
	int a;
	cout << "What do you wish to do, my Lord." << endl;
	cout << "1. View tours and edit" << endl;
	cout << "2. Add new tours" << endl;
	cin >> a;
	if (a == 1) { vne(); }
	else if (a == 2) { add(); }
}

void welcome(struct user userr) {
	system("cls"); 
	int key;
	cout << "Hi, " <<userr.login << "!" << "What type of weekend would you choose?"<<endl;
	cout << "1. Relaxation"<<endl;
	cout << "2. Excursion" << endl;
	cout << "3. Shopping" << endl;
	cin >> key;
	if (key == 1) { relaxation(userr); }
	if (key == 2) { excursion(userr); }
	if (key == 3) { shopping(userr); }
}
void pay(struct user userr, struct vacation vacationn) {
	system("cls");
	sold soldd;
	char cvv[3];
	int y, m;
	soldd.id = userr.id;
	cout << "How many people?" << endl;
	cin >> soldd.a;
	if (userr.times > 5)
	{
		cout << "You bought more than 5 tours, so we give you a 10% discount";
		vacationn.price = soldd.a * (vacationn.price - (vacationn.price * 10 / 100));
	}
	else(vacationn.price = soldd.a * vacationn.price);
	cout << "You have to pay:"<<vacationn.price<<endl;
	cout << "Your login: ";
	_memccpy(soldd.login, userr.login, '\0', 20);
	cout << soldd.login;
	cout << "Enter your email: " ;
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
	ifstream users1("users.db", ios::binary);
	int count = 0;
	while (!users1.eof())
	{
		users1.read((char*)& userr, sizeof(user));
		if (users1.eof()) { break; }
		count++;
	}
	user* mas = new user[count];
	users1.close();
	ifstream users3("users.db", ios::binary);
	for (int j = 0; j < count; j++)
	{
		users3.read((char*)(& mas[j]), sizeof(user));
	}
	users3.close();
	ofstream users2("users.db", ios::binary);
	for (int j = 0; j < count; j++)
	{
		if (!strcmp(soldd.login,mas[j].login)) 
		{
			mas[j].times++;
			users2.write((char*)(&mas[j]), sizeof(user));
		}
		else(users2.write((char*)(& mas[j]), sizeof(user)));
	}
	users2.close();
	list.close();
}                                                  //СДЕЛАТЬ ЗАЩИТУ ОТ ДАУНОВ
void shopping(struct user userr) {
	system("cls");
	int key=0, num=0;
	vacation vacationn;
	ifstream shop1("shopping.db");
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
	ifstream shop2("shopping.db", ios::binary);
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
	cout << "Do you want to pay(1) or choose another one(2) or chooe another type of vacation(3)" << endl;
	cin >> key;
	if (key == 1) { pay(userr, vacationn); }
	else if (key == 2) { shopping(userr); }
	else if (key == 3) { welcome(userr); }
	shop2.close();
}
void excursion(struct user userr) {
	system("cls");
	int key=0; int num = 0;
	vacation vacationn;
	ifstream ex1("excursion.db");
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
	ifstream ex2("excursion.db");
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
	cout << "Do you want to pay(1) or choose another one(2) or chooe another type of vacation(3)" << endl;
	if (key == 1) { pay(userr, vacationn); }
	else if (key == 2) { excursion(userr); }
	else if (key == 3) { welcome(userr); }
	ex2.close();
}                                                                      //СДЕЛАТЬ ЗАЩИТУ ОТ ДАУНОВ
void relaxation(struct user userr) {
	system("cls");
	int num=0;
	int key=0;
	vacation vacationn;
	ifstream relax1("relaxation.db", ios::binary);
	while (!relax1.eof())                                           
	{
		relax1.read((char*)& vacationn, sizeof(vacation));
		if (relax1.eof()) { break; }
		if (vacationn.isdelete == 0) 
		{
			key++;
			cout <<key << ". "<< vacationn.name << endl;
			cout << vacationn.description << endl;
			cout << vacationn.price << endl;
		}
	}
	cout << "Enter the number of your choise" << endl;
	cin >> key;
	relax1.close();
	ifstream relax2("relaxation.db");
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
	cout << "Do you want to pay(1) or choose another one(2) or chooe another type of vacation(3)" << endl;
	cin >> key;
	if (key == 1) { pay(userr, vacationn); }
	else if (key == 2) {  relaxation(userr); }
	else if (key == 3) {welcome(userr);}
	relax2.close();
}
int id() {
	user userr;
	int id=0;
	ifstream users("users1.db", ios::binary);
	if (!users.is_open())
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
int reg() {
	system("cls");
	user userr;
	cout << id();
	userr.id = id();
	cout << "login: ";                                              //сделать проверку логина на уникалькость
	cin>>userr.login;
	cout << "password: ";
	cin>>userr.password;
	cout << "role(0-user; 1-admin): ";
	cin >> userr.role;
	userr.times = 0;
	ofstream users("users1.db", ios::app || ios::binary);
	users.write((char*)& userr, sizeof(user));
	users.close();
	return 0;
}
int log_in() {
	system("cls");
	user userr;
	int countl = 0, countp = 0;
	int key;
	char login[20], password[20];
	ifstream users("users.db");
	cout << "login: ";
	cin >> login;
	cout << "password: ";
	cin >> password;
	while (!users.eof())
	{
		users.read((char*)& userr, sizeof(user));
		cout << userr.login << userr.password;
		cin >> key;
		if (!strcmp(userr.login, login))
		{
			countl++;
			if (!strcmp(userr.password, password))
			{
				countp++; break;
			}
		}
	}
	if (countl == 0)
	{
		cout << "Maybe you want to register? If YES enter 1. If you want try one more time enter 2"<<endl;
		cin >> key;
		if (key == 2) { return log_in(); }
		else if (key == 1) { return reg(); }
	}
	if (countp == 0) {
		cout << "Look's like your password is wrong.  If you want try one more time enter 1"<<endl;
		cin >> key;
		if (key == 1) { return log_in(); }
		else { return 0; }
	}
	if (countl==1 && countp==1)
	{
		if (userr.role == 0) { welcome(userr); }
		else(admin());
	}
	users.close();
}
	

int main()
{  int a;                                                                          //СДЕЛАТЬ ЗАЩИТУ ОТ ДАУНОВ
	cout << "register or log in?"<<endl;                                          
	cout << "enter 1 or 2" << endl;
	cin >> a;                                                                        //СДЕЛАТЬ МЕНЯЮЩИЕСЯ СКИДКИ

	if (a == 1) { reg(); }
	if (a == 2) { log_in(); }
	

	return 0;
}