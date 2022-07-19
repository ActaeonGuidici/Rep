#include <iostream>
#include "Abonent.h"
#include "Directory.h"

using namespace std;


int main() {
	Abonent test("DC", "Stsdveve", "5232", "USSDA", "ComWEGVs");
	Abonent test1("DfgC", "Steserve", "5422", "USDFSA", "WEFEW");
	Abonent test2("DefC", "Stesdvve", "52523", "USWSEVCA", "ECSEDs");
	Abonent test3("DvdfvC", "Stesdvve", "532522", "USWEVBA", "CWEC");

	Directory test_dir(test, 1);
	//test_dir.setAbonent(test1);
	//test_dir.setAbonent(test2);
	//test_dir.setAbonent(test3);

	//Abonent return_(test_dir.findByOwner("Stesdvve"));
	

	//test_dir.findByName("DC").print();

	//test.print();
}