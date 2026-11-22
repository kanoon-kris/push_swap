*This project has been created as part of the 42 curriculum by kboonkos, pmansak.

# push_swap

## Description
`push_swap` is a program sorting a stack with 11 operations by using four strategies.

The metric being used is called disorder...

Simple selection sort...
Medium chunk sort...
Complex radix sort...
Adaptive mode...

## Instruction
### compilaiton
Clone this project and `make` to build the executable.

`make clean` to remove object files.

`make fclean` to remove both object files and the executable.

`make re` to remove both object files and the executable, then re-build it again.

### execution
 Run `./push_swap [--bench] [--simple | --medium | --complex | --adaptive] INTEGER...` to display `push_swap` operations sorting the sequence to `stdout`.

Example:

`./push_swap 42 67 711`

`./push_swap "42 67 711"`

`./push_swap --bench --simple 42 67 711`

There are five optional flags: a benchmark flag and other four strategy flags.

Benchmark flag:

 - `--bench` to display benchmark with disorder metric, and frequency of operations to `stderr`. See below,
```
[bench] disorder:  49.75%
[bench] strategy:  Adaptive / O(n sqrt(n))
[bench] total_ops:  7963
[bench] sa:  0  sb:  0  ss:  0  pa:  500  pb:  500
[bench] ra:  4983  rb:  1008  rr:  0  rra:  0  rrb:  972  rrr:  0
```
Strategy flag:
 - `--simple` to force the program to deploy selection sort (n^2)
 - `--medium` to force the program to deploy chunk sort (n sqrt(n))
 - `--complex` to force the program to deploy radix sort (n log(n))
 - `--adaptive` to force the program to select strategy flags based on measured disorder metrics of the initial integer sequence. This is the default if no strategy flags are given.

Invalid inputs include:
- non-integer values,
- duplicated integers,
- repeated or conflicting strategy flags,
- flags after integers,
- empty quoted argument,
- other separators than space.

Given the invalid input, `Error` will be displayed.

Given no inputs, the executable will return the command prompt.

## Resources
### how AI was used

## Technical Choices
