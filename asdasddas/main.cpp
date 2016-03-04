/***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include<fstream>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<string>
#include<stdlib.h>
#include<iomanip>
using namespace std;
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
class book
{
	char bno[6];
	char bname[50];
	char aname[20];
  public:
	void create_book()
	{
		std::cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nEnter The book no.";
		cin>>bno;
		cout<<"\n\nEnter The Name of The Book ";
		gets(bname);
		cout<<"\n\nEnter The Author's Name ";
		gets(aname);
		cout<<"\n\n\nBook Created..";
	}
	void show_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nBook Name : ";
		puts(bname);
		cout<<"Author Name : ";
		puts(aname);
	}
	void modify_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nModify Book Name : ";
		gets(bname);
		cout<<"\nModify Author's Name of Book : ";
		gets(aname);
	}
	char* retbno()
	{
		return bno;
	}
	void report()
	{cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}
};         //class ends here
class student
{
	char admno[6];
	char name[20];
	char stbno[6];
	int token;
public:
	void create_student()
	{
		system("CLS");
	 	cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter The admission no. ";
		cin.get(admno,6);cin.get();
		cout<<"\n\nEnter The Name of The Student ";
		cin.get(name,20);cin.get();
		token=0;
		stbno[0]='/0';
		cout<<"\n\nStudent Record Created..";
	}
	void show_student()
	{
		cout<<"\nAdmission no. : "<<admno;
		cout<<"\nStudent Name : ";
		puts(name);
		cout<<"\nNo of Book issued : "<<token;
		if(token==1)
			cout<<"\nBook No "<<stbno;
	}
	void modify_student()
	{
		cout<<"\nAdmission no. : "<<admno;
		cout<<"\nModify Student Name : ";
		gets(name);
	}
	char* retadmno()
	{
		return admno;
	}
	char* retstbno()
	{
		return stbno;
	}
	int rettoken()
	{
		return token;
	}
	void addtoken()
	{token=1;}
	void resettoken()
	{token=0;}
	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}
	void report()
	{cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl;}
};         //class ends here
//***************************************************************
//    	global declaration for stream object, object
//****************************************************************
fstream fp,fp1;
book bk;
student st;
//***************************************************************
//    	function to write in file
//****************************************************************
void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		system("cls");
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void write_student()
{
	char ch;
	fp.open("student.bin",ios::out|ios::app);
	do
	{
		st.create_student();
		fp.write((char*)&st,sizeof(student));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;cin.get();
	}while(ch=='y'||ch=='Y');
	fp.close();
}
//***************************************************************
//    	function to read specific record from file
//****************************************************************
/*
void display_spb(char n[])
{
	cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
			bk.show_book();
		 	flag=1;
		}
	}
	fp.close();
	if(flag==0)
		cout<<"\n\nBook does not exist";
	getch();
}
*/
void display_sps()
{
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	fp.open("student.bin",ios::in|ios::binary|ios::app);
	while(fp.read((char*)&st,sizeof(student)))
	{
			st.show_student();
			flag=1;
	}
//	fp.close();
	if(flag==0)
    		cout<<"\n\nStudent does not exist";
 	getch();
}
int main()
{
    //write_book();
    write_student();
    display_sps();
}
