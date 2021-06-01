#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "BookStore.h"
using namespace std;
int main() {
	BookStore *b,*c;
	Books b1;
	CD c1;
	b = &b1; //yerlerini atadýk
	c = &c1;
	int i = 0, r, t, choice;
	char namebuy[1000], authorbuy[500]; 
	while (1) {
		
		cout << "\n\t\tMENU"<<endl;
		cout << "-------------------------------------"<<endl;
		cout<<"\n1. Entry of New Book \n2. Buy Book\n3. Search For Book\n4. Edit Details Of Book\n5. Entry of New CD";
		cout<<"\n6. Buy CD \n7. Search For CD\n8. Edit Details Of CD\n9. Show Inventory\n10. Exit\n\nEnter your Choice: ";
		cin >> choice;
		
		switch (choice) {
		case 1:
			b = new BookStore;
			b->girdialbook();	
			b->booktxt();
			i++;
			break;

		case 2: 
			cin.ignore();
			cout << "\nEnter Title Of Book: ";
			cin.getline(namebuy, 1000);
			cout << "Enter Author Of Book: ";
			cin.getline(authorbuy, 500);
			for (t = 0; t < i; t++) {
				if (b->search(namebuy, authorbuy)) {
					b->buybook();
					break;
				}
			}
			if (t == 1)
				cout << "\nThis Book is Not in Stock!";
			b->booktxt();
			break;
		case 3: 
			
			cin.ignore();
			cout << "\nEnter Title Of Book: ";
			cin.getline(namebuy, 1000);
			cout << "Enter Author Of Book: ";
			cin.getline(authorbuy, 500);

			for (t = 0; t < i; t++) {

				if (b->search(namebuy, authorbuy)) {
					cout << "\nBook Found Successfully."<<endl;
					b->show();
					
					break;
				}
			}
			
			if (t == i)
				cout << "\nThis Book is Not in Stock!";
		
			break;

		case 4: 
			cin.ignore();
			cout << "\nEnter Title Of Book: ";
			cin.getline(namebuy, 1000);
			cout << "Enter Author Of Book: ";
			cin.getline(authorbuy, 500);
			for (t = 0; t < i; t++) {
				if (b->search(namebuy, authorbuy)) {
					cout << "\nBook Found Successfully."<<endl;
					b->edit();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in Stock!";
			
			break;
		case 5: 
			c= new BookStore;
			c->girdialcd();
			c->cdtxt();
			i++;
			break;
		case 6:
			cin.ignore();
			cout << "\nEnter Title of CD: ";
			cin.getline(namebuy, 1000);
			cout << "Enter Producer Of CD: ";
			cin.getline(authorbuy, 500); 
			for (t = 0; t < i; t++) {
				if (c->search(namebuy, authorbuy)) {
					c->buycd();
					break;
				}
			}
			if (t == 1)
				cout << "\nThis CD is Not in Stock.";
			c->cdtxt();
			break;
		case 7:
			cin.ignore();
			cout << "\nEnter Title Of CD: ";
			cin.getline(namebuy, 1000);
			cout << "Enter Producer Of CD: ";
			cin.getline(authorbuy, 500);

			for (t = 0; t < i; t++) {
				if (c->search(namebuy, authorbuy)) {
					cout << "\nCD Found Successfully."<<endl;
					c->show();
					break;
				}
			}
			if (t == i)
				cout << "\nThis CD is Not in Stock!";
			c->cdtxt();
			break;
		case 8:
			cin.ignore();
			cout << "\nEnter Title Of CD: ";
			cin.getline(namebuy, 1000);
			cout << "Enter Producer of CD: ";
			cin.getline(authorbuy, 500);

			for (t = 0; t < i; t++) {
				if (c->search(namebuy, authorbuy)) {
					cout << "\nCD Found Successfully."<<endl;
					c->editcd();
					break;
				}
			}
			if (t == i)
				cout << "\nThis CD is Not in Stock!";
			c->cdtxt();
			break;
		case 9:
			b->readfile();
			break;
		case 10: exit(0);
		default: cout << "\nInvalid Choice Entered!";

		}
	
	}
	
	system("pause");
}
