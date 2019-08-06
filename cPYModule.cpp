
#include "cPYModule.h"
#include <iostream>
#include <string>

using namespace std;

cPYModule :: cPYModule()
{
    Py_Initialize();
    //Py_SetPythonHome(L"D:/Program Files/Python37/Lib;D:/Program Files/Python37");
    Py_SetPath(L"D:/Program Files/Python37/Lib;D:/Program Files/Python37");

    PyRun_SimpleString("import os,sys");
    PyRun_SimpleString("sys.path.append('D:/omnetpp-5.2/samples/routing-python')");
    PyRun_SimpleString("sys.path.append('D:/Program Files/Python37/lib/site-packages/')");

    PyObject * pModule = nullptr;
    PyObject * pFunc = nullptr;

}

cPYModule :: ~cPYModule()
{


}

void cPYModule :: addpath(std::string pathname)
{
    std::string cmd = string("sys.path.append");
    PyRun_SimpleString(cmd.c_str());
}

void cPYModule :: callpython(std::string filename, std::string funcname)
{
    pModule = PyImport_ImportModule(filename.c_str());//调用的Python文件名
    if(pModule == nullptr){
        std::cout<<"NULL"<<endl;
    }
    pFunc = PyObject_GetAttrString(pModule, funcname.c_str());//调用的函数名
    PyEval_CallObject(pFunc, nullptr);

    Py_Finalize();

}


