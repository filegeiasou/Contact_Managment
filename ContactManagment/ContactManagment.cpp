#include "Contact.h"
using namespace std;
void save(list <Contact*> );
void display(list <Contact*>);
void createlist(list <Contact*> *);
void deleteCon(list <Contact*>*);
void createCon(list <Contact*>*);
void searchCon(list <Contact*>);
int main()
{
    list <Contact* > a;
    int flag = 0;
    cout << "Contact Managment!" << endl;
    createlist(&a);
    while (flag != 5)
    {
        cout << "Select what you want " << endl;
        cout << "1)Create contact  2)See all contacts 3)Delete contact 4)Search Contact 5)Exit" << endl;
        cin >> flag;
        if (flag == 1)
        {
            createCon(&a);
        }
        else if (flag == 2)
        {
            display(a);
        }
        else if (flag == 3)
        {
            deleteCon(&a);
        }
        else if (flag == 4)
        {
            searchCon(a);
        }
        else if (flag == 5)
        {
            save(a);
            cout << "See you soon!" << endl;
        }
    }
    cout << "Bye" << endl;
    a.clear();
    return 0;
}

void save(list <Contact*> a)
{
    fstream fp;
    fp.open("contacts.txt", ios::out);
    list<Contact* >::iterator it;
    for (it = a.begin(); it != a.end(); ++it)
    {
        fp << **it;
    }
    fp.close();
}

void display(list <Contact*> a)
{
    int cnt = 0;
    list<Contact* >::iterator it;
    for (it = a.begin(); it != a.end(); ++it)
    {
        cnt++;
        cout << "Contact " << cnt << endl;
        (**it).display();
        cout << "-------" << endl;
    }
}

void createlist(list <Contact*> *a)
{
    ifstream fp;
    fp.open("contacts.txt");
    char* name2 = new char[50];
    char* surname2 = new char[50];
    char* phone2 = new char[10];
    string company2;
    string email2;
    const char* pr = "";
    while (!fp.eof())
    {
        fp.getline(name2, 50);
        fp.getline(surname2, 50);
        fp.getline(phone2, 50);
        getline(fp, company2);
        getline(fp, email2);
        if (strcmp(pr, name2) != 0)
        {
            Contact* contact3 = new Contact(name2, surname2, company2, phone2, email2);
            a->push_back(contact3);
        }
    }
    fp.close();
    delete[] name2;
    delete[] surname2;
    delete[] phone2;
}

void deleteCon(list <Contact*> *a )
{
    int f = 0;
    char* name2 = new char[50];
    char* surname2 = new char[50];
    list<Contact* >::iterator it;
    cout << "Give a name : " << endl;
    cin >> name2;
    cout << "Give a surname : " << endl;
    cin >> surname2;
    for (it = (*a).begin(); it != (*a).end(); ++it)
    {
        char* pr = (*it)->getname();
        char* pr1 = (*it)->getsurname();
        if (strcmp(pr, name2) == 0 && strcmp(pr1, surname2) == 0)
        {
            cout << "You delete a contact " << endl;
            (*a).erase(it);
            f = 1;
            break;
        }
    }
    save(*a);
    (*a).clear();
    createlist(a);
    if (f == 0)
        cout << "You can not delete this contact because it not exists" << endl;
    delete[]name2;
    delete[]surname2;
}
void createCon(list <Contact*> *a)
{
    int flag3 = 0;
    char* name = new char[50];
    char* surname = new char[50];
    char* phone = new char[10];
    char* name3 = new char[50];
    char* surname4 = new char[50];
    Contact* contact1 , *contact2;
    cout << "Give a name : " << endl;
    cin >> name;
    cout << "Give a surname : " << endl;
    cin >> surname;
    cout << "Give a phone : " << endl;
    cin >> phone;
    cout << "Do you want to add more informations ? [Y/N]" << endl;
    char epil;
    cin >> epil;
    ifstream fp2;
    fp2.open("contacts.txt");
    while (!fp2.eof())
    {
        fp2.getline(name3, 50);
        fp2.getline(surname4, 50);
        if (strcmp(name, name3) == 0 && strcmp(surname, surname4) == 0)
        {
            cout << "Same" << endl;
            flag3 = 1;
            break;
        }
    }
    if (flag3 == 0)
    {
        if (epil == 'Y' || epil == 'y')
        {
            string company;
            cout << "Give a company name : " << endl;
            cin >> company;
            string email;
            cout << "Give a email : " << endl;
            cin >> email;
            contact1 = new Contact(name, surname, company, phone, email);
            (*a).push_back(contact1);
        }
        else
        {
            contact2 = new Contact(name, surname, phone);
            (*a).push_back(contact2);
        }
        cout << "You create a contact " << endl;
        save(*a);
    }
    else
    {
        cout << "The contact has already exists" << endl;
    }
    fp2.close();
    delete[] name;
    delete[] surname;
    delete[] name3;
    delete[] surname4;
    delete[] phone;
}
void searchCon(list <Contact*> a)
{
    int f = 0;
    char* name2 = new char[50];
    char* surname2 = new char[50];
    list<Contact* >::iterator it;
    cout << "Give a name : " << endl;
    cin >> name2;
    cout << "Give a surname : " << endl;
    cin >> surname2;
    for (it = (a).begin(); it != (a).end(); ++it)
    {
        char* pr = (*it)->getname();
        char* pr1 = (*it)->getsurname();
        if (strcmp(pr, name2) == 0 && strcmp(pr1, surname2) == 0)
        {
            cout << "----------------------------" << endl;
            cout << "Details of specific contact " << endl;
            (*it)->display();
            cout << "----------------------------" << endl;
            f = 1;
            break;
        }
    }
    if (f == 0)
        cout << "Dont found the contact with this details" << endl;
    delete[] name2;
    delete[] surname2;
}