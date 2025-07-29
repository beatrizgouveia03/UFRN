with open("entries/rosalind_ini2.txt") as file:
    lines = file.readlines()
    entry = lines[0].strip().split()
    a = int(entry[0])
    b = int(entry[1])
    print(a**2+b**2)