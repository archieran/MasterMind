#include <windows.h>
#include <iostream>
using namespace std;
//Defines gotoxy() for ANSI C compilers.
void gotoxy(int x, int y)
{
	COORD pos = {x, y};									
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Changes the text color
void setColor(int ForgC)
{
    WORD wColor;
 
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void MaximizeWindow()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SMALL_RECT rc;
	rc.Left = rc.Top = 0;
	rc.Right = (short)(min(info.dwMaximumWindowSize.X, info.dwSize.X) - 1);
	rc.Bottom = (short)(min(info.dwMaximumWindowSize.Y, info.dwSize.Y) - 1);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
}

void beautify()
{
	system("color F0");
	system("mode CON: COLS=127");

	for(int i=0;i<127;i++)
		cout<<"\xdb";

	setColor(4);

	for(int i=0;i<57;i++)
		cout<<"\xb2";
	setColor(0);
	cout<<"   MASTERMIND   ";
	setColor(4);
	for(int i=0;i<54;i++)
		cout<<"\xb2";

	setColor(0);

	for(int i=0;i<127;i++)
		cout<<"\xdb";
}

void description(int a)
{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t - You need to guess a ";
	switch(a)
	{
		case 1: cout<<"TWO digit number !! At Least Take A Challenge !!";
				break;
		case 2: cout<<"THREE digit number !!! I Don\'t Think You Can !!!";
				break;
		case 3: cout<<"FOUR digit number !!!! Haven't you played this already ???? -__-";
				break;
		case 4: cout<<"FIVE digit number!!!!! Woah That\'s Challenging !!!!!";
				break;
		case 5: cout<<"SIX digit number!!!!!! ";
				break;
	}
	cout<<"\n\n\n\t\t\t - You'll get TEN chances. Better make them worth.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t";
	system("pause");
	system("cls");
}

char menu()
{
	gotoxy(54,8);
	cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
	cout<<"\n\t\t\t\t\t\t\t    ----MENU----     \n";
	setColor(4);
	cout<<"\n\n\t\t\t\t\t\t\t  Press\n";
	cout<<"\n\t\t\t\t\t\t\t  1 . Play ! ";                 //For printing Menu.
	cout<<"\n\n\t\t\t\t\t\t\t  2 . Rules";
	cout<<"\n\n\t\t\t\t\t\t\t  3 . How to Play.";
	cout<<"\n\n\t\t\t\t\t\t\t  4 . Exit !";
	setColor(0);
	gotoxy(54,24);
	cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";

	for(int i=8;i<24;i++)
	{
		gotoxy(54,i);
		cout<<"\xdb";
		gotoxy(77,i);
		cout<<"\xdb";
	}
	char menu;
	setColor(4);
	cout<<"\n\n\n\t\t\t\t\t\t Enter your choice from menu above : ";
	menu=getche();
	return menu;
}
