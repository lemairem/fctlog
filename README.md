# fctlog
C++ Function Entry/Exit Logger

This tool provide logging of class member function entry, exit and throw. If it isn't possible to use a debuger, this tool will be very helpfull.

No need to modify the original class. A child class for logging purpose must be created. Macros are provided for easy use.
```c++
class DemoWithLog : public Demo {
    FCTLOG_METHOD0(void, fct);
    FCTLOG_METHOD1(int, fct, (int val = 0), val);
};
```
The logger child class must be instantiated instead of the original class.

Per default the logging messages will be displayed on the standard output. An output stream can be set to log the messages in a specific logging system.

Logging message for:
* Function entry with argument values
* Function exit with return value
* Function throw with exception type and message

Restrictions: 
* Only virtual functions can be logged
* Constructor and destructor cannot be logged (functions called inside constructor or destructor will be logged)
