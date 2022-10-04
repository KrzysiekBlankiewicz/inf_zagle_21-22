#include <iostream>
#include <cmath>

using namespace std;
double tromba(int pokolenie){
	if(pokolenie==1)
	return 3.5;
	return tromba(pokolenie-1)*2/3;
}
	int countpra(string s){
		int count=0;
		for(int i=0;s[i]!='w';i=i+3){
			
			if(s[i]=='p'&&s[i+1]=='r'&&s[i+2]=='a'){
				                                                              
				count++;
			}
		else{
			return 0;
		}
			
			
		}
		
		
		
		
		return count+3;
		
	}
	
	
	
	

	
int main(int argc, char** argv) {
	int pokolenie;
	string s;
	cout<<"podaj stopieñ pokrewieñstwa"<<endl;
	cin>>s;
	pokolenie=countpra(s);
	
	int dlugosc;
	dlugosc=s.length();
	pokolenie=countpra(s);
   if(dlugosc!=(pokolenie-3)*3+4){
   	
   	cout<<"zle"<<endl;
   }
  else{
	cout<<tromba(pokolenie)<<endl;
    cout<<pokolenie<<endl;
    }
	
	return 0;
}
