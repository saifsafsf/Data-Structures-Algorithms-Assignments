#include <iostream>
#include <string>
#define SIZE 100

using namespace std;

/*
Patient class to store patient details
*/
class Patient {
    public:

    // patient name & id (static) to be same for every object
    string pat_name;
    int patient_id;

    // parameterized constructor
    Patient(string pat_name)
    {
        this->pat_name = pat_name;
    }
};

/*
Queue ADT
*/
class Queue {
    public:

    // front & rear indices, array to store patients
    int front = 0, rear = -1;
    Patient* arr[SIZE];

    // to add patient to rear of Queue
    void Enqueue(Patient* patient)
    {
        // if queue is full
        if(isFull())
        {
            return;
        }

        // if queue has space
        arr[++rear] = patient;
    }

    // to remove patient from queue's front
    Patient* Dequeue()
    {
        // if queue is not empty
        if (!(isEmpty()))
        {
            // storing required patient in a variable
            Patient *output = arr[front];

            // shifting each patient one step towards the front
            for (int i = 1; i <= rear; i++)
            {
                arr[i-1] = arr[i];
            }

            // updating the rear, returning the output
            rear--;
            return output;
        }
    }

    // true if rear is smaller than front
    bool isEmpty()
    {
        return rear < front;
    }

    // true if rear is last possible index
    bool isFull()
    {
        return (rear + 1) == SIZE;
    }

    // makes all patients inaccessible
    void Clear()
    {
        rear = -1, front = 0;
    }

    // displays pateint data on the front
    void FirstElement()
    {
        // if queue is empty
        if (isEmpty())
        {
            return;
        }

        // displaying required 
        cout << "Patient ID: " << arr[front]->patient_id << endl;
        cout << "Patient Name: " << arr[front]->pat_name << endl;
    }

}; // end of class Queue()

/*
Wrapper class to use Queue in hospital management system
*/
class Doctor {
    public:

    // storing doctor's id, name, & his patients' queue
    int doctor_id;
    string doc_name;
    Queue *que = new Queue();

    // parameterized constructor
    Doctor(int doctor_id, string doc_name)
    {
        this->doctor_id = doctor_id;
        this->doc_name = doc_name;
    }

    // Adding Patient in the queue
    void RegisterPatient(Patient *pat)
    {
        // assigning registeration number
        pat->patient_id = que->rear + 1;
        que->Enqueue(pat);
    }

    // removing patient from the queue
    Patient* ServePatient()
    {
        return que->Dequeue();
    }

    // Clearing the queue
    void CancelAll()
    {
        que->Clear();
    }

    // true if the queue's empty
    bool CanDoctorGoHome()
    {
        return que->isEmpty();
    }

    // displays all patients in sorted order (by name)
    void ShowAllPatient()
    {
        // if queue is empty
        if (que->isEmpty())
        {
            return;
        }

        // array to store sorted patients
        Patient* sort_arr[que->rear + 1];

        // making a copy of queue in array
        for(int i = 0; i <= que->rear; i++)
        {
            sort_arr[i] = que->Dequeue();
            que->Enqueue(sort_arr[i]);
        }

        // bubble sort algorithm, iterating through list again & again
        for(int i = 0; i < (que->rear); i++)
        {
            // iterating through the list
            for(int j = 0; j < (que->rear - i); j++)
            {
                // comparing 2 names & sorting them
                if (sort_arr[j]->pat_name > sort_arr[j+1]->pat_name)
                {
                    // exchange using a temporary variable
                    Patient *temp = sort_arr[j];
                    sort_arr[j] = sort_arr[j+1];
                    sort_arr[j+1] = temp;
                }
            }
        }

        // displaying the queue
        cout << "\nPatients: \n";
        for (int i = 0; i <= (que->rear); i++)
        {
            cout << "   " << sort_arr[i]->pat_name << endl;
        }
    }

}; // end of class Doctor()


int main()
{
    // 1 doctor & 5 patients
    Doctor *doc = new Doctor(12, "Saif Ullah");
    Patient *pat1 = new Patient("Laraib Nadeem");
    Patient *pat2 = new Patient("Laura Swift");
    Patient *pat3 = new Patient("Dixie Brown");
    Patient *pat4 = new Patient("Zoe Saldana");
    Patient *pat5 = new Patient("Zoe Salazar");

    // registering patients
    doc->RegisterPatient(pat4);
    doc->RegisterPatient(pat2);
    doc->RegisterPatient(pat3);
    doc->RegisterPatient(pat1);
    doc->RegisterPatient(pat5);

    doc->ShowAllPatient();

    // serving first 2 patients
    doc->ServePatient();
    doc->ServePatient();

    doc->ShowAllPatient();

    // checking if doctor is free
    isFree:
    if (doc->CanDoctorGoHome())
    {
        cout << "\nDoctor is free to go home.\n\n";
        return 0;
    }

    else
    {
        cout << "\nAppointments pending...\n";
    }

    // clearing his appointments
    doc->CancelAll();

    goto isFree;
}