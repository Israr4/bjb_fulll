#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>



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
//     std::cout<<*ptr<<std::endl;zz
//     return 0;
// }

// #include <set>
// int main()
// {
//     std::set <int > setname = {11,2,3,2,4,6,6,9,7,8,8,8,8,8};
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
// // }

// int main()
// {
//     string name;
//     std::cout<<"Enter your Full Name"<<" ";
//     getline(std::cin,name);
//     return 0;
// }

// int func()
// {
//     return x;
// }

// double func()
// {
//     return x,y;
// }
// // float func(float x)
// // {
// //     return x;
// // }

// class Base
// {
//     public:
//     void display() const
//     {
//         std::cout<<"Hii I am a Base Class"<<std::endl;
//     }
// };

// class derived:public Base

// {
//     public:
//     void display() const
//     {
//         std::cout<<"Hii T am a Derived Class"<<std::endl;
//     }
// };

// void greetings( const Base &b)
// {
//     b.display();
// }

// int main()
// {
//     Base b;
//     derived d;
//     b.display();
//     d.display();
//     greetings(b);
//     greetings(d);
//     Base *c = new derived();
//     c->display();
//     return 0;

// }


// class A
// {
//     protected:
//     int a,b;
//     public:
//     void show()
//     {
//         a = 10;
//         b = 20;
//         std::cout<<a<<" "<<b<<std::endl;
//     }
// };

// class B:public A
// {
//     public:
//     void display()
//     {
//         a = 30;
//         b = 40;
//         std::cout<<a<<" "<<b<<std::endl;
//     }
// };

// int main()
// {
//     A a;
//     B b;
//     a.show();
//     b.show();
//     b.display();
//     return 0;
// }


// class A
// {
//     private:
//     int a,b,c;

//     void newu()
//     {
//         a = 10;
//         b = 20;
//         c = a + b;
//         std::cout<<c<<std::endl;
//     }
//     friend void function(A);
// };

// void function(A a)
// {
//     a.newu();
// }

// int main()
// {
//     A a;
//     function(a);
//     return 0;
// }


// class A
// {
//     public:
//     A()
//     {
//         std::cout<<"Hiii"<<std::endl;
//     }
//     A(int x)
//     {
//         std::cout<<"A"<<x<<" ";
//     }
// };

// class B:public A
// {
//     public:
//     B(int x,int y):A(x)
//     {
//         std::cout<<"B"<<y<<" ";
//     }
// };

// int main()
// {
//     A a;
//     B b(10,20);
//     return 0;
// }

// class A
// {
//     public:
//     int x,y;
//     A(int a,int b)
//     {
//         x = a;
//         y = b;
//         std::cout<<"Constructor Executed"<<std::endl;
//     }
//     void display()
//     {
//         std::cout<<x<<" "<<y<<std::endl;
//     }
//     A(A &a)
//     {
//         x = a.x;
//         y = a.y;
//         std::cout<<"Copy Constructor Executed!!!"<<std::endl;
//     }
// };

// int main()
// {
//     A a(10,20);
//     A a1(a);
//     a.display();
//     a1.display();
//     return 0;
// }



// class A
// {
//     public:
//     int x,y,*ptr;
//     A()
//     {
//         ptr = new int();
//         std::cout<<"Constructor Executed"<<std::endl;
//     }
//     void getdata(int a,int b,int c)
//     {
//         x = a;
//         y = b;
//         *ptr = c;
//     }
//     void display()
//     {
//         std::cout<<x<<" "<<y<<" "<<ptr<<std::endl;
//     }
//     A(A &a)
//     {
//         x = a.x;
//         y = a.y;
//         ptr = new int();
//         *(ptr) = *(a.ptr);
//         std::cout<<"Copy Constructor Executed!!!"<<std::endl;
//     }
// };

// int main()
// {
//     A a;
//     a.getdata(10,20,30);
//     A a1(a);
//     a.display();
//     a1.display();
//     return 0;
// }

// template <typename t, typename z>

