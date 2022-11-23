//C++ program to create telephone directory
#include<iostream>
#include<fstream>
#include<string>
#include<conio>
using namespace std;
struct telerec
{
char tname[50];
long int tnum;
char tcity[50];
}t;
void append()
{
int i,n;
ofstream fout;
fout.open("tele.dat",ios::out|ios::binary|ios::app);
cout<<"Enter no. of records:";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"Enter name of the person:";
cin>>t.tname;
cout<<"Enter telephone number:";
cin>>t.tnum;
cout<<"Enter birthplace:";
cin>>t.tcity;
fout.write((char*)&t,sizeof(t));
}
fout.close();
}
void search()
{
ifstream fin("tele.dat",ios::in|ios::binary);
char place[50];
int k=0;
cout<<"Enter birthplace of the person to be searched:";
cin>>place;
while(!fin.eof())
{
fin.read((char*)&t,sizeof(t));
if(strcmp(t.tcity,place)==0)
{
k=1;
break;
}
}
if(k==1)
{
cout<<"Record found!"<<endl;
cout<<"Name:"<<t.tname<<endl;
cout<<"Telephone number:"<<t.tnum<<endl;
cout<<"Birthplace:"<<t.tcity<<endl;
}
else
cout<<"Record not found!"<<endl;
}
void main()
{
clrscr();
append();
search();
getch();
}
