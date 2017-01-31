#ifndef PYTHON_LOADER_H
#define PYTHON_LOADER_H

#include <QtCore>
#include "PythonLoaderInterface.h"

#include <Python.h>

class PythonLoader : public QObject, public PythonLoaderInterface {
    Q_OBJECT
    Q_INTERFACES(PythonLoaderInterface)
    
    public:
        PythonLoader();
        ~PythonLoader();
        int import(const QString &moduleName);
        QStringList call(int hModule,const QString function,const QStringList &arguments);
    private:
        int _last_module_handle;
        QHash<int, PyObject * > _modules;
};


#endif //PYTHON_LOADER_H