#include <cstring>

class FileFx
{
	private:
		int a, b, c, d, e, f;
		int *flag;
	public:
		int getCodeTwo();
		int getCodeThree();
		int getCodeFour();
		int getCodeFive();
		int getCodeSix();
		void checkFileExistence();
		void codeTwo();
		void codeThree();
		void codeFour();
		void codeFive();
		void codeSix();
};

class GuessNum
{
	private:
		int guess[6];
		char *guess111;
		GuessNum *next;
		static int count;
		FileFx f;
	public :
		void getGuess(int length,int line);
		int Validation(int ques[],int n,int line);
		void ColorResult(int,int,int,int,int);
		char * setDifficulty();
		GuessNum()
		{
			count++;
			guess111=new char[10];
			strcpy(guess111," ");
			for(int i=0;i<6;i++)
				guess[i]=0;
		}
		static int getCount(){return count;}
		static void setCount(){count=0;}
		int getCode(int a)
		{
			int x;
			switch(a)
			{
				case 2:x=f.getCodeTwo();
						break;
				case 3:x=f.getCodeThree();
						break;
				case 4:x=f.getCodeFour();
						break;
				case 5:x=f.getCodeFive();
						break;
				case 6:x=f.getCodeSix();
						break;
			}
			return x;
		}
  		void checker(){f.checkFileExistence();return;}
};
int GuessNum::count;
