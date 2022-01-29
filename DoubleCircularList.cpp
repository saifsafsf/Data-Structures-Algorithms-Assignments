/* C++ Program to Implement Circular Doubly Linked List
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
 * Class Declaration
 */
class DoubleCircularList
{
public:
	int counter = 0;

	/*
	 * Node Declaration
	 */
	struct node
	{
		int info;
		node *next;
		node *prev;
	} 
	*start, *last;

	DoubleCircularList()
	{
		start = NULL;
		last = NULL;
	}

	/*
		 *CREATE NODE AND ALLOCATE MEMORY DYNAMICALLY
		 */
	node *createNode(int value)
	{
		// node creation & value assignment
		node *temp = new node();
		temp->info = value;

		return temp;
	}

	/*
		 *INSERTS ELEMENT AT BEGINNING
		 */
	void insertAtStart()
	{
		int value;

		// taking user input
		cout << endl
			 << "Enter the element to be inserted: ";
		cin >> value;

		// temporary node to insert
		node *temp = createNode(value);

		// if list is empty
		if (start == last && start == NULL)
		{
			start = temp, last = temp;
		}

		// if list is not empty
		else
		{
			// start & last updated
			temp->next = start;
			start->prev = temp;
			temp->prev = last;
			last->next = temp;
			start = temp;
		}

		// length updated
		this->counter++;
	}

	/*
		 *INSERTS ELEMNET AT LAST
		 */
	void insertLast()
	{
		int value;

		// taking user input
		cout << endl
			 << "Enter the element to be inserted: ";
		cin >> value;

		// temporary node to insert
		node *temp = createNode(value);

		// if list is empty
		if (start == last && start == NULL)
		{
			start = temp, last = temp;
		}
		
		// if list is not empty
		else
		{
			// start & last updated
			temp->next = start;
			start->prev = temp;
			temp->prev = last;
			last->next = temp;
			last = temp;
		}

		// length updated
		this->counter++;
	}

	/*
		 *INSERTS ELEMENT AT POSITION
		 */
	void insertAtPos()
	{
		int value, pos, i = 1;

		// taking user input
		cout << endl
			 << "Enter the postion of element inserted: ";
		cin >> pos;

		// if inserting at last
		if (pos == counter + 1)
		{
			this->insertLast();
		}

		// if inserting at start
		else if (pos == 1)
		{
			this->insertAtStart();
		}

		// if inserting at remaining valid positions
		else if (1 < pos <= counter)
		{
			cout << endl
				 << "Enter the element to be inserted: ";
			cin >> value;

			// temporary node
			node *temp = createNode(value), *temp2 = start;

			// finding node at that position
			for (; i < pos; i++)
			{
				temp2 = temp2->next;
			}

			// placing the node in between
			temp->next = temp2;
			temp->prev = temp2->prev;
			temp2->prev->next = temp;
			temp2->prev = temp;

			// counter updated
			this->counter++;
		}

		// if position is invalid
		else
		{
			return;
		}
	}

	/*
		 * Delete Node at Particular Position
		 */
	void deleteAtPos()
	{
		int pos, i = 1;
		node *s;

		// taking user input
		cout << endl
			 << "Enter the postion of element to be deleted: ";
		cin >> pos;

		// if list is empty 
		if (start == last && start == NULL)
		{
			return;
		}

		// if start is to be deleted
		else if (pos == 1)
		{
			// if list contains 1 element only
			if (counter == 1)
			{
				start = NULL, last = NULL;
			}

			else
			{
				// s is deleted & start is updated
				s = start;
				s->prev->next = s->next;
				s->next->prev = s->prev;
				start = s->next;
				delete s;
			}

			// counter updated
			this->counter--;
		}

		// if last is deleted
		else if (pos == counter)
		{
			// s is deleted & last is updated
			s = last;
			s->prev->next = s->next;
			s->next->prev = s->prev;
			last = s->prev;
			delete s;

			// counter updated
			this->counter--;
		}

		// if position is remaining positions
		else if (1 < pos < counter)
		{
			s = start;

			// iterating to find the node
			for (; i < pos; i++)
			{
				s = s->next;
			}

			// deleting s
			s->prev->next = s->next;
			s->next->prev = s->prev;
			delete s;

			// counter updated
			this->counter--;
		}

		// if position is invalid
		else
		{
			return;
		}
	}

	/*
		 * Display Elements of the List
		 */
	void display()
	{
		// temporary node
		node *temp = start;

		// heading message
		cout << "List Data: ";

		// if list is empty
		if (temp == NULL)
		{
			cout << "Empty!" << endl;
			return;
		}

		// iterating until last is left
		while (temp != last)
		{
			cout << temp->info << ' ';
			temp = temp->next;
		}

		// displaying last info
		cout << last->info << endl;
	}
};

/*
 * Main: Contains Menu
 */
int main()
{
	int userChoice;
	DoubleCircularList cdl;
	while (1)
	{
		cout << "\n-------------------------------" << endl;
		cout << "Operations on Doubly Circular linked list" << endl;
		cout << "\n-------------------------------" << endl;
		cout << "1. Insert at Beginning" << endl;
		cout << "2. Insert at Last" << endl;
		cout << "3. Insert at Specific Position" << endl;
		cout << "4. Delete at Specific Position" << endl;
		cout << "5. Display List" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> userChoice;
		switch (userChoice)
		{
		case 1:
			cdl.insertAtStart();
			break;
		case 2:
			cdl.insertLast();
			break;
		case 3:
			cdl.insertAtPos();
			break;
		case 4:
			cdl.deleteAtPos();
			break;
		case 5:
			cdl.display();
			break;
		case 6:
			exit(1);
		default:
			cout << "Wrong choice" << endl;
		}
	}
	return 0;
}
