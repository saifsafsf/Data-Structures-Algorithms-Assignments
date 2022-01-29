#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>

using namespace std;

class Student
{
    public:

        // attributes of a student
        int id;
        string name, address;
        float cgpa;

        // no-argument constructor
        Student()
        {
            cgpa = 0;
            id = 0;
        }

        // parameterized constructor
        Student(int id, string name, string address, float cgpa)
        {
            this->id = id;
            this->name = name;
            this->address = address;
            this->cgpa = cgpa;
        }

        // to get Student data from the user
        void getStudent()
        {
            // taking user input
            cout << "\nEnter Student details:\n";

            cout << "ID: ";
            cin >> this->id;
            
            cout << "\nName: ";
            cin.ignore();
            getline(cin, this->name);

            cout << "\nCGPA: ";
            cin >> this->cgpa;

            cout << "\nAddress: ";
            cin.ignore();
            getline(cin, this->address);
        }

}; // end of Student class

class Vector
{
    // to expand the main array
    void grow()
    {
        // temp array to store students
        Student *temp = this->students;

        // array length doubled
        this->max_len *= 2;

        // original array expanded
        this->students = new Student[max_len];

        // copying students from temp array to original one
        for (int i = 0; i < this->len; i++)
        {
            this->students[i] = temp[i];
        }
    }

    // to shrink the main array
    void shrink()
    {
        // temp array to store students
        Student *temp = this->students;

        // array length doubled
        this->max_len /= 2;

        // original array expanded
        this->students = new Student[max_len];

        // copying students from temp array to original one
        for (int i = 0; i < this->len; i++)
        {
            this->students[i] = temp[i];
        }
    }

    // to find if vector's empty
    bool isEmpty()
    {
        return this->len == 0;
    }

    // to find if vector's full
    bool isFull()
    {
        return this->max_len == this->len;
    }

    public:

        // attributes of a vector
        int len = 0;
        int max_len = 5;

        // to store students
        Student *students = new Student[max_len];

        // to insert a student in the vector
        void insert(Student *student)
        {
            // when array is full
            if (isFull())
            {
                this->grow();
            }

            // student appended & length updated
            this->students[len] = *student;
            this->len++;
        }

        // to delete a student in the vector
        int Delete(int id)
        {
            // searching
            int index = search(id);

            // if found
            if (index > -1)
            {
                for(int i = index; i < this->len-1; i++)
                {
                    this->students[i] = this->students[i+1];
                }

                // length updated
                this->len--;

                // if array has been doubled & is half empty
                if (this->max_len > 5 && this->len <= this->max_len / 2)
                {
                    this->shrink();
                }

                // return 1 when deleted successfully
                return 1;
            }

            // when id not found
            return -1;
        }

        // to search the student by id
        int search(int id)
        {
            // iterating through the array
            for (int i = 0; i < this->len; i++)
            {
                // if found
                if (this->students[i].id == id)
                {
                    return i;
                }
            }

            // if not found
            return -1;
        }

        // to replace the contents by id
        int replace(int id, Student *student)
        {
            // searching the one to be replaced
            int index = search(id);

            // index check in the replaceAtIndex()
            return replaceAtIndex(index, student);
        }

        // to replace the contents at index
        int replaceAtIndex(int index, Student *student)
        {
            // if index is valid
            if (index > -1)
            {
                // replacing the students
                this->students[index] = *student;
                
                // return 1 when replaced successfully
                return 1;
            }

            // invalid index
            return -1;
        }

        void display()
        {
            cout << "\nDisplaying students' names: \n";
            for (int i = 0; i < this->len; i++)
            {
                cout << i+1 << ' ' << this->students[i].name << endl;
            }

            cout << endl;
        }
}; // end of class Vector

int main()
{
    // variables used
    Student *stu = new Student();
    Vector *vec = new Vector();
    int id, result, index;
    char user_input = 'Y';

    // unless user choose to close the program
    while (user_input != 'X')
    {
        // MENU to choose a function
        cout << "\nMENU\n\nEnter one of the following:\n\n";
        cout << "'I' - Insert a Student at the end\n";
        cout << "'D' - Delete a Student by ID\n";
        cout << "'S' - Search a Student by ID\n";
        cout << "'R' - Replace a Student by ID\n";
        cout << "'r' - Replace a Student at index\n";
        cout << "'d' - Display the Student Vector\n";
        cout << "'X' - Exit the program\n\n";
        cin >> user_input;

        switch (user_input)
        {
        case 'I':
            // getting values from user then inserting in vector
            stu->getStudent();
            vec->insert(stu);

            break;

        case 'D':
            // taking id from user to be deleted
            cout << "\nID of the student to be deleted: ";
            cin >> id;
            
            // deleting by id
            result = vec->Delete(id);

            // status display message
            if (result == 1)
                cout << "\nDeleted successfully.\n";
            else
                cout << "\nID not found.\n";

            break;

        case 'S':
            // taking id from user to be searched
            cout << "\nID of the student to be searched: ";
            cin >> id;

            // searching student by id
            index = vec->search(id);

            // status display message
            if (index != -1)
                cout << "\nStudent record found at location: " << index + 1;
            else
                cout << "\nID not found.\n";

            break;

        case 'R':
            // taking id from user to be replaced
            cout << "\nID of the student to be replaced: ";
            cin >> id;
            
            // Student will be replaced by
            stu = new Student(336, "Saif Ullah", "H-12, Islamabad", 3.62);

            // replacing student by id
            result = vec->replace(id, stu);

            // status display message
            if (result == 1)
                cout << "\nReplaced successfully.\n";
            else
                cout << "\nID not found.\n";

            break;

        case 'r':
            // taking index from user to be replaced
            cout << "\nIndex of the student to be replaced: ";
            cin >> index;
            
            // Student will be replaced by
            cout << "\nStudent will be replaced by: (Enter data)\n";
            stu->getStudent();

            // replacing student by index
            result = vec->replaceAtIndex(index, stu);
            
            // status display message
            if (result == 1)
                cout << "\nReplaced successfully.\n";
            else
                cout << "\nInvalid index.\n";

            break;

        case 'd':
            vec->display();
            break;

        case 'X':
            cout << "\nProgram exited successfully.\n";
            break;

        default:
            cout << "\nInvalid Input... Choose one from the menu.\n";
            break;
        }
    }

} // end of main method