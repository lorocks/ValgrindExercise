# Valgrind Exercise

## Standard install via command-line
```bash
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/shell-app
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

# Extra Credit
## What happens when executable in linked statically?
    When executables are linked statically all library and dependencies are packaged together in the executable. This makes the executable bigger but the executable no longer depends on any system installed dependencies or external shared library installation. In essence all functions required from external libraries become part of the program's binary.

## Does Valgrind still detect the bugs?
## Why?
    Valgrind can detect memory related bugs but not all when static linking takes place. 
    Memory allocation and deallocation errors in the main program will be found but errors coming from the use of statically linked external shared libraries and dynamic loading might not.
    
    Valgrind finds errors by loading the code onto a virtual execution environment. But while it does the loading, Valgrind also replaces certain functions, like malloc, with a Valgrind version of it, so that Valgrind can keep track of all memory allocations and deallocations. 
    But when it comes to external libraries that are statically linked, Valgrind will load the code as normal, but Valgrind might not know about any memory operations taking place since it mainly tracks memory operations on the program's address space. If the external library loads memory it does so in it's own address space which wont be accessible by Valgrind.
    Valgrind can't easily replace the specific functions inside the external library because the external library is now considered as part of the program's binary. 
    Valgrind catches and replaces functions when they are loaded dynamically during program execution, but static linking means that the functions that are meant to be replaced are already part of the executable.


## Valgrind output
The VAlgrind file outputs can be found inside the "Valgrind Output" directory
```bash
  cd "Valgrind Output"
```