def join(xx, yy):
    ret = [0, 0]
    if xx[1] > yy[1]:
        ret[1] = yy[1]
        if xx[0] > yy[1]:
            return [-1, -1]
    else:
        ret[1] = xx[1]
        if yy[0] > xx[1]:
            return [-1, -1]
    ret[0] = max(xx[0], yy[0])
    return ret
def check(kk, sol):
    for i in range(1, n):
        tmp = join(kk[i], kk[i-1])
        sol = join(tmp, sol)
        if sol[0] < 0:
            return 0
    return 1

x = input().split()
n = int(x[0])
cc = x[1]
t = 0
flag = 0
count = 0
for c in cc:
    if flag:
        count += 1
    if c == '.':
        flag = 1
    else:
        t *= 10
        t += int(c)
t *= 10**(4-count)
    
a = [int(x)*10000 for x in input().split()]
v = [int(x) for x in input().split()]
kk = []

for i in range(0, n):
    kk.append([a[i] - v[i] * t, a[i] + v[i] * t])
    if kk[i][0] < 10000:
        kk[i][0] = 10000
    if kk[i][1] > 10000000000000:
        kk[i][1] = 10000000000000

sol = kk[0]
print(check(kk, sol))