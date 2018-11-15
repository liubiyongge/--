#include "header.h"
#include "const.h"
#include "class_function.h"
#include "Linklist.h"
#include "MyTerm.h"
#include "MyPolynomialLinklist.h"
#include "function.h"

int main(int argc, char const *argv[])
{

	srand((unsigned)time(NULL));
	MyPolynomialLinklist<MyTerm> L;
	L.randomInitalFill(1);
	cout << L;
	MyPolynomialLinklist<MyTerm> L2;
	L2.randomInitalFill(1);
	cout << L2;
	MyPolynomialLinklist<MyTerm> L3;
	L3.randomInitalFill(1);
	cout << L3;
	MyPolynomialLinklist<MyTerm> L4;
	L4 = L + L2 +  L3;
	cout << L4;
	//L4 = L4 + L3;
	//cout << L4;
	
	return 0;
}