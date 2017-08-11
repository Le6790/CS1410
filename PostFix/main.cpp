#include<iostream>
#include<stack>
#include <string>
#include <vector>
using namespace std;

template<class T> class Node {
public:
	T data;
	Node *next;

	Node(T item, Node *next = NULL) {
		this->data = item;
		this->next = next;
	}
};

template<class T> class Stack {
private:
	Node<T> *top;

public:
	Stack() {
		top = NULL;
	}

	void push(T item) {
		Node<T> *temp = new Node<T>(item, top);
		top = temp;
	}

	T pop() {
		if (isEmpty())
			throw "Cannot pop from an empty stack!";
		Node<T> *temp = top;
		top = temp->next;
		return temp->data;
	}

	bool isEmpty() {
		return (top == NULL);
	}
};



char booleval(string str) {
	stack<char> st;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'T' || str[i] == 'F')     // str[i] is an operand
			st.push(str[i]);
		else {                                  // str[i] is an operator
			char x, y;
			switch (str[i]) {
			case '+':
				y = st.top();
				st.pop();
				x = st.top();
				st.pop();
				if (x == 'F' && y == 'F') {
					st.push('F');
				}
				else {
					st.push('T');
				}
				break;

			case '!':
				x = st.top();
				st.pop();
				if (x == 'F') {
					st.push('T');
				}
				else {
					st.push('F');
				}

				break;
			case '*':
				y = st.top();
				st.pop();
				x = st.top();
				st.pop();
				if (x == 'T' && y == 'T'|| x == 'F' && y == 'F') {
				st.push('T');
			}
				else {
					st.push('F');
				}
					break;
			
			}
		}
	}
	return st.top();
}


int main() {
	std::cout << "example/test:" << endl;
	std::cout << "T!F+ is: " << booleval("T!F+") << endl;
	std::cout << "TF+ is: " << booleval("TF+") << endl;
	std::cout << "T is: " << booleval("T") << endl;
	std::cout << "TT* is: " << booleval("TT*") << endl;
	std::cout << "TTFTFFTFTT!!+*+**+++*F+ is: " << booleval("TTFTFFTFTT!!+*+**+++*F+") << endl;
	std::cout << "******************************************" << endl;
	std::cout << "Enter in your own postfix logic statement: " << endl;
	string str;
	 vector<string> requests;
	
		 while (str[0] != 'Q') {
			 getline(cin, str);
			 for (int i = 0; i < str.size(); ++i) {
				 str[i] = toupper(str[i]);
				 if (str[i] != 'Q' && str[i] != 'T' && str[i] != 'F' && str[i] != '*' && str[i] != '+' && str[i] != '!') {
					 cout << "operand not recognized. Printing the logic stack and exiting" << endl;
					 str[i] = 'Q';

				 }
			 }
			 
			 if (str[0] != 'Q') {
				 requests.push_back(str);
			 }
		 }
		 cout << endl;
		 for (int i = 0; i < requests.size(); i++) {
			 std::cout << booleval(requests[i]) << endl;
		 }
		 cout << 'q' << endl;
	 
	
	 return 0;
}