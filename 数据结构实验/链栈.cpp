#include<iostream>

using namespace std;

template<class T>
struct Node
{
	T data;
	struct Node<T>* next;
};//定义节点

template<class T>
class LinkStack
{
private:
	struct Node<T> * top; //栈顶指针
public:
	LinkStack() { top = NULL; } //构造函数，初始化空栈
	~LinkStack(); //声明析构函数
	void Push(T x);
	T Pop(); //出栈操作
	T GetTop()
	{
		return top->data;
	}//获取栈顶元素
	bool Empty()
	{
		return (NULL == top) ? true : false;
	} //判断栈是否为空栈

};

template<class T>
LinkStack<T>::~LinkStack() //实现析构函数
{
	while (top)
	{
		Node<T> * p = top;
		top = top->next;
		delete p;
	}
}

template<class T>
void LinkStack<T>::Push(T x) //实现入栈操作
{
	Node<T> * p = new Node<T>;
	p->data = x;
	p->next = top;
	top = p;
}

template<class T>
T LinkStack<T>::Pop() //实现出栈操作
{
	if (Empty())
		throw"下溢";
	T x = top->data;
	Node<T> *p = top;
	top = top->next;
	delete p;
	return x;
}


int main()
{
	LinkStack<int> Mine;
	for (int i = 0; i < 10; i++)
	{
		Mine.Push(i + 1);
		cout << Mine.GetTop()<<" ";
	}//检验入栈操作
	cout << endl;
	for (int i; i < 10; i++)
	{
		cout << Mine.Pop()<< " ";
	}//检验出栈操作
	cout << endl;
	if (Mine.Empty())
		cout << "栈空";//检验判断函数
	try
	{
		Mine.Pop();
	}
	catch (const char * msg)
	{
		cerr << msg << endl;
	} //检验异常处理机制

	system("pause");
	return 0;
}