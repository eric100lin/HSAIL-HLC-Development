HSAIL-HLC-Development Compiler
===============================

LLVM to HSAIL Open Source Development HSAIL Compiler. 


This open source compiler is HSAIL code generator based on LLVM 3.2. It has added
Target/HSAIL backend along with with a few relevant changes to LLVM core.  The changes
are marked "OPENCL" tag so it will be easy to search the changes done in the LLVM source 
base. HLC means High Level Compiler, which means LLVM to HSAIL code generator and NOT
ISA generator.

The built binaries are also given. There are some test cases provided to generate
HSAIL from the BC files (LLVMIR). There is also a front-end provided (CLC2) which is
CLANG based front end. 

You need the HSAIL-Tools (provided in the GITHUB) to build this compiler.

Steps to build the LLVM-HSAIL directory (using the Target-HSAIL):

 1. Download the sources into a directory. 
 2. Download the HSAIL-tools (latest drop on GITUB)
 3. Change the directory in the LLVM_SRC/CMakeLists.txt to point to the HSAIL-tools-private directory
 in both LLVM_SRC directory and in LLVM_SRC/tools/llc)
 4. Create the build directory under LLVM_SRC 
 5. Build the HSAIL-tools (by reading the README there)
 6. Go to build directory and run "cmake .." and then "make"
 7. Go to tests directory and run the test after pointing the PATH (in the "run_tests"). Make sure you use
the builtins file given in the drop (and not use the one given in "Stable" compiler binaries).

Intended usage:

This compiler is expected to be used by compiler writers for various languages and those developers who woudl like to developer HSA applications using CLOC tool. Since this is open sourced too, the user can make required changes to the compiler (like adding meta data or different passes etc) as per their needs.
