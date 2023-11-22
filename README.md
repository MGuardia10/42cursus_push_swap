# 42Madrid - push_swap

This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. Allowed movements are specified below.

The bonus part is a checker program that verifies if all the moves made are allowed and if the stack is correctly sort once there are no moves left.

![C](https://img.shields.io/badge/C-a?style=for-the-badge&logo=C&color=grey)

You can see the subject [**HERE.**](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/push_swap_subject_en.pdf)

## Example

https://github.com/MGuardia10/42cursus_push_swap/assets/105164870/0815871e-ecc2-46a8-8204-6c3bbeaec1f0

## Valid moves
| Moves | Explanation |
| :--- | :--- |
| sa | swap a - swap the first two elements on top of the stack a. |
| sb | swap b - swap the first two elements on top of the stack b. |
| ss | swap a y swap b a la vez. |
| pa | push a -  takes the first element of stack b and puts it on top of stack a. |
| pb | push b -  takes the first element of stack a and puts it on top of stack b. |
| ra | rotate a - moves all elements of the stack a up to one position, the first element becomes the last. |
| rb | rotate b - moves all elements of the stack b up to one position, the first element becomes the last. |
| rr | ra and rb at the same time. |
| rra | reverse rotate a - moves all elements of the stack a down to one position, the last element becomes the first. |
| rrb | reverse rotate b - moves all elements of the stack b down to one position, the last element becomes the first. |
| rrr | rra and rrb at the same time. |

## Installing and running the project:

1- Clone this repository
	
	git clone https://github.com/MGuardia10/42cursus_push_swap.git
2- Navigate to the new directory and run `make`
	
	cd 42cursus_push_swap
   	make
    make bonus
3- `make clean` to remove the object files and work on a cleaner directory

	make clean
4- Start using the program by itself:

	./push_swap 9 7 8 1 3 4 2 5 6 0
or with the checker:

    ARG="9 7 8 1 3 4 2 5 6 0"; ./push_swap $ARG | ./checker $ARG

## Compiling the Program
The push_swap program comes with a Makefile that includes the following rules:

- `all`: compiles the program.
- `re`: recompiles the program.
- `bonus`: compiles bonus files for the bonus features (checker).
- `clean`: removes all object files.
- `fclean`: removes all object files and push_swap/checker programs.

## Disclaimer
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/norm_en.pdf), the school's coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.
