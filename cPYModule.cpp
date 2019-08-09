
#include "cPYModule.h"
#include <iostream>
#include <string>
#include <omnetpp>


using namespace omnetpp;
using namespace std;

cPYModule :: cPYModule()
{
    Py_Initialize();
    //Py_SetPythonHome(L"D:/Program Files/Python37/Lib;D:/Program Files/Python37");
    Py_SetPath(L"D:/Program Files/Python37/Lib;D:/Program Files/Python37");
    PyRun_SimpleString("import os,sys");
    PyRun_SimpleString("sys.path.append('D:/omnetpp-5.2/samples/routing-python')");
    PyRun_SimpleString("sys.path.append('D:/Program Files/Python37/lib/site-packages/')");
}

cPYModule :: ~cPYModule()
{

}

/*
 * 为python环境添加一个路径
 */
void cPYModule :: addpath(std::string pathname)
{
    std::string cmd = string("sys.path.append('-')");
    std::size_t index =  cmd.find("-");
	if (index != std::string::npos){
        /* 寻找'-'， 并取代为pathname */
		cmd.replace(cmd.find('-'), 1, pathname.c_str());
	}

    PyRun_SimpleString(cmd.c_str());
}

/*
 * 调用不常用的python函数接口
 */
void cPYModule :: callpython2(std::string filename, std::string funcname)
{
	/* 调用的python文件名 */
    pModule = PyImport_ImportModule(filename.c_str());
    if(pModule == nullptr){
        std::cout<<"NULL"<<endl;
    }
	/* 调用的函数名 */
    pFunc = PyObject_GetAttrString(pModule, funcname.c_str());
	PyEval_CallObject(pFunc, nullptr);

	Py_Finalize();

}


void cPYModule :: addfunc(const char *filename, const char *funcname)
{
	/* 调用的python文件名 */
	PyObject *pModule = PyImport_ImportModule(filename.c_str());
 	if(pModule == nullptr){
        std::cout<<"NULL"<<endl;
 	}
    /* 调用的函数名 */
    PyObject *pFunc = PyObject_GetAttrString(pModule, funcname.c_str());
	
	func_map[filename][funcname] = pFunc;

    Py_Finalize();

}

/*
 * 调用对应函数
 */
void cPYModule :: callpython(PyObject *func)
{
	/* 调用具体的函数 */
	if(func == nullptr){
		throw cRuntimeError("Error, this func has not import");
	}
    PyEval_CallObject(func, nullptr);
    Py_Finalize();
}





