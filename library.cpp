#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<process.h>


void welcome();
void menu();
void myprofile();
char* password();
void seller_();
void newseller();
void existingseller();
void seller_actions(int,char*);
void book_add(int,char*);
void book_modify(int);
void modify_access(int);
void modify_title(int);
void modify_author(int);
void modify_cost(int);
void coustomer_();
void newscoustomer();
void existingcoustomer();
void coustomer_actions(int,char*);
void book_search(int,char*);
void search_access(int,char*);
void search_title(int,char*);
void search_author(int,char*);
void search_cost(int,char*);
int table(int,char,int);
int generate_id(char*,char);
void purchase(int);
void addtocart(int);
void deletecart(int);
void viewcart(int);
void bill();
void clrscr();


void clrscr()
{
	system("cls");
}
class info
{	
public:
	int access,cost;
	char author[20],title[20];
};

class coustomer : private info
{
	char username[20],pass[15];
	int id;
public:
	void getnewaccountdata();
	char* getusername();
	char* getpass();
	int getaccess();
	int getcost();
	char* getauthor();
	char* gettitle();
	int getid();
	void assingid(int);
	char putbook();
	int bill(int);
};

char coustomer :: putbook()
{
	char ans;
	cout<<"\n\nCode: "<<access<<"\nTitle: "<<title<<"\nAuthor: "<<author<<"\nCost: "<<cost;
	cout<<"\n\nEnter choice (y/n): ";
cin>>ans;
return ans;
}

void coustomer:: assingid(int i)
{
	id=i;
}
int coustomer:: getid()
{
	return id;
}
int coustomer:: getaccess()
{
	return access;
}
int coustomer:: getcost()
{
	return cost;
}
char* coustomer:: gettitle()
{
	return title;
}
char* coustomer:: getauthor()
{
	return author;
}

char* coustomer:: getusername()
{
	return username;
}

