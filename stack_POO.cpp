/*By Eric Alonso 08/01/2021 -STACK OOP-*/

#include <iostream>
#include <cstdlib>

using namespace std;

/* Node structure
----------------------------------------------------------------------*/
struct Node
{
	string data;
	Node *next;
};

class Stack
{
	
	private:
		int top;
		Node *stack;
		
		Node *createNode(string name);
	public:
		Stack();
		void push(string name);
		string pop();
		void clear();
		bool contains(string name);
		bool isEmpty();
		void show();
		int size();
		string peek();
};

/* Class methods
----------------------------------------------------------------------*/
Stack::Stack()
{
	stack = NULL;
	top = -1;						//empty stack
}

Node *Stack::createNode(string name)
{
	Node *newNode = new Node();
	
	newNode->data = name;
	newNode->next = NULL;
	
	return newNode;
}

void Stack::push(string name)
{
	Node *newNode = createNode(name);
	
	newNode->next = stack;			// node: 4 -> stack: 3->2->1  merge newNode & stack
	stack = newNode;				// stack: 4->3->2->1
	
	top++;
}

string Stack::pop()
{
	string data_aux;
	Node *stack_aux = stack;		// get the whole stack
		
	data_aux = stack_aux->data;		// get current data from the first node
	stack = stack_aux->next;		// overwrite stack with the second node
	top--;
		
	delete(stack_aux);				// delete old stack
		
	return data_aux;
}

void Stack::clear()
{
	Node *node_aux;
	while (stack != NULL) {	
		node_aux = stack;					// get node to delete
						
		cout<< " "<< stack->data<< " - ";
			
		stack = stack->next;				// overwrite main stack with next node
		top--;
		
		delete node_aux;
	}
	
	cout<< "\n"<< endl;
}

bool Stack::contains(string name)
{
	Node *stack_aux;
	
	stack_aux = stack;
		
	while (stack_aux != NULL && stack_aux->data != name) { 	// keep searching until stack_aux->data == data;
		stack_aux = stack_aux->next; 
	}
		
	if (stack_aux == NULL) {								// overflow stack
		return false;
	} else {
		return true;
	}
}

bool Stack::isEmpty()
{
	if (top == -1) {
		cout<< "\n\n\t**Empty**\n"<< endl;
		return true;
	} else {
		return false;	
	}
}

void Stack::show()
{
	Node *stack_aux;
	
	stack_aux = stack;
		
	while (stack_aux != NULL) {				// iterating the whole stack to the end
		cout<< " |- \t\t"<< stack_aux->data<< "\t\t -|"<< endl;
			
		stack_aux = stack_aux->next; 		// continue to next node
	}	
}

int Stack::size()
{
	return top;
}

string Stack::peek()
{
	return stack->data;
}

/* Main function
----------------------------------------------------------------------*/
int main ()
{
	Stack *stack = new Stack();
	int option;
	string name;
	
	do {
		cout<< "\tStack OOP C++\n\n"<< endl;
		
		cout<< "\t..::Menu::..\n"<< endl;
		cout<< " [1] Add Name"<< endl;
		cout<< " [2] Show Stack"<< endl;
		cout<< " [3] Remove Name"<< endl;
		cout<< " [4] Contains"<< endl;
		cout<< " [5] Get Size"<< endl;
		cout<< " [6] Get Last Item"<< endl;
		cout<< " [7] Clear All"<< endl;
		cout<< " [8] Exit"<< endl;
		cout<< " \n Choose: ";
		cin>> option;
		
		switch(option) {
			case 1:
				cout<< "\n\n Type one name: ";
				cin>> name;
				
				stack->push(name);
				cout<< "\n"<< endl;
				break;
				
			case 2:
				if (!stack->isEmpty()) {
					cout<< "\n\n\tShowing stack...\n"<< endl;
					
					stack->show();	
				}
				
				cout<< "\n"<< endl;
				break;
				
			case 3:
				if (!stack->isEmpty()) {
					cout<< "\n\n "<< stack->pop()<< " Removed"<< "\n"<< endl;	
				}
				break;
				
			case 4:
				if (!stack->isEmpty()) {
					cout<< "\n\n Type one name: ";
					cin>> name;
				
					if (stack->contains(name)) {
						cout<< "\n\n "<< name << " found"<< "\n"<<endl;
					} else {
						cout<< "\n\n "<< name << " not found"<< "\n"<<endl;
					}	
				}
				break;
				
			case 5:
				if (!stack->isEmpty()) {
					cout<< "\n\n Size: "<< stack->size()<< "\n"<< endl;	
				}
				break;
				
			case 6:
				if (!stack->isEmpty()) {
					cout<< "\n\n Last Item: "<< stack->peek()<< "\n"<< endl;	
				}
				break;
				
			case 7:				
				if (!stack->isEmpty()) {
					cout<< "\n\n\tcleaning..."<< "\n"<< endl;
					
					stack->clear();	
				}
				break;
				
			case 8:
				cout<< "\n\n\t**Big thanks for using this program**\n"<< endl;
				break;
				
			default:
				cout<< "\n\n\tWrong option... try again\n"<< endl;
				
		}
		
		system("pause");
		system("cls");
	} while (option != 8);
	
	return 0;
}
