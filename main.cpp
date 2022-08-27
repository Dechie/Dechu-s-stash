#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

string condition[] = {"","new", "old"};

struct Book{
	char name[15], author[15], publisher[15];
	float cost, retailprice;
	string cond;
	int edition;
};

void addbook(Book &x);
void edit(Book x[], int limit);
void display(Book x[], int limit);
void search(Book x[], int limit);
void delbook(Book x[], int limit);



int main(){

	Book book[15];
	int choice, count = 0;
	menu: system("clear");
	cout<<"\t============================================"<<endl
		<<"\t\t******MENU******"<<endl
		<<"\t============================================"<<endl;
	re:
	cout<<"\t\tENTER YOUR CHOICE: "<<endl
		<<"\t\t1. ADD NEW BOOK"<<endl
		<<"\t\t2. DISPLAY ALL BOOKS"<<endl
		<<"\t\t3. SEARCH BOOK"<<endl
		<<"\t\t4. EDIT BOOK"<<endl
		<<"\t\t5. DELETE BOOK"<<endl
		<<"\t\t6. EXIT"<<endl
		<<"\t============================================"<<endl;
	cin>>choice;

	switch(choice){
		case 1: system("clear");
		addbook(book[count++]);
		goto menu;

		case 2: system("clear");
		display(book, count);
		goto menu;

		case 3: system("clear");
		search(book, count);
		goto menu;

		case 4: system("clear");
		edit(book, count);
		goto menu;

		case 5: system("clear");
		delbook(book, count);
		goto menu;

		case 6:
		system("clear");
		exit(0);

		default:
		cout<<"invalid choice. enter again.";
		goto re;
	}

}


void addbook(Book &x)
{
	system("clear");
	int choose;
	cout<<"\t============================================"<<endl
		<<"\t\t***** ADD NEW BOOK *****"<<endl
		<<"\t============================================"<<endl;
	cout<<"\t\tENTER BOOK NAME: "; 
	cin>>x.name;
	cout<<"\t\tENTER BOOK AUTHOR: ";
	cin>>x.author;
	cout<<"\t\tENTER BOOK PUBLISHER: ";
	cin>>x.publisher;
	cout<<"\t\tENTER BOOK COST: ";
	cin>>x.cost;
	cout<<"\t\tENTER BOOK RETAIL PRICE: ";
	cin>>x.retailprice;
	re:
	cout<<"\t\tENTER BOOK CONDITION (1. NEW, 2. OLD): "; 
	cin>>choose;
	if (choose != 1 && choose != 2)
	{
		cout<<"\t\tINVALID CHOICE. ENTER AGAIN.\n";
		goto re;
	}
	else 
		x.cond = condition[choose-1];
	cout<<"\t\tENTER EDITION NUMBER: ";
	cin>>x.edition;

}
void display(Book x[], int limit)
{
	system("clear");
	char key;
	cout<<"\t============================================"<<endl
		<<"\t\t***** BOOK LIST *****"<<endl
		<<"\t============================================"<<endl;
	cout<<"\t\tNAME\tAUTHOR\tPUBLISHER\tCOST\tRETAIL\tCONDITION\tEDITION"<<endl;
	for (int i = 0; i < limit; i++)
	{
		cout<<"\t\t"<<x[i].name<<"\t"<<x[i].author<<"\t"
			<<x[i].publisher<<"\t"<<x[i].cost<<"\t"
			<<x[i].retailprice<<"\t"<<x[i].cond<<"\t"<<x[i].edition<<endl;
	}
	cout<<"\t\tPRESS ANY KEY TO GO BACK TO MENU";
	cin>>key;
	if(int(key) >= 0 && int(key) <= 122)
		cout<<" ";
		//goto menu;

}
void edit(Book x[], int limit)
{
	system("clear");
	char name[15], newname[15]; int choice2;
	cout<<"\t============================================"<<endl
		<<"\t\t***** BOOK LIST *****"<<endl
		<<"\t============================================"<<endl;
	cout<<"\t\tENTER NAME OF BOOK TO EDIT: ";
	cin>>name;
	for (int i = 0; i < limit; i++)
	{
		if (strcmp(name, x[i].name) == 0)
		{
			cout<<"\t\tBOOK FOUND. "<<endl;
			re:
			cout<<"\t\t1. EDIT NAME "<<endl;

			cin>>choice2;
			switch (choice2){
				case 1:
				cout<<"\t\tENTER NEW NAME: "; cin>>newname;
				strcpy(x[i].name, name);
			}

		}
	}

}


void search(Book x[], int limit)
{
	char search[10]; char go, s = 'f';
	int count = 0, choose;
	string array[limit];
	cout<<"\t============================================"<<endl
		<<"\t\t***** BOOK SEARCH *****"<<endl
		<<"\t============================================"<<endl;
	cout<<"\t\tENTER NAME OF BOOK: ";
	cin>>search;
	for (int i = 0; i < limit; i++)
	{
		int count = 0, choose;
		
		
		if (strcmp(search, x[i].name) == 0)
		{
			cout<<"\t\tBOOK(S) FOUND. "<<endl;
			cout<<"\tSEARCH RESULTS: "<<endl;
			while (count<limit)
			{				
				cout<<count+1<<". "<<x[i].name<<endl;
				array[count++] = x[i].name;
			}
			break;
			
		}

		else{
			cout<<"\tSTUDENT NOT FOUND."<<endl
				<<"\t\tPRESS ANY KEY THEN ENTER TO GO BACK TO MENU: "; cin>>go;
				s = 'n';
		}
	}

	if (s == 'f')
	{
		cout<<"\tENTER YOUR CHOICE."; cin>>choose;
			if ((choose - 1) == count)
			{
				cout<<"\tID\tNAME\n";
				cout<<"\t============================================"<<endl
					<<"\t\tBOOK: "<<x[count].name<<endl
					<<"\t\tAUTHOR: "<<x[count].author<<endl
					<<"\t\tPUBLISHER: "<<x[count].publisher<<endl
					<<"\t\tCOST: "<<x[count].cost<<endl
					<<"\t\tCONDITION: "<<x[count].cond<<endl
					<<"\t============================================"<<endl
					<<"\t\tPRESS ANY KEY THEN ENTER TO GO BACK TO MENU: "; cin>>go;
			}
	}
}


void delbook(Book x[], int limit)
{
	system("clear");
	char name[15], newname[15]; int choice2;
	cout<<"\t============================================"<<endl
		<<"\t\t***** DELETE A BOOK *****"<<endl
		<<"\t============================================"<<endl;
	cout<<"\t\tENTER NAME OF BOOK TO EDIT: ";
	cin>>name;
	for (int i = 0; i < limit; i++)
	{
		if (strcmp(name, x[i].name) == 0)
		{
			cout<<"\t\tBOOK FOUND. "<<endl;
			strcpy(x[i].name, " ");
			strcpy(x[i].author, " ");
			strcpy(x[i].publisher, " ");
			x[i].cond = " ";
			x[i].cost = 0; x[i].retailprice = 0; x[i].edition = 0;
		}

	}

}