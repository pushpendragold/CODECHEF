#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define MAX  150001
#define MAXL 26
#define DEBUG 0

using namespace std;

typedef struct Freq {
	char letter;
	int  count;
	Freq() { letter = ' '; count = 2*MAX; }
   ~Freq() {}
}Freq;

char input[MAX];
char text[MAX];

bool myfunction (Freq i,Freq j) 
{
	if( i.count == j.count ) 
		return i.letter < j.letter;
	else
		return i.count < j.count;
}

int CreateFrequencyTable(Freq * freq, char * input)
{
	int index = 0;
	int len = 0;
	bool upperCase = false;

	while( input[ index ] != '\0')
	{
		upperCase = false;
		if( input[ index ] >= 'a' && input[ index ] <= 'z' || input[ index ] >= 'A' && input[ index ] <= 'Z' && ( upperCase = true ))
		{
			if(upperCase) 
			{
				if( freq[ input[index] - 'A' ].count == 2*MAX )
				{
					len ++;
					freq[ input[ index ] - 'A' ].count = 0;
					freq[ input[ index ] - 'A' ].letter = input[ index ] - 'A' + 'a';
				}
				freq[ input[index] - 'A' ].count++;
			}
			else
			{
				if( freq[ input[index] - 'a' ].count == 2*MAX )
				{
					len ++;
					freq[ input[ index ] - 'a' ].count = 0;
					freq[ input[ index ] - 'a' ].letter = input[ index ];
				}
				freq[ input[index] - 'a' ].count++;
			}
		}
		index++;
	}
	return len;
}

void PrintResult( map<char,char> &Hash , Freq * freqText )
{
	if(DEBUG) { for(int i = 0; i < MAXL; i++) printf(" %c : %d\n",freqText[i].letter,freqText[i].count); }

	int index = 0;
	bool upperCase = false;
	while( text[ index ] != '\0' ) 
	{
		upperCase = false;
		if( text[ index ] >= 'a' && text[ index ] <= 'z' || text[ index ] >= 'A' && text[ index ] <= 'Z' && ( upperCase = true ))
		{
			// Check for upper case
			if(upperCase) 
			{
				text[ index ] = Hash[ text[index] - 'A' + 'a' ] - 'a' + 'A';
			}
			else
			{
				text[ index ] = Hash[ text[index] ];
			}
		}
		index ++;
	}
	puts(text);
}

void GenerateMap( map<char,char> &Hash, Freq * freqText, int len)
{
	int length = strlen(input);

	for(int i = len - 1; i >= 0; i--) 
	  Hash[ freqText[len - 1 - i].letter ] = input[ length - 1 - i ];
}

int main()
{
	int T,len;
	scanf("%d\n",&T);
	while(T--) 
	{
		Freq freqText  [MAXL];
		map < char , char > Hash;
		Hash.clear();

		gets(input);
		gets(text);
		
		len = CreateFrequencyTable( freqText , text );
		sort ( freqText , freqText + MAXL , myfunction);

		GenerateMap( Hash, freqText, len);
		PrintResult( Hash, freqText);

	}
	return 0;
}
