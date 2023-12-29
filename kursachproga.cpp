#include <iostream>
#include <vector>


class node {
public:
	int key;
	node* p; //указатель на пердыдущий элемент
	int getKey()
	{
		return key;
	}
};
class Stack : public node {
private:
	int max_lenght = 30;
	node* head; //указатель верхнего элемента
public:
	Stack()//Конструктор по умолчанию
	{
		head = NULL;
	}
	Stack(int length)
	{
		head = NULL;
		max_lenght = length;
	}
	void _max_lenght_(int length)
	{
		max_lenght = length;
	}
	~Stack() { //Деструктор, он же remove
		while (head != NULL) {
			node* temporal = head->p;
			delete head;
			head = temporal;
		}
	}
	auto stackToVector(std::vector<int> vct)
	{
		node* temporal = head;
		while (temporal != NULL) {
			vct.push_back(temporal->key);
			temporal = temporal->p;
		}
		return vct;
	}
	int lenght()
	{
		node* tempStart = head;
		int i = 0;
		while (head != NULL) {
			node* temporal = head->p;
			i += 1;
			head = temporal;
		}
		head = tempStart;
		return i;
	}
	void push(int data) { //Функция добавления элемента в стек
		if (lenght() + 1 <= max_lenght) {
			node* temoral = new node;// выделние динамической памяти под новый элемент
				temoral->key = data;
			temoral->p = head;
			head = temoral;
		}
		else std::cout << "Stack is over! Can`t input " << data << "\n";
	}
	void pop() { //Функция удаления элемента из вершины стека
		if (head == NULL) {
			std::cout << "Empty stack, deliting is imposible\n";
		}
		else {
			node* temporal = head;
			std::cout << "delited: " << temporal->key << std::endl;
			head = head->p;
			delete temporal;
		}
	}
	int sum() { //Функция поиска суммы элементов стека
		node* temporal = head;
		int sum = 0;
		while (temporal != NULL) {
			sum += temporal->key;
			temporal = temporal->p;
		}
		return sum;
	}
	void print() { //Функция вывода списка на экран
		bool flag = false;
		node* temporal = head;
		std::cout << "Now the stack is:\n";
		while (temporal != NULL) {
			std::cout << temporal->key << " ";
			temporal = temporal->p;
			flag = true;
		}
		if (!flag) {
			std::cout << "The stack is empty!\n";
		}
		std::cout << "\n";
	}
	void remove()
	{
		while (head != NULL) {
			node* temporal = head->p;
			delete head;
			head = temporal;
		}
	}
};
void menu(Stack st)
{
		std::cout << "Input your move number: \n 1.Print\n 2.Push\n 3.Pop\n 4.Remove\n5.Sum\n 6.Length\n 7.Copy to vector\n 8.Max length push\n 9.Endprogram";
		std::vector<int> vct;
	int number;
	std::cin >> number;
	switch (number)
	{
	case 1:
		st.print();
		break;
	case 2:
		int input;
		std::cout << "Input pushing number.\n";
		std::cin >> input;
		st.push(input);
		menu(st);
		break;
	case 3:
		st.pop();
		menu(st);
		break;
	case 4:
		st.remove();
		menu(st);
		break;
	case 5:
		st.sum();
		menu(st);
		break;
	case 6:
		st.lenght();
		menu(st);
		break;
	case 7:
		st.stackToVector(vct);
		menu(st);
		break;
	case 8:
		std::cout << "input max stack length:\n";
		int length;
		std::cin >> length;
		st._max_lenght_(length);
		menu(st);
		break;
	case 9:
		break;
	default:
		std::cout << "incorrect input. Try again";
		menu(st);
		break;
	}
}
int main() {
	Stack st;
	st._max_lenght_(4);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.print();
	st.pop();
	st.pop();
	st.print();
	std::cout << "Found sum of stack elements: " << st.sum() << "\n";

	menu(st);
	return 0;
}
