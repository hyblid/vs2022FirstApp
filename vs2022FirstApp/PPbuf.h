#ifndef _PPbufh
#define _PPbufh

#include "dynstrlb.h"
#include "error.h"

class PPbuf {
protected:
	String* _Strings;
	int _len;
	int _Space;
	char terminator;
	static error PPerror;
	void GrowBuf();
public:
	PPbuf();
	~PPbuf();
	PPbuf(char** ppbuf, int pplen = 0);
	PPbuf(char* filename);
	PPbuf(String line, char* delimiters);
	PPbuf(PPbuf& other);
	PPbuf& operator = (PPbuf& other);
	operator char** ();
	String& operator[](int index);
	friend istream& operator >> (istream& stream, PPbuf& obj);
	friend ostream& operator << (ostream& stream, PPbuf& obj);
	int size();
	void AppendString(String instr);
	void AppendString(char* instr);
	PPbuf dupPPbuf(int start, int len);
	String RemoveFirst();
	String RemoveLast();
};

#define CHUNKSZ 10

#endif
