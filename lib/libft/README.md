# Libft - A Custom C Library

I am a student at 42 Wolfsburg and this is the first project that each of us has to program here.

# Overview

The task was:
"Write your own library: a collection of functions that will be a useful tool for your cursus."

To begin, a set of functions from the libc were reimplemented. These functions have the same prototypes and behaviors as the originals but are prefixed with ft_. For example, strlen becomes ft_strlen.

# Standard Functions

The following functions were implemented without using any external functions:

    Character checks and transformations:
        ft_isalpha
        ft_isdigit
        ft_isalnum
        ft_isascii
        ft_isprint
        ft_toupper
        ft_tolower

    String manipulation:
        ft_strlen
        ft_strchr
        ft_strrchr
        ft_strncmp
        ft_strnstr

    Memory manipulation:
        ft_memset
        ft_bzero
        ft_memcpy
        ft_memmove
        ft_memchr
        ft_memcmp

    String copy and concatenation:
        ft_strlcpy
        ft_strlcat

    Conversion:
        ft_atoi

To implement the following functions, malloc() is used:

    ft_calloc
    ft_strdup

# Additional Functions

The following functions were developed to provide additional functionalities not present in libc or in different forms:

    String operations:
        ft_substr: Allocates and returns a substring from the string s, starting at index start and of maximum size len.
        ft_strjoin: Allocates and returns a new string, which is the result of the concatenation of s1 and s2.
        ft_strtrim: Allocates and returns a copy of s1 with characters specified in set removed from the beginning and the end of the string.
        ft_split: Allocates and returns an array of strings obtained by splitting s using the character c as a delimiter. The array ends with a NULL pointer.
        ft_itoa: Allocates and returns a string representing the integer received as an argument, handling negative numbers.

    Function applications:
        ft_strmapi: Applies the function f to each character of the string s, passing its index as the first argument and the character itself as the second, creating a new string to collect the results.
        ft_striteri: Applies the function f on each character of the string s, passing its index as the first argument. Each character is passed by address to f to be modified if necessary.

    File descriptor operations:
        ft_putchar_fd: Outputs the character c to the given file descriptor.
        ft_putstr_fd: Outputs the string s to the given file descriptor.
        ft_putendl_fd: Outputs the string s to the given file descriptor followed by a newline.
        ft_putnbr_fd: Outputs the integer n to the given file descriptor.

# Bonus Part

Additional functions for list manipulation were also implemented:

    List creation and addition:
        ft_lstnew: Allocates and returns a new node. The content is initialized with the value of the parameter content, and next is initialized to NULL.
        ft_lstadd_front: Adds the node new at the beginning of the list.
        ft_lstadd_back: Adds the node new at the end of the list.

    List traversal and modification:
        ft_lstsize: Counts the number of nodes in a list.
        ft_lstlast: Returns the last node of the list.
        ft_lstdelone: Frees the memory of the node’s content using the function del and frees the node itself, but not the memory of next.
        ft_lstclear: Deletes and frees the given node and every successor of that node using del and free, then sets the list pointer to NULL.
        ft_lstiter: Iterates over the list lst and applies the function f on the content of each node.
        ft_lstmap: Iterates over the list lst, applies the function f on the content of each node, and creates a new list resulting from the successive applications of f. The del function is used to delete the content of a node if needed.

# Conclusion

I scored 125/100 points for this project, but this doesn't mean the code is flawless. Please use it with caution!

This README provides an overview of the custom library created as part of a project to reimplement standard libc functions and develop additional useful functions. The implemented functions cover a wide range of operations, from basic character checks to complex list manipulations, ensuring a comprehensive and versatile toolset.
