#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "BookStore.h"
using namespace std;

void BookStore :: girdialbook(BookStore&B) {//yeni kitap girme fonksiyonu
	cin.ignore();
	cout << "\nEnter Author Name: ";
	cin.getline(author, 500);
	
	cout << "Enter Title Name: ";
	cin.getline(name, 1000);

   cout << "Enter the tpye of the book: ";
	cin.getline(type, 500);

	cout << "Enter Price: ";
	cin >> *price;
	
	cout << "Enter Stock Position: ";
	cin >> *stock;
	B = BookStore(name, author, price, stock));
	
	
}
void BookStore::girdialcd(BookStore&C) {
	cin.ignore();
	cout << "\nEnter Producer Name: ";
	cin.getline(author, 500);

	cout << "Enter Title Name: ";
	cin.getline(name, 1000);

	cout << "Enter the tpye of the cd: ";
	cin.getline(type, 500);

	cout << "Enter Price: ";
	cin >> *price;

	cout << "Enter Stock Position: ";
	cin >> *stock;
	C = BookStore(name, author, price, stock);

}
void BookStore::edit() { //kitap düzenleme fonksiyonu
	cout << "\nEnter Author Name: ";
	cin.getline(author, 500);
	cout << "Enter Title Name: ";
	cin.getline(name, 1000);
	cout << "Enter the type of the book: ";
	cin.getline(type, 500);
	cout << "Enter Price: ";
	cin >> *price;
	cout << "Enter Stock Position: ";
	cin >> *stock;

}
void BookStore::editcd() { //cd düzenleme fonksiyonu
	cout << "\nEnter producer Name: ";
	cin.getline(author, 500);
	cout << "Enter Title Name: ";
	cin.getline(name, 1000);
	cout << "Enter the tpye of the book: ";
	cin.getline(type, 500);

	cout << "Enter Price: ";
	cin >> *price;
	cout << "Enter Stock Position: ";
	cin >> *stock;

}
void BookStore::show() {//kitap gösterme fonksiynu
	cout << "						" << endl;
	cout << "\nAuthor Name: " << author;
	cout << "\nTitle Name: " << name;
	cout << "\nType: " << type;
	cout << "\nPrice: " << *price;
	cout << "\nStock Position: " << *stock;

}
int BookStore::search(char namebuy[1000],char authorbuy[500])
{//Arama fonksiyonu
	char a[500];
	char n[1000];
	ifstream bookstoreread;
	bookstoreread.open("bookstore.txt");

	while (!bookstoreread.eof())
	{
		cin.ignore();
		bookstoreread.getline(n, 1000,'\n');
		bookstoreread.getline(a, 500,'\n');
		if (strcmp(namebuy, n) == 0 && strcmp(authorbuy, a) == 0) {//strcmp alýnan stringleri karþýlaþtýrýrýr
			return 1;//bu iki string birbine eþitse kitap var
			
		}
		else return 0;//Deðilse kitap yok
		bookstoreread.close();
	}
}
void BookStore::readfile() {
	ifstream bookstoreread;
	bookstoreread.open("bookstore.txt", ios::in);
	string line;

	while (!bookstoreread.eof())
	{
		getline(bookstoreread, line);
		cout << line << "\n";
	}
	bookstoreread.close();
}

void BookStore::buybook() {//kitap satýn alma fonksiyonu
	int count;
	cout << "\nEnter Number Of Books to buy: ";
	cin >> count;
	if (count <= *stock) {
		*stock = *stock - count;

		cout << "\nAmount: " << (*price)*count << "tl";
		cout << "\n\nBooks Bought Sucessfully! :) " << endl;
	}
	else
		cout << "\nRequired Copies not in Stock";

}
void BookStore::buycd() {//cd satýn alma fonksiyonu
	int count;
	cout << "\nEnter Number Of CD to buy: ";
	cin >> count;
	if (count <= *stock) {
		*stock = *stock - count;

		cout << "\nAmount: " << (*price)*count << "tl";
		cout << "\n\nCDs Bought Sucessfully! :) " << endl;
	}
	else
		cout << "\nRequired Copies not in Stock";

}

