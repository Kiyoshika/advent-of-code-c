# Day One
## Problem Statement
### Part 1:
A text file contains numbers on each new line. Whenever a blank line is encountered, need to sum all previous values and finally return the maximum sum.

### Part 2:
Maintain a list of the top three values and return their sum at the end.

## Approach
NOTE: I make a large assumption that each entry contains a value > 0 as I am using 0 to indicate a newline when parsing integers from the string.

For part 1, we had two counters to keep track of the current sum and the current maximum. Anytime we reach a breakpoint we can compare it against the current max and replace it if needed.

For part 2, I mantain a sorted array of three items and whenever reaching a break point, we check if our current sum is greater than our lowest element (minimizing our comparisons) then insert into the appropriate position (and shift other elements down, popping the last item off). Finally, we return the sum of the three elements at the end.
