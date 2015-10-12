/*
create a function to tokenize a string
*/

//includes
#include <iostream>
using namespace std;

//prototypes
void tokenize(char *s, char delim);

int main(void)
{
	tokenize("h,k", ',');

	return 0;
}

//tokenize prints a string split up between the specified delimeter
void tokenize(char *s, char delim)
{
	for(char *ptr = s; *ptr != '\0'; ptr++)
	{
		*ptr != delim ? cout << *ptr : cout << "\n";

		/*if (*ptr != delim)
		{
			cout << *ptr;
		}
		else
		{
			cout << "\n";
		}*/
	}
	cout << "\n";
}