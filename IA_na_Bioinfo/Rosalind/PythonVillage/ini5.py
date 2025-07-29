with open("entries/rosalind_ini5.txt") as file:
    result = ""
    i = 0
    for line in file:
        i += 1
        if i%2 != 0:
            continue
        result += line.strip() + "\n"
    print(result.strip())
