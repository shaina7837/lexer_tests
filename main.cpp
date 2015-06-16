#include <iostream>
#include <fstream>
#include <string>
#include "lexertl/generator.hpp"
#include "lexertl/lookup.hpp"
using namespace std;

class lexer
{
	public:
	lexertl::rules rules_;
	lexertl::state_machine sm;
	std::string token;
	
	lexer(){
	 rules_.push("[a-zA-Z]", 1);
	 rules_.push("[0-9]", 2);
	lexertl::generator::build(rules_, sm);
	}
};
int main(int argv, char* argc[]){

	ifstream newfile(argc[1]);
	ofstream output(argc[2]);
	string line;
 	getline (newfile, line, '\0');
	lexer l;
	const std::string input(line);
	lexertl::smatch results(input.begin(), input.end());
	lexertl::lookup(l.sm, results);
	while(results.id != 0)	{
		if(results.id == 1){
			output<< results.str();
		}
		if(results.id == 2){
			output << results.str();
		}
	lexertl::lookup(l.sm, results);
	}
	newfile.close();
}	
