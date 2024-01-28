#include <iostream>
#include <iomanip>
using namespace std;

int generator = 1;

class Task
{
public:
    int number;
    string title;
    string text;
    bool done;
    Task* next;

    Task()
    {
        number = 0;
        done = false;
        next = NULL;
    }
};

class List
{
    Task* start;

public:
    List()
    {
        start = NULL;
    }

    void search (string t, Task * s)
    {
        if (s == NULL)
        {
            cout << "Task not found!" << endl;
            return;
        }

        if (t == s -> title)
        {
            cout << "Task found" << endl;
            cout << "Task number: " << s -> number << endl;
            cout << "Title: " << s -> title << endl;
            cout << "Text: " << s -> text << endl;
            s -> done ? cout << "status: completed" << endl : cout << "status: pending" << endl << endl;
        }

        else
        {
            search (t, s -> next);
        }
    }

    void add (string ti, string te)
    {
        Task * newTask = new Task ();
        newTask -> number = generator++;
        newTask -> title = ti;
        newTask -> text = te;
        
        if (start == NULL)
        {
            start = newTask;
        }

        else
        {
            Task * temp = start;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newTask;
        }

        cout << "Task added successfully!" << endl;
    }

    void remove (string t, Task * s)
    {
        if (s == NULL)
        {
            cout << "Task not found!" << endl;
            return;
        }

        if (t == s -> title)
        {
            Task * temp = start;
            if (s == start)
            {
                start = start -> next;
            }
            else
            {
                Task * temp = start;
                while (temp -> next != NULL && temp -> next != s)
                {
                    temp = temp -> next;
                }
                temp -> next = s -> next;
            }
            delete s;

            cout << "Task removed successfully!" << endl;

            generator = 1;
            temp = start;
            while (temp != NULL)
            {
                temp -> number = generator++;
                temp = temp -> next;
            }
        }

        else
        {
            remove (t, s -> next);
        }
    }

    void edit (string t, Task * s)
    {
        if (s == NULL)
        {
            cout << "Task not found!" << endl;
            return;
        }

        if (t == s -> title)
        {
            cout << "Enter new title: ";
            getline (cin, s -> title);
            cout << "Enter new text: ";
            getline (cin, s -> text);
            cout << "Task edited successfully!" << endl;
        }

        else
        {
            edit (t, s -> next);
        }
    }

    void mark (string t, Task * s)
    {
        if (s == NULL)
        {
            cout << "Task not found!" << endl;
            return;
        }

        if (t == s -> title)
        {
            s -> done = true;
            cout << "Task marked as completed!" << endl;
        }

        else
        {
            mark (t, s -> next);
        }
    }

    void tasks (Task * t, Task * s)
    {
        if (s == NULL)
        {
            cout << "There are no tasks to do." << endl;
        }

        if (t == NULL)
        {
            return;
        }

        cout << "Task number: " << t -> number << endl;
        cout << "Title: " << t -> title << endl;
        cout << "Text: " << t -> text << endl;
        t -> done ? cout << "status: completed" << endl << endl : cout << "status: pending" << endl << endl;

        tasks (t -> next, s);
    }

    Task * get_start ()
    {
        return start;
    }
};

void exit ()
{
    system ("cls");
    cout << endl << endl << endl;
    cout << setw (100) << "==============================================================" << endl;
    cout << setw (100) << "                     Thank You for using.                     " << endl;
    cout << setw (100) << "                        See You Again.                        " << endl;
    cout << setw (100) << "==============================================================" << endl;
    cout << endl << endl << endl;
}

void back (int & ch)
{
    cout << endl << endl;
    cout << setw(100) << "==============================================================" << endl;
    cout << setw(100) << "       Press corresponding number for specific operation      " << endl;
    cout << setw(100) << "==============================================================" << endl;
    cout << setw(100) << "                                                              " << endl;
    cout << setw(100) << "                          1. Go Back                          " << endl;
    cout << setw(100) << "                          0. Exit                             " << endl;
    cout << setw(100) << "==============================================================" << endl;
    cout << setw(100) << "                                                              " << endl;
    cout << setw(75) << "                       Enter number: ";
    cin >> ch;

    if (ch == 0)
        exit ();
}

void to_do_list()
{
    List l;
    int choice;
    bool flag = false;

    do
    {
        system("cls");
        cout << setw(100) << "==============================================================" << endl;
        cout << setw(100) << "                   Welcome to my To Do List                   " << endl;
        cout << setw(100) << "       Press corresponding number for specific operation      " << endl;
        cout << setw(100) << "==============================================================" << endl;
        cout << setw(100) << "                                                              " << endl;
        cout << setw(100) << "                      1. All Tasks                            " << endl;
        cout << setw(100) << "                      2. Search any Task                      " << endl;
        cout << setw(100) << "                      3. Add Task                             " << endl;
        cout << setw(100) << "                      4. Edit any Task                        " << endl;
        cout << setw(100) << "                      5. Mark Status                          " << endl;
        cout << setw(100) << "                      6. Delete any Task                      " << endl;
        cout << setw(100) << "                      0. Exit                                 " << endl;
        cout << setw(100) << "                                                              " << endl;
        cout << setw(100) << "==============================================================" << endl;
        cout << setw(100) << "                                                              " << endl;
        cout << setw(75) << "                       Enter number: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                system ("cls");
                l.tasks (l.get_start (), l.get_start ());
                flag = true;
                break;
            }

            case 2:
            {
                system ("cls");
                string title;

                cin.ignore ();
                cout << "Enter title of the task to search: ";
                getline (cin, title);

                l.search (title, l.get_start ());
                flag = true;
                break;
            }

            case 3:
            {
                system ("cls");
                string title;
                string text;

                cin.ignore ();
                cout << "Enter title: ";
                getline (cin, title);
                cout << "Enter text: ";
                getline (cin, text);

                l.add (title, text);
                flag = true;
                break;
            }

            case 4:
            {
                system ("cls");
                string title;

                cin.ignore ();
                cout << "Enter title of the task to edit: ";
                getline (cin, title);

                l.edit (title, l.get_start ());
                flag = true;
                break;
            }

            case 5:
            {
                system ("cls");
                string title;

                cin.ignore ();
                cout << "Enter title of the task to mark it completed: ";
                getline (cin, title);

                l.mark (title, l.get_start ());
                flag = true;
                break;
            }

            case 6:
            {
                system ("cls");
                string title;

                cin.ignore ();
                cout << "Enter title of the task to delete: ";
                getline (cin, title);

                l.remove (title, l.get_start ());
                flag = true;
                break;
            }

            case 0:
            {
                exit ();
                break;
            }

            default:
            {
                break;
            }
        }

        if (flag)
        {
            flag = false;
            back (choice);
        }

    } while (choice != 0);
}

int main()
{
    to_do_list();
    return 0;
}
