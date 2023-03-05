#include<iostream>
#include<string>
using namespace std;
string to_string(string s)
{
	return s;
}
template <typename T1, typename T2>
class MyPair
{
public:
	T1 key;
	T2 value;
	MyPair();
	MyPair(const MyPair<T1, T2>& obj);
	MyPair(T1 a, T2 b);
	MyPair<T1,T2> Assign(const MyPair<T1, T2>& obj);
	bool operator== (const MyPair<T1, T2> p);
	bool operator < (const MyPair<T1, T2> p);
	void operator=(const MyPair<T1,T2> p);
	void swap(MyPair<T1, T2>& obj);
	void output()
	{
		cout << key<<endl;
		cout << value<<endl;
	}
};
template <typename T1, typename T2>
MyPair<T1, T2>::MyPair()
{
	key = '\0';
	value = '\0';
}
template <typename T1, typename T2>
MyPair<T1, T2>::MyPair(const MyPair<T1, T2>& obj)
{
	key = obj.key;
	value = obj.value;
}
template <typename T1, typename T2>
MyPair<T1, T2>::MyPair(T1 a, T2 b)
{
	key = a;
	value = b;
}
template <typename T1, typename T2>
MyPair<T1,T2> MyPair<T1, T2>::Assign(const MyPair<T1, T2>& obj)
{
	key = obj.key;
	value = obj.value;
	return *this;
}
template <typename T1, typename T2>
void MyPair<T1, T2>::swap(MyPair<T1, T2>& obj)
{
	MyPair<T1, T2> temp;
	temp.key = key;
	key = obj.key;
	obj.key = temp.key;
	temp.value = value;
	value = obj.value;
	obj.value = temp.value;
}
template<class T1, class T2>
bool MyPair<T1, T2> ::operator== (const MyPair<T1, T2> p)
{
	return ((key == p.key) && (value == p.value));
}
template<class T1, class T2>
bool MyPair<T1, T2> ::operator< (const MyPair<T1, T2> p)
{
	return ((key < p.key));
}
template<class T1, class T2>
void MyPair<T1, T2> ::operator= (const MyPair<T1, T2> p)
{
    key=p.key;
    value=p.value;
	return ;
}
template <typename T1, typename T2>
class MyMap
{
private:
	int size;
	static const int max_size = 1000;
	MyPair<T1, T2>* container;
public:
	MyMap();
	MyMap(const MyMap<T1, T2> &obj);
	~MyMap();
	MyMap<T1, T2> operator = (MyMap<T1, T2> &obj);
	bool isEmpty();
	T2 operator [] (T1 k);
	T2 at(T1 k);
	MyMap<T1, T2> Insert(MyPair<T1, T2> );
	MyMap<T1, T2> remove(T1 k);
	MyMap<T1, T2> clear();
	MyPair<T1, T2> find(T1 k);
	template <typename u1, typename u2>
	friend MyMap<u1, u2> operator +(MyMap<u1, u2> a,MyMap<u1, u2> b);
	template <typename u1, typename u2>
	friend ostream &operator<< (ostream &out, MyMap<u1, u2>);
	template <typename u1, typename u2>
	friend bool operator == (MyMap<u1, u2> a,MyMap<u1, u2> b);
	template <typename u1, typename u2>
	friend bool operator != (MyMap<u1, u2> a,MyMap<u1, u2> b);
	void sort();
	T1 * keys(); 
	T2 * values();
	template <typename u1, typename u2>
	friend string toString(MyMap<u1, u2> a);
	bool isFull();
};
template <typename T1, typename T2>
MyMap<T1, T2>:: MyMap()
{
	size = 0;
	container = nullptr;
}
template <typename T1, typename T2>
MyMap<T1, T2>:: MyMap(const MyMap<T1, T2> &obj)
{
	size = obj.size;
	container = new MyPair<T1, T2>[obj.size];
	for (int i = 0; i < obj.size; i++)
	{
	    
		container[i] = obj.container[i];
	}
}
template <typename T1, typename T2>
MyMap<T1, T2>:: ~MyMap()
{
	if(container != nullptr)
	delete [] container;
}
template <typename T1, typename T2>
bool MyMap<T1, T2>:: isEmpty()
{
	if(size==0)
		return 1;
	else 
		return 0;
}
template <typename T1, typename T2>
MyMap<T1, T2> MyMap<T1, T2>::operator = (MyMap<T1, T2> &obj)
{
	size = obj.size;
	container = new MyPair<T1, T2>[obj.size];
	for (int i = 0; i < obj.size; i++)
	{
		container[i].key = obj.container[i].key;
		container[i].value = obj.container[i].value;
	}
	return *this;
}
template <typename T1, typename T2>
T2 MyMap<T1, T2>:: operator [](T1 k)
{
	
	for (int i = 0; i < size; i++)
	{ if(container[i].key == k)
	{
		return container[i].value;
	}
	}
		MyPair<T1, T2> * temp;
		temp = new MyPair<T1, T2>[size+1];
		for (int i = 0; i < size; i++)
		{
			temp[i].key=container[i].key;
		}
		temp[size].key = k;
		delete []container;
		container = temp;
		size++;
		return container[size-1];
}
template <typename T1, typename T2>
T2 MyMap<T1, T2>:: at (T1 k)
{
	return operator[](k);
}
template <typename T1, typename T2>
bool MyMap<T1, T2>:: isFull()
{
	if(size==max_size)
		return 1;
	else 
		return 0;
}
template <typename T1, typename T2>
MyMap<T1, T2> MyMap<T1, T2>:: Insert(MyPair<T1, T2> a)
{
    	if(isEmpty())
	{
		size++;
		container= new MyPair<T1, T2> [size];
		container[size-1] = a;
		return *this;
	}

	int x=0;
	for (int i = 0; i < size; i++)
	{
		if(a.key == container[i].key)
		{
			x=1;
			break;
		}
	}
	if(x==0)
	{
		MyPair<T1, T2> * temp;
		temp = new MyPair<T1, T2>[size+1];
		for (int i = 0; i < size; i++)
		{
			temp[i]=container[i];
		}
		temp[size] = a;
		delete []container;
		container = temp;
		size++;
		return *this;
	}
	if(x==1 || isFull())
	{
		return *this;
	}
}
template <typename T1, typename T2>
MyMap<T1, T2> MyMap<T1, T2>:: remove(T1 k)
{
	MyPair<T1, T2> *temp = new MyPair<T1, T2>[size];
	int j=0;
	for (int i = 0; i < size; i++)
	{
		if(container[i].key!=k)
		{
			temp[j] = container[i];
			j++;
		}
	}
	if(j<size)
	{
		size--;
	}
	delete [] container;
	container = new MyPair<T1, T2>[j];
	for (int i = 0; i < j; i++)
	{
		container[i]=temp[i];
	}
	return *this;
}
template <typename T1, typename T2>
MyMap<T1, T2> MyMap<T1, T2>:: clear()
{
	size=0;
	delete [] container;
	container = nullptr;
	return *this;
}
template <typename T1, typename T2>
MyPair<T1, T2> MyMap<T1, T2>:: find(T1 k)
{
	for (int i = 0; i < size; i++)
	{
		if (container[i].key==k)
		{
			return container[i];
		}
	}
}
template <typename T1, typename T2>
MyMap<T1, T2> operator +(MyMap<T1, T2> a,MyMap<T1, T2> b)
{
	MyMap<T1, T2> c;
	for (int i = 0; i < a.size; i++)
	{
		c.Insert(a.container[i]);
	}
	int j=0;
	for (int i = a.size; i < b.size + a.size ; i++,j++)
	{
		c.Insert(b.container[j]);
	}
	return c;
}
template <typename T1, typename T2>
bool operator == (MyMap<T1, T2> a,MyMap<T1, T2> b)
{
	if(a.size!=b.size)
	{
		return 0;
	}
	for (int i = 0; i < a.size; i++)
	{
		if(a.container[i]!=b.container[i])
			return 0;
	}
	return 1;
}
template <typename T1, typename T2>
bool operator != (MyMap<T1, T2> a,MyMap<T1, T2> b)
{
	if(a==b)
		return 0;
	return 1;
}
template <typename T1, typename T2>
ostream &operator<< (ostream &out, MyMap<T1, T2> a)
{
    if(a.container!=nullptr) {
	for (int i = 0; i < a.size; i++)
	{
		out<<"key["<<i+1<<"]:"<<a.container[i].key<<"             ";
		out<<"value["<<i+1<<"]:"<<a.container[i].value<<endl;
	}
    }
    else
    {
        out<<"Map is empty!\n";
    }
	return out;
}
template <typename T1, typename T2>
void MyMap<T1, T2>:: sort()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - (i+1); j++)
		{
			if(container[i].key>container[i+1].key)
			{
				MyPair<T1, T2> t;
				t = container[i+1];
				container[i+1] = container[i];
				container[i] = t;
			}
		}
	}
}
template <typename T1, typename T2>
string toString(MyMap<T1, T2> a)
{
	string s;
	for (int i = 0; i < a.size; i++)
	{
		s = s + to_string(a.container[i].key) + " " + to_string(a.container[i].value) + " ";
	}
	s = s + "\n";
	return s;
}
template <typename T1, typename T2>
T1* MyMap<T1, T2>::keys()
{
	T1 * arr = new T1[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = container[i].key; 
	}
	return arr;
}
template <typename T1, typename T2>
T2 * MyMap<T1, T2>::values()
{
	T2 * arr = new T2[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = container[i].value; 
	}
	return arr;
}
int main()


