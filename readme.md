# ft_printf


 
## :printer: Description

My own implementation of the famous printf function from the ANSI C Standard Library (libc).

It handles cspdiuxX% conversions, the ’-0.*’ flags and minimun field width specifier.

This project is part of the common core at 42 Madrid Coding School and serves as an introduction to variadic functions.

## :nut_and_bolt: How it works

This implementation doesn't replicate the buffer management used in the original printf. Instead, it writes to stdout for each conversion. I now understand that this approach is more resource consuming but i was focused on other aspects of the project at the time.

The main algorithm  found in the ft_printf.c file parses the input string. When a % is detected it will mark the encountered flags and redirect to the corresponding conversion file. Each type has its own file where the specific formatting logic and nuances are handled

This way the code stays pretty modular and more conversions could be added in the future without major changes.



## How to use



1. Open terminal inside the repo
2. Make
3. Compile libftprintf.a with the file where you want to use ft_printf

The repo contains a main.c file with a few examples comparing the output of the original printf vs this implementation. 






---