#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
struct Account {
public:
	std::string first_name = "";
	std::string last_name = "";
	std::string password = "";
	std::string email = "";
	//bool equals(const Account& account) {
	//	return (email == account.email);
	//}

	bool operator==(const Account& account) const {
		return email == account.email;
	}
};