// void min(t a, z b)
// {
//     std::cout<<a<<" "<<b<<std::endl;
// }
    
// int main()
// {
//     min(10,20.32);
//     min(30.25,20.32);
//     min('a',20);
//     min("Ali",'h');
//     return 0;
// }

// int main()
// {   
//     int sum = 0;
//     int a = 0;
//     int b = 1;
//     for(int i = 0; i< 100; i++)
//     {
//         if(sum <250)
//         {
//         sum = a + b;
//         std::cout<<sum<<std::endl;
//         }
//     }
//     return 0;
// }


// class A
// {
//     public:
//     int a,b,*ptr;
//     A()
//     {
//         ptr = new int();
//     }
    
//     void set(int x,int y,int c)
//     {
//         a = x;
//         b = y;
//         c = *ptr;
//     }
//     void display()
//     {
//         std::cout<<a<<" "<<b<<" "<<ptr<<std::endl;
//     }
//     A(A &obj)
//     {
//         a = obj.a;
//         b = obj.b;
//         ptr = new int();
//         *(ptr) = *(obj.ptr);
//     }
// };

// int main()
// {
//     A a;
//     a.set(10,20,30);
//     a.display();
//     A b(a);
//     b.set(10,20,30);
//     b.display();
//     return 0;
// }

// class A
// {
//     public:
//     int x = 10;
//     int y = 20;

//     void func(  int a =30, int b= 40) 
//     {
//         x = 50;
//         a = 20;
//         std::cout<<x<<std::endl;
//         std::cout<<a<<std::endl;
//     }
// };

// int main()
// {
//     A a;
//     a.func(600,700);
//     return 0;
// }


// class A
// {
//     private:
//     int x ;
//     int y ;
//     friend int func(A);
    
// };

// int func(A a)
// {
//     a.x = 10;
//     a.y = 20;
//     return a.x + a.y;
// }

// int main()
// {
//     A a;
//     std::cout<<func(a)<<std::endl;
//     return 0;
// }


// class A
// {
//     public:
//     int a,b;
    
//     public:
//     virtual void display()
//     {
//         a = 10;
//         b = 20;
//         std::cout<<"a "<<a<<" "<<"b "<<b<<std::endl;
//     }
// };

// class B: public A
// {
//     public:
//     void display()
//     {
//         a = 100;
//         b = 200;
//         std::cout<<"a "<<a<<" "<<"b  "<<b<<std::endl;
//     }
// };

// void greeting(A &a)
// {
//     a.display();
// }
// int main()
// {
//     A a;
//     B b;
//     a.display();
//     b.display();
//     b.display();
//     greeting(a);
//     greeting(b);
//     A *ptr = new B();
//     ptr -> display();
//     return 0;
// }



// int main()
// {
//     int a = 0;
//     int b = 1;
//     int sum = 0;
//     static int i = 0;
//     std::cout<<0<<" ";
//     while(i<30)
//     {
//         a = b;
//         b = sum;
//         sum = a+b;
//         std::cout<<sum<<" ";
//         i++;
//     }
//     std::cout<<std::endl;
//     return 0;
// }

// int main()
// {
//     for(int i  = 5;i >= 0;i--)
//     {
//         for(int j=5;j>=i;j--)
//         {
//             std::cout<<i<<" ";
//         }
//         std::cout<<std::endl;
//     }

//     std::cout<<"     *"<<std::endl;
//     std::cout<<"    ***"<<std::endl;
//     std::cout<<"   *****"<<std::endl;
//     std::cout<<"  *******"<<std::endl;
//     std::cout<<"   *****"<<std::endl;
//     std::cout<<"    ***"<<std::endl;
//     std::cout<<"     *"<<std::endl;

//     std::cout<<"-----------------------------"<<std::endl;

