#include <iostream>
double dlugosc(short pokolenie)
{return pokolenie?dlugosc(pokolenie-1)*2/3:3.5;}
short pra_counter(std::string input)
{short counter;
for(counter=0;counter<(input.length()-2)/3;++counter)
if(input.substr(3*counter,3)!="pra")
exit(1);
++++++counter;
if(input.length()<4||input.substr(input.length()-4,4)!="wnuk")
exit(1);
return counter;}
int main()
{std::string input;
std::cout<<dlugosc(pra_counter(std::cin>>input?input:"\0")-1);
return 0;}
