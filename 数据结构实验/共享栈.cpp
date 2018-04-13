#include<iostream>

using namespace std;

const int Maxsize = 100;//���干��ջ���ޡ�

template<class T>
class sharedstack //���干��ջģ�塣
{
private:
	int top1, top2;
	T data[Maxsize];
public:
	sharedstack() //�޲ι��캯��������
	{
		top1 = -1;
		top2 = Maxsize;
	}
	sharedstack(T a[], int n, T b[], int m); //���캯��������
	void Push(int i, T x); //��ջ������Ԫ��
	T Pop(int i); //������ջ����
	T GetTop(int i); //����ջ��Ԫ��
	bool Empty(int i); //�жϹ���ջ�Ƿ�Ϊ��
	void Clear(int i); //���ջ��Ԫ��
	void Print(int i); //��ӡĳջΪ��
};

template<class T>
sharedstack<T>::sharedstack(T a[], int n, T b[], int m)//ʵ�ֹ��캯��
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
		throw"����";
	}
}

template<class T>
void sharedstack<T>::Push(int i, T x) //ʵ�ֲ���ջ�Ĳ���
{
	if (top1 != top2) //�ж��Ƿ�ջ��
	{
		if (i == 1)
			data[++top1] = x;
		else if (i == 2)
			data[--top2] = x;

	}
	else
		throw"����";
}

template<class T>
T sharedstack<T>::Pop(int i) //ʵ�ֳ�ջ����
{
	if (i == 1)
		if (top1 != -1)
			return data[top1--];
		else
			throw"����";
	if (i == 2)
		if (top2 != Maxsize)
			return data[top2++];
		else
			throw"����";
}

template<class T>
T sharedstack<T>::GetTop(int i) //����ջ��Ԫ��
{
	if (i == 1)
		if (top1 != -1)
			return data[top1];
		else
			throw"����";
	if (i == 2)
		if (top2 != Maxsize)
			return data[top2];
		else
			throw"����";
}

template<class T>
bool sharedstack<T>::Empty(int i) //�ж�ջ�Ƿ�Ϊ��
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
void sharedstack<T>::Clear(int i) //���ջ��Ԫ��
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
void sharedstack<T>::Print(int i) //��ӡĳջԪ��
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
	sharedstack<int> A(a, 6, b, 4); //���칲��ջA
	A.Print(1);
	A.Print(2); //��ӡջ������Ԫ��
	A.Push(1, 12);
	A.Push(2, 12); //�ڵ�һ������ջ�ڲ���Ԫ��12
	A.Print(1);
	A.Print(2); //�����Ƿ���ջ
	A.Pop(1);
	A.Pop(2); //��ջһ�������г�ջ����
	A.Print(1);
	A.Print(2); //�����Ƿ��ջ

	A.Clear(1);
	if (A.Empty(1))
		cout << "ջһ�����" << endl;
	A.Clear(2);
	if (A.Empty(2))
		cout << "ջ�������" << endl;
	try
	{
		for (int i = 0; i < 102; i++)
		{
			A.Push(1, i);
		}
	}
	catch (const char* msg)
	{
		cerr << msg << endl; //����������쳣�������
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
		cerr << msg << endl; //����������쳣�������
	}



	system("pause");
	return 0;
}