//     for (int i = 0;i<=6;i++)
//     {
//         for(int j = 0; j<=6;j++)
//         {
//             if(i==0 && j==3)
//             {
//                 std::cout<<"*"<<std::endl;
//             }
//             if(i==1 && j==3)
//             {
//                 std::cout<<"*"<<std::endl;
//             }
//             if(i==2 && j==3)
//             {
//                 std::cout<<"*"<<std::endl;
//             }
//             if(i==3 && j==3)
//             {
//                 std::cout<<"*"<<std::endl;
//             }
//             if(i==4 && j==3)
//             {
//                 std::cout<<"*"<<std::endl;
//             }
//             if(i==5 && j==3)
//             {
//                 std::cout<<"*"<<std::endl;
//             }
//             if(i==6 && j==3)
//             {
//                 std::cout<<"*"<<std::endl;
//             }
//         }
//     }
//     return 0;
// }

// class Base
// {
//     public:
//     int a;
//     int b;
    
//     void display()
//     {
//         std::cout<<"Hello!!! Base  Class"<<std::endl;
//     }
// };

// class Derived: public Base
// {
//     public:
//     int x;
//     int y;

//     void display()
//     {
//         std::cout<<"Hello!!! Derived Class"<<std::endl;
//     }
// };

// void greeting(Base &b)
// {
//     b.display();
// }


// int main()
// {
//     Base b;
//     Derived d;
//     b.display();
//     d.display();
//     Base *ptr = new Derived();
//     ptr -> display();
//     greeting(b);
//     greeting(d);
//     return 0;
// }

// class Base
// {
//     public:
//     int a,b,*ptr;

//     Base()
//     {
//         ptr = new int();
//     }

//     void set(int x,int y,int z)
//     {
//         a = x;
//         b = y;
//         z = *ptr;
//     }

//     void display()
//     {
//         std::cout<<a<<" "<<b<<" "<<ptr<<std::endl;
//     }

//     Base(Base &g)
//     {
//         a = g.a;
//         b = g.b;
//         ptr = new int;
//         *(ptr) = *(g.ptr);
//         std::cout<<"Copy constructor Executed"<<std::endl;
//     }
// };

// int main()
// {
//     Base b;
//     b.set(10,20,30);
//     b.display();
//     Base b1(b);
//     b1.display();
//     return 0;
// }


// int main()
// {
//     int a = 0;
//     int b = 1;
//     int sum = 0;
//     static int i = 0;
//     std::cout<<0<<" ";
//     while(i<50)
//     {
//         a = b;
//         b = sum;
//         sum = a+b;
//         std::cout<<sum<<" ";
//         i++;
//     }
//     std::cout<<std::endl;
//     return 0;
// }


// #include<iostream>
// using namespace std;
// int main()
// {
//     int i, j, space;
//     space = 6-1;
//     for(i=1; i<=6; i++)
//     {
//         for(j=1; j<=space; j++)    //this loop contain space from left side of windows with the help of cout<<" "
//         {
//             cout<<" ";  // jdr yeh spaces print ho gai ha udr kuch ni print ho ga usa sa aga print ho ga sab kuch
//         }
//         space--;
//         for(j=1; j<=(2*i-1); j++)  //left space ka aga staric print karana han
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }

//     space = 1;
//     int z = 10;
//     for(int i = 1;i<=5;i++)
//     {
//         for(int j = 1;j<=space;j++)
//         {
//             cout<<" ";
//         }
//         space++;
//         for(j=1; j<=(z - i); j++)  //left space ka aga staric print karana han
//         {
//             cout<<"*";
            
//         }
//         z --;
//         cout<<endl;
//     }
//     return 0;
// }

// #include <cmath>
// int main()
// {
//     double a = remainder(1.234,10);
//     std::cout<<a<<std::endl;
// }




// class A
// {
//     protected:
//     int a = 10;
//     int b = 30;

//     public:
//     void display()
//     {
//         std::cout<<a<<" "<<b<<std::endl;
//     }
// };

// class B:public A
// {
//     public:
//     void sum()
//     {
//         std::cout<<a<<" "<<b<<std::endl;
//     }
// };

