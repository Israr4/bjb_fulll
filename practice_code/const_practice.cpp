// // C++ program to demonstrate the
// // constant function
// #include <iostream>
// using namespace std;

// // Class Test
// class Test {
// 	int value;

// public:
// 	// Constructor
// 	Test(int v = 0)
// 	{
// 		value = v;
// 	}

// 	// We get compiler error if we
// 	// add a line like "value = 100;"
// 	// in this function.
// 	const int getValue() 
// 	{
// 		return value;
// 	}
	
// 	// a nonconst function trying to modify value
// 	void setValue(int val) {
// 		value = val;

// 	}
// };

// // Driver Code
// int main()
// {
// 	// Object of the class T
// 	Test t(20);

// 	// non-const object invoking const function, no error
// 	cout << t.getValue() << endl;
	
// 	// const object
// 	 Test t_const(10);

// 	// const object invoking const function, no error
// 	cout << t_const.getValue() << endl;

// 	// const object invoking non-const function, CTE
// 	// t_const.setValue(15);
	
// 	// non-const object invoking non-const function, no error
// 	t.setValue(12);
	
// 	cout << t.getValue() << endl;

// 	return 0;
// }



// C++ program to demonstrate the
// above approach
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
// using namespace std;

// // Function foo() with variable
// // const int
// void foo(const int y)
// {
// 	// y = 6; const value
// 	// can't be change
// 	cout << y<<endl;
// }

// // Function foo() with variable int
// // void foo1(int y)
// // {
// // 	// Non-const value can be change
// // 	y = 5;
// // 	cout << '\n'
// // 		<< y;
// // }

// // Driver Code
// int main()
// {
// 	int x = 9;
// 	const int z = 10;
	

// 	foo(z);
// 	// foo1(x);

// 	return 0;
// }



// void zero_array(int num[],size_t size)
// {
// 	for(size_t i=0;i<size;i++)
// 	{
// 		num[i]=0;
// 	}
// 	num[0]=5000;
// }
// void print_array(int num[],size_t size)
// {
// 	for(size_t i=0;i<size;i++)
// 	{
// 		std::cout<<num[i]<<" ";
// 	}
// }

// int main()
// {
//     int num[]={1,2,3,4,5};
// 	zero_array(num,5);
// 	print_array(num,5);
// 	return 0;
// }




// void passbyreference(int num)
// {
// 	num=1000;
// }

// int main()
// {
// 	int num = 10;
// 	std::cout<<"befor calling"<<num<<std::endl;
// 	passbyreference(num);
// 	std::cout<<"after calling"<<num<<std::endl;
// 	return 0;
// }


// void func(int *ptr)
// {
// 	*ptr = *ptr *2;
// }

// int main()
// {
// 	int val =10;
// 	std::cout<<val<<std::endl;
// 	func(&val);
// 	std::cout<<val<<std::endl;

// 	int *ptr1=0;
// 	ptr1 = &val;
// 	func(ptr1);
// 	std::cout<<val<<std::endl;

// }

// void display(std::vector<std::string> *v)
// {

// 	for(int i=0;i< (*v).size();i++)
// 	{
// 		std::cout<< (*v)[i]<<std::endl;
// 	}
// 	// for(auto str: *v)
// 	// {
// 	// 	std::cout<<str<<std::endl;
// 	// }
// }

// int main()
// {
// 	std::vector<std::string> vector ={"A","B","C"};
// 	display(&vector);
// }

// int *large(int *ptr1, int *ptr2);


// int main()
// {
// 	int a=100;
// 	int b=200;
// 	int *ptr=0;
// 	ptr = large(&a,&b);
// 	std::cout<<*ptr<<std::endl;
// }
// int *large(int *ptr1, int *ptr2)
// {
// 	if(*ptr1>*ptr2)
// 	{
// 		return ptr1;
// 	}
// 	else{
// 		return ptr2;
// 	}
// }



// class a 
// {
// 	public:
// 	void func()
// 	{
// 	std::cout<<"A Class"<<std::endl;
// 	}
// };

// class b final:public a 
// {
// 	public:
// 	void func1()
// 	{
// 	std::cout<<"A Class"<<std::endl;
// 	}
// };

// class c:public b

// {

// };

// int main()
// {
// 	a ap;
// 	ap .func();

// 	b bp;
// 	bp .func1();
	

// }



// class traffic
// {
// 	public:
// 	int x;
// 	int y;

// 	traffic(int i,int j)
// 	{
// 		x=i;
// 		y=j;
// 		std::cout<<x<<std::endl;
// 		std::cout<<y<<std::endl;
// 	}

// };

// int main()
// {
// 	traffic t= traffic(20,30);
// 	return 0;+
// }


// #include <iostream>
// #include <string>

// template <typename t>
// t min(t a,t b)
// {
// 	return (a<b) ? a:b;
// }


