#include <iostream>
#include <string>

using namespace std;

double tromba(int pokolenie)
{
	if(pokolenie==1)
		return 3.5;
	
	return tromba(pokolenie-1)*2/3;
}

int count_pra(string s)
{
	int count=0;
	
	for(int i=0; i<s.length() && s[i]=='p'; i+=3)
	{
		if(s[i]=='p' && s[i+1]=='r' && s[i+2]=='a')
			count++;
		else
			return -1;
	}
	
	if(s.length()-count*3==4 && s.substr(s.length()-4,4)=="wnuk")
		return count+3;
	else
		return -1;
}


int main(int argc, char** argv) {
	
	string input;
	
	cin>>input;
	
	int pokolenie=count_pra(input);
	
	if(pokolenie==-1)
		cout<<"Blad nazwy"<<endl;
	else
		cout<<tromba(pokolenie)<<endl;
	
	return 0;
}
