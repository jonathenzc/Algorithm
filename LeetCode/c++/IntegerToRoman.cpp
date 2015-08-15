#include <iostream>
#include <string>
#include <map>

using namespace std;

string intToRoman(int num) 
{
	//构建1000，900，500，400，100，90，50，40，10，9，5，4，1的映射
	int romanNum[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	string letter[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		
	string result="";
	for(int i=0;i<13;i++)
	{	
	    while(num>=romanNum[i])
		{
			num -= romanNum[i];
			result += letter[i];
		}
	}
	
	return result;    
}

int main()
{
	cout<<intToRoman(10)<<endl
		<<intToRoman(4)<<endl
		<<intToRoman(7)<<endl
		<<intToRoman(9)<<endl
		<<intToRoman(3999)<<endl;
	
	
	return 0;
}