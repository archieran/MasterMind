#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int FileFx::getCodeTwo()
{
	ifstream two;
	srand(time(NULL));
	int y;
	
	two.open("codeTwo.txt");
	two.seekg(((rand()%30)*4),ios::beg);
	two>>y;
	
	two.close();
	return y;
}

int FileFx::getCodeThree()
{
	ifstream three;
	srand(time(NULL));
	int y, choose;
	choose=rand() % 3;
	three.open("codeThree.txt");
	
 	if(choose==1)
	{
		three.seekg(((rand()%120)*5),ios::beg);
	}

 	if(choose==2)
	{
		three.seekg(((rand()%120)*5),ios::cur);
	}

	if(choose==0)
	{
		three.seekg(-((rand()%120)*5),ios::end);
	}
	three>>y;
	three.close();
	return y;
}

int FileFx::getCodeFour()
{
	ifstream four;
	srand(time(NULL));
	int y, choose;
	choose=rand()%3;
	four.open("codeFour.txt");
	
 	if(choose==1)
	{
		four.seekg(((rand()%360)*6),ios::beg);
	}

 	if(choose==2)
	{
		four.seekg(((rand()%360)*6),ios::cur);
	}

	if(choose==0)
	{
		four.seekg(-((rand()%360)*6),ios::end);
	}
	
	four>>y;
	four.close();
	return y;
}

int FileFx::getCodeFive()
{
	ifstream five;
	srand(time(NULL));
	int y, choose;
	choose=rand()%3;
	five.open("codeFive.txt");
	
	if(choose==1)
	{
		five.seekg(((rand()%720)*7),ios::beg);
	}

 	if(choose==2)
	{
		five.seekg(((rand()%720)*7),ios::cur);
	}

	if(choose==0)
	{
		five.seekg(-((rand()%720)*7),ios::end);
	}
	
	five>>y;
	five.close();
	return y;
}

int FileFx::getCodeSix()
{
	ifstream six;
	srand(time(NULL));
	int y, choose;
	choose=rand()%3;
	six.open("codeSix.txt");

	if(choose==1)
	{
		six.seekg(((rand()%720)*8),ios::beg);
	}
	
 	if(choose==2)
	{
		six.seekg(((rand()%720)*8),ios::cur);
	}
	
	if(choose==0)
	{
		six.seekg(-((rand()%720)*8),ios::end);
	}

	six>>y;
	six.close();
	return y;
}

void FileFx::checkFileExistence()
{
	bool b2,b3,b6,b4,b5;
	ifstream get2,get3,get4,get5,get6;
	get2.open("codeTwo.txt");
	get3.open("codeThree.txt");
	get4.open("codeFour.txt");
	get5.open("codeFive.txt");
	get6.open("codeSix.txt");

	b2 = get2.good();
	b3 = get3.good();
	b4 = get4.good();
	b5 = get5.good();
	b6 = get6.good();

	if(b2==0)
	{
		codeTwo();
	}
	if(b3==0)
	{
		codeThree();
	}
	if(b4==0)
	{
		codeFour();
	}
	if(b5==0)
	{
		codeFive();
	}
	if(b6==0)
	{
		codeSix();
	}

	get2.close();
	get3.close();
	get4.close();
	get5.close();
	get6.close();
}
