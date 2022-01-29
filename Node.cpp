#include <iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node *next;

};

Node *head = NULL;

class List
{
    public:

        int count = 0;

        void insertAtHead(int new_value)
        {
            // Node to be added at head
            Node *ptr = new Node();
            ptr->value = new_value;

            // Placed in the start
            ptr->next = head;

            // head & count updated
            head = ptr;
            this->count++;

        } // end of insertAtHead()

        void insertAtLocation(int location, int new_value)
        {
            // Node to be added at location, count updated
            Node *ptr = new Node();
            ptr->value = new_value;
            this->count++;

            // head updated if head doesn't exist
            if (head == NULL)
            {
                head = ptr;
            }

            else if (0 > location > this->count)
            {
                // count updated
                this->count--;
                return;
            }

            else
            {
                // Node to traverse thru existing list
                Node *ptr2 = head;

                // traversing till the desired location
                for (int i = 1; i < location-1 && ptr2; i++)
                {
                    ptr2 = ptr2->next;
                }

                // placing ptr on location
                ptr->next = ptr2->next;
                ptr2->next = ptr;
            }
        } // end of insertAtLocation()

        void deleteValue(int del_value)
        {
            // two nodes, one to traverse, second to link nodes after deletion
            Node *ptr2;
            Node *ptr = head;

            // until the del_value is found
            while(ptr->value != del_value && ptr)
            {
                ptr2 = ptr;
                ptr = ptr->next;
            }
            
            // if found
            if (ptr != NULL)
            {
                // ptr skipped & deleted
                ptr2->next = ptr->next;
                
                // count updated
                this->count--;

                delete ptr;
            }
        } // end of delete()

        void displayList()
        {
            // traversing node
            Node *ptr = head;

            while (ptr != NULL)
            {
                cout << ptr->value << endl;
                ptr = ptr->next;
            }
        } // end of displayList()

        void countList()
        {
            // displaying count value
            cout << this->count << endl << endl;

        } // end of countList()

};

int main()
{
    List lissy;
    char user_input;
    int val, loc;

    while (user_input != 'X')
    {
        cout << "\nMENU\n\nEnter the following:\n\n";
        cout << "'H' - Insert at head location\n";
        cout << "'L' - Insert at specified location\n";
        cout << "'R' - Delete specified value\n";
        cout << "'D' - Display the list\n";
        cout << "'C' - Count the list\n";
        cout << "'X' - Exit the program\n";
        cin >> user_input;

        switch (user_input)
        {
        case 'H':
            cout << "Integer value to be inserted: ";
            cin >> val;
            lissy.insertAtHead(val);
            break;

        case 'L':
            cout << "Integer value to be inserted: ";
            cin >> val;
            cout << "Location to be inserted at: ";
            cin >> loc;
            lissy.insertAtLocation(loc, val);
            break;

        case 'R':
            cout << "Integer value to be deleted: ";
            cin >> val;
            lissy.deleteValue(val);
            break;

        case 'D':
            cout << "List:\n";
            lissy.displayList();
            cout << "End\n";
            break;

        case 'C':
            cout << "List elements count: ";
            lissy.countList();
            break;

        case 'X':
            cout << "Program exited successfully";
            break;

        default:
            cout << "Invalid Input... Choose one from the menu.";
            break;
        }
    }

} // end of main method