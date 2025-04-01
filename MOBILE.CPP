/*****************************************************************************
			       * HEADER FILES *
*****************************************************************************/
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<iostream>
using namespace std;
class Mobile
{
	char name[50],G,WiFi,procssr[50],RAM[30],version[100];
	double price,scrnsize,Rcamera,Fcamera;
	int battery,no;
public:
/*****************************************************************************
			    * FUNCTIONS IN CLASS *
*****************************************************************************/
	void sell();
	void purchase();
	 int add();
	void disp_all();
	void display();
	void search();
	void remov();
	char *rname();
}M;
void Mobile::sell()
{
int count=0,tno;
char tname[50];
Mobile A;
ifstream fin("mobile.txt",ios::app|ios::binary);
ofstream fout("temp.txt",ios::app|ios::binary);
A.disp_all();
clrscr();
cout<<"                             ";for(int i=0;i<23;i++)	cout<<char(-2);
cout<<"\n                              ABCD MOBILE GALLARY                             ";
cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"\n ____________________________________________________________________________ ";
cout<<"\n\n Enter the Name of Mobile that You Want to Sell \n ";gets(tname);
	while(fin.read((char*)&A,sizeof(A)))
	{ 	if(stricmp(A.rname(),tname)==0)
		{	count=1;
			cout<<"\n Enter the Number of Mobiles that You Want to Sell \n ";cin>>tno;
			if(A.no>=tno)
			{   	A.no=A.no-tno;
				cout<<"\n Amount = $"<<A.price*tno<<"\n ";
				cout<<"\n Mobile(s) Sold \n ";
			}
			else	cout<<"\n Sorry!! Not Enough Stock \n ";
		}
		fout.write((char*)&A,sizeof(A));
	}
	if(count==0)	cout<<"\n Enter Correct Name!! \n ";
fin.close();
fout.close();
remove("mobile.txt");
rename("temp.txt","mobile.txt");
}
void Mobile::purchase()
{
int count=0,tno;
char tname[50];
Mobile A;
ifstream fin("mobile.txt",ios::app|ios::binary);
ofstream fout("temp.txt",ios::app|ios::binary);
clrscr();
cout<<"                             ";for(int i=0;i<23;i++)	cout<<char(-2);
cout<<"\n                              ABCD MOBILE GALLARY                             ";
cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"\n ____________________________________________________________________________ ";
cout<<"\n\n Enter Name of Mobile that You Want to Purchase \n ";gets(tname);
	while(fin.read((char*)&A,sizeof(A)))
	{     	if(stricmp(A.rname(),tname)==0)
		{	count=1;
			cout<<"\n Enter the Number of Mobiles that You Want to Purchase \n ";cin>>tno;
			A.no+=tno;
			cout<<"\n Amount = $"<<A.price*tno<<"\n ";
			cout<<"\n Mobile(s) Purchased \n ";
		}
		fout.write((char*)&A,sizeof(A));
	}
	if(count==0)	cout<<"\n Enter Correct Name!! \n ";
fin.close();
fout.close();
remove("mobile.txt");
rename("temp.txt","mobile.txt");
}
int Mobile::add()
{
int i;
Mobile A;
ifstream fin("mobile.txt",ios::app|ios::binary);
clrscr();
cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"\n                              ABCD MOBILE GALLARY                             ";
cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"\n ____________________________________________________________________________ ";
cout<<"\n\n Enter the Mobile Name \n ";gets(name);
	for(i=0;name[i]!='\0';i++)	name[i]=toupper(name[i]);
	while(fin.read((char*)&A,sizeof(A)))
		if(stricmp(A.rname(),name)==0)
		{	cout<<"\n Record Already Exist!! \n ";
			return 1;
		}
cout<<"\n Enter Price (In US Dollors) \n ";cin>>price;
cout<<"\n Is the Mobile Supports 3G? (Y/N) \n ";cin>>G;
	G=toupper(G);
cout<<"\n Is the Mobile Supports WiFi? (Y/N) \n ";cin>>WiFi;
	WiFi=toupper(WiFi);
cout<<"\n Enter Processor \n ";gets(procssr);
	for(i=0;procssr[i]!='\0';i++)
	{    	if(procssr[i]!='z'&&procssr[i]!='Z')	procssr[i]=toupper(procssr[i]);
		else	procssr[i]=tolower(procssr[i]);
	}
cout<<"\n Enter RAM \n ";gets(RAM);
	for(i=0;RAM[i]!='\0';i++)	RAM[i]=toupper(RAM[i]);
clrscr();
cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"\n                              ABCD MOBILE GALLARY                             ";
cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"\n ____________________________________________________________________________ ";
cout<<"\n\n Enter Battery Capacity (In mAh) \n ";cin>>battery;
cout<<"\n Enter Screen Size (In Inches) \n ";cin>>scrnsize;
cout<<"\n Enter Rear Camera (In Mega Pixals) \n ";cin>>Rcamera;
cout<<"\n Enter Front Camera (In Mega pixals) \n ";cin>>Fcamera;
cout<<"\n Enter Version \n ";gets(version);
	for(i=0;version[i]!='\0';i++)	version[i]=toupper(version[i]);
cout<<"\n Enter No. of Mobiles that You Want to Purchase \n ";cin>>no;
cout<<"\n\t\t\t\t   Record Added \n ";
fin.close();
return 0;
}
void Mobile::disp_all()
{
Mobile A;
ifstream fin("mobile.txt",ios::app|ios::binary);
	while(fin.read((char*)&A,sizeof(A)))
	{	A.display();
		getch();
	}
cout<<"\n\n\t\t\t\t  No More Records \n ";
fin.close();
}
void Mobile::display()
{
clrscr();
cout<<"                             ";for(int i=0;i<23;i++)	cout<<char(-2);
cout<<"\n                              ABCD MOBILE GALLARY                             ";
cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"\n ____________________________________________________________________________ ";
	cout<<"\n\n The Information About Mobile Is: \n\n";
	cout<<" Mobile Name     : ";puts(name);
	cout<<" Price           : $"<<price<<endl;
	cout<<" 3G              : "<<G<<endl;
	cout<<" WiFi            : "<<WiFi<<endl;
	cout<<" Processor       : ";puts(procssr);
	cout<<" RAM             : ";puts(RAM);
	cout<<" Battery Capacity: "<<battery<<" mAh"<<endl;
	cout<<" Screen Size     : "<<scrnsize<<" Inch"<<endl;
	cout<<" Rear Camera     : "<<Rcamera<<" MP"<<endl;
	cout<<" Front Camera    : "<<Fcamera<<" MP"<<endl;
	cout<<" Version         : ";puts(version);
	cout<<" No. of Mobile   : "<<no<<endl;
	cout<<"\n Press Any Key to Continue.... \n ";
}
void Mobile::search()
{
int count=0;
char tname[50];
Mobile A;
ifstream fin("mobile.txt",ios::app|ios::binary);
clrscr();
cout<<"                             ";for(int i=0;i<23;i++)	cout<<char(-2);
cout<<"\n                              ABCD MOBILE GALLARY                             ";
cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"\n ____________________________________________________________________________ ";
cout<<"\n\n Enter the Mobile Name that You Want to Search \n ";gets(tname);
	while(fin.read((char*)&A,sizeof(A)))
		if(stricmp(A.rname(),tname)==0)
		{
			count=1;
			cout<<"\n Search Successful. Record Found. \n ";
			getch();
			A.display();
		}
	if(count==0)	cout<<"\n Search Unsuccessful. Record Not Found. \n ";
fin.close();
}
void Mobile::remov()
{
char tname[50],ans;
int count=0;
Mobile A;
ifstream fin("mobile.txt",ios::app|ios::binary);
ofstream fout("temp.txt",ios::app|ios::binary);
clrscr();
cout<<"                             ";for(int i=0;i<23;i++)	cout<<char(-2);
cout<<"\n                              ABCD MOBILE GALLARY                             ";
cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"\n ____________________________________________________________________________ ";
cout<<"\n\n Enter the Mobile Name that You Want to Remove \n ";gets(tname);
	while(fin.read((char*)&A,sizeof(A)))
	{      	if(stricmp(A.rname(),tname)==0)
		{ 	count++;
			A.display();
			getch();
			clrscr();
			cout<<"                             ";for(int i=0;i<23;i++)	cout<<char(-2);
			cout<<"\n                              ABCD MOBILE GALLARY                             ";
			cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
			cout<<"\n ____________________________________________________________________________ ";
			cout<<"\n\n Are You Sure? You Want to Remove This Record? \n ";cin>>ans;
			if(ans=='N'||ans=='n')	fout.write((char*)&A,sizeof(A));
			else
			{	cout<<"\n Deleting.... \n ";
				sleep(1);
				cout<<"\n Record Deleted \n ";
			}
		}
		else	fout.write((char*)&A,sizeof(A));
	}
	if(count==0)	cout<<"\n The Record Does Not Exist!! \n ";
fin.close();
fout.close();
remove("mobile.txt");
rename("temp.txt","mobile.txt");
}
char *Mobile::rname()
{ return name; }
void add_mob()
{
Mobile C;
ofstream fout("mobile.txt",ios::app|ios::binary);
	if(C.add()==0)	fout.write((char*)&C,sizeof(C));
fout.close();
}
/*****************************************************************************
			  * USER DEFINED FUNCTIONS *
*****************************************************************************/
void add_mob();
int main();

