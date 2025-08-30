#include <iostream>
#include <string>
#include <limits>
using namespace std;

class student
{
private:
    string name[10];
    int rollno[10];
    int marks[10][3];
    int sl[10];
    static int count;
    int total_students;

public:
    student() { total_students = 0; } // constructor initialize

    // function to clear wrong input
    void clearInput()
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // for intake data
    void intakedata(void)
    {
        cout << "Enter student details" << endl;
        for (int i = total_students; i < 10; i++)
        {
        
            while (true)
            {
                cout << "Enter SL number of " << count << " student: ";
                if (cin >> sl[i] && sl[i] > 0)
                    break;
                else
                {
                    cout << "Invalid input... SL number must be positive." << endl;
                    clearInput();
                }
            }

            // Name
            cout << "Enter name of " << count << " student: ";
            cin >> name[i];

            // Roll number
            while (true)
            {
                cout << "Enter roll number of " << count << " student: ";
                if (cin >> rollno[i] && rollno[i] > 0)
                    break;
                else
                {
                    cout << "Invalid input... Roll number must be positive." << endl;
                    clearInput();
                }
            }

            // Marks
            for (int j = 0; j < 3; j++)
            {
                while (true)
                {
                    cout << "Enter marks of subject " << (j + 1) << " (0-100): ";
                    if (cin >> marks[i][j] && marks[i][j] >= 0 && marks[i][j] <= 100)
                        break;
                    else
                    {
                        cout << "Invalid marks... Enter value between 0 and 100." << endl;
                        clearInput();
                    }
                }
            }

            count++;
            total_students++;

            // exit option during entry
            int r;
            while (true)
            {
                cout << "If you want to stop adding data, press 9. To continue, press 0: ";
                if (cin >> r && (r == 9 || r == 0))
                {
                    if (r == 9)
                    {
                        cout << "You exited data entry." << endl;
                        return; // exit intake function
                    }
                    else
                    {
                        cout << "Continue..." << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Invalid option... Enter only 9 or 0." << endl;
                    clearInput();
                }
            }
        }
    }

    void entrydisplay()
    {
        cout << "Entry successfully completed!" << endl;
    }

    // for search
    void search()
    {
        int search_sl;
        cout << "Enter SL. no to search: ";
        while (!(cin >> search_sl))
        {
            cout << "Invalid input... SL number must be numeric." << endl;
            clearInput();
        }

        for (int i = 0; i < total_students; i++)
        {
            if (sl[i] == search_sl)
            {
                cout << "Result found!" << endl;
                cout << "Student name       : " << name[i] << endl;
                cout << "Student roll number: " << rollno[i] << endl;
                cout << "Student average    : " << avgmarks(i) << endl;
                return;
            }
        }
        cout << "No data found!" << endl;
    }

    void displayall()
    {
        if (total_students == 0)
        {
            cout << "No student data has been added yet." << endl;
            return;
        }

        cout << "--- All Student Data ---" << endl;
        for (int i = 0; i < total_students; i++)
        {
            cout << "Sl no.             : " << sl[i] << endl;
            cout << "Student name       : " << name[i] << endl;
            cout << "Student roll no    : " << rollno[i] << endl;
            cout << "Student average    : " << avgmarks(i) << endl;
            cout << "_______------________" << endl;
        }
    }

    float avgmarks(int i)
    {
        float sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += marks[i][j];
        }
        return sum / 3.0;
    }
};

int student::count = 1;

int main()
{
    student secA;
    int option;

    while (true)
    {
        cout << "Choose your option" << endl;
        cout << "First you need to add data" << endl;
        cout << "1. Add data" << endl;
        cout << "2. Display all data" << endl;
        cout << "3. Search data" << endl;
        cout << "4. Exit" << endl;

        while (!(cin >> option))
        {
            cout << "Invalid input... Option must be numeric." << endl;
            secA.clearInput();
        }

        switch (option)
        {
        case 1:
            secA.intakedata();
            secA.entrydisplay();
            break;
        case 2:
            secA.displayall();
            break;
        case 3:
            secA.search();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid option.. Choose between 1 and 4." << endl;
        }
    }

    return 0;
}
