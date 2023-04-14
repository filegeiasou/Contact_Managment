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
	out << "First name : " << a.first_name << endl;
	out << "Surname : " << a.surname << endl;
	out << "Phone :" << a.phone << endl;
	out << "Company : " << a.company << endl;
	out << "Email : " << a.email << endl;
	return out;
}
