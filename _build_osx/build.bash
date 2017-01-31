source ./setenv.bash
qmake ../PythonLoaderPlugin/pythonLoader.pro
make
qmake ../test/test.pro -spec macx-g++
make