char* coustomer:: getpass()
{
	return pass;
}
void coustomer:: getnewaccountdata()
{
		label:
		coustomer obj;
		char pass1[10];
		int flag=0;
		clrscr();
		cout<<"\nEnter username: ";
		cin>>username;
		fstream f;
		f.open("coustomer.dat",ios::in|ios::binary);
		if(!f)
		{	f.close();
			goto passcode;
		}
		while(f.read((char*)&obj,sizeof(obj)))
		{
			if(strcmp(obj.getusername(),username)==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"\nUser name aldready taken.";
			cout<<"\nPress enter to continue .....";
			getch();
			clrscr();
			f.close();
			goto label;
		}
	
			f.close();
		passcode:
		cout<<"\nCreate password: ";
		cin>>pass;
		if(strlen(pass)<=3 || strlen(pass)>14)
	{
		cout<<"\nPassword should me minimum of 4 characters and maximum of 14 characters.";
		cout<<"\nPress enter to continue .....";
		getch();
		goto passcode;
	}
		cout<<"\nConfirm password: ";
		cin>>pass1;
		if(strcmp(pass,pass1)!=0)
		{
			cout<<"\nError passwords dont match.";
			cout<<"\nPress enter to continue: ";
			getch();
			goto passcode;
		}
		else
			cout<<"\nAccount created successfully.";
			cout<<"\nPress enter to continue ..... ";
			getch();

}





class seller : private info
{
	char username[20],pass[15];
	int id;
public:
	char* getusername();
	char* getpass();
	void getnewaccountdata();
	void get_book_data();
	int getaccess();
	int getcost();
	void access_assign(int);
	void cost_assign(int);
	char* getauthor();
	char* gettitle();
	int getid();
	void assignid(int);
	char putbook();
};
	int seller:: getid()
	{
		return id;
	}

	void seller:: assignid(int i)
	{
		id=i;
	} 
	void seller :: access_assign(int n)
	{
		access=n;
	}

	void seller:: cost_assign(int n)
	{
		cost=n;
	}
	int seller:: getaccess()
	{
		return access;
	}
	
	int seller:: getcost()
	{
		return cost;
	}

	char* seller:: getauthor()
	{
		return author;
	}

	char* seller:: gettitle()
	{
		return title;
	}

	void seller :: get_book_data()
	{
		clrscr();
		label:
		cout<<"\nEnter access code of the book: ";
		cin>>access;
		fstream f;
		seller s;
		f.open("books.dat",ios::in|ios::binary);
		while(f.read((char*)&s,sizeof(s)))
		{
			if(s.getaccess()==access)
			{
				cout<<"\nAccess number aldready taken.";
				cout<<"\nPress enter to continue .....";
				getch();
				f.close();
				goto label;
			}	
		}
		f.close();
		title:
		cout<<"\nEnter title of the book: ";
		cin>>title;
		if(strlen(title)>19)
		{
			cout<<"\nTitle can be maximum of 19 characters only.";
			cout<<"\nPress enter to continue .....";
				getch();
				goto title;
		}
		author:
		cout<<"\nEnter name of the author of this book: ";
		cin>>author;
		if(strlen(author)>19)
		{
			cout<<"\nAuthor name can be maximum of 19 characters only.";
			cout<<"\nPress enter to continue .....";
				getch();
				goto author;;

		}
		cost:
		cout<<"\nEnter cost of the book: ";
		cin>>cost;
		if(cost<=0)
		{
			cout<<"\nEnter valid amount.";
			cout<<"\nPress enter to continue .....";
				getch();
				goto cost;
		}
		cout<<"\n\nBook added successfully.";
		cout<<"\nPress enter to continue .....";
		getch();
	}
	char* seller :: getusername()
	{
		return username;
	}
	char* seller ::getpass()
	{
		return pass;
	}
	char seller :: putbook()
{
	char ans;
	cout<<"\n\nCode: "<<access<<"\nTitle: "<<title<<"\nAuthor: "<<author<<"\nCost: "<<cost;
	cout<<"\n\nEnter choice (y/n): ";
cin>>ans;
return ans;
}
	
	void seller:: getnewaccountdata()
	{
		label:
		seller obj;
		char pass1[10];
		int flag=0;
		clrscr();
		cout<<"\nEnter username: ";
		cin>>username;
		fstream f;
		f.open("seller.dat",ios::in|ios::binary);
		if(!f)
		{	f.close();
			goto passcode;
		}
		while(f.read((char*)&obj,sizeof(obj)))
		{
			if(strcmp(obj.getusername(),username)==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"\nUser name aldready taken.";
			cout<<"\nPress enter to continue .....";
			getch();
			clrscr();
			f.close();
			goto label;
		}
	
			f.close();
		passcode:
		cout<<"\nCreate password: ";
		cin>>pass;
		if(strlen(pass)<=3 || strlen(pass)>14)
	{
		cout<<"\nPassword should me minimum of 4 characters and maximum of 14 characters.";
		cout<<"\nPress enter to continue .....";
		getch();
		goto passcode;
	}
		cout<<"\nConfirm password: ";
		cin>>pass1;
		if(strcmp(pass,pass1)!=0)
		{
			cout<<"\nError passwords dont match.";
			cout<<"\nPress enter to continue: ";
			getch();
			goto passcode;
		}
		else
			cout<<"\nAccount created successfully.";
			cout<<"\nPress enter to continue .....";
			getch();
	}

	void book_add(int id,char user[20])
	{
		seller t;
		fstream f;
		char ans='y';
		while(ans=='y'||ans=='Y')
		{
		t.get_book_data();
		f.open("books.dat",ios::app|ios::binary);
		strcpy(t.getusername(),user);
		t.assignid(id);
		f.write((char*)&t,sizeof(t));
		f.close();
		cout<<"\nWant to add another book. (y/n): ";
		cin>>ans;
		}
	}

	void book_modify(int id)
	{	
		start:
		clrscr();
		int choice;
		cout<<"\nMenu:";
		cout<<"\n1.Modify access no.";
		cout<<"\n2.Modify title of the book";
		cout<<"\n3.Modify author name.";
		cout<<"\n4.Modify cost of the book.";
		cout<<"\n5.Go back.";
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: modify_access(id);break;
			case 2: modify_title(id);break;
			case 3: modify_author(id);break;
			case 4: modify_cost(id);break;
			case 5: break;
			default: cout<<"\nInvalid choice.";
			cout<<"\nPress enter to continue .....";
			getch();
			goto start;
		}	
	}

	void modify_access(int id)
	{	
		clrscr();
		seller s;
		int no,newno,flag=0,pos=0;
		char ans;
		cout<<"\nEnter the access no of the book you want to modify: ";
		cin>>no;
		fstream f;
		f.open("books.dat",ios::in|ios::out|ios::binary);
		while(f.read((char*)&s,sizeof(s)))
		{
			if(s.getid()==id)
			if(s.getaccess()==no)
			{
				cout<<"\nAre you sure you want to modify access no of this book:\n";
				ans=s.putbook();
				if(ans=='n'||ans=='N')
					goto skip;
				f.seekp(pos);
				cout<<"\nEnter the modified access no: ";
				cin>>newno;
				fstream f1;
				seller t;
				f1.open("books.dat",ios::in|ios::binary);
			while(f1.read((char*)&t,sizeof(t)))
			{
			if(t.getaccess()==newno)
			{
				cout<<"\nAccess number aldready taken.";
				cout<<"\nPress enter to continue .....";
				getch();
				f1.close();
				flag=-1;
				break;
			}	
			}
				if(flag==-1)
					break;
				s.access_assign(newno);
				f.write((char*)&s,sizeof(s));
				flag=1;
				cout<<"\nData updated successfully.";
				cout<<"\nPress enter to continue .....";
				getch();
				break;
			}
			pos=f.tellg();
		}
		if(flag==0)
		{
			cout<<"\nAccess no does not exist.";
			cout<<"\nData updation failed!!!";
			cout<<"\nPress enter to continue .....";
			getch();
		}
		skip:
		f.close();
	}

	void modify_title(int id)
	{
		clrscr();
		seller s;
		char ans;
		int no,flag=0,pos=0;
		char newt[20];
		cout<<"\nEnter the access no of the book you want to modify: ";
		cin>>no;
		fstream f;
		f.open("books.dat",ios::in|ios::out|ios::binary);
		while(f.read((char*)&s,sizeof(s)))
		{
			if(s.getid()==id)
			if(s.getaccess()==no)
			{
				cout<<"\nAre you sure you want to modify title of this book:\n";
				ans=s.putbook();
				if(ans=='n'||ans=='N')
					goto skip;
				f.seekp(pos);
				title:
				cout<<"\nEnter the modified title: ";
				cin>>newt;
				if(strlen(newt)>19)
		{
			cout<<"\nTitle can be maximum of 19 characters only.";
			cout<<"\nPress enter to continue .....";
				getch();
				goto title;
		}
				strcpy(s.gettitle(),newt);
				f.write((char*)&s,sizeof(s));
				flag=1;
				cout<<"\nData updated successfully.";
				cout<<"\nPress enter to continue .....";
				getch();
				break;
			}
			pos=f.tellg();
		}
		if(flag==0)
		{
			cout<<"\nAccess no does not exist.";
			cout<<"\nData updation failed!!!";
			cout<<"\nPress enter to continue .....";
			getch();
		}
		skip:
		f.close();
	}

	void modify_author(int id)
	{
		clrscr();
		seller s;
		char ans;
		int no,flag=0,pos=0;
		char newa[20];
		cout<<"\nEnter the access no of the book you want to modify: ";
		cin>>no;
		fstream f;
		f.open("books.dat",ios::in|ios::out|ios::binary);
		while(f.read((char*)&s,sizeof(s)))
		{
			if(s.getid()==id)
			if(s.getaccess()==no)
			{
				cout<<"\nAre you sure you want to modify author name of this book:\n";
				ans=s.putbook();
				if(ans=='n'||ans=='N')
					goto skip;	
				f.seekp(pos);
				author:
				cout<<"\nEnter the modified author name: ";
				cin>>newa;
				if(strlen(newa)>19)
		{
			cout<<"\nAuthor name can be maximum of 19 characters only.";
			cout<<"\nPress enter to continue .....";
				getch();
				goto author;
		}
				strcpy(s.getauthor(),newa);
				f.write((char*)&s,sizeof(s));
				flag=1;
				cout<<"\nData updated successfully.";
				cout<<"\nPress enter to continue .....";
				getch();
				break;
			}
			pos=f.tellg();
		}
		if(flag==0)
		{
			cout<<"\nAccess no does not exist.";
			cout<<"\nData updation failed!!!";
			cout<<"\nPress enter to continue .....";
			getch();
		}
		skip:
		f.close();
	}

	void modify_cost(int id)
	{
		clrscr();
		seller s;
		int no,newcost,flag=0,pos=0;
		char ans;
		cout<<"\nEnter the access no of the book you want to modify: ";
		cin>>no;
		fstream f;
		f.open("books.dat",ios::in|ios::out|ios::binary);
		while(f.read((char*)&s,sizeof(s)))
		{
			if(s.getid()==id)
			if(s.getaccess()==no)
			{
				cout<<"\nAre you sure you want to modify cost of this book:\n";
				ans=s.putbook();
				if(ans=='n'||ans=='N')
					goto skip;	
				f.seekp(pos);
				cost:
				cout<<"\nEnter the modified cost: ";
				cin>>newcost;
				if(newcost<=0)
		{
			cout<<"\nEnter valid amount.";
			cout<<"\nPress enter to continue .....";
				getch();
				goto cost;
		}
				s.cost_assign(newcost);
				f.write((char*)&s,sizeof(s));
				flag=1;
				cout<<"\nData updated successfully.";
				cout<<"\nPress enter to continue .....";
				getch();
				break;
			}
			pos=f.tellg();
		}
		if(flag==0)
		{
			cout<<"\nAccess no does not exist.";
			cout<<"\nData updation failed!!!";
			cout<<"\nPress enter to continue .....";
			getch();
		}
		skip:
		f.close();
	}
	void seller_actions(int id,char user[20])
	{
		clrscr();
		int choice;
		label:
		cout<<"\nMenu: ";
		cout<<"\n1.Add book information.";
		cout<<"\n2.Modify book information.";
		cout<<"\n3.Your books.";
		cout<<"\n4.Go back.";
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: book_add(id,user);break;
			case 2: book_modify(id);break;
			case 3: table(0,'s',id);break;
			case 4: goto skip;
			default:cout<<"Invalid option.";
			cout<<"\nPress enter to contine.";
			getch();
			goto label;
		}
		seller_actions(id,user);
		skip:
		cout<<" ";
	}
	char* password()
	{
		char a[15];
		int length;
		cout<<"\nEnter password: ";
		for(int i=0;i<15;++i)
		{
			a[i]=getch();
			if((int)a[i]==13)
			{
				a[i]='\0';
				break;
			}
			cout<<"*";
		}
		return a;
	}

	
	void newseller()
	{
		seller s;
		fstream f;
		f.open("seller.dat",ios::app|ios::binary);
		s.getnewaccountdata();
		f.write((char*)&s,sizeof(s));
		f.close();
	}
	
	void existingseller()
	{
		clrscr();
		seller obj;
		char u[20],p[15];
		int flag=0;
		cout<<"\nEnter username: ";
		cin>>u;
		strcpy(p,password());
		fstream f;
		f.open("seller.dat",ios::in|ios::binary);
		while(f.read((char*)&obj,sizeof(obj)))
			{
				if (strcmp(obj.getusername(),u)==0)
					if(strcmp(obj.getpass(),p)==0)
					{
						flag=1;
						cout<<"\nAccess granted.";
						cout<<"\nPress enter to continue .....";
						getch();
						break;
					}
			}
		f.close();
		if(flag==0)
		{
			cout<<"\nInvalid username or password.";
			cout<<"\nAccess denied.";
			cout<<"\nPress enter to continue .....";
			getch();
		}
		else
		{
			int id = generate_id(obj.getusername(),'s');
			seller_actions(id,obj.getusername());
		}
	}