// int main()
// {
//     A a;
//     B b;
//     a.display();
//     b.display();
//     b.sum();
//     return 0;
// }



// int main()
// {
//     int a = 10;
//     int b = 20;
//     int c = a+b;
//     std::cout<<a<<" "<<b<<" "<<c<<std::endl;
//     return 0;
// }



// int main()
// {
//     int a;
//     p:
//     std::cout<<"Enter Number"<<std::endl;
//     std::cin>>a;
//     switch(a)
//     {
//         case(1):
//         std::cout<<"You Entered 1"<<std::endl;
//         break;

//         case(2):
//         std::cout<<"You Entered 2"<<std::endl;
//         break;

//         case(3):
//         std::cout<<"You Entered 3"<<std::endl;
//         break;

//         case(4):
//         std::cout<<"You Entered 4"<<std::endl;
//         break;

//         default:
//         std::cout<<"You Entered Wrong Number"<<std::endl;
//         std::cout<<"Please Try Again"<<std::endl;
//         goto p;
//     }
//     return 0;
// }


// int main()    //fibonacci series
// {
//    int  i = 0;
//    int  a =0;
//    int  b = 1;
//    int  sum = 0;
//    std::cout<<0<<" ";
//     while(sum<1000)
//     {
//         a = b;
//         b = sum;
//         sum = a + b;
//         std::cout<<sum<<" ";
//     }
//     std::cout<<std::endl;
//     return 0;
// }

// int main()
// {
//     int i,j,space;
//     space = 3 - 1;
//     int a = 0;
//     int b = 4;

//     for(i =1;i<=3;i++)
//     {
//         for( j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for( j=1;j<=i+a;j++)
//         {
//             std::cout<<"*";
//         }
//         a ++;
//         space --;
//         std::cout<<std::endl;
//     }

//     space = 1;
//     for( i = 1;i<=2;i++)
//     {s A
// {
//     public:
//     int a,b,*ptr;

//     A()
//     {
//         ptr = new int();
//         std::cout<<"Constructor Executed"<<std::endl;
//     }

//     void set(int x,int y,int z)
//     {
//         a = x;
//         b = y;
//         *ptr  = z;
//     }
//     void display()
//     {
//         std::cout<<a<<" "<<b<<" "<<ptr<<std::endl;
//     }

//     A(A &o)
//     {
//         a = o.a;
//         b = o.b;
//         ptr = new int();
//         *(ptr) = *(o.ptr);
//         std::cout<<"Copy Constructor Executed"<<std::endl;
//     }

// };


// int main()
// {
//     A a;
//     a.set(10,20,30);
//     a.display();
//     A a1(a);
//     a1.display();
//     return 0;
// }

//         for( j = 1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for( j=1;j<=b-i;j++)
//         {
//             std::cout<<"*";
//         }
//          b --;
//         space ++;
//         std::cout<<std::endl;
//     }



//     return 0;
// }


// template<typename t>
   
//     void funct(t a,t b)
//     {
//         std::cout<<a<<" "<<b<<std::endl;
//     }

// int main()
// {
//     funct(10,90);
//     return 0;
// }

// int main()
// {
//     int i,j,score;
//     score  = 30;
//     int a = 0;
//     for(i = 1;i <=7;i++)
//     {
//         for(j = 1;j <= score;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j = 1;j <= a+i; j++)
//         {
//             std::cout<<"*";
//         }
//         a ++;
//         score --;
//         std::cout<<std::endl;

//     }

//     score = 25;
//     a = 12;

//     for(i=1; i <=6;i++)
//     {
//         for(j = 1; j<= score;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j = 1; j<= a-i; j++)
//         {
//             std::cout<<"*";
//         }
//          std::cout<<std::endl;
//          a --;
//          score++;
//     }
   
//     return 0;
// }


// class A
// {
//     public:
//     int a,b,*ptr;
//     A()
//     {
//         ptr = new int();
//         std::cout<<"Constructor Executed"<<std::endl;
//     }

