# a declaration example is a = b; a is the lhs and b is the rhs
# here the key will be lsh and the value will be rhs
declarations = {}

with open("input.txt", "r") as f:
    for line in f.readlines():
        lhs, rhs = line.split('=')
        rhs = rhs[:-1]  # pop the '\n' from the rhs
        for key, val in declarations.items():
            rhs = rhs.replace(val, key)
        if rhs not in declarations.values() and rhs not in declarations.keys():
            declarations[lhs] = rhs

# Create the output
with open("output.txt", "w") as f:
    for key, val in declarations.items():
        f.write(f"{key}={val}\n")