void seller_()
	{	int choice;
		start:
		clrscr();
		cout<<"\n1.New Seller.";
		cout<<"\n2.Existing Seller.";
		cout<<"\n3.Go back.";
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: newseller();break;
			case 2: existingseller();break;
			case 3: goto skip;
			default: cout<<"\nInvalid option!!!";
			cout<<"\npress enter to continue .....";
			getch();
			goto start;
		}
		seller_();
		skip:
			cout<<" ";
	}

void coustomer_()
{
		int choice;
		start:
		clrscr();
		cout<<"\n1.New Coustomer.";
		cout<<"\n2.Existing Coustomer.";
		cout<<"\n3.Go back.";
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: newscoustomer();break;
			case 2: existingcoustomer();break;
			case 3: goto skip;
			default: cout<<"\nInvalid option!!!";
			cout<<"\npress enter to continue .....";
			getch();
			goto start;
		}
		coustomer_();
		skip:
			cout<<" ";
}

void newscoustomer()
{
	coustomer c;
	fstream f;
	f.open("coustomer.dat",ios::app|ios::binary);
	c.getnewaccountdata();
	f.write((char*)&c,sizeof(c));
	f.close();
}

void existingcoustomer()
{
		clrscr();
		coustomer obj;
		char u[20],p[15];
		int flag=0;
		cout<<"\nEnter username: ";
		cin>>u;
		strcpy(p,password());
		fstream f;
		f.open("coustomer.dat",ios::in|ios::binary);
		while(f.read((char*)&obj,sizeof(obj)))
			{
				if (strcmp(obj.getusername(),u)==0)
					if(strcmp(obj.getpass(),p)==0)
					{
						flag=1;
						cout<<"\nAccess granted.";
						cout<<"\nPress enter to continue .....";
						getch();
						break;
					}
			}
		f.close();
		if(flag==0)
		{
			cout<<"\nInvalid username or password.";
			cout<<"\nAccess denied.";
			cout<<"\nPress enter to continue .....";
			getch();
		}
		else
		{
			int id = generate_id(obj.getusername(),'c');
			coustomer_actions(id,obj.getusername());
		}
}