// template <typename t1,typename t2>
// void func(t1 a,t2 b)
// {
// 	std::cout<<a<<"  "<<b<<std::endl;


// class Base
// {
// 	public:
// 	 virtual int show() = 0;
// 	// {
// 	// 	std::cout<<"Hello Base Class"<<std::endl;
// 	// }
// };

// class Derived : public Base
// {
// 	public:
// 	int show()
// 	{
// 		std::cout<<"Hello Derived Class"<<std::endl;
// 		return 0;
// 	}
// };

// class Derived1 : public Derived
// {
// 	public:
// 	int show()
// 	{
// 		std::cout<<"Hello Derived1 Class"<<std::endl;
// 		return 0;
// 	}
// };

// void greetings( Base &obj)
// {
// 	std::cout<<"Greetings"<<std::endl;
// 	obj.show();
// }

// int main()
// {
// 	// Base a;
// 	Derived b;
// 	Derived1 c;
// 	// a.show();
// 	b.show();
// 	c.show();
// 	// Base *ptr  = new Base();
// 	Base *ptr1 = new Derived();
// 	Base *ptr2 = new Derived1();
// 	// ptr  -> show();
// 	ptr1 -> show();
// 	ptr2 -> show();
// 	// greetings(b);

// }

// class Base
// {
// 	private:
// 	int a,b,c;
// 	friend int function(Base);
// };

//     int function(Base b)
// 	{
// 		b.a = 100;
// 		b.b = 20;
// 		b.c = b.a / b.b;
// 		return(b.c);
// 		std::cout<<std::endl;
// 	}

// 	int main()
// 	{
// 		Base b;
// 		std::cout<<function(b);
// 		return 0;
// 	}


// class Base
// {
// 	public:
// 	Base()
// 	{

// 	}
// 	Base(int x)
// 	{
// 		std::cout<<"Base"<<x<<std::endl;
// 	}
// };

// class Derived:public Base
// {
// 	public:
// 	Derived(int x,int y):Base(x)
// 	{
// 		std::cout<<"Derived"<<x<<std::endl;
// 		std::cout<<"Derived"<<y<<std::endl;
// 	}
// };


// int main()
// {
// 	Derived b(12,5);
// 	// Derived d;
// 	return 0;
// }


// class Base
// {
// 	public:
// 	int a,b,*ptr;
// 	Base()
// 	{
// 		ptr = new int;
// 	}

// 	void getdata(int x,int y,int z)
// 	{
// 		a = x;
// 		b = y;
// 		*ptr = z;
// 	}

// 	void display()
// 	{
// 		std::cout<<a<<std::endl;
// 		std::cout<<b<<std::endl;
// 		std::cout<<ptr<<std::endl;
// 	}

// 	Base(Base &obj)
// 	{
// 		a = obj.a;
// 		b = obj.b;
// 		ptr = new int;
// 		*(ptr) = *(obj.ptr);
// 		std::cout<<"Copy Constructor Executed"<<std::endl;
// 	}
// };

// int main()
// {
// 	Base b;
// 	b.getdata(10,20,30);
// 	Base b1(b);
// 	b.display();
// 	b1.display();
// }

// class A
// {
// 	public:
// 	void display()
// 	{
// 		std::cout<<"Hello I m a Base Class"<<std::endl;
// 	}
// };


// class B : public A
// {
// 	public:
// 	void display()
// 	{
// 		A::display();
// 		std::cout<<"Hello I m a Derived Class"<<std::endl;
		
// 	}
	
// };


// class A
// {
// 	public:
// 	int a = 10;
// 	int b = 20;

// 	void display()
// 	{
// 		std::cout<<a<<std::endl;
// 		std::cout<<b<<std::endl;
// 	}

// };

// class B:public A
// {
// 	public:

// 	void show()
// 	{
// 		a = 30;
// 	    b = 40;
//         std::cout<<a<<std::endl;
// 		std::cout<<b<<std::endl;
// 	}
// };

// class C:protected B
// {
// 	public:

// 	void displayy()
// 	{
// 		a = 50;
// 	    b = 60;
//         std::cout<<a<<std::endl;
// 		std::cout<<b<<std::endl;
// 	}
// };

// int main()
// {

// 	A a;
// 	B b;
// 	C c;
// 	a.display();
// 	b.display();
// 	c.display();
// 	b.show();
// 	c.show();
// 	c.displayy();
// 	return 0;
// }

// class Base
// {
// 	public:
// 	 void display()  const
// 	{
// 		std::cout<<"Hello I am a Base Class"<<std::endl;
// 	}
// };


// class Derived : public Base
// {
// 	public:
// 	void display()  const
// 	{
// 		std::cout<<"Hello I am a Derived Class"<<std::endl;
// 	}
// };


