#include "pch.h"
#include <iostream>
#include <string>         // std::string
#include <algorithm> 
#include <regex>
using namespace std;

int main()
{
	string input,output;
	int end1, end2, end3, sub, end, length, count;
	count = 0;
	end1 = 0; end2 = 0; end3 = 0; sub = 0;
	string head = "ATG";
	string tail1, tail2, tail3;
	tail1 = "TAG"; tail2 = "TAA"; tail3 = "TGA";
	cout << "Enter a gene code:"; //ATGHHJJTAGATGHHKKKTAG kjkjkkj     TTATGTTTTAAGGATGGGGCGTTAGTT  TTATGTTTTAGGGATGGGGCGTTAGTT
	cin >> input;
	regex e("[TGAC]*");
	if (!regex_match(input, e)) { cout << "not a normal Genome code!"; return 1; }
	while (input != "")
		{
			sub = input.find(head);
			end1 = input.find(tail1);  end2 = input.find(tail2);  end3 = input.find(tail3);
			if (sub != std::string::npos && (end1 > sub + 2 || end2 > sub + 2 || end3 > sub + 2))
			{
				if (end1 > sub + 2){
					end = end1;
					if (end2 > sub + 2){   
						end = min(end, end2);
						if (end3 > sub + 2){
							end = min(end, end3);}
					}}
				length = end - sub - 3;
				output = input.substr(sub + 3, length);
				if (output.length() % 3 == 0) { 
				cout << output; cout << "\n"; 
				count = count + 1; }
				input.erase(0, end + 3);
			}
			else {  break; }
		}
	if (count<=0){ cout << "no gene found"; }
	return 0;	
}
