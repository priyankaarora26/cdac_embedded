# Embedded OS Assignments

## DAY_1   
###### Assignment 1

**Getting Started**
- Created git-Hub account
- Created repository eosmay2022
- Created security Token
- Added git ignore 

**Steps followed**
1. touch README.md ```md ==> Mark down``` 
2. git init ```creating a hidden .git file```
3. git add README.md ```Adding the README file to git repository```
4. git commit -m "Details of updates"
5. git log
6. touch .gitignore
7. git add .
8. git push




## DAY_2

**Addition of 2 numbers using main.c and add.c**
- STEPS : 
1. create main.c
2. create add.c
3. create intermediate object file main.o ```gcc -c -o main.o main.c```
4. create intermediate object file add.o ```gcc -c -o add.o add.c```
5. To check the excecutability of main.o and add.o use ```file main.o ``` ```file add.o```
6. We need linker to link(ld) the two object files. ```gcc``` internally calls linker.
7. Create executable object file using main.o and add.o ```gcc -o airthprog main.o add.o```
8. arithprog is an ELF which can be executed by OS
9. Excecuting the arithprog provides the result of addition



## DAY_3

###### Assignment 3

- Downloaded the cross-complier for linux to arm ```gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu.tar.xz```
- Complied the main.o and add.o using cross complier.

- arith_new_DAY4
    - Added sub.o in Makefile
    - Updated main with substraction operation
    - executed the file generated using makefile
    

- sections
    - For knowing how the code is divided in different sections. The sections are:
        1. .code / .text
        2. .data
        3. BSS 
        4. Heap
        5. stack
    - The .text, .data, BSS section are static.
    - The Heap and Stack section are dynamic.

- PID
    - Process Identification.
    - Parent Process Identification.

- libsyscall
    - Checking the library and system calls.
    - The library calls may or may not invode system calls.
    - Library calls :
        - printf , scanf :- will invoke write and read system calls.
    - System calls :
        - read
        - write
        - Open
        - Close



## DAY_4

###### Assingment 4

- Creating a Static library
    - Find libc.a 
    - Use the libc.a and adding add.o and sub.o to create a user library.
    - Updating Makefile with creating a user library.
    - While checking the Disassembly we can find the add file and main file
    - For compilation of .c file. ```gcc -o file file.c -L. -larith```  


- Creating a Dynamic library
    - Find libc.a
    - Updating Makefile with creating a user library. ```gcc -shared -fPIC -o libarith.so add.o main.o```
    - While checking the Disassembly we can find the add file and main file
    - For compilation of .c file. ```gcc -o file file.c -L. -larith```  
    - Using ```export LD_LIBRARY_PATH = .``` to specify path for using Dynamic Library.
    
- Creating a System Call
    - open a file and write inside it.
    - if the file is not opening, add flag ```O_CREAT|O_WRONLY``` which will create a file of given name if not available.
    











