#include "GenerateCode.hpp"

void GuessNum::ColorResult(int green,int blue,int red,int line,int n)
{
	if(n==5)
		gotoxy(80,line);
	else if(n==1)
		gotoxy(92,line);
	else if(n==2)
		gotoxy(88,line);
	else if(n==3)
		gotoxy(86,line);
	else if(n==4)
		gotoxy(84,line);
		
	setColor(10);
	for(int i=0;i<green;i++)
		printf("%c     ",254);

	setColor(9);

	for(int i=0;i<blue;i++)
		printf("%c     ",254);

	setColor(12);

	for(int i=0;i<red;i++)
		printf("%c     ",254);

	setColor(0);
	cout<<"\n";
}

void GuessNum::getGuess(int length,int line)
{
	for(int i=0,j=11;i<=length;i++,j+=9)
	{
		gotoxy(j,line);
		guess111[i]=getche();
		//cin>>guess111[i];
		if(guess111[i]>=49 && guess111[i]<=54)
		{
			guess[i]=atoi((guess111+i));
			gotoxy(0,32);
			cout<<"\n\t\t\t                                                                               ";
		}
		else
		{
			gotoxy(0,32);
			setColor(4);
			cout<<"\n\t\t\t   WHY ARE YOU TRYING TO LOSE ! YOU LOST ONE CHANCE !! ENTER VALID NUMBERS !!!!";
			setColor(0);
			return;
		}
	}
	
	return;
}

int GuessNum::Validation(int ques[],int n,int line)
{

	int flag=0,GrnCnt=0,BluCnt=0,RedCnt=0;

	for(int i=0,j=0;i<=n;i++,j++)
	{
		if(ques[i]==guess[i])
			GrnCnt++;
	}

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(ques[i]==guess[j])
				BluCnt++;
		}
	}

	int flag1=0;

	for(int i=0;i<=n;i++)
	{
		int key=guess[i];
		for(int j=i+1;j<=n;j++)
		{
			if(guess[j]==key)
			{
				flag1++;
			}
		}
	}

	if(flag1>0)
	{
		for(int i=0 ; i<=n ; i++)
		{
			for(int j=0 ; j<=n ; j++)
			{
				if(ques[i]==guess[j])
				{
					int tempG=ques[i];
					if(flag!=0 && tempG==guess[j])
						BluCnt--;
					if(flag==0 && tempG==guess[j])
						flag++;
				}
			}
			flag=0;
		}
	}

	BluCnt-=GrnCnt;
	RedCnt=	RedCnt=((n+1)-(GrnCnt+BluCnt));

	//cout<<"     G : "<<GrnCnt<<"      B : "<<BluCnt<<"      R : "<<RedCnt;
	ColorResult(GrnCnt,BluCnt,RedCnt,line,n);

	if(GrnCnt==(n+1) && BluCnt==0 && RedCnt==0)
		return 2;
	else
		return 1;

}

char* GuessNum::setDifficulty()
{
	char *diff=new char[2];
	strcpy(diff," ");
	gotoxy(54,8);
	setColor(0);
	cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
	cout<<"\n\t\t\t\t\t\t\t--DIFFICULTY LEVEL--\n";
	setColor(4);
	cout<<"\n\n\t\t\t\t\t\t\t  Press\n";
	cout<<"\n\t\t\t\t\t\t\t  1 . Child's Play ! ";                 //For printing Menu.
	cout<<"\n\n\t\t\t\t\t\t\t  2 . Beginner";
	cout<<"\n\n\t\t\t\t\t\t\t  3 . Moderate";
	cout<<"\n\n\t\t\t\t\t\t\t  4 . Not so easy ";
	cout<<"\n\n\t\t\t\t\t\t\t  5 . Bring it on ! ";
	setColor(0);
	gotoxy(54,25);
	cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
	
	for(int i=8;i<25;i++)
	{
		gotoxy(54,i);
		cout<<"\xdb";
		gotoxy(77,i);
		cout<<"\xdb";
	}
	
	setColor(4);
	cout<<"\n\n\n\t\t\t\t\t\t Enter your choice from menu above : ";
	*(diff+0)=getche();	
	return diff;
}
