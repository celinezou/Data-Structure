#include <iostream>
#include <string>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
//---------------------------------------stack
namespace defined_by_me {
	template<class T>
	class stack {
	private:

		int msize;
		int top;
		T *st;
	public:
		stack(int size) {
			msize = size;
			top = -1;
			st = new T[msize];
		}
		stack() {
			msize = 50;
			top = -1;
			st = new T[msize];
		}

		~stack() {
			delete[]st;
		}

		void clear() {
			top = -1;
		}
		bool push(const T item);
		bool pop(T &item);
		int size() { return top + 1; };
		bool isempty() {
			if (top == -1)
				return true;
			else
				return false;
		};
		T topprint() { return st[top]; };
	};

	template<class T>
	bool stack<T>::push(const T item) {
		if (top == msize - 1) {
			cout << "stack is full" << endl;
			return false;
		}
		st[++top] = item;
		return true;
	}
	template<class T>
	bool stack<T>::pop(T &item) {
		if (top == -1) {
			cout << "stack is empty" << endl;
			return false;
		}
		item = st[top--];
		return true;
	}
}

 

