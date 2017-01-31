#include <QtCore>
#include "PythonLoaderInterface.h"

int main(int argc,char ** argv) {
    QPluginLoader loader(argv[1]);
    PythonLoaderInterface * interface = qobject_cast<PythonLoaderInterface *>(loader.instance());
    int mytest = interface->import("mytest");
    QStringList rtn = interface->call(mytest,"hello_python",QStringList()<<"va"<<"vb");
    foreach (const QString &str, rtn) {
        printf("%s\n",qPrintable(str));
    }
    return 0;
}
