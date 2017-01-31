source ./setenv.bash
qmake ../PythonLoaderPlugin/pythonLoader.pro
make
qmake ../test/test.pro
make

