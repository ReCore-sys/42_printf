### The game plan

- Split the string by %
- Add each one to a linked list
- on each string, get the first character and if it is a flag, replace it with the actual value
- do this by removing the first character and then using libft to join the remaining string with the value
- after doing this, join the linked list back together
- Need to figure out how to solve not replacing if the first char in the string is a flag character