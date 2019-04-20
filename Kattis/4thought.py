op = ['+','-','/','*']

dataset = {}

for i in op:
    for j in op:
        for k in op:
            evaled = 0
            exec("evaled = 4%c4%c4%c4" % (i,j,k))
            dataset[evaled] = "4 %c 4 %c 4 %c 4 = %d" % (i,j,k,evaled)

TC = int(input())

for i in range(TC):
    n = int(input())
    if n not in dataset:
        print "no solution"
    else:
        print dataset[n]     