#include <iostream>
#include <string>
#include <cctype>

using namespace std;

short string_comparison(const string& first,const string& second);

int main(void)
{
	short comp_res;
	string first, second;
	
	/* insert string */
	cout << "\nPlease enter a string:  ";
	cin >> first;
	
	cout << "\nPease enter another string:  ";
	cin >> second;

	/* string comparison function */
	comp_res = string_comparison(first,second);
	
	/* print out the compared strings */
	if (comp_res > 0)
	{
		cout << '\'' << first << "' comes after '" << second << "' in the dictionary!\n";
	}
	else if (comp_res < 0)  // first < second?
	{
		cout << '\'' << first << "' comes before '" << second << "' in the dictionary!\n";
	}
	else
	{
		cout << '\'' << first << "' is the same as '" << second << "'!\n";
	}
	return 0;
}
