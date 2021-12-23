// dissect.cpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

void exhausted()
{
	cout << "Exhausted the free store." << endl;
	exit(0);
}

// strdup will allocate a copy of the input string.
char* strdup(char* instr)
{
	char* outstr = 0;

	if (!instr)
	{
		cerr << "strdup: FATAL - NULL argument!" << endl;
		return(0);
	}

	outstr = new char[strlen(instr) + 1];
	strcpy(outstr, instr);

	return(outstr);
}

/* ***********************************************************
	 FUNCTION NAME:  file2ppbuf
	 PURPOSE:  read a text file into a character pointer pointer buffer.
	 INPUT:  filename - a character string of the file to open.
	 OUTPUT:  a character pointer pointer which points to the
			  null-terminated ppbuf.
	 NOTE: this function allocates memory.
	 AUTHOR: MCD
	************************************************************ */
char** file2ppbuf(char* filename)
{
	FILE* fp;

	char str[512];
	char** buf = 0;
	char** tmp = 0;

	int linechunk = 100;
	int cnt = 0, len = 0;

	if (!filename)
	{
		cerr << "file2ppbuf:FATAL - filename is NULL!" << endl;
		return(0);
	}

	if ((fp = fopen(filename, "r")) == 0)
	{
		cerr << "file2ppbuf: FATAL - cannot open " << filename
			<< endl;
		return(0);
	}

	buf = new char* [linechunk];
	cnt = 0;
	while (!feof(fp))
	{
		if (fgets(str, 500, fp))
		{
			len = strlen(str);
			buf[cnt] = new char[len + 1];
			strcpy(buf[cnt], str);
			cnt++;
			if (cnt >= linechunk)
			{
				/* reallocate in quantities of 100 */
				tmp = new char* [linechunk + 100];
				memcpy(tmp, buf, sizeof(char*) * cnt);
				delete buf;
				buf = tmp;
				linechunk += 100;
			}
		}
	}

	buf[cnt] = 0;

	fclose(fp);
	return(buf);
}

/* ***********************************************************
	 FUNCTION NAME:  delete_ppbuf
	 PURPOSE:  delete each string and the array of pointers that
			   make up a ppbuf.
	 INPUT:  inbuf - a character pointer pointer buffer to be freed.
			count - the number of lines in the ppbuf.  If 0 it will
					expect the ppbuf to be null-terminated.
	 OUTPUT:  none.
	 AUTHOR: MCD
	************************************************************ */
void delete_ppbuf(char** inbuf, int count)
{
	int i;

	if (inbuf)
	{
		if (count > 0)
		{
			for (i = 0; i < count; i++)
				delete inbuf[i];
			delete inbuf;
		}
		else
		{
			for (i = 0; inbuf[i]; i++)
				delete inbuf[i];
			delete inbuf;
		}
	}
}


/* ***********************************************************
	 FUNCTION NAME:  main for dissect.cpp
	 PURPOSE:  read in any C source file and count the number
			   of words, statements, blocks and comments in
			   the source file.
	 INPUT:  none.
	 OUTPUT:  none.
	 AUTHOR: MCD
	************************************************************ */
void main()
{
	char source[80];
	char* dot = 0;
	char** src_ppbuf = 0;
	char last_char = '~';

	int i = 0, j = 0;
	int words = 0, statements = 0, blocks = 0, comments = 0;

	short int alnum = 0;

	cout << "Source file to dissect? ";
	cin >> source;
	if (!(strlen(source)))
	{
		cerr << "dissect: FATAL - No file to dissect!"
			<< endl;
		exit(0);
	}

	dot = strrchr(source, '.');
	if (!dot || strcmp(dot, ".cpp"))
	{
		cerr << "dissect: FATAL - source file must end in .cpp!"
			<< endl;
		exit(0);
	}

	src_ppbuf = file2ppbuf(source);
	if (!src_ppbuf)
	{
		cerr << "dissect: FATAL - file2ppbuf failed!" << endl;
		exit(0);
	}

	cout << "Dissecting ... ";
	cout.flush();
	/* go through all the lines in the file */
	for (i = 0; src_ppbuf[i]; i++)
	{
		for (j = 0; src_ppbuf[i][j]; j++)
		{
			if (isalnum(src_ppbuf[i][j]))
				alnum = 1;
			else if (isspace(src_ppbuf[i][j]))
			{
				if (alnum)
				{
					words++;
					alnum = 0;
				}
			}
			else if (ispunct(src_ppbuf[i][j]))
			{
				switch (src_ppbuf[i][j]) {
				case ';':
					statements++;
					break;
				case '{':
					blocks++;
					break;
				case '*':
					if (last_char == '/')
						comments++;
					break;
				case '/':
					if (last_char == '/')
						comments++;
					break;
				} /* end of switch */
			} /* end of if */
			last_char = src_ppbuf[i][j];
		} /* end of for all chars on line */
	} /* end of for all lines */

	cout << "Done." << endl;

	cout << "+---------- " << source << " ----------+" << endl;
	cout << "Number of words      : " << words << endl;
	cout << "Number of statements : " << statements << endl;
	cout << "Number of blocks     : " << blocks << endl;
	cout << "Number of comments   : " << comments << endl;
	cout << "+--------------------------------------+" << endl;

	delete_ppbuf(src_ppbuf, 0);
}
