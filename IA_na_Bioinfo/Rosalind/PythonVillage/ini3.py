with open("entries/rosalind_ini3.txt") as file:
    lines = file.readlines()
    phrase = lines[0].strip()
    entry = lines[1].strip().split()
    a = int(entry[0])
    b = int(entry[1])
    c = int(entry[2])
    d = int(entry[3])

    word1 = phrase[a:b+1]
    word2 = phrase[c:d+1]
    print(word1, word2)