//     void set(int x,int y,int z)
//     {
//         a = x;
//         b = y;
//         *ptr = z;
//     }

//     void display()
//     {
//         std::cout<<a<<" "<<b<<" "<<ptr<<std::endl;
//     }

//     A(A &obj)
//     {
//         a = obj.a;
//         b = obj.b;
//         ptr = new int();
//         *(ptr) = *(obj.ptr);
//         std::cout<<"Copy Constructor Executed"<<std::endl;
//     }
// };

// int main()
// {
//     A a;
//     a.set(10,20,30);
//     a.display();
//     A a1(a);
//     a1.display();
//     return 0;
// }





// using namespace std;
// int main()
// {
//     int i, j, space;
//     int x = 0;
//     space = 11;
//     for(i=1; i<=6; i++)
//     {
//         for(j=1; j<=space; j++)    //this loop contain space from left side of windows with the help of cout<<" "
//         {
//             cout<<" ";  // jdr yeh spaces print ho gai ha udr kuch ni print ho ga usa sa aga print ho ga sab kuch
//         }
//         for(j=1; j<=(i+x); j++)  //left space ka aga staric print karana han              or j <= i + new      (int new = 0;            new ++)
//         {
//             cout<<"*";
//         }
//         space--;
//         x ++;
//         cout<<endl;
//     }

//     space = 7;
//     static int z = 10;
//     for(int i = 1;i<=5;i++)
//     {
//         for(int j = 1;j<=space;j++)
//         {
//             cout<<" ";
//         }
//         for(j=1; j<=(z - i); j++)  //left space ka aga staric print karana han
//         {
//             cout<<"*";
            
//         }
//         space++;
//         z --;
//         cout<<endl;
//     }   
//     return 0;
// }

// class A
// {
//     public:
//     virtual void display()
//     {
//         std::cout<<"This is a base class"<<std::endl;
//     }
// };

// class B:public A
// {
//     public:
//     void display()
//     {
//         std::cout<<"This is a derived class"<<std::endl;
//     }
// };

// void greeting(A &a)
// {
//     a.display();
// }


// int main()
// {
//     A a;
//     B b;
//     a.display();
//     b.display();
//     A *ptr = new B();
//     ptr -> display();
//     greeting(a);
//     greeting(b);
//     return 0;
// }

// class A
// {
//     public:
//     int a,b,*ptr;

//     A()
//     {
//         ptr = new int();
//         std::cout<<"Constructor Executed"<<std::endl;
//     }

//     void set(int x,int y,int z)
//     {
//         a = x;
//         b = y;
//         *ptr  = z;
//     }
//     void display()
//     {
//         std::cout<<a<<" "<<b<<" "<<ptr<<std::endl;
//     }

//     A(A &o)
//     {
//         a = o.a;
//         b = o.b;
//         ptr = new int();
//         *(ptr) = *(o.ptr);
//         std::cout<<"Copy Constructor Executed"<<std::endl;
//     }

// };


// int main()
// {
//     A a;
//     a.set(10,20,30);
//     a.display();
//     A a1(a);
//     a1.display();
//     return 0;
// }



// int main()
// {
//     int i,j,score;
//     score = 50;
//     int p=0;
    
//     for(i=1;i<=50;i++)
//     {
//         for(j=1;j<=score;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=(i+p);j++)
//         {
//             std::cout<<"*";
//         }
//         p++;
//         score--;
//         std::cout<<std::endl;
//     }

//     score = 1;
//     p = 105;

//     for(i=1;i<=55;i++)
//     {
//         for(j=1;j<=score;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=(p-i);j++)
//         {
//             std::cout<<"*";
//         }
//         p --;
//         score ++;
//         std::cout<<std::endl;
//     }
//     return 0;
// }



// #include <iostream>
// #include <string> // Needed to use strings
// #include <cstdlib> // Needed to use random numbers
// #include <ctime>
// using namespace std;
 
// void drawLine(int n, char symbol)
// {
//     for(int i=0; i<n; i++)
//         cout << symbol;
//     cout << endl ;
// }
 
