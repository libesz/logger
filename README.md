## logger
======

Lightweight logger library for any C++ application.

- uses macroes which are manipulating a global log instance
- timestamp, filename and line number are automatically included into the log messages
- formatted log string (variable amount of arguments)
- no need for explicitly open and close the log (means that global objects can log in construction time before main())
- compiles into a single linkable object
- interface for new log targets (currently the only implementation is for ostreams)
- changable log level during runtime
- user can allow the log to expand if the resulted string would be too long (initally disabled, see usage)
- logs under the current loglevel will be discarded
- currently tested under Linux with GCC

### Usage:
```
#include <Logger.h>

class A {
public:
  A(){LOG("%s", __PRETTY_FUNCTION__);}
  ~A(){LOG("%s", __PRETTY_FUNCTION__);}
};

A a;

int main() {
  LOG("this is a log with a number: %d", 42);
  ERR("this is an error with two numbers: %d, %x", 42, 42);

  LOG("long string1: '%s'", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  EXPANDABLE(true);
  LOG("long string2: '%s'", "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");

  return 0;
}

```

### It prints like:
```
2014-10-12 20:29:32 LOG OPEN
0000000|2014-10-12 20:29:32  INFO       main2.cpp (  5): A::A()
0000001|2014-10-12 20:29:32  INFO       main2.cpp ( 11): this is a log with a number: 42
0000002|2014-10-12 20:29:32   ERR       main2.cpp ( 12): this is an error with two numbers: 42, 2a
2014-10-12 20:29:32 TRUNCATED LOG:
0000003|2014-10-12 20:29:32  INFO       main2.cpp ( 14): long string1: 'aaaaaaaaaaaaaaaaaaaaaa
0000004|2014-10-12 20:29:32  INFO       main2.cpp ( 16): long string2: 'bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb'
0000005|2014-10-12 20:29:32  INFO       main2.cpp (  6): A::~A()
2014-10-12 20:29:32 LOG CLOSE
```

You can change the log target in Log &getGlobalLog() function.