{
    
	MyPair<char*, double> Course1("English",114.7);
	MyPair<char*, double> Course2("Calculus 1",115.4);
	MyPair<char*, double> Course3("Pak Studies",116.9);
	MyPair<char*, double> Course4("Islamiyat",117.0);
	MyPair<char*, double> Course5("Programming",118.2);
	MyPair<char*, double> Course6("Physics",119.1);
	MyPair<char*, double> Course7("OOP",120.4);
	MyPair<char*, double> Course8("Calculus 2",121.6);
	MyPair<char*, double> Course9("CPS",122.3);
	MyPair<char*, double> Course10("DLD",123.0);
	
	MyMap<char*,double> x;

	x.Insert(Course1);
	x.Insert(Course2);
	x.Insert(Course3);
	x.Insert(Course4);
	x.Insert(Course5);
	x.Insert(Course6);
	x.Insert(Course7);
	x.Insert(Course8);
	x.Insert(Course9);
	x.Insert(Course10);
	
	cout<<x;
	char* chararr;
	x.remove("DLD");
	cout<<x;
	x.find("OOP");
	x.keys();
	x.values();
	x.clear();
	cout<<x;

	MyPair<int, char*> City1(021,"Karachi");
	MyPair<int, char*> City2(022,"HyderAbad");
	MyPair<int, char*> City3(051,"IslamAbad");
	MyPair<int, char*> City4(040,"Sahiwal");
	MyPair<int, char*> City5(041,"FaisalAbad");
	MyPair<int, char*> City6(042,"Lahore");
	MyPair<int, char*> City7(044,"Okara");
	MyPair<int, char*> City8(046,"HyderAbad");
	MyPair<int, char*> City9(047,"Sargodha");
	MyPair<int, char*> City10(052,"Sialkot");
	MyMap<int, char*> y;

	y.Insert(City1);
	y.Insert(City2);
	y.Insert(City3);
	y.Insert(City4);
	y.Insert(City5);
	y.Insert(City6);
	y.Insert(City7);
	y.Insert(City8);
	y.Insert(City9);
	y.Insert(City10);
	
	cout<<y;
	y.sort();
	cout<<y;

	system("pause");
	return 0;
}