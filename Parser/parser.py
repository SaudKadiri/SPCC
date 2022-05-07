import re

# does three things:
#   1. re.search('>(.*?)<', x).group() returns a new string of the form `>This is some text<`
#   2. [1:-1] converts the string to `This is a message`
#   3. strip(' '): Strip all spaces from the head and tail of the previous string.
parser = lambda x: re.search('>(.*?)<', x).group()[1:-1].strip(' ')

input1 = "<h1>This is a statement</h1>"
input2 = "<h1>         This is a statement with  some spaces</h1>"
input3 = "<p> This is a statement with some @ #$ ., / special characters</p>         "

print(parser(input1))
print(parser(input2))
print(parser(input3))