int generate_id(char user[20],char ch)
{	
	label:
	int id,flag=0;
	clrscr();
	fstream f;
	if(ch=='c')
	{
		coustomer c;
		cout<<"\nEnter your coustomer id: ";
		cin>>id;
		f.open("cart.dat",ios::in|ios::binary);
		if(!f)
	goto pos;
	while(f.read((char*)&c,sizeof(c)))
	{
		if(c.getid()==id)
				if(strcmp(c.getusername(),user)!=0)
				{
					flag=1;
					cout<<"\nId not available.";
					cout<<"\nPress enter to continue .....";
					getch();
					goto label;
				}
				else
					break;
	}
	pos:
	f.close();
	}
	else
		if(ch=='s')
		{
			seller s;
		cout<<"\nEnter your Seller id: ";
		cin>>id;
		f.open("books.dat",ios::in|ios::binary);
		if(!f)
	goto pos1;
	while(f.read((char*)&s,sizeof(s)))
	{
		if(s.getid()==id)
				if(strcmp(s.getusername(),user)!=0)
				{
					flag=1;
					cout<<"\nId not available.";
					cout<<"\nPress enter to continue .....";
					getch();
					goto label;
				}
				else
					break;
	}
	pos1:
	f.close();
	}
	if(flag==0)
	{
		cout<<"\nId available.";
		cout<<"\nPress enter to continue .....";
		getch();
	}
	return id;
}


