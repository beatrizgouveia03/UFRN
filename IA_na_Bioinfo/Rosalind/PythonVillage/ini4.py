with open("entries/rosalind_ini4.txt") as file:
    lines = file.readlines()
    entry = lines[0].strip().split()
    a = int(entry[0])
    b = int(entry[1])
    sum = 0

    for i in range(a, b+1):
        if i % 2 != 0:
            sum += i
    print(sum)