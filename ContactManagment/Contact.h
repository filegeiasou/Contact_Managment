#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Contact
{
	private:
		char* first_name, * surname;
		string company;
		char* phone;
		string  email;
	public:
		Contact( char * ,  char * , string ,  char *  , string );
		Contact( char* , char*,  char*);
		friend ostream& operator << (ostream&, const Contact&);
		char* getname();
		void display();
		~Contact();
};

