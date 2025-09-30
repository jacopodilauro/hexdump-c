# hexdump-c
Hexdump utility using system calls in C. Similar to the original Linux `hexdump`.
## Description
This program reads a file and displays its contents in hexadecimal format alongside the ASCII representation of the characters.
It uses low-level system calls (`open`, `read`, `close`) for direct file I/O operations.
## Compilation
```bash
gcc hexdump.c -o hex
```
## Running
```bash
./hex <filename>
```
## Example Output
### Dumping the source code itself:
```bash
$ gcc hexdump.c -o hex
$ ./hex hexdump.c
23 69 6E 63 6C 75 64 65  20 3C 73 74 64 69 6F 2E 	|#include <stdio.|
68 3E 0A 23 69 6E 63 6C  75 64 65 20 3C 75 6E 69 	|h>.#include <uni|
...
70 29 3B 0A 09 72 65 74  75 72 6E 20 30 3B 0A 7D 	|p);..return 0;.}|
0A ~~ ~~ ~~ ~~ ~~ ~~ ~~  ~~ ~~ ~~ ~~ ~~ ~~ ~~ ~~ 	|.|
```
### Dumping a text file:
```bash
$ gcc hexdump.c -o hex
$ ./hex test.txt
48 65 6C 6C 6F 20 57 6F  72 6C 64 2E 0A 49 73 20 	|Hello World..Is |
61 20 74 65 73 74 2E 0A  ~~ ~~ ~~ ~~ ~~ ~~ ~~ ~~ 	|a test..|
```
## License
MIT License
