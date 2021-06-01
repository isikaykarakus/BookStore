#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BookStore {
public:
	 char *name;
	 char *author;
	 float *price;
	 int *stock;
	 char *type;

	BookStore() {
		author = new char[500];
		name = new char[1000];
		type = new char[50];
		price = new float;
		stock = new int;
	}
	BookStore(char *_name, char *_author, float *_price, int *_stock) {
		name = new char[strlen(_name)];
		strcpy(name, _name);
		author = new char[strlen(_author)];
		price = _price;
		stock = _stock;
	}
	virtual void girdialbook(BookStore&) {};
	virtual void girdialcd(BookStore&) {};
	void edit();
	void show();
	int search(char[], char[]);
	void buybook();
	void editcd();
	void buycd();
	void booktxt();
	void cdtxt();
	void readfile();
};
class Books :public virtual BookStore {
public:
	Books() {};
	Books(char *_name, char *_author, float *_price, int *_stock): BookStore(_name, _author, _price, _stock) {}
	
};
class Novels :public Books {
public:
	Novels() {};
	Novels(char *_name, char *_author, float *_price, int *_stock): Books(_name, _author, _price, _stock) {}
	void girdialbook(Novels&);
};
class UniversityBooks : public Books {
public:
	UniversityBooks(){}
	UniversityBooks(char *_name, char *_author, float *_price, int *_stock) :Books(_name, _author, _price, _stock)  {}
	void girdialbook(UniversityBooks&);
};
class CD :public virtual BookStore {
public:
	CD() {};
	CD(char *_name, char *_author, float *_price, int *_stock):BookStore(_name, _author, _price, _stock) {}
	
};
class EducationCD :public CD {
public:
	EducationCD() {};
	EducationCD(char *_name, char *_author, float *_price, int *_stock):CD(_name, _author, _price, _stock) {}
	void girdialcd(EducationCD&);
};
class MusicCD : public CD {
	MusicCD() {};
	MusicCD(char *_name, char *_author, float *_price, int *_stock):CD(_name, _author, _price, _stock) {}
	void girdialcd(MusicCD&);
};
class MovieCD :public CD {
	MovieCD() {};
	MovieCD(char *_name, char *_author, float *_price, int *_stock):CD(_name, _author, _price, _stock) {} 
	void girdialcd(MovieCD&);
};
class Education : public EducationCD, public UniversityBooks {
	Education() {}
	Education(char *_name, char *_author, float *_price, int *_stock):BookStore(_name, _author, _price, _stock){}
	void girdialcd(Education&);
};

#endif
