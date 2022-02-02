#include <iostream>

bool round_up(int i, int key, int alph_length)
{
	if(i + key > alph+length)
		return true;
	else
		return false;
}

void cyfer(std::string word, int key)
{
	std::string result;
	const int alphabet_length = 26;
	
	int acctual_key = key % alphabet_length;
	
	for(int i = 0; i < word.length()); ++i)
	{
		if(round_up((int)word[i], acctual_key, alphabet_length))
		{
			result[i] = 'A' + key - ('Z' - word[i]);
		}
		else
		{
			result[i] = word[i] + acctual_key;
		}
	}
}

int main()
{
	std::cout << cyfer("ABC", 3);
}
