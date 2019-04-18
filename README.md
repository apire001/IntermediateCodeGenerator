# cs152-Lexical Anaylzer, Parser Generator and MIL Intermediate Code Generator For mini_l Language 

CS 152 Project by Andrew Pirelli and William Spalding

## Introduction

This program performs lexical analysis using flex, parser generation using bison and generates runnable MIL intermediate code for any given mini_l file. Lexical, parser and semantic error checking is also performed during the various stages. 

### Requirements For Compilation:

```
gcc version 4.1.2 20080704 (Red Hat 4.1.2-55)
flex version 2.5.4
bison (GNU) version 2.3
```

### Requirements For Execution:

```
gcc version 4.8.5 20150623 (Red Hat 4.8.5-11) (GCC)
```

### Install Instructions

```
$ git clone https://github.com/apire001/IntermediateCodeGenerator.git
$ cd Project3
$ make clean
$ make
$ ./mini_l filename.min > filename.mil
$ ./mil_run filename.mil < input.txt
```

### Known Bugs

* Embedded loops and if-statements may lead to segmentation faults
