# A Note about Code Style
We decided to go for the Google Code Style Guide, with a small change in the 
naming convention for getters/setter (called accessors/mutators in the guide). We decided to name them 
using the same convention regular functions  "Ordinarily, functions should start with a capital letter and have a 
capital letter for each new word." to be more consistent with the overall naming convention. Inspecting some 
opensource Google C++ code we found that this is the same approach they took in some of their codebases.


# How to run

```bash
# Clone this repository
$ git clone https://github.com/BIRSAx2/library library
$ cd library
# Create build directory if not exists
$ mkdir -p build
$ cd build
# Generate build files
$ cmake ../
# Build the executable
$ cmake --build .

# Run the executable
$ ./Library

```