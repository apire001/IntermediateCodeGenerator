Requirements for compilation:
gcc version 4.1.2 20080704 (Red Hat 4.1.2-55)
flex version 2.5.4
bison (GNU) version 2.3

Requirements for execution:
gcc version 4.8.5 20150623 (Red Hat 4.8.5-11) (GCC)

How to run the code:
make clean
make
//Performs lexical analysis using flex, parser generation using bison and generates MIL intermediate code representation
//on filename.min. MIL intermediate code is stored in filename.mil
./mini_l filename.min > filename.mil
//Runs the MIL intermediate code in filename.mil using input provided by input.txt
./mil_run filename.mil < input.txt
