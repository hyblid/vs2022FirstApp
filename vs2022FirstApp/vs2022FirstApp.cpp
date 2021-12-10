// vs2022FirstApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLib.h"
#include "Vctr.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <memory>
#include "console.h"
#include "Person.h"
#include "validation.h"
#include <list>
#include "Sample.cpp"

import helloWorld;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void printHelloWorld();
void myPrint();
using namespace std;
using namespace validation;

int recursive_sum(int m, int n) {
	//base case for break recursion
	if (m == n) {
		return m;
	}
	return m + recursive_sum(m + 1, n);
}

bool ascendingCompare(int a, int b) {
	return a < b;
}

bool descendingCompare(int a, int b) {
	return a > b;
}

void customSort(vector<int>& numberVector, bool (*compareFuncPtr)(int, int)) {
	for (int  startIndex = 0 ; startIndex < numberVector.size(); startIndex++)
	{
		int bestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < numberVector.size(); currentIndex++)
		{
			//we are doing comparison here
			if (compareFuncPtr(numberVector[currentIndex], numberVector[bestIndex]))
				bestIndex = currentIndex;
		}
		swap(numberVector[startIndex], numberVector[bestIndex]);
	}
}

void printNumbers(vector<int>& numberVector) {
	for (int i = 0; i < numberVector.size(); i++)
	{
		cout << numberVector[i] << ' ';
	}
}

struct YoutubeChannel {
	std::string name;
	int subscribeCount;
	YoutubeChannel(std::string name, int subscribeCount) {
		this->name = name;
		this->subscribeCount = subscribeCount;
	}
	//1.Error C2676 binary '==': 'const YoutubeChannel' does not define this operator 
	//or a conversion to a type acceptable to the predefined operator vs2022FirstApp
	//2.Error C2678	binary '==': no operator found which takes a left - hand operand of type 'const _Ty' 
	//(or there is no acceptable conversion) -----> add 2 const
	//before remove collection check demand and target are same collection
	bool operator==(const YoutubeChannel& channel) const {
		return this->name == channel.name;
	}
};

struct MyCollection {
	list<YoutubeChannel> myChannels;
	//insert dont need return
	void operator+=(YoutubeChannel& channel) {
		this->myChannels.push_back(channel);
	}
	void operator-=(YoutubeChannel& channel) {
		this->myChannels.remove(channel);
	}
};

ostream& operator<<(ostream& COUT, YoutubeChannel& channel) {
	COUT << "Name: " << channel.name << endl;
	COUT << "Subscribers: " << channel.subscribeCount << endl;
	return COUT;
}

ostream& operator<<(ostream& COUT, MyCollection& collection) {
	for (YoutubeChannel ychannel : collection.myChannels) {
		cout << "Channel Name: " << ychannel.name << endl;
		cout << "Channel subscribes: " << ychannel.subscribeCount << endl;
	}
	return COUT;
}

/// when pass array as function argument,
/// it points only first element of array
/// like A[0]
/// 

ostream& operator<<(ostream& COUT, Sample& sample) {
	cout << "sample class's two value : " << sample.getIntA() << ' ' << sample.getIntB() << endl;
	return COUT;
}

struct Movie {
    string title = "";
    unsigned int year = 0;
    unsigned int stars = 0;
    bool equals(Movie&);              // member function declaration
};

// member function definition
bool Movie::equals(Movie& to_compare) {
    return (title == to_compare.title && year == to_compare.year);
}

const string movies_file = "movies.txt";

list<Movie> read_movies_from_file() {
    list<Movie> movies;

    ifstream input_file(movies_file);
    if (input_file) {    // if file opened successfully...
        Movie movie;
        string line;
        while (getline(input_file, line)) {
            stringstream ss(line);

            getline(ss, movie.title, '\t');     // get title
            ss >> movie.year >> movie.stars;    // get year and stars
            movies.push_back(movie);            // add movie to vector
        }
        input_file.close();
    }
    return movies;
}

void write_movies_to_file(const list<Movie>& movies) {
    ofstream output_file(movies_file);
    if (output_file) {     // if file opened successfully...
        for (Movie movie : movies) {
            output_file << movie.title << '\t'
                << movie.year << '\t'
                << movie.stars << '\n';
        }
        output_file.close();
    }
}

void view_movies(const list<Movie>& movies) {
    int col_width = 8;
    cout << left
        << setw(col_width / 2) << " "
        << setw(col_width * 4) << "TITLE"
        << setw(col_width) << "YEAR"
        << setw(col_width) << "STARS" << endl;

    int number = 1;
    for (Movie movie : movies) {
        cout << setw(col_width / 2) << number
            << setw(col_width * 4) << movie.title
            << setw(col_width) << movie.year
            << setw(col_width) << movie.stars << endl;
        ++number;
    }
    cout << endl;
}

Movie get_movie() {
    Movie movie;
    cout << "Title: ";
    cin.ignore(1000, '\n');
    getline(cin, movie.title);
    cout << "Year: ";
    cin >> movie.year;
    cout << "Stars (1-5): ";
    cin >> movie.stars;
    return movie;
}

void add_movie(list<Movie>& movies) {
    Movie movie = get_movie();

    // check if movie already exists
    bool already_exists = false;
    for (Movie& m : movies) {
        if (m.equals(movie)) {
            if (already_exists = true) {
                cout << movie.title << " already exists and was updated.\n\n";
            }

            m.stars = movie.stars;
            break;
        }
    }

    if (already_exists) {
        write_movies_to_file(movies);
    }
    else {
        movies.push_back(movie);
        write_movies_to_file(movies);
        cout << movie.title << " was added.\n\n";
    }
}

int get_movie_number(const list<Movie>& movies) {
    cin.ignore(1000, '\n');
    int number;
    while (true) {
        cout << "Number: ";
        cin >> number;
        if (number > 0 && number <= movies.size()) {
            return number;
        }
        else {
            cout << "Invalid movie number. Try again.\n";
        }
    }
}

void delete_movie(list<Movie>& movies) {
    int number = get_movie_number(movies);
    auto itr = movies.begin();
    for (int i = 0; i < number -1; i++)
    {
        itr++;
    }
    Movie movie = *itr;
    movies.erase(itr);
    write_movies_to_file(movies);
    cout << movie.title << " was deleted.\n\n";
}

void display_menu() {
    cout << "COMMANDS\n"
        << "v - View movie list\n"
        << "a - Add a movie\n"
        << "d - Delete a movie\n"
        << "m - Modify a movie\n"
        << "x - Exit\n\n";
}

void modify_movie(list<Movie>& movies) {
    auto itr = movies.begin();
    int rating = 0;
    int number = get_movie_number(movies);

    for (int i = 0; i < number -1 ; i++)
    {
        itr++;
    }
    Movie movie = *itr;
    cout << "Enter new number of stars (1-5) for " << itr->title << ": ";
    cin >> rating;
    itr->stars = rating;
    write_movies_to_file(movies);
    cout << movie.title << " was updated.\n\n";
}

int main() {
    cout << "The Movie List program\n\n";
    display_menu();
    list<Movie> movies = read_movies_from_file();
    int rate = 0;
    char command = 'v';
    while (command != 'x') {
        cout << "Command: ";
        cin >> command;
        switch (command) {
        case 'v':
            view_movies(movies);
            break;
        case 'a':
            add_movie(movies);
            break;
        case 'd':
            delete_movie(movies);
            break;       
        case 'm':
            modify_movie(movies);
            break;
        case 'x':
            cout << "Bye!\n\n";
            break;
        default:
            cout << "Not a valid command. Please try again.\n\n";
            break;
        }
    }
}