// void rules()
// {
//     cout << "\n\n";
//     drawLine(80,'-');
//     cout << "\t\t\tRULES OF THE GAME\n";
//     drawLine(80,'-');
//     cout << "\t1. Choose any number between 1 to 10\n";
//     cout << "\t2. If you win you will get 10 times of money you bet\n";
//     cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
//     drawLine(80,'-');
// }
 
// int main()
// {
//     int amount; // hold player's balance amount
//     int bettingAmount; 
//     int guess;
//     int dice; // hold computer generated number
//     char choice;
 
//     srand(time(0)); // "Seed" the random generator

//     drawLine(60,'_');
//     cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
//     drawLine(60,'_');
 
    // cout << "\n\nEnter Your Name : ";
    // getline(cin, playerName);
 
//     cout << "\n\nEnter Deposit amount to play game : $";
//     cin >> amount;
    
//     do
//     {
//         rules();
//         cout << "\n\nYour current balance is $ " << amount << "\n";
		
// 		// Get player's betting amount
//         do
//         {
//             cout <<"Enter money to bet : $";
//             cin >> bettingAmount;
//             if(bettingAmount > amount)
//                 cout << "Your betting amount is more than your current balance\n"
//                        <<"\nRe-enter data\n ";
//         }
//         while(bettingAmount > amount);
 
// 		// Get player's numbers
//         do
//         {
//             cout << "Guess your number to bet between 1 to 10 :";
//             cin >> guess;
//             if(guess <= 0 || guess > 10)
//                 cout << "Please check the number!! should be between 1 to 10\n"
//                     <<"\nRe-enter data\n ";
//         } 
//         while(guess <= 0 || guess > 10);
 
//         dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10
    
//         if(dice == guess)
//         {
//             cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
//             amount = amount + bettingAmount * 10;
//         }
//         else
//         {
//             cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
//             amount = amount - bettingAmount;
//         }
 
//         cout << "\nThe winning number was : " << dice <<"\n";
//         cout <<", You have $ " << amount << "\n";
//         if(amount == 0)
//         {
//             cout << "You have no money to play ";
//             break;
//         }
//         cout << "\n\n-->Do you want to play again (y/n)? ";		
//         cin >> choice;
//     }
//     while(choice =='Y'|| choice=='y');
    
//     cout << "\n\n\n";
//     drawLine(70,'=');
//     cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
//     drawLine(70,'=');
 
//     return 0;
// }
 


// class Base
// {
//     public:
//     int a,b,*ptr;

//     Base()
//     {
//         ptr = new int();
//         std::cout<<"Constructor Executed"<<std::endl;
//     }
//     void set(int x,int y,int z)
//     {
//         a = x;
//         b = y;
//         *ptr = z;
//     }
//     void display()
//     {
//         std::cout<<a<<" "<<b<<" "<<ptr<<std::endl;
//     }
//     Base(Base &obj)
//     {
//         a = obj.a;
//         b = obj.b;
//         ptr =  new int();
//         *(ptr) = *(obj.ptr);
//         std::cout<<"Copy Constructor Executed"<<std::endl;
//     }
// };

// int main()
// {
//     Base b;
//     b.set(10,20,30);
//     b.display();
//     Base b1(b);
//     b1.display();
//     return 0;
// }


// int main()
// {
//     int i,j,space = 5;
//     int a = 0;
//     for(i=1;i<=6;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=i+a;j++)
//         {
//             std::cout<<"a";
//         }
//         std::cout<<std::endl;
//         a++;
//         space--;
//     }

//     space = 1;
//     a = 10;
//     for(i=1;i<=5;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=a-i;j++)
//         {
//             std::cout<<"a";
//         }
//         std::cout<<std::endl;
//         a--;
//         space++;
//     }
//     return 0;
// }

// class Base
// {
//     public:
//     int a,b,*ptr;

//     Base()
//     {
//         ptr = new int();
//         std::cout<<"Constructor Executed"<<std::endl;
//     }

