#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 50
#define MAXM 100
char chars[MAXN][MAXN], words[MAXM][MAXN];	//holds the map and words, respectively
bool out[MAXN][MAXN];						//stores whether the char is part of output or not
int R, C, N;	//row, column and number of words, respectively
bool flag;		//stores if the word is found or not

//finds the words
void find(char* str) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {		//loop through row and column
		
			for (int x = -1; x <= 1; x++)
				for (int y = -1; y <= 1; y++)	//loop through all 8 directions
					if ((x||y)) {				//do not check if x = 0 and y = 0
						
						flag = true;			
						for (int k = 0; k < strlen(str); k++) 
							if ((i+x*k)<0 || (i+x*k) >= R || (j+y*k)< 0 || (j+y*k) > C || chars[i+x*k][j+y*k] != str[k]) {
								flag = false;	//word not found
								break;
							}
								
						
						if (flag) {		//word found
							for (int k = 0; k < strlen(str); k++)
								out[i+x*k][j+y*k] = true;
							#ifdef DEBUG
							cout << str << ":" << i << " " << j << " , " << x << " " << y << endl; //prints row, column and direction
							#endif
							return;
						}
					}
				
		}
	}
}

int main() {
	//freopen("a.txt","r",stdin); //file input
	while (cin >> R >> C) {
			//reset the arrays
			memset(out,0,sizeof(out));	
			memset(words,0,sizeof(words));
			memset(chars,0,sizeof(chars));
			for (int i = 0; i < R; i++)
				cin >> chars[i];
			cin >> N;
			cin.getline(words[0],MAXN);
			for (int i = 0; i < N; i++) {
				cin.getline(words[i],MAXN);
				for (int j = 0; j < strlen(words[i]); j++) {
					#ifdef WRONG
					if (words[i][j] == ' ') {		//mistake during the contest
					#else
					if (words[i][j] < 'A' || words[i][j] > 'Z') {		//proper way
					#endif
						for (int k = j; k < strlen(words[i]); k++) 
							words[i][k] = words[i][k+1];
						j--;
					}
					
				}
			#ifdef CMP
				cout << words[i] <<endl;
			#endif
			}
			//find words
			for (int i = 0; i < N; i++)
				find(words[i]);
				
			#ifdef DEBUG
			for (int i = 0; i < R; i++,cout<<endl)
				for (int j = 0; j < C; j++)
					if (!out[i][j])
						cout << chars[i][j];
					else
						cout << " ";
			#else
				for (int i = 0; i < R; i++)
					for (int j = 0; j < C; j++)
						if (!out[i][j])
							cout << chars[i][j];
			#endif
			cout << endl;
	}
}


/*
Test data:
17 17
KLIMTSEINWORBCHOC
CGOLYNASEMISWEETT
EHNCSDENETEEWSNUO
RCIIOENIIGFILLING
SIOPKCLADNABFTESE
KFRNSAOFCEIOOMCTV
NRHEFDBAFTRSOEHEI
ICATAERTTUIGDDOGT
RORDSNCECCRONSCNC
DOWEFTRTEUTTUIOII
GKHTASPCIRPOHFLDD
NIIEWMRUEOICOTADD
IETESEPSRCNNAHTUA
CSESAESIIYDEBKIPO
ITIMBERLEUSAROEAM
AWFUDGECEARCAYRSO
SUGARDTESSUOMRSEE
37
ADDICTIVE
BAKING
BARS
BITTERSWEET
BROWNIES
CAKES
CANDY
CHIPS
CHOCOLATIERS
COCOA
CONFECTIONERY
COOKIES
CREAM PIE
CUPCAKE
DARK
DECADENT
DELICIOUS
DESSERT
DRINKS
FILLING
FONDUE
FOOD
FUDGE
ICE CREAM
ICING
INGREDIENT
MILK
MOUSSE
PUDDING
SEMISWEET
SUGAR
SWISS
SYRUP
TREAT
TRUFFLES
UNSWEETENED
WHITE
*/