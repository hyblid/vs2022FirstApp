#pragma once
#include <iostream>
struct AppErrors {
	char* msg;
	int severity;
};

class error {
protected:
	static AppErrors StdErrors[];
	static int numErrors;
	int stdidx;
	char File[80];
	int Line;
public:
	error();
	void StandardError(int index, const char * thefile = "UNKNOWN", int theline = 0, std::ostream& stream = std::cerr);
	void CustomError(char* msg, int level, const char* thefile = "UNKNOWN", int theline = 0, std::ostream& stream = std::cerr);
};