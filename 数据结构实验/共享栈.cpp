#include<iostream>

using namespace std;

const int Maxsize = 100;//定义共享栈上限。

template<class T>
class sharedstack //定义共享栈模板。
{
private:
	int top1, top2;
	T data[Maxsize];
public:
	sharedstack() //无参构造函数声明。
	{
		top1 = -1;
		top2 = Maxsize;
	}
	sharedstack(T a[], int n, T b[], int m); //构造函数声明。
	void Push(int i, T x); //在栈顶推入元素
	T Pop(int i); //声明出栈操作
	T GetTop(int i); //访问栈顶元素
	bool Empty(int i); //判断共享栈是否为空
	void Clear(int i); //清空栈内元素
	void Print(int i); //打印某栈为空
};

template<class T>
sharedstack<T>::sharedstack(T a[], int n, T b[], int m)//实现构造函数
{
	top1 = -1;
	top2 = Maxsize;
	if (m + n <= Maxsize)
	{
		for (int i = 0; i < n; i++)
		{
			top1++;
			data[top1] = a[i];
		}
		for (int i = 0; i < m; i++)
		{
			top2--;
			data[top2] = b[i];
		}
	}
	else
	{
		throw"上溢";
	}
}

template<class T>
void sharedstack<T>::Push(int i, T x) //实现插入栈的操作
{
	if (top1 != top2) //判断是否栈满
	{
		if (i == 1)
			data[++top1] = x;
		else if (i == 2)
			data[--top2] = x;

	}
	else
		throw"上溢";
}

template<class T>
T sharedstack<T>::Pop(int i) //实现出栈操作
{
	if (i == 1)
		if (top1 != -1)
			return data[top1--];
		else
			throw"下溢";
	if (i == 2)
		if (top2 != Maxsize)
			return data[top2++];
		else
			throw"下溢";
}

template<class T>
T sharedstack<T>::GetTop(int i) //访问栈顶元素
{
	if (i == 1)
		if (top1 != -1)
			return data[top1];
		else
			throw"下溢";
	if (i == 2)
		if (top2 != Maxsize)
			return data[top2];
		else
			throw"下溢";
}

template<class T>
bool sharedstack<T>::Empty(int i) //判断栈是否为空
{
	if (i == 1)
	{
		if (top1 == -1)
			return true;
		else
			return false;
	}
	if (i == 2)
	{
		if (top2 == Maxsize)
			return true;
		else
			return false;
	}
}

template<class T>
void sharedstack<T>::Clear(int i) //清空栈内元素
{
	if (i == 1)
	{
		while (top1 != -1)
			data[top1--] = 0;
	}
	if (i == 2)
	{
		while (top2 != Maxsize)
			data[top2++] = 0;
	}
}

template<class T>
void sharedstack<T>::Print(int i) //打印某栈元素
{
	int p = top1;
	int q = top2;
	if (i == 1)
	{
		while (p != -1)
			cout << data[p--] << " ";
		cout << endl;
	}
	if (i == 2)
	{
		while (q != Maxsize)
			cout << data[q++] << " ";
		cout << endl;
	}
}

int main()
{
	int a[] = { 1,2,3,4,5,6 };
	int b[] = { 7,8,9,10 };
	sharedstack<int> A(a, 6, b, 4); //构造共享栈A
	A.Print(1);
	A.Print(2); //打印栈内所有元素
	A.Push(1, 12);
	A.Push(2, 12); //在第一、二个栈内插入元素12
	A.Print(1);
	A.Print(2); //检验是否入栈
	A.Pop(1);
	A.Pop(2); //对栈一、二进行出栈操作
	A.Print(1);
	A.Print(2); //检验是否出栈

	A.Clear(1);
	if (A.Empty(1))
		cout << "栈一已清空" << endl;
	A.Clear(2);
	if (A.Empty(2))
		cout << "栈二已清空" << endl;
	try
	{
		for (int i = 0; i < 102; i++)
		{
			A.Push(1, i);
		}
	}
	catch (const char* msg)
	{
		cerr << msg << endl; //检验上溢的异常处理机制
	}
	try
	{
		for (int i = 0; i < 100; i++)
		{
			A.Pop(2);
		}
	}
	catch (const char* msg)
	{
		cerr << msg << endl; //检验下溢的异常处理机制
	}



	system("pause");
	return 0;
}