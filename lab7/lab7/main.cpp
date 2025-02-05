#include "Persons/receipt.h"

int main(int argc, char* argv[]) {
    system("chcp 65001>nul");
	Person Person1("doc1", 123012);
    Person Person2("doc2", 341220);
	wayBill waybill("wb", 342345, true);
	PayCheck paycheck("pc", 232312, false);
	Receipt receipt("rec", 121230, false, true, 23.5, "Alex");
	
	Person::printArray();
	return 0;
}