# String Functions

`main()` command line arguments
1. `char` character
2. `char*` filename

- program needs to print only lines in the file that contain the given character
- lines are terminated with `\n`
  - assume no line is >256 chars long
- you need to use `fgets()` or `getline()` for reading the file
  - use `puts()` for displaying output