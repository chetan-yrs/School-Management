#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
void border1()
{
    setcolor(12);
    int i;
    for(i=0;i<=15;i++)
    {
	 line(0,i,getmaxx(),i);
    }
    for(i=0;i<=20;i++)
    {
	 line(i,0,i,getmaxy());
    }
    for(i=getmaxx();i>=getmaxx()-20;i--)
    {
	 line(i,0,i,getmaxy());
    }
    for(i=getmaxy();i>=getmaxy()-20;i--)
    {
	 line(0,i,getmaxx(),i);
    }
}
void loading()
{
    char c[5];
    int j;
    setbkcolor(3);
    setcolor(2);
    setcolor(4);
    settextstyle(3,HORIZ_DIR,3);
    outtextxy(200,370,"Loading...");
    sprintf(c,"%c",177);
    settextstyle(3,HORIZ_DIR,2);
    setcolor(6);
    rectangle(198,405,402,425);
    for(int i=200;i<=400;i++)
    {    setcolor(6);
	 outtextxy(i,400,"|");
	 j=i;
	 j=(j-200)/2;
	 sprintf(c,"%d",j);
	 setcolor(8);
	 settextstyle(3,HORIZ_DIR,2);
	 outtextxy(380,380,c);
	 outtextxy(410,380,"%");
	 delay(50);
	 setcolor(3);
	 if(j!=100)
	      outtextxy(380,380,c);
    }
}
void front()
{
    cleardevice();
    border1();
    setcolor(6);
    int i;
    settextstyle(1,HORIZ_DIR,5);
    for(i=21;i<=150;i++)
    {
	 setcolor(6);
	 outtextxy(150,i,"School DataBase");
	 if(i>21)
	 {
	      setcolor(3);
	      outtextxy(150,i-1,"School DataBase");
	 }
	 setcolor(6);
	 outtextxy(150,i,"School DataBase");
	 delay(10);
    }
    i=getmaxy()-80;
    while(i>=220)
    {
	 setcolor(6);
	 outtextxy(100,i,"Management System");
	 if(i<getmaxy()-21)
	 {
	      setcolor(3);
	      outtextxy(100,i+1,"Management System");
	 }
	 setcolor(6);
	 outtextxy(100,i,"Management System");
	 delay(10);
	 i--;
    }
    loading();
    getch();
}
class data
{
    private:
	      char name[20];
	      int roll,m1,m2,m3,m4,m5,total,per,div;
    public:
	      void inputdata(int r);
	      void outputdata();
	      void modify();
	      int returnroll()
	      {
		   return roll;
	      }
	      void rollwise(int r);
    protected:
	      void calc();
	      void result();
};
class rolllast
{
    private:
	      int lastr;
    public:
	      int returnlastroll()
	      {
		   return lastr;
	      }
	      void add(int i)
	      {
		   lastr=i;
	      }
};
int lastrolll()
{
     rolllast rl;
     int rec,roll;
     FILE *f1;
     f1=fopen("rom.txt","r");
     fseek(f1,0,2);
     rec=ftell(f1)/sizeof(rl);
     fseek(f1,0,0);
     if(rec==0)
     {
	 roll=0;
     }
     else
     {
	 fread(&rl,sizeof(rl),1,f1);
	 roll=rl.returnlastroll();
     }
     fclose(f1);
     return roll;
}
int calcrecord()   // it calculate total records
{
    data stud;
    FILE *fp;
    int rec;
    fp=fopen("data12.txt","r");
    fseek(fp,0,2);
    rec=ftell(fp)/sizeof(stud);
    fclose(fp);
    return rec;
}
void page()    // drawing of page boundry
{
    for(int i=1;i<=79;i++)
    {
	 gotoxy(i,1);
	 printf("%c",205);
    }
    for(int k=1;k<=79;k++)
    {
	 gotoxy(k,24);
	 printf("%c",205);
    }
    gotoxy(1,1);
    printf("%c",201);
    gotoxy(79,1);
    printf("%c",187);
     for(int j=2;j<24;j++)
    {
	 gotoxy(1,j);
	 printf("%c",186);
    }
    for(int l=2;l<24;l++)
    {
	 gotoxy(79,l);
	 printf("%c",186);
    }
    gotoxy(1,24);
    printf("%c",200);
    gotoxy(79,24);
    printf("%c",188);
    gotoxy(30,2);
    cout<<" ABC Public School ";
    gotoxy(25,3);
    cout<<" Najafgarh ,New Delhi- 110043";
}
void data::inputdata(int r)  // class function to enter data
{
     roll=r+1;
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 printf("%c",196);
     }
     gotoxy(1,5);
     printf("%c",199);
     gotoxy(79,5);
     printf("%c",182);
     gotoxy(30,6);
     cout<<" Student Details ";
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 printf("%c",196);
     }
     gotoxy(1,7);
     printf("%c",199);
     gotoxy(79,7);
     printf("%c",182);
     div=12;
     gotoxy(2,10);
     cout<<" Enter name of student        ";
     cin>>name;
     gotoxy(2,11);
     cout<<" Enter Roll No.               "<<roll;
     gotoxy(2,12);
     cout<<" Enter Class                  "<<div;
     gotoxy(2,13);
     cout<<" Enter marks of Physics       ";
     cin>>m1;
     gotoxy(2,14);
     cout<<" Enter marks of Chemistry     ";
     cin>>m2;
     gotoxy(2,15);
     cout<<" Enter marks of Maths         ";
     cin>>m3;
     gotoxy(2,16);
     cout<<" Enter marks of English       ";
     cin>>m4;
     gotoxy(2,17);
     cout<<" Enter marks of Computer      ";
     cin>>m5;
     calc();
}
void data::calc()  // calculate percentage and total
{
    total=m1+m2+m3+m4+m5;
    per=total/5;
}
void data::rollwise(int r)    // it displays the data roll no. wise
{
    FILE *fp;
    data stud;
    int rec;
    rec=calcrecord();
    fp=fopen("data12.txt","r");
    for(int i=1;i<=rec;i++)
    {
	 fread(& stud,sizeof(stud),1,fp);
	 if(r==stud.returnroll())
	 {
	      stud.outputdata();
	      getch();
	      return;
	 }
    }
    clrscr();
    page();
    gotoxy(5,7);
    cout<<" Roll No. not found ";
    getch();
}
void data::result()              //it gives the result
{
    if(per<33)
    {
	 gotoxy(65,22);
	 cout<<"      Fail";
    }
    else if(per>=33 && per<=50)
    {
	 gotoxy(65,22);
	 cout<<"      Pass ";
    }
    else if(per>50 && per<75)
    {
	 gotoxy(65,22);
	 cout<<"     Second ";
    }
    else if(per>=75 && per<85)
    {
	 gotoxy(65,22);
	 cout<<"       First ";
    }
    else if(per>=85)
    {
	 gotoxy(65,22);
	 cout<<"Outstanding ";
    }
}
void data::outputdata()    // displays the data
{
    clrscr();
    page();
    strupr(name);
    gotoxy(2,5);
    cout<<" Student Name :  "<<name;
    gotoxy(2,6);
    cout<<" Roll No.     :  "<<roll;
    gotoxy(2,7);
    cout<<" Class        :  "<<div;
    for(int j=1;j<=79;j++)
    {
	 gotoxy(j,8);
	 printf("%c",196);
    }
    gotoxy(1,8);
    printf("%c",199);
    gotoxy(79,8);
    printf("%c",182);
    gotoxy(36,9);
    cout<<" RESULT";
    for(int k=1;k<=79;k++)
    {
	 gotoxy(k,10);
	 printf("%c",196);
    }
    gotoxy(1,10);
    printf("%c",199);
    gotoxy(79,10);
    printf("%c",182);
    gotoxy(2,11);
    cout<<" Subjects";
    gotoxy(35,11);
    cout<<" Max. Marks ";
    gotoxy(68,11);
    cout<<"Marks Obt.";
    for(int l=1;l<=79;l++)
    {
	 gotoxy(l,12);
	 printf("%c",196);
    }
    gotoxy(1,12);
    printf("%c",199);
    gotoxy(79,12);
    printf("%c",182);
    gotoxy(2,13);
    cout<<" English";
    gotoxy(38,13);
    cout<<"100";
    gotoxy(72,13);
    cout<<m1;
    gotoxy(2,14);
    cout<<" Hindi";
    gotoxy(38,14);
    cout<<"100";
    gotoxy(72,14);
    cout<<m2;
    gotoxy(2,15);
    cout<<" Maths";
    gotoxy(38,15);
    cout<<"100";
    gotoxy(72,15);
    cout<<m3;
    gotoxy(2,16);
    cout<<" Science";
    gotoxy(38,16);
    cout<<"100";
    gotoxy(72,16);
    cout<<m4;
    gotoxy(2,17);
    cout<<" SST";
    gotoxy(38,17);
    cout<<"100";
    gotoxy(72,17);
    cout<<m5;
    for(int m=1;m<=79;m++)
    {
	 gotoxy(m,19);
	 printf("%c",196);
    }
    gotoxy(1,19);
    printf("%c",199);
    gotoxy(79,19);
    printf("%c",182);
    gotoxy(2,20);
    cout<<" Total Marks ";
    gotoxy(75,20);
    cout<<total;
    gotoxy(2,21);
    cout<<" Percentage ";
    gotoxy(75,21);
    cout<<per;
    gotoxy(2,22);
    cout<<" Result";
    for(int n=1;n<=79;n++)
    {
	 gotoxy(n,23);
	 printf("%c",196);
    }
    gotoxy(1,23);
    printf("%c",199);
    gotoxy(79,23);
    printf("%c",182);
    result();
}
void data::modify()          //modify data class function
{
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 printf("%c",196);
     }
     gotoxy(1,5);
     printf("%c",199);
     gotoxy(79,5);
     printf("%c",182);
     gotoxy(33,6);
     cout<<" MODIFY DETAILS";
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 printf("%c",196);
     }
     gotoxy(1,7);
     printf("%c",199);
     gotoxy(79,7);
     printf("%c",182);
     div=12;
     gotoxy(2,9);
     cout<<" Student Name                 "<<name;
     gotoxy(2,10);
     cout<<" Roll No.                     "<<roll;
     gotoxy(2,11);
     cout<<" Class                        "<<div;
     gotoxy(2,12);
     cout<<" Enter marks of Physics       ";
     cin>>m1;
     gotoxy(2,13);
     cout<<" Enter marks of Chemistry     ";
     cin>>m2;
     gotoxy(2,14);
     cout<<" Enter marks of Maths         ";
     cin>>m3;
     gotoxy(2,15);
     cout<<" Enter marks of English       ";
     cin>>m4;
     gotoxy(2,16);
     cout<<" Enter marks of Computer      ";
     cin>>m5;
     calc();
}
void modifydata(int r)     // modify function
{
    data stud;
    FILE *fp,*fp1;
    int rec,i=0;
    fp=fopen("data12.txt","r");
    fp1=fopen("temp.txt","a");
    rec=calcrecord();
    for(int j=1;j<=rec;j++)
    {
	 fread(&stud,sizeof(stud),1,fp);
	 if(r==stud.returnroll())
	 {
	      stud.modify();
	      fwrite(&stud,sizeof(stud),1,fp1);
	      i=1;
	 }
	 else
	      fwrite(&stud,sizeof(stud),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    remove("data12.txt");
    rename("temp.txt","data12.txt");
    if(i==0)
    {
	 clrscr();
	 page();
	 gotoxy(5,7);
	 cout<<" You have Entered Wrong Roll No.";
	 getch();
    }

}
void deleterecord(int r)      // delete the record
{
    data stud;
    FILE *fp,*fp1;
    int rec,i=0;
    fp=fopen("data12.txt","r");
    fp1=fopen("temp.txt","a");
    rec=calcrecord();
    for(int j=1;j<=rec;j++)
    {
	 fread(&stud,sizeof(stud),1,fp);
	 if(r==stud.returnroll())
	 {
	      i=1;
	 }
	 else
	      fwrite(&stud,sizeof(stud),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    remove("data12.txt");
    rename("temp.txt","data12.txt");
    if(i==1)
    {
	 clrscr();
	 page();
	 gotoxy(5,7);
	 cout<<" Record Deleted";
	 getch();
    }
    else
    {
	 clrscr();
	 page();
	 gotoxy(5,7);
	 cout<<" Record Not Found";
	 getch();
    }
}
void main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode,"");
    setbkcolor(3);
    setcolor(2);
   // front();
    closegraph();
    textcolor(15);
    data stud;
    FILE *fp;
    //fp=fopen("rom.txt","w");
    //fclose(fp);
    int j=0,choice,rec,r,roll=0,lastroll=0;
    char ch;
    do
    {
	 clrscr();
	 page();
	 for(int j=1;j<=79;j++)
	 {
	      gotoxy(j,5);
	      printf("%c",196);
	 }
	 gotoxy(1,5);
	 printf("%c",199);
	 gotoxy(79,5);
	 printf("%c",182);
	 gotoxy(37,6);
	 cout<<" MENU ";
	 for(int k=1;k<=79;k++)
	 {
	      gotoxy(k,7);
	      printf("%c",196);
	 }
	 gotoxy(1,7);
	 printf("%c",199);
	 gotoxy(79,7);
	 printf("%c",182);
	 gotoxy(2,8);
	 cout<<"\t 1. Data Entry";
	 gotoxy(2,10);
	 cout<<"\t 2. Display All  ";
	 gotoxy(2,12);
	 cout<<"\t 3. Roll No. Wise Display";
	 gotoxy(2,14);
	 cout<<"\t 4. Modify Marks ";
	 gotoxy(2,16);
	 cout<<"\t 5. Delete Record ";
	 gotoxy(2,18);
	 cout<<"\t 6. Exit ";
	 gotoxy(2,22);
	 cout<<"\t Enter your choice : ";
	 cin>>choice;
	 switch(choice)
	 {
	      case 1:
			clrscr();
			lastroll=lastrolll();
			fp=fopen("data12.txt","a");
			stud.inputdata(lastroll);
			fwrite(& stud,sizeof(stud),1,fp);
			fclose(fp);
			lastroll=lastroll+1;
			rolllast r1;
			FILE *f1;
			f1=fopen("rom.txt","w");
			r1.add(lastroll);
			fwrite(&r1,sizeof(r1),1,f1);
			fclose(f1);
			break;

	      case 2:
			clrscr();
			fp=fopen("data12.txt","r");
			rec=calcrecord();
			for(int i=1;i<=rec;i++)
			{
			     fread(& stud,sizeof(stud),1,fp);
			     stud.outputdata();
			     getch();
			}
			fclose(fp);
			break;

	      case 3:
			clrscr();
			page();
			gotoxy(5,7);
			cout<<" Enter Roll to Search ";
			cin>>roll;
			stud.rollwise(roll);
			break;

	      case 4:   clrscr();
			page();
			gotoxy(5,7);
			cout<<" Enter Roll no. to modify ";
			cin>>roll;
			modifydata(roll);
			break;

	      case 5:   clrscr();
			page();
			gotoxy(5,7);
			cout<<" Enter Roll no. to Delete record ";
			cin>>roll;
			deleterecord(roll);
			break;
	      case 6:
			break;
	 }
    }while(choice!=6);
}

