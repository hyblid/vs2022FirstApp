export module Vector;
import <iostream>;

export class Vector {
private:
	double* elem;
	int sz;
public:
	Vector(int s) : elem{ new double[s] }, sz{ s } {}
	double& operator[](int i) {
		return elem[i];
	}
	int size() const{
		return sz;
	}
};

export int size(const Vector& v) { 
	return v.size(); 
}