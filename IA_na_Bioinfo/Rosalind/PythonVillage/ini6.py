with open("entries/rosalind_ini6.txt") as file:
    line = file.readline()
    dictionary = {}
    for word in line.strip().split(' '):
        if word in dictionary:
            dictionary[word] += 1
        else:
            dictionary[word] = 1

    for key in dictionary:
        print(key, dictionary[key])