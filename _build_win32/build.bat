call setenv.bat
qmake ..\PythonLoaderPlugin\pythonLoader.pro && nmake release
qmake ..\test\test.pro && nmake release

