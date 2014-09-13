## logger
======

Lightweight logger library for any C++ application.

- uses macroes which are manipulating a global log instance
- timestamp, filename and line number are automatically included into the log messages
- formatted log string (variable amount of arguments)
- compiles into a single linkable object
- interface for new log targets (currently the only implementation is for streams)
- changable log level during runtime
- user can allow the log to expand if the resulted string would be too long (initally disabled, see usage)
- logs under the current loglevel will be discarded
- currently tested under Linux

### Usage:
```
#include <Logger.h>
#include <StreamLogTarget.h>

int main() {

  Logger::StreamLogTarget log(std::cout);
  STARTLOG(log, Logger::Severity::INFO);

  LOG("this is a log with a number: %d", 42);
  ERR("this is an error with two numbers: %d, %x", 42, 42);

  LOG("long string1: '%s'", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  EXPANDABLE(true);
  LOG("long string2: '%s'", "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");

  STOPLOG();
    return 0;
}

```

### It prints like:
```
2014-09-13 15:15:24 LOG OPEN
2014-09-13 15:15:24  INFO       main2.cpp ( 10): this is a log with a number: 42
2014-09-13 15:15:24   ERR       main2.cpp ( 11): this is an error with two numbers: 42, 2a
2014-09-13 15:15:24 TRUNCATED LOG:
2014-09-13 15:15:24  INFO       main2.cpp ( 13): long string1: 'aaaaaaaaaaaa
2014-09-13 15:15:24  INFO       main2.cpp ( 15): long string2: 'bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb'
2014-09-13 15:15:24 LOG CLOSE
```

### TODO:
-thread safety
