# fctlog
C++ Function Entry/Exit Logger

This tool provide logging of class member function entry, exit and throw. If You cannot use a debuger, this tool will be very helpfull.

No need to modify the original class. A child class for logging purpose must be added. Macros are provided for easy use.
```c++
class DemoWithLog : public Demo {
    FCTLOG_METHOD0(void, fct);
    FCTLOG_METHOD1(int, fct, (int val = 0), val);
};
```
The logger child class must be instantiated instead of the original class.

Per default the logging messages will be displayed on the standard output. You can provide an output stream to log it in your logging system.

Logging message for:
- Function entry with argument values.
- Function exit with return value.
- Function throw with exception type and message.

Restrictions: 
- Only virtual functions can be logged.
- Constructor and destructor cannot be logged. But you can call functions inside your constructor or destructor that will be logged.
