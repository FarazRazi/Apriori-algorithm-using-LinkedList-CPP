////////
// Name: Faraz Razi
// Roll# i201866	
// Section F
// DS Assignment# ( 1 )
// 
// //////////////////////Steps For assignment///////////////
//  
// Create linklist class (DONE)
// 
// class transactionLL (DONE)
// 
// read txt files , store in linklist (DONE)
// void readInputFile (char* inputFilePath) 
// 
// punctuation	(DONE)
// void removePunctuationMarks 
// 
// UpperToLower	(DONE)
// void convertUpperToLowerCase ()
// 
// write txt file	(DONE)
// void writingTransactionLLToFile (char* outputFilePath)
// 
// Generate Item Sets (DONE)
// 1st	(DONE)
// void generateFirstItemSet(char* LL_frequency)
// 2nd	(DONE)
// void generateSecondItemSet(char* frequency_outputfile)
// 3rd	(DONE)
// void generateThirdItemSet(char* frequency_outputfile)
// 
//////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#pragma once

using namespace std;
double STHold; //Support threshold
int numofTransc; 

/// <summary>
/// //////	Classes: 
/// Node - class for TransctionLL linkedlist nodes having data and next node pointer and operations
/// TransctionLL - class for each transction having nodes (Node) and next TransctionLL pointer and operation
/// LinkedList - class for main list containg head of first TransctionLL and operations	
/// Frequency - class for seperate list of items frequency (Node_F) , generated and operated using data from main LinkedList
/// NodeF - class for Frequency linkedlist nodes having Name and next Node_F pointer
/// </summary>

