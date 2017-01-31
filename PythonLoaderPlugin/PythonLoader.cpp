#include "PythonLoader.h"

PythonLoader::PythonLoader() {
    Py_Initialize();
    _last_module_handle = 0;
}

PythonLoader::~PythonLoader() {
    Py_Finalize();
}

int PythonLoader::import(const QString &moduleName) {
    PyObject * module = PyImport_Import(PyString_FromString(qPrintable(moduleName)));
    if (module == NULL) {
        return 0;
    } else {
        _last_module_handle ++;
        this->_modules[_last_module_handle] = module;
        return _last_module_handle;
    }
}

QStringList PythonLoader::call(int hModule,const QString function,const QStringList &arguments) {
    if (!this->_modules.contains(hModule)) {
        return QStringList();
    }
    PyObject * module = this->_modules[hModule];
    PyObject * pFunc = PyObject_GetAttrString(module, qPrintable(function));
    if (pFunc == NULL) {
        return QStringList();
    }
    PyObject * pArgs = PyTuple_New(arguments.size());
    for (int i = 0; i < arguments.size(); i ++ ) {
        PyTuple_SetItem(pArgs,i, PyString_FromString(qPrintable(arguments.at(i))));
    }
    PyObject * pValue = PyObject_CallObject(pFunc, pArgs);
    QStringList rtn;
    for (int i = 0; i < PyTuple_Size(pValue); i ++) {
        rtn.append(QString(PyString_AsString(PyTuple_GetItem(pValue,i))));
    }
    return rtn;
}

Q_EXPORT_PLUGIN2("PythonLoader",PythonLoader)