void BookStore:: booktxt() {//txt dosyasý açma içine girdi yazdýrma fonksiyonu kitap için
	fstream bookstore;//bookstore txtyi açar içini okumak ve girdi yazmak için
	bookstore.open("bookstore.txt", ios::out | ios::app);
    
	if (!bookstore) {
		cerr << "file could not be opened." << endl;
		exit(1);
	}
	
	bookstore << name << endl;
	bookstore << author << endl;
	bookstore << *stock<< endl;
	bookstore <<*price << endl;
	bookstore << type << endl;
	
	bookstore.close();
}
void BookStore::cdtxt() {//cd için
	fstream bookstore;//bookstore txtyi açar içini okumak ve girdi yazmak için
	bookstore.open("bookstore.txt", ios::out | ios::app);

	if (!bookstore) {
		cerr << "File Could Not Be Opened." << endl;
		exit(1);
	}
	
	bookstore << name << endl;
	bookstore << author << endl;
	bookstore << *stock << endl;
	bookstore << *price << endl;
	bookstore << type << endl;

	bookstore.close();
}

void Novels::girdialbook(Novels &N)
{
	cout << "\nEnter Author Name: ";
	cin.getline(author, 500);

	cout << "Enter Title Name: ";
	cin.getline(name, 1000);

	cout << "Enter the tpye of the book: ";
	 cin.getline(type, 500);

	cout << "Enter Price: ";
	cin >> *price;

	cout << "Enter Stock Position: ";
	cin >> *stock;
	N=Novels(name, author, price, stock);
}

void UniversityBooks::girdialbook(UniversityBooks &U)
{
	cout << "\nEnter Author Name: ";
	cin.getline(author, 500);

	cout << "Enter Title Name: ";
	cin.getline(name, 1000);

	cout << "Enter the tpye of the book: ";
	cin.getline(type, 500);

	cout << "Enter Price: ";
	cin >> *price;

	cout << "Enter Stock Position: ";
	cin >> *stock;
	U= UniversityBooks(name, author, price, stock));
}

void EducationCD::girdialcd(EducationCD &E)
{
	cout << "\nEnter producer Name: ";
	cin.getline(author, 500);
	cout << "Enter Title Name: ";
	cin.getline(name, 1000);
	cout << "Enter the tpye of the book: ";
	cin.getline(type, 500);

	cout << "Enter Price: ";
	cin >> *price;
	cout << "Enter Stock Position: ";
	cin >> *stock;
	E = EducationCD(name,author, price, stock);
}

void MusicCD::girdialcd(MusicCD &M)
{
	cout << "\nEnter producer Name: ";
	cin.getline(author, 500);
	cout << "Enter Title Name: ";
	cin.getline(name, 1000);
	cout << "Enter the tpye of the book: ";
	cin.getline(type, 500);

	cout << "Enter Price: ";
	cin >> *price;
	cout << "Enter Stock Position: ";
	cin >> *stock;
	M = MusicCD(name, author, price, stock);
}

void MovieCD::girdialcd(MovieCD &m)
{
	cout << "\nEnter producer Name: ";
	cin.getline(author, 500);
	cout << "Enter Title Name: ";
	cin.getline(name, 1000);
	cout << "Enter the tpye of the book: ";
	cin.getline(type, 500);

	cout << "Enter Price: ";
	cin >> *price;
	cout << "Enter Stock Position: ";
	cin >> *stock;
	m = MovieCD(name, author, price, stock);
}

void Education::girdialcd(Education &Ed)
{
	cout << "\nEnter producer Name: ";
	cin.getline(author, 500);
	cout << "Enter Title Name: ";
	cin.getline(name, 1000);
	cout << "Enter the tpye of the book: ";
	cin.getline(type, 500);

	cout << "Enter Price: ";
	cin >> *price;
	cout << "Enter Stock Position: ";
	cin >> *stock;
	Ed= Education(name, author, price, stock);
}
