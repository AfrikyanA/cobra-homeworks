#include <iostream>
#include <fstream>

int main()
{
	std::fstream f("1mbFile.txt");
	
	size_t integersN = 100000;
	int number;
	for (int i = 0; i < integersN; ++i){
		number = rand() % integersN + 1;
		f << number;
		f << std::endl;
	}
	f.close();
}