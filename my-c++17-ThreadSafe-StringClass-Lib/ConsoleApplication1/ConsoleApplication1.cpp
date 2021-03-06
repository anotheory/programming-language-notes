// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "..\StaticLib1\StaticLib1.h"
// #include "..\StaticLib1\StaticLib1.cpp"
#include "iostream"
#include "string"
using namespace std;
using namespace NsString;

int g_int = 0;
String g_s1;

void threadFunc(const char *param1) {
	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	String pp(to_string(++g_int).c_str());
	g_s1 = pp;
}

int main() {

	{
		String s1;	cout << s1 << s1.size() << endl;

		String s2("hello world");	cout << s2 << s2.size() << endl;
		String *p = new String("abc");	cout << *p << p->size() << endl;

		String s3(s2);	cout << s3 << s3.size() << endl;

		cout << "s3 " << s3 << s3.size() << endl;
		String s4(move(s3));
		cout << "s4 " << s4 << s4.size() << endl;
		cout << "s3 " << s3 << s3.size() << endl;
	}

	{
		{String s1("abc");	String s2("abc");	cout << s1.compare(s2) << endl; }
		{String s1("abc");	String s2("ABC");	cout << s1.compare(s2) << endl; }
		{String s1("ABC");	String s2("abc");	cout << s1.compare(s2) << endl; }

		{String s1("abc");	String s2("abcd");	cout << s1.compare(s2) << endl; }
		{String s1("abcd");	String s2("abc");	cout << s1.compare(s2) << endl; }
	}

	{
		{String s1("abc"), s2; s2 = s1; }
	}

	{
		std::thread t1(threadFunc, "t1");
		std::thread t2(threadFunc, "t2");
		t1.join();
		t2.join();

		cout <<"g_int: "<< g_int << '\n';
	}

	return 0;
}
