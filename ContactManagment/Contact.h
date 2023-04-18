#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <list>
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
		Contact(const Contact&);
		friend ostream& operator << (ostream&, const Contact&);
		char* getname();
		char* getsurname();
		char* getphone();
		void setname( char *);
		void setsurname(char*);
		void setphone(char*);
		string getcompany();
		string getemail();
		void setcompany(string);
		void setemail(string);
		void display();
		~Contact();
};

