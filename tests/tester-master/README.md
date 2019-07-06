
```
clang++ -O2 -std=c++14 *.cpp && ./a.out 3 1000 ./fillita ./fillitb
```
#### The preceding command:
1. compiles the tester
2. removes ./map and ./log directories
3. generates 1000 random .fillit files containing 3 valid pieces in ./map
4. runs in parallel the two given binaries over those maps
5. computes a report, and logs errors in ./log

<BR>

* av[1] pieces per test (0+)
* av[2] num tests (1+)
* av[3] binary 1
* av[4] binary 2

#### todo:
- solve bin2 superiority over read phase
- dispatch includes in .cpp files
- use clock instead of chrono for some measures (wait4)
- screenshot
- more info in readme (WORK_TIMEOUT, NUM_WORKERS in tester.hpp) etc...
- more timings info in report