void coustomer_actions(int id,char user[20])
{
	clrscr();
	int choice;
	cout<<"\nMenu: ";
	cout<<"\n1.Search for a book.";
	cout<<"\n2.Purchase a book";
	cout<<"\n3.Go back.";
	cout<<"\nEnter choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1: book_search(id,user);break;
		case 2: purchase(id);break;
		case 3: goto skip;
		default: cout<<"\nInvalid choice.";
		cout<<"\nPress enter to continue .....";
		getch();
}
coustomer_actions(id,user);
skip:
cout<<" ";
}

void purchase(int id)
{
	clrscr();
	int choice;
	cout<<"\nMenu: ";
	cout<<"\n1.Add book to cart.";
	cout<<"\n2.Remove book from cart.";
	cout<<"\n3.View cart.";
	cout<<"\n4.Go back.";
	cout<<"\nEnter choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1: addtocart(id);break;
		case 2: deletecart(id);break;
		case 3: viewcart(id);break;
		case 4: goto skip;
		default: cout<<"\nInvalid choice.";
		cout<<"\nPress enter to continue .....";
		getch();
	}
	purchase(id);
	skip:
	cout<<" ";
}

void deletecart(int id)
{
	clrscr();
	int no,flag=0;
	coustomer c;
	char ans;
	cout<<"\nEnter access no of the book you want to remove from cart: ";
	cin>>no;
	fstream f,q;
	f.open("cart.dat",ios::in|ios::binary);
	q.open("temp.dat",ios::out|ios::trunc|ios::binary);
	while(f.read((char*)&c,sizeof(c)))
	{
		if(c.getaccess()==no)
			if(c.getid()==id)
			{
				flag=1;
				cout<<"\nDo you want to remove this book from cart: ";
				ans=c.putbook();
				if(ans=='y'||ans=='Y')
					continue;
				else
					q.write((char*)&c,sizeof(c));
			}
			else
				q.write((char*)&c,sizeof(c));
		else
			q.write((char*)&c,sizeof(c));
	}
	f.close();
	q.close();
	if(flag==0)
	{
		cout<<"\nBook no found.";
		cout<<"\nBook removal unsuccessfull !!!";
		cout<<"\nPress enter to continue .....";
		getch();
	}
	else
	{
		cout<<"\nBook removed successfully.";
		cout<<"\nPress enter to continue .....";
		getch();
	}
	remove("cart.dat");
	rename("temp.dat","cart.dat");
}
void addtocart(int id)
{
	clrscr();
	int no,flag=0;
	coustomer c;
	char ans;
	cout<<"\nEnter access no of the book you want to add: ";
	cin>>no;
	fstream f;
	f.open("books.dat",ios::in|ios::binary);
	while(f.read((char*)&c,sizeof(c)))
	{
		if(c.getaccess()==no)
			{
				flag=1;
				cout<<"\n\nDo you want to add this book to cart. (y/n): ";
				ans=c.putbook();
				if(ans=='y'|ans=='y')
				{
					fstream q;
					q.open("cart.dat",ios::app|ios::binary);
					c.assingid(id);
					q.write((char*)&c,sizeof(c));
					q.close();
					cout<<"\nAdded to cart successfully.";
					cout<<"\nPress enter to continue .....";
					getch();
				}
				break;
			}
	}
			f.close();
			if(flag==0)
			{
			cout<<"\nAccess no does not exist !!!!";
			cout<<"\nPress enter to continue .....";
			getch();
			}
			
}

