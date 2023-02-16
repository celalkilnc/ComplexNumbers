#include <math.h>
#include <string> 
#include <iostream>

using namespace std;
int main()
{
	ComplexNum cmp1, cmp2, result;

	string option = MainMenuMethod();
	cmp1 = SetValue("1");
	cmp2 = SetValue("2");

	if (option != "5"){ 
		//Operation control
		result = ComplexNumTransaction(cmp1, cmp2, option);
		result.print();
	}
	else {
		system("cls");
		cmp1.Polar();
	}

	string orientation;
	cout << "Please press '0' to return to the previous menu...." << endl;
	cout << "If you want to terminate the program, press any key and click 'Enter'..." << endl;
	cin >> orientation;

	if (orientation == "0") { return main(); }
}

// Classes
class ComplexNum
{
private:
	int _reel;
	int _imag;
public:
	void setReel(int r) { _reel = r; }
	void setImag(int i) { _imag = i; }
	
	int  getReel() { return _reel; }
	int  getImag() { return _imag; }

	void print() //print to complex number type
	{
		if (_imag > 0) 
		     { cout << _reel << " + " << _imag << "i" << endl; }
		else if (_imag < 0) 
		     { cout << _reel << " - " << _imag << "i" << endl; }
		else 		    
		     { cout << _reel << endl; }
	}

	void Polar()
	{
		int reel = _reel, imag = _imag;
		double r = sqrt(reel * reel + imag * imag);
		double Angle = reel / imag;

		cout << "Polar Representation of a Complex Number ," << endl;
		cout << "1) " << "Z = a + bi" << endl << endl;
		cout << "2) " << "|Z| = r" << endl << endl;
		cout << "3) " << "r" << " = " << "(" << reel << "(a)^2  +  " << imag << "(b)^2)^1/2" << endl << endl;
		cout << "4) " << reel << "(a) = " << "sin(Angle).r" << endl << endl;
		cout << "5) " << imag << "(b) = " << "cos(Angle).r" << endl << endl;
		cout << "6) " << "Z = r.(cos(Angle) + i.sin(Angle))" << endl << endl;

		cout << "Angle : " << Angle << " Radyan : " << (Angle * 180) / 3.14 << " Degree" << endl << endl;
		cout << "r : " << r << endl << endl << endl;

		cout << "Polar value : " << r << "(" << cos(Angle) << " Pi  +  " << sin(Angle) << "i Pi)" << endl << endl;
	}
};

// Methods
ComplexNum ComplexNumTransaction(ComplexNum obj1, ComplexNum obj2, string operation)
{
	/* 1- Addition  2- Extraction  3- Division  4- Multiplation */
	ComplexNum compnum;
	int obj1Reel = obj1.getReel(), obj2Reel = obj2.getReel(), obj1Imag = obj1.getImag(), obj2Imag = obj2.getImag();
	
	
	if (operation == "1") {
		compnum.setReel(obj1Reel + obj2Reel);
		compnum.setImag(obj1Imag + obj2.getImag());
	}
	else if (operation == "2") {
		compnum.setReel(obj1Reel - obj2Reel);
		compnum.setImag(obj1Imag - obj2Imag);
	}
	else if (operation == "3") {
		float reelsayi = obj1Reel * obj2Reel + obj1Imag * obj2.getImag();
		compnum.setReel(((obj1Reel * obj2Reel) - obj1Imag * (-1 * obj2Reel) / reelsayi));
		compnum.setImag(((obj1Reel * (-1 * obj2Imag) + obj1Imag * obj2Reel) / reelsayi));
	}
	else if (operation == "4") {
		compnum.setReel(obj1Reel * obj2Reel);
		int aritmethic = (obj2.getImag() * obj1Imag) + (obj2Reel * obj1Imag) + (obj1Reel * obj2Imag);
		compnum.setImag(aritmethic);
	}
	return compnum;
}

ComplexNum SetValue(string num)
{
	int reel, imag;
	ComplexNum comp;

	cout << "Please enter reel for " + num + ". Complex num: "; cin >> reel;
	cout << "Please enter imag for " + num + ". Complex num: "; cin >> imag;

	comp.setReel(reel);
	comp.setImag(imag);

	return comp;
}

string MainMenuMethod()
{
	system("cls");
	string options;
	
	cout << "Please choose one of the options : " << endl;
	cout << "1- Addition : " << endl;
	cout << "2- Extraction process : " << endl;
	cout << "3- Division : " << endl;
	cout << "4- Multiplication : " << endl;
	cout << "5- Polar value of complex number : " << endl;

	cin >> options;
	return options;
}
