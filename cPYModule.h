
#include <iostream>
#include <Python.h>
#include <unordered_map>


using namespace omnetpp;
using namespace std;



class cPYModule 
{
    public:
		std::unordered_map<const char *, unordered_map<const char *, PyObject *>> func_map;

    public:
		cPYModule();
		virtual ~cPYModule();
        void addpath(std::string pathname);
        void callpython2(std::string filename, std::string funcname);
        void callpython(PyObject *);
		
}