void viewcart(int id)
{
	clrscr();
	char ans;
	int bill_no,total_cost,no;
	coustomer c;
	total_cost=table(0,'c',id);
	cout<<"\n\nTotal amount: "<<total_cost;
	cout<<"\nStatus: Not paid.";
	if(total_cost!=0)
	{
	cout<<"\n\nDo you want to checkout: (y/n): ";
	cin>>ans;
	if(ans=='y'|ans=='Y')
	{
		srand(time(0));
		bill:
		bill_no=rand();
		if(bill_no>100000)
			goto bill;
		fstream b;
		b.open("bill_id.txt",ios::in);
		if(!b)
			goto skip;
		while(b>>no)
			if(bill_no==no)
				goto bill;
		skip:
		b.close();
		fstream f,q;
		f.open("cart.dat",ios::in|ios::binary);
		q.open("bill.dat",ios::app|ios::binary);
		while(f.read((char*)&c,sizeof(c)))
			if(c.getid()==id)
			{
				c.assingid(bill_no);
				q.write((char*)&c,sizeof(c));
			}
		f.close();
		q.close();
		b.open("bill.txt",ios::app);
		b<<bill_no<<endl;
		b.close();
	cout<<"\nChecked out successfully.";
	cout<<"\nPress enter to continue ...... ";
	getch();
	total_cost=table(0,'B',bill_no);
	cout<<"\n\nTotal amount: "<<total_cost;
	cout<<"\nStatus: Paid";
	cout<<"\nPress enter to continue .....";
	getch();
	f.open("cart.dat",ios::in|ios::binary);
	q.open("temp.dat",ios::out|ios::trunc|ios::binary);
	while(f.read((char*)&c,sizeof(c)))
	{
		if(c.getid()==id)
				continue;
		else
			q.write((char*)&c,sizeof(c));
	}
	f.close();
	q.close();
	remove("cart.dat");
	rename("temp.dat","cart.dat");
	}
	}
}

int table(int cnt,char ch,int id)
{
	clrscr();
	coustomer c;
	fstream f;
	if(ch=='b')
	{
		cout<<"\n"<<cnt<<" results found.";
	getch();
		f.open("results.dat",ios::in|ios::binary);
		cout<<endl;
		cout<<"\n-------------------------------------------------------------------------";
		cout<<"\n|| "<<setw(9)<<"  Code    | "<<setw(20)<<"     Title           | "
		<<setw(23)<<"      Author       | "<<setw(9)<<"   Cost   || ";
		cout<<"\n-------------------------------------------------------------------------";
		while(f.read((char*)&c,sizeof(c)))
		cout<<"\n|| "<<setw(9)<<c.getaccess()<<" | "<<setw(20)<<c.gettitle()<<" | "
		<<setw(20)<<c.getauthor()<<" | "<<setw(9)<<c.getcost()<<" ||";
		f.close();
		cout<<"\n-------------------------------------------------------------------------";
		cout<<"\nPress enter to continue .....";
		getch();
		return 0;
	}
	else
		if(ch=='c')
		{
			int cost=0;
		f.open("cart.dat",ios::in|ios::binary);
		cout<<endl;
		cout<<"\n-------------------------------------------------------------------------";
		cout<<"\n|| "<<setw(9)<<"  Code    | "<<setw(20)<<"     Title           | "
		<<setw(23)<<"      Author       | "<<setw(9)<<"   Cost   || ";
		cout<<"\n-------------------------------------------------------------------------";
		while(f.read((char*)&c,sizeof(c)))
			if(c.getid()==id)
		{
			cout<<"\n|| "<<setw(9)<<c.getaccess()<<" | "<<setw(20)<<c.gettitle()<<" | "
		<<setw(20)<<c.getauthor()<<" | "<<setw(9)<<c.getcost()<<" ||";
		cost+=c.getcost();
		}
		f.close();
		cout<<"\n-------------------------------------------------------------------------";
		cout<<"\nPress enter to continue .....";
		getch();
		return cost;
	}

		else
			if(ch=='B')
			{
				int cost=0;
			cout<<"\nBILL:\n";
			cout<<"\nBill no: "<<id;
		f.open("bill.dat",ios::in|ios::binary);
		cout<<endl;
		cout<<"\n-------------------------------------------------------------------------";
		cout<<"\n|| "<<setw(9)<<"  Code    | "<<setw(20)<<"     Title           | "
		<<setw(23)<<"      Author       | "<<setw(9)<<"   Cost   || ";
		cout<<"\n-------------------------------------------------------------------------";
		while(f.read((char*)&c,sizeof(c)))
		if(c.getid()==id)
		{
			cout<<"\n|| "<<setw(9)<<c.getaccess()<<" | "<<setw(20)<<c.gettitle()<<" | "
		<<setw(20)<<c.getauthor()<<" | "<<setw(9)<<c.getcost()<<" ||";
		cost+=c.getcost();
		}
		f.close();
		cout<<"\n-------------------------------------------------------------------------";
		return cost;
			}
			else
				if(ch=='s')
				{
		cout<<"\nBooks added by you: ";
		f.open("books.dat",ios::in|ios::binary);
		cout<<endl;
		cout<<"\n-------------------------------------------------------------------------";
		cout<<"\n|| "<<setw(9)<<"  Code    | "<<setw(20)<<"     Title           | "
		<<setw(23)<<"      Author       | "<<setw(9)<<"   Cost   || ";
		cout<<"\n-------------------------------------------------------------------------";
		while(f.read((char*)&c,sizeof(c)))
			if(c.getid()==id)
			cout<<"\n|| "<<setw(9)<<c.getaccess()<<" | "<<setw(20)<<c.gettitle()<<" | "
		<<setw(20)<<c.getauthor()<<" | "<<setw(9)<<c.getcost()<<" ||";
		f.close();
		cout<<"\n-------------------------------------------------------------------------";
		cout<<"\nPress enter to continue .....";
		getch();
		return 0;	
				}
}

