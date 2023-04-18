#include "Contact.h"
Contact::Contact( char* first_name,  char* surname, string company,  char* phone, string email)
{
	this->first_name = new char[strlen(first_name)+1];
	this->surname = new char[strlen(surname)+1];
	this->phone = new char[strlen(phone)+1];
	this->company =  company;
	this->email = email;
	strcpy_s(this->first_name, strlen(first_name)+1, first_name);
	strcpy_s(this->surname, strlen(surname)+1, surname);
	strcpy_s(this->phone, strlen(phone)+1, phone);
}

Contact::Contact( char* first_name,  char* surname,  char* phone)
{
	this->first_name = new char[strlen(first_name)+1];
	this->surname = new char[strlen(surname)+1];
	this->phone = new char[strlen(phone)+1];
	strcpy_s(this->first_name, strlen(first_name)+1, first_name);
	strcpy_s(this->surname, strlen(surname) +1,  surname);
	strcpy_s(this->phone, strlen(phone) +1,  phone);
	this->company = "None";
	this->email = "None";
}

Contact::~Contact()
{
	delete[] first_name;
	delete[] surname;
	delete[] phone;
}

ostream& operator <<(ostream& out, const Contact& a)
{
	out << a.first_name << endl;
	out << a.surname << endl;
	out << a.phone << endl;
	out << a.company << endl;
	out << a.email << endl;
	return out;
}

void Contact::display()
{
	cout << "First name : " << this->first_name << endl;
	cout << "Surname : " << this->surname << endl;
	cout << "Phone :" << this->phone << endl;
	cout << "Company : " << this->company << endl;
	cout << "Email : " << this->email << endl;
}

char * Contact::getname()
{
	return this->first_name;
}

char* Contact::getsurname()
{
	return this->surname;
}

char* Contact::getphone()
{
	return this->phone;
}

void Contact::setname(char* name)
{
	strcpy_s(this->first_name, strlen(first_name) + 1, name);
}

void Contact::setsurname(char*surname)
{
	strcpy_s(this->surname, strlen(surname) + 1, surname);
}

void Contact::setphone(char*phone)
{
	strcpy_s(this->phone, strlen(phone) + 1, phone);
}

string Contact::getcompany()
{
	return this->company;
}

string Contact::getemail()
{
	return this->email;
}

void Contact::setcompany(string company)
{
	this->company = company;
}

void Contact::setemail(string email)
{
	this->email = email;
}