# fctlog
C++ Function Entry/Exit Logger

This tool provide logging of class member function entry, exit and throw. 
If it isn't possible to use a debuger, this tool will be very helpfull.

No need to modify the original class. 
A child class for logging purpose must be created. 
Macros are provided for easy use.
```c++
class DemoWithLog : public Demo {
    FCTLOG_METHOD0(void, fctName);
    FCTLOG_METHOD1(int, fctName, (int val = 0), val);
};
```
The logger child class must be instantiated instead of the original class.
See 'demo' for more details.

Per default the logging messages will be displayed on the standard output. 
An output stream can be set to log the messages in a specific logging system.

Logging message for:

* Function entry with argument values
* Function exit with return value
* Function throw with exception type and message

Restrictions:

* Only virtual functions can be logged (workaround: make function to log virtual)
* Private functions cannot be logged (workaround: change accessibility to protected)
* Constructor and destructor cannot be logged (functions called inside constructor or destructor will be logged)