/// Node - class for TransctionLL linkedlist nodes having data and next node pointer and operations
class Node
{
public:
	char* data;
	Node* next;
	Node()
	{
		char* data = new char;
	}
	void setchar(char* main)
	{
		int size = 0;
		while (main[size] != '\0')
		{
			size++;
		}
		char* data = new char[size + 1];
		int i;
		for (i = 0; i < size; i++)
		{
			data[i] = main[i];
		}
		data[i] = '\0';
		this->data = data;
	}
	int getsize()
	{
		int size = 0;
		while (data[size] != '\0')
		{
			size++;
		}
		size++;
		return size;
	}
	void removechar(int index)
	{
		
		for (int i = index ; i < getsize() - 1; ++i)
			data[i] = data[i + 1];
	}
	bool comaparechar(char* arr)
	{
		int i;
		for (int i = 0; i < getsize(); i++)
		{
			if (data[i] != arr[i])
			{
				return false;
			}
		}
		return true;
	}
};
/// NodeF - class for Frequency linkedlist nodes having Name and next Node_F pointer
class Node_F
{
public:
	char* Name;
	int Frequency=0;
	Node_F* next;
	void setchar(char* main)
	{
		int size = 0;
		while (main[size] != '\0')
		{
			size++;
		}
		char* data = new char[size + 1];
		int i;
		for (i = 0; i < size; i++)
		{
			data[i] = main[i];
		}
		data[i] = '\0';
		this->Name = data;
	}
	int getsize()
	{
		int size = 0;
		while (Name[size] != '\0')
		{
			size++;
		}
		size++;
		return size;
	}
	void removechar(int index)
	{

		for (int i = index; i < getsize() - 1; ++i)
			Name[i] = Name[i + 1];
	}
	bool comaparechar(char* arr)
	{
		int i;
		for (int i = 0; i < getsize(); i++)
		{
			if (Name[i] != arr[i])
			{
				return false;
			}
		}
		return true;
	}
};
/// TransctionLL - class for each transction having nodes (Node) and next TransctionLL pointer and operation
class TransctionLL
{
public:
	TransctionLL()
	{
		head = NULL;
	}
	TransctionLL(Node* head)
	{
		this->head = head;
	}
	~TransctionLL()
	{
		Node* curr = head;
		Node* next = NULL;
		while (curr != NULL)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void print()
	{
		int i=0;
		Node* current = head;
		while (current != NULL)
		{
			i = 0;
			while (current->data[i]!='\0')
			{
				cout<<current->data[i];
				i++;
			}
			cout << " ";
			current = current->next;
		}
		cout << endl;
	}

	void insert(char* Value)
	{
		Node* newNode = new Node();
		
		newNode->setchar(Value);

		newNode->next = NULL;

		if (isEmpty())
			head = newNode;
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
		//delete[] arr;
	}
	void Punctuate()
	{
		Node* remove = head;


		while (remove)
		{
			remove->data;
			for (int i = 0; i < remove->getsize(); i++)
			{
				if ((remove->data[i] >= 0 && remove->data[i] < 'A'||remove->data[i]>'z'))
				{
					remove->removechar(i);
				}
			}

			remove = remove->next;
		}
	}
	void UptoLow()
	{
		Node* remove = head;
		while (remove)
		{
			remove->data;
			for (int i = 0; i < remove->getsize(); i++)
			{
				if ((remove->data[i] >= 'A' && remove->data[i] <= 'Z'))
				{
					remove->data[i] = remove->data[i] + 32;
				}
			}
			remove = remove->next;
		}
	}
	void remove()
	{
		Node* current = head;
		Node* next;
		while (current != NULL) {
			next = current->next;
			free(current);
			current = next;
		}
		head = NULL;
	}
	
public:
	Node* head;
	TransctionLL* next_T;
};
/// LinkedList - class for main list containg head of first TransctionLL and operations	
class LinkedList
{
public:
	LinkedList()
	{
		Transc = NULL;
		
	}
	LinkedList(TransctionLL* Transc)
	{
		this->Transc = Transc;
	}
	TransctionLL* insert_list()
	{
		TransctionLL* newNode = new TransctionLL();

		newNode->next_T = NULL;
		Lists++;

		if (!Transc)
			Transc = newNode;
		else
		{
			TransctionLL* temp = Transc;
			while (temp->next_T != NULL)
			{
				temp = temp->next_T;
			}
			temp->next_T = newNode;
		}
		return newNode;
	}
	bool isEmpty()
	{
		return Transc == NULL;
	}
	void print_list()
	{
		
		TransctionLL* current = Transc;
		while (current != NULL)
		{
			
			current->print();
			cout << endl;
			current = current->next_T;
		}
	}
	TransctionLL* getTransc()
	{
		return Transc;
	}
	void Punctuate_List()
	{
		TransctionLL* current = Transc;
		while (current!=NULL)
		{
			current->Punctuate();
			current = current->next_T;
		}
	}
	void UptoLow_list()
	{
		TransctionLL* current = Transc;
		while (current != NULL)
		{
			current->UptoLow();
			current = current->next_T;
		}
	}
	friend std::ostream& operator<<(std::ostream& out,const LinkedList& list)
	{
		TransctionLL* current = list.Transc;
		while (current != NULL)
		{
			for (auto node = current->head; node; node = node->next)
			{
				out << node->data;
				if (node->next)
				{
					out << ',';
				}
			}
			if(current->next_T)
				out << '\n';
			current = current->next_T;
		}
		return out;
	}
	void remove_list()
	{
		TransctionLL* current = Transc;
		while (current)
		{
			current->remove();
			current = current->next_T;
			Lists--;
		}
		Transc = current;
	}
	void remove_List(TransctionLL* toRemove)
	{
		TransctionLL* current = Transc;
		TransctionLL* next;
		while (current != NULL) {
			if (current == toRemove)
			{
				next = current->next_T;
				current->remove();
				current = next;
			}
			else
			{
				current = current->next_T;
			}
		}

		//Transc = current;
	}
	
