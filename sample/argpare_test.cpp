#include "../source/argparse/argparse.hpp"
#include <iostream>
using namespace std;

/**
 * @brief testing program for argParse in c++ 17
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv){
    ArgumentParser parser;
    parser.add_argument<int>("arg1").help("positional argument arg1");
    parser.add_argument<double>("-arg2","--argument2").choices<double>({0.1,0.2}).help("argument 2 with choices in [0.1,0.2]");
    parser.add_argument<char>("-arg3","--argument3").default_<char>('A').help("character argument with default value A");
    parser.add_argument<long long>("-arg4","--argument4").required().help("argument but is required");
    parser.add_argument<int>("-arg5","--argument5").nArgs('+').help("argument with multi-params");
    parser.add_argument<bool>("-d","--debug").help("debug args");

    parser.parse_args(argc,argv);

    cout << parser.get_value<int>("arg1") << endl;
    cout << parser.get_value<double>("arg2") << endl;
    cout << parser.get_value<char>("argument3") << endl;
    cout << parser.get_value<long long>("arg4") << endl;
    auto arg5 = parser.get_values<int>("arg5");
    for(auto it:arg5)
        cout << it << " ";
    cout << endl;
    cout << parser.get_value<bool>("d") << endl;

}