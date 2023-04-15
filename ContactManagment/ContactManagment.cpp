#include "Contact.h"
#include <fstream>
#include <vector>
#include <list>
using namespace std;
int main()
{
    list <Contact* > a,b;
    int flag = 0 , fg =1 ,flag3=0;
    cout << "Contact Managment!" << endl;
    while (flag != 5)
    {
        cout << "Select what you want " << endl;
        cout << "1)Create contact  2)See now list contacts 3)Delete contact 4)See all contacts  5)Exit" << endl;
        cin >> flag;
        if (flag == 1)
        {
            char* name = new char[50];
            cout << "Give a name : " << endl;
            cin >> name;
            char* surname = new char[50];
            cout << "Give a surname : " << endl;
            cin >> surname;
            char* phone = new char[10];
            cout << "Give a phone : " << endl;
            cin >> phone;
            cout << "Do you want to add more informations ? [Y/N]" << endl;
            char epil;
            cin >> epil;
            ifstream fp2;
                fp2.open("contacts.txt");
                char* name3 = new char[50];
                while (!fp2.eof())
                {
                    fp2.getline(name3, 50);
                    if (strcmp(name, name3) == 0)
                    {
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
                        Contact* contact1 = new Contact(name, surname, company, phone, email);
                        b.push_back(contact1);
                        cout << "You create a contact " << endl;
                        
                    }
                    else
                    {
                        Contact* contact2 = new Contact(name, surname, phone);
                        cout << "You create a contact " << endl;
                        b.push_back(contact2);
                    }
                }
                else
                {
                    cout << "The contact has already exists" << endl;
                }
            fp2.close();
        }
        else if (flag == 2)
        {
            list<Contact * >::iterator it;
            for (it = b.begin(); it != b.end(); ++it)
            {
                (**it).display();
                cout << "-------" << endl;
            }
        }
        else if (flag == 3)
        {
            list<Contact* >::iterator it;
            char* name = new char[50];
            cout << "Give a name : " << endl;
            cin >> name;
            for (it = a.begin(); it != a.end(); ++it)
            {
                char* pr = (*it)->getname();
                if (strcmp(pr, name)==0)
                {
                    a.erase(it);
                    break;
                }
            }
            cout << "You delete a contact " << endl;
        }
        else if (flag == 4)
        {
            if (fg == 1)
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
                        a.push_back(contact3);
                    }
                }
                fg = 0;
                fp.close();
            }
            a.splice(a.end(), b);
            list<Contact* >::iterator it;
            for (it = a.begin(); it != a.end(); ++it)
            {
                (**it).display();
                cout << "-------" << endl;
            }
        }
        else if (flag ==  5)
        {
            fstream fp;
            fp.open("contacts.txt",ios::out);
            list<Contact* >::iterator it;
            for (it = a.begin(); it != a.end(); ++it)
            {
                fp << **it;
            }
            fp.close();
            cout << "See you soon!" << endl;
        }

    }
    cout << "Bye" << endl;
    return 0;
}