// void greetings(const Base &obj) 
// {
// 	std::cout<<"Greetings"<<std::endl;
// 	obj.display();
// }
 


//  int main()
//  {
// 	Base b;
// 	Derived d;
// 	b.display();
// 	d.display();
// 	greetings(b);
// 	greetings(d);
// 	Base *ptr = new Derived();
// 	ptr -> display();
// 	return 0;
//  }


// class Base 
// {
// 	public:
// 	int a,b,*ptr;
// 	Base()
// 	{
// 		ptr = new int;
// 	}
// 	void set_Base(int x,int y,int z)
// 	{
// 		a = x;
// 		b = y;
// 		*ptr = z;
// 	}
// 	void display()
// 	{
// 		std::cout<<a<<std::endl;
// 		std::cout<<b<<std::endl;
// 	}
// 	Base(Base &c)
// 	{
// 		a = c.a;
// 		b = c.b;
// 		ptr = new int;
// 		*ptr = *(c.ptr);
// 		std::cout<<"Copy Constructor Executed"<<std::endl;
// 	}
// };

// int main()

// {
// 	Base b;
// 	b.set_Base(100,20,30);
// 	b.display();
// 	return 0;
// }


// enum icecream
// {
// 	vanilla,
// 	strawberry,
// 	chocolate
// };

// int main()
// {
// 	icecream i = chocolate;
// 	std::cout<<i<<" "<<chocolate<<std::endl;
// 	return 0;
// }


// void display(int &x)
// {
// 	std::cout<<x<<std::endl;
// 	x = 20;
// 	std::cout<<x<<std::endl;
// }

// int main()
// {
// 	int x = 10;
// 	display(x);
// 	std::cout<<x<<std::endl;
// 	return 0;
// }

// int function(int a,int b)
// {
// 	 int c= a /b;
// 	return c;
// }

// double function()
// {
// 	double a =10.5;
// 	double b= 20.8;
// 	double c= a /b;
// 	return c;
// }

// int main()
// {
// 	std::cout<<function(20,10)<<std::endl;
// 	std::cout<<function()<<std::endl;
// 	return 0;
// }

// int main()
// {
// int a = 10;
// int &b = a;
// std::cout<<a<<std::endl;
// b = 20;
// std::cout<<a<<std::endl;
// return 0;
// }


//  void display(int array[])
// {
// 	for(int i=0 ; i<5 ;i++)
// 	{
// 		array[i] ;
// 		std::cout<<array[i]<<std::endl;
// 	}
// }

// int main()
// {
// 	int array1[] = {1,2,3,4,5};
// 	display(array1);
// 	return 0;
// }

// int main()
// {
// 	int a = 10;
// 	int b = 20;
// 	int *ptr = &a;
// 	std::cout<<s;
// 	*ptr = 30;
// 	ptr = &b;
// 	return 0;
// }
// class A
// {
// 	public:
//     int a = 20;
// 	const int function( int x)
// 	{
// 		a ++;
// 		std::cout<<a<<std::endl;
// 		std::cout<<x<<std::endl;
// 		return a;
// 	}
// };

// int main()
// {
// 	A a;
// 	const int z = 10;
// 	a.function(z);
// 	return 0;

// }

// int main()
// {
//     int a = 10;
//     int b = 20;
//      int  * ptr = &a;
//      *ptr = 30;
//      ptr = &b;
    
//     return 0;
// }

// void function(int &x)
// {
//     std::cout<<x<<std::endl;
//     x = 100;
//     std::cout<<x<<std::endl;
// }


// class A
// {
//     public:
//     // int a = 10;

//     int *function( int *ptr, int *ptr1 ) 
//     {
//         if(*ptr > *ptr1)
//         {
//             return ptr;
//         }

//         else
//         {
//             return ptr1;
//         }
//     }
// };
// int main()
// {
//     A a;
//     int x = 10;
//     int y = 20;
//     int *ptr = a.function(&x,&y);
//     std::cout<<*ptr<<std::endl;
//     return 0;
// }

// #include <set>
// int main()
// {
//     // int a = 10;
//     // int b = 20;
//     // int *ptr = &a ;
//     // *ptr  = b;
//     // // std::cout<<*ptr<<std::endl;
//     //  std::cout<<ptr<<std::endl;
//     //  return 0;
//     std::set <int > setname = {1,2,3,2,4,6,6,9,7,8,8,8,8,8};
//     for(auto i:setname)
//     {
//         std::cout<<i<<std::endl;
//     }
//     std::cout<<"Size Is "<<setname.size()<<std::endl;
//     return 0;
// }


// int main()
// {
//     std::string a = "jhgjhsd";
//     std::string b;
//     std::cin>>b;
//     switch(b)
//     {
//     case('a'):
//     std::cout<<"Value is True"<<std::endl;
//     break;
//     default:
//     }

//     return 0;
// }






























































































































































































































































































































