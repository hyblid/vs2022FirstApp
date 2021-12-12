#include <iostream>
#include <cassert>

const int MAX = 255;
class String {
protected:
	char _storage[MAX + 1];
	int _sz;

public:
	String() {
		_sz = 0;
	}

	String(char* instr) {
	 	if (instr) {
			_sz = strlen(instr);
			assert(_sz < MAX);
			strcpy(_storage ,instr);
		}
		else {
			_sz = 0;
		}
	}

	~String() { _sz = 0; }
	
	char& operator[] (int index) {
		assert(index < _sz);
		assert(index >= 0);
		return _storage[index];
	}

	operator char* () {
		return _storage;
	}

	friend std::ostream& operator << (std::ostream& stream, String& inobj) {
		stream << inobj._storage;
		return stream;
	}

	void oldcopy(char* instr) {
		int len = 0;
		char* sptr = _storage;
		if (instr)
		{
			len = strlen(instr);
			assert(len < MAX);
			_sz = len;
		    while ((*sptr++ = *instr++) != '\0');
		}
	}

	String& operator=(String& inobj) {
		int i = 0;
		char* sptr = _storage;
		char* instr = inobj._storage;

		_sz = inobj._sz;
		while ((*sptr++ = *instr++) != '\0');
		return *this;
	}
	
	String& operator=(char* instr) {
		int len = 0;
		char* sptr = _storage;
		if (instr)
		{
			len = strlen(instr);
			assert(len < MAX);
			_sz = len;
			while ((*sptr++ = *instr++) != '\0');
		}
	}

	void pad(char pad_char, int pad_len) {
		int i = 0;
		assert(pad_len < MAX);
		for (int i = _sz; i < pad_len; i++)
		{
			_storage[i] = pad_char;
		}
			_storage[pad_len] = '\0';
	}

	int slen() {
		int i;
		for (i = 0; *(_storage); i++) {
			return (i);
		}
	}

	int search(char* word) {
		int idx, i, j;
		char* searchstr = _storage;
		for (i = 0; searchstr[i]; i++)
		{
			if (searchstr[0] == word[j])
			{
				if (!j) idx = i;
				j++;
			} 
			else {
				j = 0;
			}

			if (word[j] == '\0')
			{
				break;
			}
		}

		if (word[j] != '\0') {
			return (-1);
		}
		else {
			return (idx);
		}
	}

	String reverse() {
		int i = 0, len = 0;
		String temp;
		char* reverse = temp._storage;
		char* instr = _storage;

		len = _sz;
		reverse[len] = '\0';
		while (instr[i] != '\0')
		{
			reverse[--len] = instr[i++];
		}
		return temp;
	}
};