#include <iostream>
#include <fstream>

using namespace std;

string coding(string text, string key)
{
	string coded_text={};
	
	for(int i=0; i<text.length(); i++)
	{
		char sign=text[i]+(key[i%key.length()]-64);
		
		if(sign>'Z')
			sign-=26;
			
		coded_text+=sign;
	}
	
	return coded_text;
}

string decoding(string text, string key)
{
	string decoded_text={};
	
	for(int i=0; i<text.length(); i++)
	{
		char sign=text[i]-(key[i%key.length()]-64);
		
		if(sign<'A')
			sign+=26;
			
		decoded_text+=sign;
	}
	
	return decoded_text;
}

bool coding_the_text_exercise_4a()
{
	fstream infile_to_code("tj.txt",ios::in);
	fstream infile_key_to_code("klucze1.txt",ios::in);
	fstream outfile_coded_text("wynik4a.txt",ios::out);
	
	string text_to_code;
	string key_to_code;
	
	while(infile_to_code>>text_to_code && infile_key_to_code>>key_to_code)
	{
		outfile_coded_text<<coding(text_to_code, key_to_code)<<endl;
	}
	
	infile_to_code.close();
	infile_key_to_code.close();
	outfile_coded_text.close();
	
	return true;
}

bool decoding_the_text_exercise_4b()
{
	fstream infile_to_decode("sz.txt",ios::in);
	fstream infile_key_to_decode("klucze2.txt",ios::in);
	fstream outfile_decoded_text("wynik4b.txt",ios::out);
	
	string text_to_decode;
	string key_to_decode;
	
	while(infile_to_decode>>text_to_decode && infile_key_to_decode>>key_to_decode)
	{
		outfile_decoded_text<<decoding(text_to_decode, key_to_decode)<<endl;
	}
	
	infile_to_decode.close();
	infile_key_to_decode.close();
	outfile_decoded_text.close();
	
	return true;
}

int main(int argc, char** argv) {
	
	coding_the_text_exercise_4a();
	decoding_the_text_exercise_4b();
	
	return 0;
}
