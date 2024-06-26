#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

bool IsValidNumber(string Number)
{
	regex regex_NumberCheck("\\d{7}(A|B|C|H|E|M|À|Â|Ñ|Å|Ì|Í|K|Ê)\\d{3}\\s?((ĞÂ)|(ÂÀ)|(BI))\\d\\s+([À-ß][à-ÿ]+)?\\s*ĞÓÂÄ\\s[À-ß][à-ÿ]+");
	cmatch result;
	if (regex_match(Number.c_str(), result, regex_NumberCheck))
	{
		cout << "Number is correct" << endl;
		return true;
	}
	else
	{
		cout << "Number is not correct" << endl;
		return false;
	}
}

int main()
{
	string inputName = "input.txt";
	string outputName = "output.txt";
	fstream fin, fout;
	string strTmp;
	fin.open(inputName);
	fout.open(outputName);
	if (!fin.is_open() || !fout.is_open())
	{
		cout << "Incorrect file path" << endl;
		return 1;
	}
	while (!fin.eof())
	{
		getline(fin, strTmp);
		fout << IsValidNumber(strTmp) << endl;
	}

	return 0;
}