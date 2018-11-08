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
	cin >> L;
	cout << L;
	


	return 0;
}