int main()
{clrscr();
char ch;
char ans='Y';
sleep(1);
cout<<" .............................................................................. ";
cout<<" :                                                                            : ";
cout<<" :                            Sendhwa Public School                           : ";
cout<<" :                            ~~~~~~~~~~~~~~~~~~~~~                           : ";
cout<<" :............................................................................: ";
sleep(1);
cout<<" .............................................................................. ";
cout<<" :                                                                            : ";
cout<<" :                                   : ";
cout<<" :                    MOBILE GALLERY MANAGEMENT PROGRAM                   : ";
cout<<" :                                   : ";
cout<<" :............................................................................: ";
sleep(1);
cout<<" .............................................................................. ";
cout<<" :                                                                            : ";
cout<<" :  Appointed By:- Mr. Sourabh Sahu                                           : ";
cout<<" :  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                           : ";
cout<<" :............................................................................: ";
sleep(1);
cout<<" .............................................................................. ";
cout<<" :                                                                            : ";
cout<<" :  Made By:- Mohit Verma                                                     : ";
cout<<" :............................................................................: ";
sleep(1);
cout<<"                                  Press Any Key to Run the Further Program.....  ";
getch();
clrscr();
cout<<" .............................................................................. ";
cout<<" :                                                                            : ";
cout<<" :                            Sendhwa Public School                           : ";
cout<<" :                            ~~~~~~~~~~~~~~~~~~~~~                           : ";
cout<<" :............................................................................: ";
cout<<" .............................................................................. ";
cout<<" :                                                                            : ";
cout<<" :                                   : ";
cout<<" :                    MOBILE GALLERY MANAGEMENT PROGRAM                   : ";
cout<<" :                                   : ";
cout<<" :............................................................................: ";
sleep(1);
cout<<" .............................................................................. ";
cout<<" :                                                                            : ";
cout<<" :                            ";for(int i=0;i<23;i++)	cout<<char(-2);
cout<<"                         : ";
cout<<" :                             ABCD MOBILE GALLARY                          : ";
cout<<" :                            ";for(i=0;i<23;i++)	cout<<char(-2);
cout<<"                         : ";
cout<<" :............................................................................: ";
sleep(1);
cout<<"                                  Press Any Key to Run the Further Program.....  ";
getch();

	while(ans=='Y'||ans=='y')
	{
	clrscr();
	cout<<"                             ";for(int i=0;i<23;i++)	cout<<char(-2);
	cout<<"\n                              ABCD MOBILE GALLARY                             ";
	cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
	cout<<"\n ____________________________________________________________________________ ";
	cout<<"\n\n\t\t  Select Your Choice From The Options Below.... \n ";
	cout<<"\n\n\t  1.Sell \t  2.Purchase \t  3.Add New \t  4.Display All \n\n\t  5.Search \t  6.Remove \t  7.Exit \n\n ";
	ch=getche();
		switch(ch)
		{	case'1':M.sell();
				break;
			case'2':M.purchase();
				break;
			case'3':add_mob();
				break;
			case'4':M.disp_all();
				break;
			case'5':M.search();
				break;
			case'6':M.remov();
				break;
			case'7':exit(0);
			default:cout<<"\n\n Enter Correct Choice \n ";
		}
	getch();
	clrscr();
	cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
	cout<<"\n                              ABCD MOBILE GALLARY                             ";
	cout<<"                             ";for(i=0;i<23;i++)	cout<<char(-2);
	cout<<"\n ____________________________________________________________________________ ";
	cout<<"\n\n Thank You \n ";
	sleep(1);
	cout<<"\n Want to Do More? (Y/N) \n ";cin>>ans;
	}return 0;
}
/*****************************************************************************
			      * END OF PROGRAM *
*****************************************************************************/