//     void set(int x,int y,int z)
//     {
//         a = x;
//         b = y;
//         *ptr = z;
//     }

//     void display()
//     {
//         std::cout<<a<<" "<<b<<" "<<ptr<<std::endl;
//     }

//     Base(Base &obj)
//     {
//         a = obj.a;
//         b = obj.b;
//         ptr =  new int();
//         *(ptr) = *(obj.ptr);
//         std::cout<<"Copy Constructor Executed"<<std::endl;
//     }
// };

// int main()
// {
//     Base b;
//     b.set(14,15,258);
//     b.display();
//     Base b1(b);
//     b1.display();
//     return 0;
// }



// class Base
// {
//     public:
//     int a,b,*ptr;

//     Base()
//     {
//         ptr = new int();
//         std::cout<<"Constructor Executed"<<std::endl;
//     }

//     void set(int x,int y,int z)
//     {
//         a = x;
//         b = y;
//         *ptr = z;
//     }

//     void display()
//     {
//         std::cout<<a<<" "<<b<<" "<<ptr<<std::endl;
//     }

//     Base(Base &obj)
//     {
//         a = obj.a;
//         b = obj.b;
//         ptr = new int();
//         *(ptr) = *(obj.ptr);
//         std::cout<<"Copy Constructor Executed"<<std::endl;
//     }
// };

// int main()
// {
//     Base b;
//     b.set(10,20,30);
//     b.display();
//     Base b1(b);
//     b1.display();
//     return 0;
// }

// int main()
// {
//     int a = 10,b = 20;

//     auto c = [a,b](int x,int z)
//     {
//         std::cout<<a<<" "<<b<<" "<<x<<" "<<z<<std::endl;
//     };
//     c(30,40);
// return 0;
// }


// int main()
// {
//     int i,j,space;
//     space = 5;
//     int a = 0;

//     for(i=1;i<=6;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=i+a;j++)
//         {
//             std::cout<<"*";
//         }
//         std::cout<<std::endl;
//         space--;
//         a++;
//     }

//     space = 1;
//     a = 10;
//     for(i=1;i<=5;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=a-i;j++)
//         {
//             std::cout<<"*";
//         }
//         std::cout<<std::endl;
//         space++;
//         a--;
//     }   


//      space = 5;
//      a = 0;

//     for(i=1;i<=6;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=i+a;j++)
//         {
//             std::cout<<"*";
//         }
//         std::cout<<std::endl;
//         space--;
//         a++;
//     }

//     space = 1;
//     a = 10;
//     for(i=1;i<=5;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=a-i;j++)
//         {
//             std::cout<<"*";
//         }
//         std::cout<<std::endl;
//         space++;
//         a--;
//     }


//          space = 5;
//      a = 0;

//     for(i=1;i<=6;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=i+a;j++)
//         {
//             std::cout<<"*";
//         }
//         std::cout<<std::endl;
//         space--;
//         a++;
//     }

//     space = 1;
//     a = 10;
//     for(i=1;i<=5;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=a-i;j++)
//         {
//             std::cout<<"*";
//         }
//         std::cout<<std::endl;
//         space++;
//         a--;
//     }


//          space = 5;
//      a = 0;

//     for(i=1;i<=6;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=i+a;j++)
//         {
//             std::cout<<"*";
//         }
//         std::cout<<std::endl;
//         space--;
//         a++;
//     }

//     space = 1;
//     a = 10;
//     for(i=1;i<=5;i++)
//     {
//         for(j=1;j<=space;j++)
//         {
//             std::cout<<" ";
//         }
//         for(j=1;j<=a-i;j++)
//         {
//             std::cout<<"*";
//         }
//         std::cout<<std::endl;
//         space++;
//         a--;
//     }
//     return 0;
// }



// using namespace std;

// void buildVec(vector<int> &vec, int n)
// {
//   for (int i = 1; i <= n; i++) 
//   {
//     vec.push_back(rand() % 100 + 1);
//   }
// }

