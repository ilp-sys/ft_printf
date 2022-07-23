# FT_PRINTF [![jiwahn's 42 ft_printf Score](https://badge42.vercel.app/api/v2/cl5mpp96a00400amd35y6oqy6/project/2663121)](https://github.com/JaeSeoKim/badge42)

    Custom printf of 42 C School
---
/* unlike original `printf`, this project doesn't support buffer manegement */<br>


## 0. Based Concepts
 - `Variadic arguments` in `<stdarg.h>`
 - Handling a number of arguments
 - Standard output's `buffer I/O`
 - Condition checks using `flags` (or `bitwise calculation`)

## 1. Implementation

####  How the printf's buffer works?
Buffer is a block of memory which belongs to a kernal stream and is used to hold stream data temporarily.
Stdout is line buffered by default(ISO).
Characters written to a line buffered stream are transmitted to the file in blocks when a newline character is encountered.

####  Parameters 
	printf    : %[Flag][Width][.Precision][Length]Specifier
	ft_printf : %[Flag][Width][.Precision]Specifier

notes!
- Precision `.` means `.0`.
- A precision of 0 means that no character is written for the value 0.
- For integer, numbers `0 flag` is ignored if the precision is explicitly specified, also ignored when `- flag` is present.
####  Flag dependancies
|spec/flag   | %c | %s  | %p  | %d  | %i  | %u | %x | %X | %% |
|:---:|:---:|:---:|:---:|:---:|:---:|:---: | :---: | :---: | :---:| 
|  width   |o|o|o|o|o|o|o|o|x|
| precision|x|o|o|o|o|x|o|o|x|
| -        |o|o|o|o|o|o|o|o|x|
| 0        |x|x|o|o|o|x|o|o|x|
| #        |x|x|x|x|x|x|o|o|x|
| SPACE    |x|x|o|o|x|x|x|x|x|
| +        |x|x|o|o|x|x|x|x|x|

#### Tags
```

                         / check_flag
                         - check_width
ft_printf - ft_vsprintf  - check_precision
                         \ check_conversion - conversion %, c, s
                                            \ conversion p, int, x - print_numbers

```

## 2. Makefile
```
$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) all	  //go into the libft dir and run make all
	@cp $(LIBFT_DIR) $(LIBFT_LIB) $@ //cp the archived file as the name of the target
	$(AR) $@ $^	                //append printf's objs
```

## 3. Reference
- [tovalds github](https://github.com/torvalds/linux/blob/master/arch/x86/boot/printf.c) <br>
- [apple opensource](https://opensource.apple.com/source/xnu/xnu-201/osfmk/kern/printf.c.auto.html)<br>
- [cpp reference](https://en.cppreference.com/w/cpp/io/c/fprintf)<br>
- [libc printf](https://android.googlesource.com/kernel/lk/+/9d564f1bd646819a9824c5a55c73521cb4f8fb81/lib/libc/printf.c)

## 4. Tester
- [paulo-santana](https://github.com/paulo-santana/ft_printf_tester) - examine over a thousand cases. <br>
- [francinette](https://github.com/xicodomingues/francinette) - Integrated testing framework for 42

---
Any suggestions or inputs are always welcomed! <br>
More details are in my [personal blog](https://velog.io/@ilp-sys)(Korean)
