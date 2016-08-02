num = raw_input("number:")
num = int(num)
num_2 = 2 * num + 1;
matrix = [[0] * num_2 for i in range(num_2)]
print(matrix)

for i in range(num_2):
    for j in range(num_2):
        matrix[i][j] = i.__str__() + "," + j.__str__()
print(matrix)

print matrix[num][num]

for loop in range(num):
    circle = num - 1 - loop
    star = circle
    end = 2 * num + 1 - circle

    for n1 in range(star + 1, end):
        print matrix[star][n1],
    print ""

    for n2 in range(star + 1, end):
        print matrix[n2][end - 1],
    print ""

    for n3 in range(star, end - 1):
        print matrix[end - 1][end - 2 +circle - n3],
    print ""

    for n4 in range(star, end - 1):
        print matrix[end - 2 + circle - n4][star],
    print ""