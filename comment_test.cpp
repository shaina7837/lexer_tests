
#include <iostream>
#include "lexertl/generator.hpp"
#include "lexertl/lookup.hpp"
#include <string>

int main(){
	lexertl::rules rules_;
	lexertl::state_machine sm_;

	rules_.push("[0-9]+",1); // arguments are regex for pattern matching and id for categorization of tokens
    	rules_.push("[/][/].*$", 2);
	rules_.push("[/][*].*?[*][/]", 3);
	lexertl::generator::build(rules_, sm_);
	
	std::string std_input;
	std::string line;
	std::cout << "enter Comment\n " <<std::flush;
	
	while(std::getline(std::cin, line)){
		if(line == "^D")
		break;
		std_input += line;
	}
	std::string input(std_input);
        lexertl::smatch results (input.begin(), input.end());
        lexertl::lookup(sm_, results);

        if(results.id != 0){ // id is 0 at the end of the input
			
		std::cout << "id: " << results.id <<std::endl << "token: "<<results.str() <<std::endl;
	}
}


