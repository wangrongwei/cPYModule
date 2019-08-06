
#include <iostream>
#include <Python.h>

class cPYModule 
{
    public:
        int a,b;
        PyObject * pModule;
        PyObject * pFunc;

    public:
        cPYModule();
        virtual ~cPYModule();
        void addpath(std::string pathname);
        void callpython(std::string filename, std::string funcname);

}











