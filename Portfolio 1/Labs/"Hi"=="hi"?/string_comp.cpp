#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/* string comparison function */
short string_comparison(const string& first,const string& second)
{
	short comp_res;	
	string::size_type c, shorter_length;
	
	shorter_length = first.size();
	if (second.length() < shorter_length)
	{
		shorter_length = second.length();
	}
	
	c = 0;
	while (c != shorter_length && toupper(first[c]) == toupper(second[c]))
	{
		c = c + 1;
	}
	
	if (c == shorter_length)
	{
		if (first.length() == second.length())
		{
			comp_res = 0;
		}
		else if (first.length() == shorter_length)
		{
			comp_res = -1;
		}
		else
		{
			comp_res = +1;
		}
	}//end of if (c == shorter_length)
	else
	{
		if (toupper(first[c]) > toupper(second[c]))
		{
			comp_res = +1;
		}
		else
		{
			comp_res = -1;
		}
	}
	return comp_res;
}//end of double string_comparison()
