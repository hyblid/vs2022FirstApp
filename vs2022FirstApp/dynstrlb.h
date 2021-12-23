// dynstrlb.h
#ifndef _dynstrlibh
#define _dynstrlibh
#include <iostream>

using std::istream;
using std::ostream;

class String {
private:
	char* _str;
	int _len;
public:
	String();
	String(char* instring);
	~String();

	// anytime you use dynamic memory in a class you MUST
	// provide a copy constructor and overload the assignment
	// operator

	// copy constructor
	String(String& other);

	// overload the assignment operator
	String& operator = (String& other);
	String& operator = (const char* instr);

	operator char* ();
	String operator + (String& ss);
	String operator + (char* ss);
	String operator - (String& ss);
	String operator - (char* ss);
	short operator == (String& ss);
	short operator == (char* ss);
	short operator != (String& ss);
	short operator != (char* ss);
	short operator > (String ss);
	short operator < (String ss);
	char& operator [](int index);
	char* Strdup();
	String Substr(int start, int numchars);
	void getline(istream& stream);
	int getlen();
	int Strindex(char* word);
	friend ostream& operator << (ostream& stream, String& obj);
	friend istream& operator >> (istream& stream, String& obj);
};

#endif