// void printVec(vector<int> &vec)
//  {
//   for (const int n : vec) 
//   {
//     cout << n << " ";
//   }
// }

// int main ()
// {
//   srand(time(0));
//   vector<int> numbers;
//   buildVec(numbers, 20);
//   printVec(numbers);
//   sort(numbers.begin(), numbers.end(), greater<int>());
//   cout << endl << endl;
//   printVec(numbers);
//   cout<<endl;
//   return 0;
// }



// #include<iostream>
// #include<memory>
// using namespace std;
// class Rectangle
// {
//     int Length;
//     int Breadth;
//     public: 
//     Rectangle(int l, int b)
//     {
//         Length = l;
//         Breadth = b;
//     }
//     int Area()
//     {
//         return Length * Breadth;
//     }
// };
// int main()
// {
//     shared_ptr <Rectangle> ptr1 (new Rectangle(10, 5));
//     cout << ptr1->Area() << endl;
//     shared_ptr <Rectangle> ptr2;
//     ptr2 = ptr1;
//     cout << "ptr1 " << ptr1->Area() << endl;
//     cout << "ptr1 " << ptr2->Area() << endl;
//     cout << ptr1.use_count() << endl;
//     cout << ptr2.use_count() << endl;
//     return 0;
// }
 



// int main()
// {
//     int row1,col1row2,col2;
//     int sum = 0;
//     std::cout<<"Enter Number Of Rows For First Matrix ";
//     std::cin>>row1;
//     std::cout<<"Enter Number Of Rows/Columns for First/Second Matrix ";
//     std::cin>>col1row2;
//     std::cout<<"Enter Number Of Columns For Second Matrix ";
//     std::cin>>col2;
//     int matrix1[row1][col1row2];
//     int matrix2[col1row2][col2];
//     int matrix3[row1][col2];

//     std::cout<<std::endl;
//     std::cout<<"Enter Values For First Matrix "<<std::endl;
//     for(int i=0;i<row1;i++)
//     {
//         for(int j=0;j<col1row2;j++)
//         {
//             std::cin>>matrix1[i][j];
//         }
//     }

//     std::cout<<std::endl;
//     std::cout<<"First Matrix Is "<<std::endl;
//     for(int i=0;i<row1;i++)
//     {
//         for(int j=0;j<col1row2;j++)
//         {
//             std::cout<<matrix1[i][j]<<" ";
//         }
//         std::cout<<std::endl;
//     }


    
//     std::cout<<std::endl;
//     std::cout<<"Enter Values For Second Matrix "<<std::endl;
//     for(int i=0;i<col1row2;i++)
//     {
//         for(int j=0;j<col2;j++)
//         {
//             std::cin>>matrix2[i][j];
//         }
//     }

//     std::cout<<std::endl;
//     std::cout<<"Second Matrix Is "<<std::endl;
//     for(int i=0;i<col1row2;i++)
//     {
//         for(int j=0;j<col2;j++)
//         {
//             std::cout<<matrix2[i][j]<<" ";
//         }
//         std::cout<<std::endl;
//     }

//     std::cout<<std::endl;
//     std::cout<<"Multiplication Of These Two Matrices Is "<<std::endl;
//     for(int i=0;i<row1;i++)
//     {
//         for(int j=0;j<col2;j++)
//         {
//             for(int k=0;k<col1row2;k++)
//             {
//                 sum = sum + matrix1[i][k] * matrix2[k][j];
//                 matrix3[i][j] = sum;
//             }
//             sum = 0;
//             std::cout<<matrix3[i][j]<<" ";
//         }
        
//         std::cout<<std::endl;
//     }

//     //  for(int i=0;i<row1;i++)
//     // {
//     //     for(int j=0;j<col2;j++)
//     //     {
//     //         std::cout<<matrix3[i][j]<<" ";
//     //     }
//     //     std::cout<<std::endl;
//     // }
//     return 0;
// }





























// ctrl + alt + t