void book_search(int id,char user[20])
{
	label:
	clrscr();
	int choice;
	char t[20],a[20];
	cout<<"\nMenu: ";
	cout<<"\n1.Search book by access no.";
	cout<<"\n2.Search book by title.";
	cout<<"\n3.Search book by author.";
	cout<<"\n4.Search book by cost.";
	cout<<"\n5.Go back.";
	cout<<"\nEnter choice: ";
	cin>>choice;
	switch(choice)
	{
	case 1:search_access(id,user);break;
	case 2: search_title(id,user);break;
	case 3:search_author(id,user);break;
	case 4:search_cost(id,user);break; 
	case 5: break;
	default: cout<<"\nInvalid choice.";
		cout<<"\nPress enter to continue .....";
		getch();
		goto label;
	}	
}

void search_access(int id,char user[20])
{
clrscr();
coustomer c;
int no,cnt=0;
char ans;
cout<<"\nEnter access no of the book: ";
cin>>no;
fstream f,r;
f.open("books.dat",ios::in|ios::binary);
r.open("results.dat",ios::out|ios::trunc|ios::binary);
while(f.read((char*)&c,sizeof(c)))
{
if(c.getaccess()==no)
	{
		r.write((char*)&c,sizeof(c));
		++cnt;
		break;
	}	
}
f.close();
r.close();
if(cnt!=0)
{
table(cnt,'b',1);
cout<<"\nDo you want to add all these books to cart.(y,n): ";
cin>>ans;
if(ans=='y'||ans=='Y')
{
f.open("results.dat",ios::in|ios::binary);
r.open("cart.dat",ios::app|ios::binary);
while(f.read((char*)&c,sizeof(c)))
{
if(c.getaccess()==no)
			{
				c.assingid(id);
				strcpy(c.getusername(),user);
			r.write((char*)&c,sizeof(c));
		}
}
f.close();
r.close();
cout<<"\nAdded to cart successfully.";
getch();
}
}
else
{
cout<<"\n"<<cnt<<" results found.";
getch();
}
}

void search_title(int id,char user[20])
{
	clrscr();
	coustomer c;
	char t[20],ans;
	int cnt=0;
	cout<<"\nEnter title of the book: ";
	cin>>t;
	fstream f,r;
	f.open("books.dat",ios::in|ios::binary);
	r.open("results.dat",ios::out|ios::trunc|ios::binary);
	while(f.read((char*)&c,sizeof(c)))
	{
	if(strcmp(c.gettitle(),t)==0)
			{
			++cnt;
			r.write((char*)&c,sizeof(c));
		}
	}
f.close();
r.close();
if(cnt!=0)
{
table(cnt,'b',1);
cout<<"\nDo you want to add all these books to cart.(y,n): ";
cin>>ans;
if(ans=='y'||ans=='Y')
{
f.open("results.dat",ios::in|ios::binary);
r.open("cart.dat",ios::app|ios::binary);
while(f.read((char*)&c,sizeof(c)))
{
if(strcmp(c.gettitle(),t)==0)
			{
				c.assingid(id);
				strcpy(c.getusername(),user);
			r.write((char*)&c,sizeof(c));
		}
}
f.close();
r.close();
cout<<"\nAdded to cart successfully.";
getch();
}
}
else
{
cout<<"\n"<<cnt<<" results found.";
getch();
}
}

void search_author(int id,char user[20])
{
	clrscr();
	coustomer c;
	int cnt=0;
	char a[20],ans;
	cout<<"\nEnter name of the author of the book: ";
	cin>>a;
fstream f,r;
f.open("books.dat",ios::in|ios::binary);
r.open("results.dat",ios::out|ios::trunc|ios::binary);
while(f.read((char*)&c,sizeof(c)))
{
if(strcmp(c.getauthor(),a)==0)
			{
				++cnt;
			r.write((char*)&c,sizeof(c));
		}
}
f.close();
r.close();
if(cnt!=0)
{
table(cnt,'b',1);
cout<<"\nDo you want to add all these books to cart.(y,n): ";
cin>>ans;
if(ans=='y'||ans=='Y')
{
f.open("results.dat",ios::in|ios::binary);
r.open("cart.dat",ios::app|ios::binary);
while(f.read((char*)&c,sizeof(c)))
{
if(strcmp(c.getauthor(),a)==0)
			{
				c.assingid(id);
				strcpy(c.getusername(),user);
			r.write((char*)&c,sizeof(c));
		}
}
f.close();
r.close();
cout<<"\nAdded to cart successfully.";
getch();
}
}
else
{
cout<<"\n"<<cnt<<" results found.";
getch();
}
}

