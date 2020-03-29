#include <iostream> //for console i/o in main()
#include <ctime>	//for time 
#include <cstdlib>	//for random generator

class Dartboard {
public:

	/*
	The dartboard has a diameter of 1
	The center is set to (0.5,0.5) in a coordinate system where edges are:
	A(0,0)
	B(0,1)
	C(1,1)
	D(1,0)
	*/

	Dartboard() {
		//Sets inital seed for srand function based on machine time
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}

	void throwDart() {
		
		darts++;

		//The dart must have coordinates x and y
		//Those must be random numbers between -1 and 1, being any rational number

		//Stores the proportion between 1 and the maximum value that std::rand() will ever return
		//This proportion is used to transfrom random integers from 0 and RAND_MAX to from 0 to 1
		static constexpr double fraction = 1.0 / static_cast<float>(RAND_MAX);
		
		//A circunference of r = 0.5 and P(0.5,0.5) is defined as 0.5^2 = (x - 0.5)^2 + (y - 0.5)^2 = 0.25
		//Points inside that circle agree that 0.25 > (x - 0.5)^2 + (y - 0.5)^2

		double a = fraction * std::rand() - 0.5;
		double b = fraction * std::rand() - 0.5;
		//float x = fraction * std::rand();
		//float y = fraction * std::rand();
		//double a = x - 0.5;
		//double b = y - 0.5;

		if (0.25 > (a * a + b * b)) inside_circle++;

	}

	double getPi() {
		//The way this works is explained in the README
		return 4.0 * inside_circle / darts;
	}

private:

	unsigned long long darts{};
	unsigned long long inside_circle{};

};

int main() {

	Dartboard Dartboard1;

	unsigned long long i;
	while (true) {
		std::cout << "Darts to throw: ";
		std::cin >> i;

		//The following code just makes the interface work well

		if (std::cin.fail()) {
			//This stops std::cin from entering failure mode

			std::cin.clear(); //Puts back normal mode
			std::cin.ignore(32767, '\n'); //Removes trash input
			continue;
		}
		std::cin.ignore(32767, '\n'); //Removes trash input

		//This loop feeds the method
		while (i > 0) {
			Dartboard1.throwDart();
			i--;
		}
		std::cout << Dartboard1.getPi() << std::endl;
	}

}
