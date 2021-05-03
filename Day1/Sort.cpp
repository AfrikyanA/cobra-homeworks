#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <utility>


std::pair<int,int> min_value(const std::vector<int>& v){
	
	int min = v[0];
	int index = 0;
	for(int i = 1; i < v.size(); ++i){
		if(min > v[i]){
			min = v[i];
			index = i;
		}
	}
	return std::pair<int, int>(index, min);
}

int main() {
	
	std::vector<std::fstream> files(10);
	
	//divide and sort
	std::fstream input;
	std::string iFileName = "1mbFile.txt";
    input.open(iFileName);
	
	if (!input.is_open()){
		std::cout << "cant open " << iFileName << std::endl;
		std::abort();
	}
	
	for (int i = 0; i < 10; ++i) {
            files[i].open(std::to_string(i+1) + ".txt");
        }
	
	
	std::multiset<int> input100kb;
	
	for(int i = 0; i < 10; ++i){ 
		
		for(int j = 0; j < 10000; ++j){ 
			int tmp;
			input >> tmp;
			input100kb.insert(tmp);
		}
		
		for (auto& it:input100kb) {
                files[i] << it << std::endl;
       	}
        input100kb.clear();
	}
	
	for (int i = 0; i < 10; ++i) {
            files[i].close();
        }
	
	input.close();
	//divide and sort 
	
	//merge
	
	std::fstream output;
	
	std::string oFileName = "SortedFile.txt";
	output.open(oFileName);
	
	if (!output.is_open()){
		std::cout << "cant open " << oFileName << std::endl;
		std::abort();
	}
	
	for (int i = 0; i < 10; ++i) {
    	files[i].open(std::to_string(i+1) + ".txt");
		if(!files[i].is_open()){
			std::cout << "cant open " << i+1 << ".txt" << std::endl;
			std::abort();
		}
    }
	
	std::vector<int> vec(10,0);
	std::pair<int, int> p(-1,-1);
	
	for (int i = 0, val = 0; i < 100000; ++i){
		for (int j = 0; j < 10; ++j){
			if(p.second == -1){ 
				files[j] >> val;
				vec[j] = val;
			}
			else if (j == p.first){
				files[j] >> val;
				vec[j] = val;
				break;
			}
		}
		p = min_value(vec);
		output << p.second << std::endl;
				
	}
	//merge
	output.close();
	for (int i = 0; i < 10; ++i) {
            files[i].close();
        }
}
