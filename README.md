# Hash-Table-in-C
A quick fixed size hashtable implementation in C

### Building
To build the static library,  run the following commands from the terminal:
```bash
mkdir build && cd build && cmake .. && make ; cd ..
```
This will build ```libHashTable.a``` in ```./bin``` directory.

### Usage
Include ```HashTable.h``` in the source file and link to ```libHashTable.a``` while compiling the source file.

See ```include/HashTable.h``` for information about functionality provided by this module.
