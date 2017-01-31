#ifndef PYTHON_LOADER_INTERFACES_H
#define PYTHON_LOADER_INTERFACES_H
 

#include <QtCore>

class QString;

class PythonLoaderInterface {
    public:
        virtual ~PythonLoaderInterface() {}
        virtual int import(const QString &moduleName) = 0;
        virtual QStringList call(int hModule,const QString function,const QStringList &arguments) = 0;
};

Q_DECLARE_INTERFACE(PythonLoaderInterface,"PythonLoaderInterface/1.0")

#endif //PYTHON_LOADER_INTERFACES_H