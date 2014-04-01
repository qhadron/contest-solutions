#include <cstdlib>
#include <cstring>
#include <iostream>

#define MAXLEN 1000

using namespace std;

char U[MAXLEN], D[MAXLEN], msg[MAXLEN];		//upper string, lower string, message string, respectively
bool bin[MAXLEN];							//binary data (not really binary)
int N;										//number of characters
int val;									//value of current character
bool test(int start, bool inverted) {
	//check from start, to as far as possible without exceeding the limit
	for (int i = start, cnt = 0; i <= (N - 8); i+=8) {
		val = 0;
		//convert to actual ASCII
		for (int j = 0; j < 8; j++) val |= ((inverted)?bin[j+i]:!bin[j+i]) << (7-j);
		#ifdef DEBUG
		cout << val << endl;
		#endif
		//checks message, records if valid
		if ( val == 32 || (val >= 65 && val <= 90) ) {
			msg[cnt++] = (char)val;
		} else {
			return false;
		}
	}
	//done
	return true;
}
int main(void) {
	while (cin >> U >> D) {
		memset(msg,0,sizeof(msg));
		N = strlen(U);		//get length of data
		for (int i = 0; i < strlen(U); i++) {
			//check for sneaky input cases
			if (U[i] == 'C' && D[i] == 'G'||(U[i] == 'G' && D[i] == 'C') )
				bin[i] = false;
			else if (U[i] == 'T' && D[i] == 'A' || U[i] == 'A' && D[i] == 'T')
				bin[i] = true ;
		}
		#ifdef DEBUG
		for (int i = 0; i < N; i++)
			cout << (int)bin[i];
		cout << endl;
		#endif
		//start from the first character, all the way up the 7th character, break if done
		for (int i = 0; i <= (N % 8); i++) {
			if (test(i,true)||test(i,false)) break;
		}
		cout << msg << endl;		//print message
	}
	
}

/*
Test Data:

CAACACGTGGCGTGCCAGTGACCTTGGCAGGTTGCGTCGAAATCCC
GTTGTGCACCGCACGGTCACTGGAACCGTCCAACGCAGCTTTAGGG
ACCAGTTATACTACATAAAAGATTACTTACTTTAATCTTTAGCTTGTTTTATGTTAGTTA
TGGTCAATATGATGTATTTTCTAATGAATGAAATTAGAAATCGAACAAAATACAATCAAT
CCAGACGAGTAGTCCGACAGAGCCTGTGAGAGGGGCGTCGGGGGTGCCGTAGTCCGGCTGAGCAAGCCAGGTTCACC
GGTCTGCTCATCAGGCTGTCTCGGACACTCTCCCCGCAGCCCCCACGGCATCAGGCCGACTCGTTCGGTCCAAGTGG
ACAACAAAACAAACACACAACCAAACAACCAAACAACCCCAACAAAAAACACACCCACAACCCCACACAACAACAACCAAACAAACAA
TGTTGTTTTGTTTGTGTGTTGGTTTGTTGGTTTGTTGGGGTTGTTTTTTGTGTGGGTGTTGGGGTGTGTTGTTGTTGGTTTGTTTGTT

output:

HELLO
A B C D
KEEP CALM
HELLO WORLD
*/