//#include <iostream>
//#include <iomanip>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//
//#include "error.h"
//
////AppErrors error::StdErrors[] = { {"Out of Memory", 1},{"Nul Argument", 0},{"Illegal Input", 0} };
//int error::numErrors = 3;
//
//error::error() {}
//
//void error::StandardError(int index, const char* thefile, int theline, std::ostream& stream) {
//	assert(index < numErrors);
//	stream << StdErrors[index].msg << std::endl;
//	stream << "Error in " << thefile << " at line # " << theline << std::endl;
//	if (StdErrors[index].severity >0)
//	{
//		stream << "Fanal Error, exiting" << std::endl;
//		exit(StdErrors[index].severity);
//	}
//	stdidx = index;
//	strcpy(File, thefile);
//	Line = theline;
//}
//void error::CustomError(char* msg, int level, const char*  thefile, int theline, std::ostream& stream) {
//	stream << msg << std::endl;
//	stream << "Error in " << thefile << " at line # " << theline << std::endl;
//	if (level > 0) {
//		stream << "Fatal Error, exiting" << std::endl;
//		exit(level);
//	}
//	stdidx = -1;
//	strcpy(File, thefile);
//	Line = theline;
//}