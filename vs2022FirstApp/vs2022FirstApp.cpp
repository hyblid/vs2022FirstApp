#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

const int STRAVG = 30;

void exhausted()
{
	cout << "Exhausted the free store." << endl;
}

void main()
{
	int** class_grades = 0;
	char** student_names = 0;
	string name;
	int num_students = 0;
	int num_tests = 0;
	int i = 0, j = 0;

	set_new_handler(exhausted);

	cout << "Enter the number of students in your class: ";
	cin >> num_students;
	cout << "Enter the number of tests you gave this semester: ";
	cin >> num_tests;
	cout << endl;

	if (!num_students || !num_tests)
	{
		cout << "You entered 0 for one of the fields. Goodbye.\n";
		exit(0);
	}

	// allocate the space for ppbufs
	student_names = new char* [num_students + 1];
	class_grades = new int* [num_students + 1];

	for (i = 0; i < num_students;i++)
	{
		cout << "Enter name of student " << i << ": ";
		cin.ignore(100, '\n');
		getline(cin, name);
		student_names[i] = new char[name.length() + 1];
		strcpy(student_names[i], name.c_str());
		// allocate space for the 1d int array
		class_grades[i] = new int[num_tests];

		for (j = 0; j < num_tests; j++)
		{

			cout << "Enter the students grade for test " << j << ": ";
			cin >> class_grades[i][j];
		}
	}
	cout << endl;

	/* print out what we stored. See Exercise 1 to expand
	upon this program.  We will print out the information
	differently than we received it. */
	for (i = 0; i < num_tests; i++)
	{
		cout << "On test #" << i << "..." << endl;
		for (j = 0; j < num_students; j++)
			cout << "\t" << student_names[j]
			<< " scored " << class_grades[j][i] << endl;
	}
}

