#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string encode (string word, string cypher)
{
	for (short x = 0; x < word.length(); ++x)
	{
		word[x] += cypher[x%cypher.length()] - 64;
		if (word[x] > 90)
			word[x] -= 26;
	}
	return word;
}

string decode (string word, string cypher)
{
	for (short x = 0; x < word.length(); ++x)
	{
		word[x] -= cypher[x%cypher.length()] - 64;
		if (word[x] < 65)
			word[x] += 26;
	}
	return word;
}
int main(int argc, char** argv)
{
	string word, cypher;
	ifstream words, cyphers;
	words.open("tj.txt");
	cyphers.open("klucze1.txt");
	ofstream output ("wynik4a.txt");
	while (words >> word && cyphers >> cypher)
		output << encode (word, cypher) << endl;
	words.close();
	cyphers.close();
	output.close();
	words.open("sz.txt");
	cyphers.open("klucze2.txt");
	output.open ("wynik4b.txt");
	while (words >> word && cyphers >> cypher)
		output << decode (word, cypher) << endl;
	words.close();
	cyphers.close();
	output.close();
	return 0;
}
