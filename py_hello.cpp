#include<string>
#include<boost/python.hpp>

using namespace std;
using namespace bp = boost::python;

char const * greet() {
    return "hello,world";

}

bp::BOOST_PYTHON_MODULE(py_hello) {
    bp::def("greet", greet);
}
