#include <cstdint>
#include <iostream>
#include <stdint.h>
#include <string>
#include <boost/program_options.hpp>
#include <boost/regex.hpp>

namespace  bp = boost::program_options;

int main(int argc, char const *argv[]) {
    bp::options_description opts("选项"); 
    bp::variables_map vm;

    opts.add_options()  
        ("filename", bp::value<std::string>(), "the file name which want to be found (string)")
        ("address", bp::value<int64_t>(), "the address of the host. (integer only)")
        ("help", "this is a program to find a specified file (no value)");

    try{
        bp::store(bp::parse_command_line(argc, argv, opts), vm);
    } catch(...) {
        std::cout << "输入的参数中存在未定义的, 或不符合类型的选项" << std::endl;
        std::cout << opts << std::endl; 
        return 0;
    }

    if(vm.count("help") ) {
        std::cout << opts << std::endl;   
    }

    if(vm.count("filename") ){
        std::cout << "filename : " << vm["filename"].as<std::string>() << std::endl;
    }

    if(vm.count("address") ){
        std::cout << "address : " << vm["address"].as<int64_t>() << std::endl;
    }

    if(vm.empty() ) {
        std::cout << "no options found" << std::endl;
    }

    std::string line;
    boost::regex pat( "^H" );

    while (std::cin) {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << "MATCH : " << matches[0] << std::endl;
    }

    return 0;
}
