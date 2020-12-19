#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
#include<cstdlib>
#include<iostream>

#include "Function.hpp"
#include "Zetacompiler.hpp"
#include "Token.hpp"


class func{
	private:
		long int argcnt = 0;
		std::string functionname;
		std::vector<token> functionargs;
		std::vector<token> functionbody;

	public:
		// Constructor
		func(std::vector<token> argvect, std::string name, std::vector<token> functokens){
			functionargs = argvect;
			for(token x: argvect){
				if(x.type != 7){
					argcnt++;
				}
			}

			functionname = name;
			functionbody = functokens;

		}
		// Deconstructor
		~func(void){}


		std::string fname(void){
			return functionname;
		}
		std::vector<token> ret(void){
			return functionbody;
		}

		long int argcount(void){
			return argcnt;
		}

		std::vector<token> getarg(void){
			return functionargs;
		}

};

token lookup(token var, std::vector<token> identifiers, std::vector<token> args){
	long int index = 0;
	for(token id: identifiers){
		if(id == var){
			return args.at(index);
		}else{
			index++;
		}
	}
	token tk("NULL",-1);
	return tk;
}
/*
	argsname ex a, b, c : identifiers
	argsvar  ex 2, 4, 8 : Nums to replace identifiers 
	fbody    ex a+b+c   : the function
*/
std::vector<token> fillvars(std::vector<token> argsname, std::vector<token> argsvar, std::vector<token> fbody){
	if(argsname.size() == 0) return fbody; // Return if there are no arguments
	std::vector<token> output;
	token varfilldata;
	while(!fbody.empty()){
		switch(fbody.front().type){
			case 5:
				varfilldata = lookup(fbody.front(), argsname, argsvar);
				if(varfilldata.type == -1){
					output.push_back(fbody.front());
					fbody.erase(fbody.begin());
					break;
				}
				output.push_back(varfilldata);
				fbody.erase(fbody.begin());
				break;
			default:
				output.push_back(fbody.front());
				fbody.erase(fbody.begin());
				break;
		}
	}
	return output;
}



std::vector<func> nfunctions; // Callable normal functions

// Wrapper functions

// delete function
void udef(std::string name){
	unsigned long int idx = 0;
	for(func f_id: nfunctions){
		if(f_id.fname() == name){
			nfunctions.erase(nfunctions.begin()+idx);
		}
		idx++;
	}
}

void def(std::vector<token> assignTo, std::vector<token> body){ // Input must go through lexical analyzer and tokenComp
	std::string name = assignTo.front().data;
	assignTo.erase(assignTo.begin()); assignTo.erase(assignTo.begin());// Erase name and first bracket
	assignTo.pop_back(); // Erase end bracket
	func obj(assignTo,name,body); // Create function object
	nfunctions.push_back(obj);	

}


// call function returns body list of tokens with vars filled
// format = funcname(, arg1, arg2, ...
std::vector<token> call(std::vector<token> fargs, std::string name){
	unsigned long int idx = 0;
	for(func f_id: nfunctions){
		if(f_id.fname() == name){
			return fillvars(nfunctions.at(idx).getarg(), fargs, nfunctions.at(idx).ret());
		}
		idx++;
	}
	std::vector<token> nullvec;
	return nullvec;
}


long int argcount(std::string name){
	unsigned long int idx = 0;
	for(func f_id: nfunctions){
		if(f_id.fname() == name){
			break;
		}
		idx++;
	}
	return nfunctions.at(idx).argcount();
}
