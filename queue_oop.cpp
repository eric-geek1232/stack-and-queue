/*By Eric 9/01/2021 - QUEUE OOP-*/
#include <iostream>
#include <stdlib.h>

using namespace std;

/* Node structure
----------------------------------------------------------------------*/
struct Node
{
	string data;
	Node *next;
};

class Queue
{
	private:
		Node *front, *rear;
		int size;
		
		Node *createNode(string name);
		void showQueue(Node *front);
		void clearQueue(Node *&front);
	public:
		Queue();
		string add(string name);
		string remove();
		void show();
		string peek();
		void clear();
		bool isEmpty();
		int getSize();
		
};

/* Class methods
----------------------------------------------------------------------*/
Queue::Queue()
{
	front = NULL;
	rear = NULL;
	
	size = -1;
}

Node *Queue::createNode(string name)
{
	Node *newNode = new Node();
	
	newNode->data = name;
	newNode->next = NULL;
	
	return newNode;
}

string Queue::add(string name)
{
	Node *newNode = createNode(name);
	
	if (isEmpty()) {			// first element just add to front
		front = newNode;
	} else {
		rear->next = newNode;		// add to rear
	}
	
	rear = newNode;				// always rear points to end
	size++;
	
	return rear->data;
}

string Queue::remove()
{
	string item_aux;
	Node *front_aux = front; 	// get the whole queue from the front
	
	item_aux = front_aux->data; 	// get current data
	
	if (front == rear) { 		// when there's only a element
		front = NULL;		// initial conditions
		rear = NULL;
		size = -1;
	} else {
		front = front->next; 	// overwrite front with next node
		size--;	
	}

	delete front_aux;		// delete old queue
	
	return item_aux;
}

void Queue::showQueue(Node *front)
{
	if (front == NULL){		// end queue
		return;
	}
		
	if (front == rear) {		// last node
		cout<< " "<< front->data<< ".\n"<< endl;
	} else {
		cout<< " "<< front->data<< " - ";	
	}	
	
	showQueue(front->next);		// keep iterating
}

void Queue::show()
{
	showQueue(front);
}

void Queue::clearQueue(Node *&front)	// when you use recursion you must implement *& for using delete
{
	Node *node_aux = front;
	
	if (front == rear) {		// last node 
		cout<< " "<< front->data<< " .\n"<< endl;
		front = NULL;		// initial conditions
		rear = NULL;
		size = -1;
		
	} else {
		cout<< " "<< front->data<< " - ";
		front = front->next;			// overwrite front with next node;
		size--;
		
		clearQueue(front);			// keep iterating
	}
		
	delete node_aux;
}

void Queue::clear()
{
	clearQueue(front);
}

bool Queue::isEmpty()
{
	return front == NULL ? true: false;
}

string Queue::peek(){
	return front->data;
}

int Queue::getSize()
{
	return size;
}

/* Main function
----------------------------------------------------------------------*/
int main()
{
	Queue *queue = new Queue();
	string name;
	int option;
	
	do {
		cout<< "\tQueue OOP C++\n\n"<< endl;
		
		cout<< "\t..::Menu::..\n"<< endl;
		cout<< " [1] Add Name"<< endl;
		cout<< " [2] Show queue"<< endl;
		cout<< " [3] Remove Name"<< endl;
		cout<< " [4] Get Head"<< endl;
		cout<< " [5] Get Size"<< endl;
		cout<< " [6] Clear All"<< endl;
		cout<< " [7] Exit"<< endl;
		cout<< " \n Choose: ";
		cin>> option;
		
		switch(option) {
			case 1:
				cout<< "\n\n Type one name: ";
				cin>> name;
				
				cout<< "\n\n\t"<< queue->add(name)<< " Added\n"<<endl;
				break;
				
			case 2:
				if (!queue->isEmpty()) {
					cout<< "\n\n\tShowing queue...\n"<< endl;
					
					queue->show();	
					cout<< "\n"<< endl;
				} else {
					cout<< "\n\n\t**Empty**\n"<< endl;
				}
				break;
				
			case 3:
				if (!queue->isEmpty()) {
					cout<< "\n\n "<< queue->remove()<< " Removed"<< "\n"<< endl;	
				} else {
					cout<< "\n\n\t**Empty**\n"<< endl;
				}
				break;
				
			case 4:
				if (!queue->isEmpty()) {
					cout<< "\n\n Head Item: "<< queue->peek()<< "\n"<< endl;	
				} else {
					cout<< "\n\n\t**Empty**\n"<< endl;
				}
				break;
				
			case 5:
				if (!queue->isEmpty()) {
					cout<< "\n\n Size: "<< queue->getSize()<< "\n"<< endl;	
				} else {
					cout<< "\n\n\t**Empty**\n"<< endl;
				}
				break;
				
			case 6:
				if (!queue->isEmpty()) {
					cout<< "\n\n\tcleaning..."<< "\n"<< endl;
					
					queue->clear();	
				} else {
					cout<< "\n\n\t**Empty**\n"<< endl;
				}
				break;
				
			case 7:
				cout<< "\n\n\t**Big thanks for using this program**\n"<< endl;
				break;
				
			default:
				cout<< "\n\n\tWrong option... try again!\n"<< endl;
		}
		
		system("pause");
		system("cls");
	} while (option != 7);
	
	return 0;
}
