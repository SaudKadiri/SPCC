keywords = [
    'auto', 'break', 'case', 'char', 'const', 'continue', 'default', 'do', 'double',
    'else', 'enum', 'extern', 'float', 'for', 'goto', 'if', 'int', 'long', 'register',
    'return', 'short', 'signed', 'sizeof', 'static', 'struct', 'switch', 'typedef',
    'union', 'unsigned', 'void', 'volatile', 'while'
]

# remove all the special characters from `text`. e.g.: if text is 'a;' then only 'a' is returned
fix = lambda text: ''.join([x for x in text if x.isalnum()])

with open('program.txt', 'r') as f:
    tokens = []

    # Step 1: Storing all the tokens from the input C program
    for token in f.read().split():
        # check for operators; which are also special characters
        if token in '+=*/%=':
            tokens.append(token)
            continue
        token = fix(token)
        if token:
            tokens.append(token)

    # Step 2: Classifying each of the tokens
    for token in tokens:
        if token in keywords:
            print(f'{token} is a keyword')
        elif not token.isalnum():
            print(f'{token} is an operator')
        else:
            print(f'{token} is an identifier')
