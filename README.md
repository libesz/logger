## logger
======

Lightweight logger library for any C++ application.

- uses macroes which are manipulating a global log instance
- timestamp, filename and line number are automatically included into the log messages
- formatted log string (variable amount of arguments)
- compiles into a single linkable object
- interface for new log targets (currently the only implementation is for streams)
- changable log level during runtime
- logs under the current loglevel will be discarded
- currently tested under Linux

### Usage:
```
#include <iostream>
#include <Logger.h>
#include <StreamLogTarget.h>

using namespace std;
using namespace Logger;
int main() {
  StreamLogTarget log(cout);
  STARTLOG(log, Severity::INFO);

  LOG("this is a log with a number: %d", 42);
  ERR("this is an error");

  STOPLOG();
	return 0;
}
```

### It prints like:
```
2014-09-13 02:00:53 LOG OPEN
2014-09-13 02:00:53  INFO  LoggerUser.cpp ( 19): this is a log with a number: 42
2014-09-13 02:00:53   ERR  LoggerUser.cpp ( 20): this is an error
2014-09-13 02:00:53 LOG CLOSE
```

### TODO:
-thread safety
