#include <iostream>
#include <fstream>
#include "list.h"
#include "phonenumbers.h"

using namespace std;

enum Command {
    endProgramm, add, find1, find2, save
};

Command setCommand(int tmp)
{
    return static_cast<Command>(tmp);
}

int main()
{
    ifstream fin;
    fin.open("phone_numbers.txt");
    List *phonebook = createList();
    Person *newPerson = createPerson();
    int amount = 0;
    fin >> amount;
    char curSymbol = 0;
    fin.get(curSymbol);
    for (int i = 0; i < amount; ++i)
    {
        input(fin, newPerson->phone);
        input(fin, newPerson->name);
        pushBack(phonebook, *newPerson);
    }
    fin.close();

    ofstream fout;
    fout.open("phone_numbers.txt");
    int tmp = 1;
    Command way = setCommand(tmp);
    char name[maxSize];
    char phone[maxSize];
    ListElement *searched = nullptr;
    while (tmp != 0)
    {
        cout << "0 - exit" << endl;
        cout << "1 - add note" << endl;
        cout << "2 - find phone number by name" << endl;
        cout << "3 - find name by phone number" << endl;
        cout << "4 - save" << endl;
        cout << "Enter a number: ";
        cin >> tmp;
        way = setCommand(tmp);
        cin.get(curSymbol);
        switch (way)
        {
            case add:
                cout << "Enter phone number and name: ";
                input(newPerson->phone);
                input(newPerson->name);
                pushBack(phonebook, *newPerson);
                break;

            case find1:
                cout << "Enter name: ";
                input(name);
                searched = findName(phonebook, name);
                cout << "Phone number is: ";
                if (searched == nullptr)
                    cout << "not found";
                else
                    show(searched->value.phone);
                break;

            case find2:
                cout << "Enter phone number: ";
                input(phone);
                show(phone); cout << endl;
                searched = findPhone(phonebook, phone);
                cout << "Name is: ";
                if (searched == nullptr)
                    cout << "not found";
                else
                    show(searched->value.name);
                break;

            case save:
                showList(fout, phonebook);
                break;
        }
        cout << endl;
    }

    clearList(phonebook);
    delete newPerson;
    fout.close();
}
