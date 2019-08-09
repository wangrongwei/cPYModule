
#include <iostream>
#include <Python.h>
#include <unordered_map>


using namespace omnetpp;
using namespace std;



class cPYModule 
{
    public:
        int a,b;
        PyObject * pModule;
        PyObject * pFunc;
        std::unordered_map<const char *, unordered_map<const char *, PyObject *>> func_map;

    public:
        cPYModule();
        virtual ~cPYModule();
        void addpath(std::string pathname);
        void callpython(std::string filename, std::string funcname);

}











