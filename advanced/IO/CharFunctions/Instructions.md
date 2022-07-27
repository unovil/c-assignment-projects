# Character Challenge 1

- write a program to count number of words and characters in the file OR from `stdin`
- takes either zero or one command-line argument
  - if there's no argument, `stdin` is used for input
  - if there's an argument, that argument is the name of the file

## from a file

some file
```text
hello?
hi
bye
why
see you later
alligator
```

C program example
```text
./a someFile.txt

The number of words are: 8
The number of characters are: 41
```

## from `stdin`

```text
./a

what
who
hee

The number of words in the file are: 3
The number of characters in the file are: 12
```

# Character Challenge 2

- write program to convert uppercase to lowercase and vice versa in a file
  - takes command line argument for name of file, or ask user for name of file
- need to create temporary file to store converted character
  - rename temp file to original file
- need to use `isupper()` to check for upper or lower case
  - can also use `toupper()` or `tolower()`  

## Example program

Input from file
```text
hello, how are you?
nope
ok
what
why
bye.
```

Example output
```text
HELLO, HOW ARE YOU?
NOPE
OK
WHAT
WHY
BYE.
```