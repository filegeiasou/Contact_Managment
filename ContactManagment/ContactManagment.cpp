#include "Contact.h"
#include <vector>
#include <list>
using namespace std;
int main()
{
    list <Contact* > a;
    int flag = 0;
    cout << "Contact Managment!" << endl;
    int count = 0;
    while (flag != 4)
    {
        cout << "Select what you want " << endl;
        cout << "1)Create contact  2)See contact 3)Delete contact  4)Exit" << endl;
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
            if (epil == 'Y' || epil == 'y')
            {
                string company;
                cout << "Give a company name : " << endl;
                cin >> company;
                string email;
                cout << "Give a email : " << endl;
                cin>> email;
                Contact *contact1=new Contact(name, surname,company, phone,email);
                a.push_back(contact1);
                count++;
            }
            else
            {
                Contact *contact2 = new Contact(name, surname, phone);
                a.push_back(contact2);
               /* char* pr = (*contact2).getname();
                cout << *pr << endl;*/
                count++;
            }
            cout << "You create a contact " << endl;
        }
        else if (flag == 2)
        {
            list<Contact * >::iterator it;
            for (it = a.begin(); it != a.end(); ++it)
            {
                cout << **it;
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
            cout << "See you soon!" << endl;
        }

    }
    cout << "Bye" << endl;
    return 0;
}
