
# 简介

借助python功能，用于OMNeT++仿真数据分析和整理

# 环境

## install python

下载最新python安装包，安装路径记为\<python-path\>，安装成功后，可在OMNeT++下加入include和lib路径。

## OMNeT++配置

添加python.a文件路径和**site-packages**路径到**Paths---**。

# usage

```c

cPYMpdule *foo = new cPYModule();

/* 第一步：添加py文件搜索路径 */
foo->addpath("/<py-file-path>/");
/* 第二步：导入py文件及文件中函数 */
foo->addfunc("fullpath-filename","funcname");

/* 第三步：调用函数（func_map为记录函数地址的成员变量）  */
foo->callpython(foo->func_map["filename"]["funcname"]);

/* 此外，对于使用频率较少的模块，可直接使用以下接口，不需经过以上三步 */
foo->callpython2("py-filename", "py-func");

```