void search_cost(int id,char user[20])
{
	clrscr();
	coustomer c;
	char ans;
	int cost,cnt=0,less;
	cout<<"\nEnter cost of the book: ";
	cin>>cost;
	start:
	cout<<"\nEnter 0 for results below "<<cost<< ".";
	cout<<"\nEnter 1 for results above "<<cost<<".\n";
	cin>>less;
	if(less!=0 && less!= 1)
		{
			cout<<"\nInvalid option.";
			goto start;
		}
	fstream f,r;
f.open("books.dat",ios::in|ios::binary);
r.open("results.dat",ios::out|ios::trunc|ios::binary);
while(f.read((char*)&c,sizeof(c)))
{
if(less==0)
	{
	if(c.getcost()<= cost)
		{
			++cnt;
			r.write((char*)&c,sizeof(c));		}
	}
else
	if(c.getcost() >= cost)
			{
				++cnt;
				r.write((char*)&c,sizeof(c));			}	
}
f.close();
r.close();
if(cnt!=0)
{
table(cnt,'b',1);
cout<<"\nDo you want to add all these books to cart.(y,n): ";
cin>>ans;
if(ans=='y'||ans=='Y')
{
f.open("results.dat",ios::in|ios::binary);
r.open("cart.dat",ios::app|ios::binary);
while(f.read((char*)&c,sizeof(c)))
{
if(less==0)
	{
	if(c.getcost()<= cost)
		{
			c.assingid(id);
			strcpy(c.getusername(),user);
			r.write((char*)&c,sizeof(c));		
		}
	}
else
	if(c.getcost() >= cost)
			{
				c.assingid(id);
				strcpy(c.getusername(),user);
				r.write((char*)&c,sizeof(c));			
			}	
}
f.close();
r.close();
cout<<"\nAdded to cart successfully.";
getch();
}
}
else
{
cout<<"\n"<<cnt<<" results found.";
getch();
}
}

void bill()
{
	clrscr();
	int no,total_cost=0;
	coustomer c;
	cout<<"\nEnter bill no: ";
	cin>>no;
	total_cost=table(0,'B',no);
	if(total_cost==0)
	{
		cout<<"\nNo bill exists.";
		cout<<"\nPress enter to continue .....";
	getch();
	}
	else
	{
	cout<<"\n\nTotal amount: "<<total_cost;
	cout<<"\nStatus: Paid";
	cout<<"\nPress enter to continue .....";
	getch();
	}
}

void myprofile()
{
	clrscr();
	cout<<"\nPROFILE:\n";
	cout<<"\nName: Ashik meeran mohideen.";
	cout<<"\n\nEducation: B.E. CS in Sri venkateswara college of engineering (2019-2023). Tamilnadu, India";
	cout<<"\n\nGithub: github.com/ASHIK11ab";
	cout<<"\n\nLinkedIn: https://www.linkedin.com/in/ashik-meeran-mohideen-157091189";
	cout<<"\n\nGmail: ashikmeeranmohideen@gmail.com";
	cout<<"\n\nPress enter to continue .....";
	getch();
}
void menu()
{	
	label:
	clrscr();
	int choice;
	cout<<"\n\tMenu:\n";
	cout<<"\t1.Coustomer.\n";
	cout<<"\t2.Seller.\n";
	cout<<"\t3.Generate bill.\n";
	cout<<"\t4.About the developer.\n";
	cout<<"\t5.Exit.";
	cout<<"\n\tEnter choice: ";
	cin>>choice;
	cout<<"\npress enter to continue .....";
	getch();
	switch(choice)
	{
		case 1: coustomer_();break;	
		case 2: seller_();break;
		case 3: bill();break;
		case 4: myprofile();break;
		case 5: exit(0);
		default: cout<<"\nInvalid choice.";
		cout<<"\nPress enter to continue .....";
		getch();
		goto label;
	}
	menu();
}
void welcome()
{
	cout<<"\n\n\n\n\n\n\t\t\t   WELCOME \n\n\t\tASHIK LIBRARY MANAGEMENT SYSTEM";
	cout<<"\n\n\t\tpress enter to continue .....";
	getch();
	menu();
}
int main()
{
	welcome();
	return 0;
}
