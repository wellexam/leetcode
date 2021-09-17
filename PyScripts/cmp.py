dic1 = {}
dic2 = {}
f1 = open("text.txt", mode='r')
f2 = open("text2.txt", mode='r')
list1 = f1.readlines()
list2 = f2.readlines()
for i in list1:
    i.strip("\n")
    dic1[i] = True
for i in list2:
    i.strip("\n")
    dic2[i] = True
for i in dic1:
    # print(i, end = "")
    if i not in dic2:
        print(i)