	TransctionLL* Transc;
	static int Lists;
};
/// Frequency - class for seperate list of items frequency (Node_F) , generated and operated using data from main LinkedList
//Function to get char* from string
char* getchar(string s);
class Frequency
{
public:
	Frequency() {
		head = NULL;
	}
	//function traversing through Linked list L1
	Node_F* insert_L1(LinkedList& L1)
	{
		TransctionLL* current = L1.Transc;
		while (current != NULL)
		{
			insert_L2(L1, current);
			current = current->next_T;
		}
		return head;
	}
	//function to traverse through each TransctionLL
	void insert_L2(LinkedList& L1, TransctionLL* T1)
	{
		Node* current = T1->head;
		if (!head)//adding one first new Freq item
		{
			insert_new(current->data);
			current = current->next;
		}
		while (current != NULL)
			//adding or updating frequency item according to searching
		{
			if (search(L1, T1, current->data))
				insert_old(current->data);
			else
				insert_new(current->data);
			current = current->next;
		}
	}
	//Function to Match the item node with the 
	bool search(LinkedList& L1, TransctionLL* T1, char* str)
	{
		TransctionLL* current_T = L1.Transc;
		while (current_T != NULL)
		{
			Node* current = current_T->head;
			while (current != NULL)
			{
				if (current->comaparechar(str))
					return true;
				current = current->next;
			}
			current_T = current_T->next_T;
		}
		return false;
	}
	//Update the Frequency of an already present Freqency item
	void insert_old(char* Value)
	{
		bool flag = true;
		Node_F* current = head;
		while (current != NULL) {

			if (current->comaparechar(Value))
			{
				current->Frequency++;
				flag = false;
			}
			current = current->next;
		}
		if (flag)
		{
			insert_new(Value);
		}
	}
	//add a new Frequency item in Linked List
	void insert_new(char* Value) {

		Node_F* newNode = new Node_F();
		
		newNode->setchar(Value);
		newNode->Frequency++;


		if (isEmpty())
			head = newNode;
		else
		{
			Node_F* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void insertAtHead(char* Value)
	{
		Node_F* newNode = new Node_F();

		newNode->setchar(Value) ;
		newNode->next = head;
		head = newNode;
	}
	void remove()
	{
		Node_F* current = head;
		Node_F* next;
		while (current != NULL) {
			next = current->next;
			free(current);
			current = next;
		}
		head = NULL;
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void print()
	{
		int i = 0;
		Node_F* current = head;
		while (current != NULL)
		{
			i = 0;
			while (current->Name[i] != '\0')
			{
				cout << current->Name[i];
				i++;
			}
			cout << " ";
			cout << current->Frequency;
			cout << endl;
			current = current->next;
		}
		cout << endl;
	}
	void SetSupport()
	{

		Node_F* current = head;
		Node_F* prevoius = NULL;

		while (current)
		{
			if (current->Frequency < STHold * numofTransc)
			{
				
				if (current == head)
				{
					Node_F* temp=current->next;
					remove_Node(current);
					current = temp;
				}
				else
				{
					remove_Node(current, prevoius);
					current = prevoius->next;
				}
				/*remove_Node(current, prevoius);
				
				current = prevoius->next;*/
			}
			else
			{
				prevoius = current;
				if (current)
					current = current->next;
			}
		}
	}
	void remove_Node(Node_F* current)
	{
		head = current->next; // Changed head
		delete current;            // free old head
	}
	void remove_Node(Node_F* current, Node_F* prevoius)
	{
		if (current)
		{
			if (prevoius) {
				prevoius->next = current->next;
				delete current;
			}
			else {
				head = current->next;
				prevoius->next = head;
				delete current;
			}
		}
	}
	void remove_last()
	{
		Node_F* previous = NULL;
		Node_F* current = head;

		if (current == NULL)
			return;
		if (current->next == NULL)
		{		
			delete current;
			return;
		}
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		delete current->next;
		current->next = NULL;


	}
	void bubbleSort()
	{
		int swapped, i;
		Node_F* current;
		Node_F* end = NULL;
		/* Checking for empty list */
		if (head == NULL)
			return;

		do
		{
			swapped = 0;
			current = head;

			while (current->next != end)
			{
				if (current->Frequency < current->next->Frequency  )
				{
					swap(current, current->next);
					swapped = 1;
				}
				else if (current->Frequency == current->next->Frequency)
				{
					if (current->Name[0]>current->next->Name[0])
					{
						swap(current, current->next);
					}	
				}
				current = current->next;
			}
			end = current;
		} while (swapped);
	}
	void swap(Node_F* a, Node_F* b)
	{
		int temp = a->Frequency;
		a->Frequency = b->Frequency;
		b->Frequency = temp;

		char* temp_2 = a->Name;
		a->Name = b->Name;
		b->Name = temp_2;
		//b->Name.replace(0, sizeof(temp_2), temp_2);
	}
	void _2ndList()
	{

		Node_F* current = new Node_F();
		current = head;
		//Formula for number of possible unique pairs
		//n*(n - 1) / 2;
		int i = 0;
		string str;
		string temp_str;
		Node_F* temp;
		Node_F* memory_node = head;
			while (current)
			{
				temp = current->next;
				temp_str = current->Name;
				while (temp)
				{
					i++;
					str = temp_str + ',' + temp->Name;
					insertAtHead(getchar(str));
					str = "\0";
					temp = temp->next;
				}
				memory_node = memory_node->next;
				current = memory_node;
			}
			//cout << i << endl;
		
			for (int i = 0; i < 4; i++)
			{
				remove_last();
			}
		
	}
	void _3rdList()
	{
		Node_F* current = new Node_F();
		current = head;
		int count = 0;
		while (current)
		{
			count++;
			current = current->next;
		}
		current = head;
		//Formula for number of possible unique pairs
		//n*(n - 1) / 2;
		int i = 0;
		string str;
		string temp_str;
		Node_F* temp;
		Node_F* temp2;
		Node_F* memory_node = head;
		while (current)
		{
			temp = current->next;
			temp_str = current->Name;
			while (temp)
			{
				
				temp2 = temp->next;
				while (temp2)
				{
					i++;
					str = temp_str + ',' + getHalfstring(temp->Name);
					insertAtHead(getchar(str));
					str = "\0";
					temp2 = temp2->next;
					break;
				}
				
				temp = temp->next;
				break;
			}
			break;
			memory_node = memory_node->next;
			current = memory_node;
		}
		cout << i << endl;

		for (int i = 0; i < count; i++)
		{
			remove_last();
		}
	}
	string getHalfstring(string str)
	{
		int i = 0;
		string cpy;
		while (str[i]!=',')
			i++;
		i++;
		while (str[i] != '\0')
			cpy += str[i++];
		return cpy;
	}


	Node_F* head;
};
/////////////////////////////Function Prototypes///////////////////////////////
// 
//Global Function to read Input File and create or replace LinkedList of TransctionLL 
void readInputFile(char* inputFilePath);
//Global Function to remove Punctuation from linkedlist data 
void removePunctuationMarks();
//Global Function to convert Upper case letters to Lower case of linked list data
void convertUpperToLowerCase();
//Global Function to write LinkedList to .txt file
void writingTransactionLLToFile(char* outputFilePath);
//Function used while updating List(Nodes) to remove reauired nodes
void remove_Node(TransctionLL* L1, Node* current, Node* prevoius);
//Global Function to get size of char array
int getsize(char* data);
//Function to search for substring
bool search(char* main, char* sub);
//Function to check for duplication of 
void UpdateNodes(TransctionLL* T1, Frequency F1);
//Global Function to traverse through LinkedList while updating using freq
void UpdateList(LinkedList& L1, Frequency& F1);
//Global function to create 2nd Frequency values
void _2ndFreq_1(LinkedList& L1, Frequency& F1);
//Global function to set 3rd Frequency values
void _3rdFreq_1(LinkedList& L1, Frequency& F1);
//Function to generate first item list
void generateFirstItemSet(char* LL_frequency);
//Function to generate 2nd item list
void generateSecondItemSet(char* LL_frequency);
//Function to generate 3rd item list
void generateThirdItemSet(char* LL_frequency);
/////////////////////////////////////////////////////////////////////////////
//counter for # of lists
int LinkedList::Lists = 0;
//Global Objests for LinkedList Classes
//LinkedList main class linked list
LinkedList L1;
//Frequency class linked list
Frequency F1;


//Global Function to read Input File and create or replace LinkedList of TransctionLL 
void readInputFile(char* inputFilePath)
{
	double a;
	int b;
	char c;
	char arr[6]={0};
	string str;
	ifstream InputFile;
	InputFile.open(inputFilePath);
	if (!InputFile)
	{
		cout << "File Not Opened" << endl;
		exit(0);
	}
	else
	{
		int j = 0;
		InputFile >> a;
		InputFile >> b;
		//Member Function to first remove all the lists and nodes in Linked List
		L1.remove_list();
		TransctionLL* current = L1.Transc;
		//loop running for b times according to number of Transctions
		for (int i = -1; i < b; i++) 
		{
			//running loop one time more to skip newline //to read properly
			if (i != -1)
				//Function to return new TransctinLL address to current
				current = L1.insert_list();
			do
			{
				
				j = 0;
				//Loop till ',' and newline and eof //to read item
				while (InputFile.peek()!=',' && InputFile.peek() != '\n' && !InputFile.eof())
				{
					InputFile >> c;
					str += c;
					
				}
				if (i != -1)
				{ //inserting data in current TransctionLL
					
					current->insert(getchar(str));
				}
					str = "\0";
				//Loop till not eof or newline  //to read whole transctionLL
			} while (InputFile.get() != '\n' && !InputFile.eof());		
		}
	}
	InputFile.close();

	STHold = a;
	numofTransc = b;
}
//Function to get char* from string
char* getchar(string s) {
	const int size = s.length();
	char* arr = new char[size + 1];
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = s[i];
	}
	arr[i] = '\0';
	return arr;
}
//Global Function to remove Punctuation from linkedlist data 
void removePunctuationMarks()
{
	//Member Function of LinkedList
	L1.Punctuate_List();
	//L1.print_list();
}
//Global Function to convert Upper case letters to Lower case of linked list data
void convertUpperToLowerCase()
{
	//Member Function of LinkedList
	L1.UptoLow_list();
	//L1.print_list();
}
//Global Function to write LinkedList to .txt file
void writingTransactionLLToFile(char* outputFilePath)
{
	ofstream OutFile;
	OutFile.open(outputFilePath);
	if (!OutFile)
	{
		cout << "File Not Opened" << endl;
		exit(0);
	}
	else
	{
		//Overloaded << operator to write L1 linked list in OutFile
		OutFile << L1;
	}
}
//Function used while updating List(Nodes) to remove reauired nodes
void remove_Node(TransctionLL* L1, Node* current, Node* prevoius)
{
	if (current)
	{
		if (prevoius) {//if node is other then head
			prevoius->next = current->next;
			delete current;
		}
		else {//if node is head
			prevoius = current;
			L1->head = current->next;
			//prevoius = NULL;
			delete current;
		}

	}
}
//Function used while updating List(Nodes) to remove reauired nodes
void remove_Node(LinkedList& T1,TransctionLL* L1, Node* current)
{
		//L1->head = current->next;
		T1.remove_List(L1);
		//delete current;
}
//Global Function to get size of char array
int getsize(char* data)
{
	int size = 0;
	while (data[size] != '\0')
	{
		size++;
	}
	size++;
	return size;
}
//Function to search for substring
bool search(char* main, char* sub)
{
	int size_main = getsize(main)-1;
	int size_sub = getsize(sub)-1;
	int i = 0;
	int j = 0;

	while (i < size_main && j < size_sub) {
			if (main[i] == sub[j]) {
			i++;
			j++;
			if (j == size_sub)
				return true;
		}
		else 
		{
			i = i - j + 1;
			j = 0;
		}
	}

	return false;
}
//Function to check for duplication of 
void UpdateNodes(LinkedList L1,TransctionLL* T1, Frequency F1)
{
	Node* currN = T1->head;
	Node* prevoius ;
	Node_F* curr_FN;
	bool flag;
	int count ;
	while (currN)//Loop for each Linked list item
	{
		count = 0;
		flag = 1;
		curr_FN = F1.head;
		while (curr_FN)//loop for each Freq item
		{
			if (search(curr_FN->Name,currN->data))
				//if currN mathches with any Freq List member the item is not removed
				//Else it is removed
			{
				flag = 0;
			}
			curr_FN = curr_FN->next;
		}
		if (flag)
		{
			if (currN==T1->head)
			{
				remove_Node(L1,T1, currN);
				currN = NULL;
			}
			else
			{
				remove_Node(T1, currN, prevoius);
				currN = prevoius->next;
			}
		}
		prevoius = currN;
		if (currN)
			currN = currN->next;
	}
}
//Global Function to traverse through LinkedList while updating using freq
void UpdateList(LinkedList& L1, Frequency& F1)
{
	TransctionLL* current = L1.Transc;
	while (current)
	{
		UpdateNodes(L1,current, F1);
		current = current->next_T;
	}
}
//Global function to create 2nd Frequency values
void _2ndFreq_1(LinkedList& L1,Frequency& F1)
{
	TransctionLL* current = L1.Transc;
	bool flag;
	int count;
	while (current)
	{
		Node* currN ;
		Node* prevoius = NULL;
		Node_F* curr_FN=F1.head;
		bool flag1;
		bool flag2;
		int count;
		while (curr_FN)//Loop for each Frequency list item
		{
			count = 0;
			currN = current->head;
			while (currN)
			{
				if (search(curr_FN->Name, currN->data))
				{
					count++;
				}
				currN = currN->next;
			}
			if (count == 2)
			{
				curr_FN->Frequency++;
			}
			curr_FN = curr_FN->next;
		}

		current = current->next_T;
	}
}
//Global function to set 3rd Frequency values
void _3rdFreq_1(LinkedList& L1, Frequency& F1)
{
	TransctionLL* current = L1.Transc;
	bool flag;
	int count;
	while (current)
	{
		Node* currN;
		Node* prevoius = NULL;
		Node_F* curr_FN = F1.head;
		bool flag1;
		bool flag2;
		int count;
		while (curr_FN)//Loop for each Frequency list item
		{
			count = 0;
			currN = current->head;
			while (currN)
			{
				if (search(curr_FN->Name, currN->data))
				{
					count++;
				}
				currN = currN->next;
			}
			if (count == 3)
			{
				curr_FN->Frequency++;
			}
			curr_FN = curr_FN->next;
		}

		current = current->next_T;
	}
}
//Function to generate first item list
void generateFirstItemSet(char* LL_frequency)
{
	F1.remove();
	//make frequency list according to data in LinkedList L1
	F1.insert_L1(L1);
	//F1.print();
	//Sorting the freq list
	F1.bubbleSort();
	//F1.print();
	//removing item that has less than STHold (<3)
	F1.SetSupport();
	//F1.print();
	//Updating the LinkedList L1 according to the updated Freq List
	UpdateList(L1,F1);
	//L1.print_list();
	
	ofstream OutFile;
	OutFile.open(LL_frequency);
	if (!OutFile)
	{
		cout << "File Not Opened" << endl;
		exit(0);
	}
	else
	{
		int i = 0;
		Node_F* current = F1.head;
		while (current != NULL)
		{
			i = 0;
			while (current->Name[i] != '\0')
			{
				OutFile << current->Name[i];
				i++;
			}
			OutFile << '(';
			OutFile <<current->Frequency;
			OutFile << ')';
			if (current->next)
				OutFile << '\n';
			current = current->next;
		}
		
	}
	OutFile.close();
}
//Function to generate 2nd item list
void generateSecondItemSet(char* LL_frequency)
{
	
	//make 2nd frequency list 
	F1._2ndList();
	//Set Frequency for 2nd list
	_2ndFreq_1(L1,F1);
	//F1.print();
	//Sorting the freq list
	F1.bubbleSort();
	//F1.print();
	//removing item that has less than STHold (<3)
	F1.SetSupport();
	//F1.print();
	//Updating the LinkedList L1 according to the updated Freq List
	UpdateList(L1, F1);
	//L1.print_list();


	ofstream OutFile;
	OutFile.open(LL_frequency);
	if (!OutFile)
	{
		cout << "File Not Opened" << endl;
		exit(0);
	}
	else
	{
		int i = 0;
		Node_F* current = F1.head;
		while (current != NULL)
		{
			i = 0;
			while (current->Name[i] != '\0')
			{
				OutFile << current->Name[i];
				i++;
			}
			OutFile << '(';
			OutFile << current->Frequency;
			OutFile << ')';
			if (current->next)
				OutFile << '\n';
			current = current->next;
		}
	}
	OutFile.close();
}
//Function to generate 3rd item list
void generateThirdItemSet(char* LL_frequency)
{
	//make 2nd frequency list 
	F1._3rdList();
	//F1.print();
	//Set Frequency for 2nd list
	_3rdFreq_1(L1, F1);
	//F1.print();
	//Sorting the freq list
	F1.bubbleSort();
	//F1.print();
	//removing item that has less than STHold (<3)
	F1.SetSupport();
	//F1.print();
	//Updating the LinkedList L1 according to the updated Freq List
	UpdateList(L1, F1);
	//L1.print_list();


	ofstream OutFile;
	OutFile.open(LL_frequency);
	if (!OutFile)
	{
		cout << "File Not Opened" << endl;
		exit(0);
	}
	else
	{
		int i = 0;
		Node_F* current = F1.head;
		while (current != NULL)
		{
			i = 0;
			while (current->Name[i] != '\0')
			{
				OutFile << current->Name[i];
				i++;
			}
			OutFile << '(';
			OutFile << current->Frequency;
			OutFile << ')';
			if (current->next)
				OutFile << '\n';
			current = current->next;
		}
	}
	OutFile.close();
}
