#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node
{

    string data;

    Node *next;
    Node *prev;
    Node *up;
    Node *down;

    Node()
    {

        next = NULL;
        prev = NULL;
        up = NULL;
        down = NULL;
    }
};

Node *head = NULL;
Node *tail = NULL;
Node *upper_line = NULL;
Node *lower_line = NULL;

Node **arr = new Node *[500];
int connection = 0;

Node *node_1(char val)
{
    Node *node = new Node();
    node->data = val;

    if (head == NULL)
    {
        head = node;
        tail = node;
    }

    return node;
}

void fullyLinkedList(char text)
{
    Node *temp = node_1(text);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;

    if (connection != 0)
    {
        if (upper_line != NULL)
        {
            temp->up = upper_line;
            upper_line->down = temp;
            upper_line = upper_line->next;
        }
    }
}

struct Notepad
{
    char text;
    void read()
    {
        system("Color B");
        system("CLS");

        cout << "\t\t\t\t\t\t*************************************************" << endl
             << "\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t     NOTEPAD\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*" << endl;
        cout << "\t\t\t\t\t\t*************************************************" << endl
             << endl
             << endl;
        cout << "\n\n\n \t\t================ READ TEXT ================\n\n\n"
             << endl;
        string data;
        ifstream Notepad_File("Notepad.txt");
        while (getline(Notepad_File, data))
        {
            cout << data << endl;
        }
        
    }
     
    void enterText()
    {
        system("Color 2");
        system("CLS");

        cout << "\t\t\t\t\t\t*************************************************" << endl
             << "\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t     NOTEPAD\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*" << endl;
        cout << "\t\t\t\t\t\t*************************************************" << endl
             << endl
             << endl;
        cout << "\n\n\n \t\t================ WRITE TEXT ================" << endl;
        cout << "\n\n\n\t\tEnter 0 to stop" << endl;
        cout << "\n\t\tEnter Text (Alphabets or Numbers) " << endl;
        while ('1')
        {
            text = getch();
            if (text == '0')
            {

                break;
            }

            else if (text == '\r')
            {
                cout << endl;
                saveNote('\n');
                text = getch();
                cout << text;
                fullyLinkedList(text);
                saveNote(text);
            }
            else
            {
                cout << text;
                fullyLinkedList(text);
                saveNote(text);
            }
        }
    }

    void menu()
    {
    menu:
    	
        cout << "\n\n\n \t\t================ MENU ================" << endl;
        cout << "\n\n\n\t\ta. Add Text" << endl;
        cout << "\n\t\tb. Read Text" << endl;
        cout << "\n\t\tc. Delete File" << endl;
        cout << "\n\t\t0. Exit Program" << endl;

        cout << "\n\t\tEnter Your Choice: ";
        cin >> text;

        if (text == 'a')
        {
            enterText();
        }
        else if (text == 'b')
        {
            read();
        }
        else if (text == 'c')
        {
            char filename[] = "Notepad.txt";

            int result = remove(filename);
            if (result != 0)
            {
                cout << "\n\t\t\t\t\t\tFile Deletion Failed!! because File Not Found ";
            }
            else
            {
                cout << "\n\t\t\t\t\t\tFile Deleted Successfully";
            }
        }
        else if (text == '0')
        {
        	system("CLS");
        	system("Color D");
        	 cout << "\t\t\t\t\t\t*************************************************" << endl
             << "\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\tTHANK YOU FOR USING MY NOTEPAD\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
             << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*" << endl;
        cout << "\t\t\t\t\t\t*************************************************" << endl
             << endl
             << endl;
            exit(0);
        }
        else
            cout << "\n\t\t\t\t\t\tOh no!! You Enter Invalid Entry! Please try Again\n";

        goto menu;
    }

    void saveNote(char r)
    {
        if (r != '0')
        {
            ofstream Notepad_File("Notepad.txt", ios::app);
            Notepad_File << r;
        }
    }
};

int main()
{

    cout << "\t\t\t\t\t\t*************************************************" << endl
         << "\t\t\t\t\t\t*\t\t\t\t\t\t*"
         << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
         << "\n\t\t\t\t\t\t*\t       WELCOME TO NOTEPAD\t\t*"
         << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
         << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*"
         << "\n\t\t\t\t\t\t*\t\t\t\t\t\t*" << endl;
    cout << "\t\t\t\t\t\t*************************************************" << endl
         << endl
         << endl;

    Notepad note;
    note.menu();
    note.enterText();
    note.read();

    return 0;
}
