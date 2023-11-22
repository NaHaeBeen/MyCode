word = input("Enter words: ")
word_list = word.split()

print("약자:", end=' ')

for x in word_list:
    print(x[0], end='')
