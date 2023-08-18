# Name of the static library to be built
Library = libftprintf

SRC = "~/libftprintf"

# List of source files (C functions) without the ".c" extension
# Find all files ending with ".c" in the current directory
files = $(wildcard ./*.c)

# Not 100% sure why but the files found end with .c.c so we need to remove the second .c
targets = $(files:%.c=%)

# Compiler to be used
Compiler = cc

# Compiler flags for the compilation process
CmpFlags = -g -Wall -Wextra -Werror

# Output name for the static library
OUTN = $(Library).a

# List of source files with ".c" extension
CFILES = $(targets:%=%.c)

# List of object files with ".o" extension (generated from C source files)
OFILES = $(targets:%=%.o)

# Target name for the final library file
NAME = libftprintf.a

# Rule to build the library
# This is the stupidest shit I have ever coded and that's saying a lot
# It extracts libft into a bunch of .o files, compiles printf into a bunch of .o files then recompiles all of them into a .a file
# This sucks a truly ungodly amount of ass, please kill me
$(NAME): $(OFILES)
	@make -C libft
	ar -x libft/libft.a
	$(Compiler) $(CmpFlags) -c $(CFILES)
	ar -crs $(NAME) $(OFILES) $(wildcard ./*.o)
	rm -f "__.SYMDEF SORTED"


# Default target is "all," which builds the library
all: $(NAME)

exe:
	@make -C libft
	$(Compiler) $(CmpFlags) $(CFILES)

# Rule to clean up object files and the library
clean:
	rm -f $(NAME)
	rm -f $(OFILES)
	rm -f $(wildcard ./*.o)

# Rule to remove all generated files, including the library
fclean: clean
	rm -f $(NAME)

# Rule to force a rebuild of the library
re: fclean all

# Declaring the phony targets (targets that don't represent files)
.PHONY: all, clean, fclean, re
