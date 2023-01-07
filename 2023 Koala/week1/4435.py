n = int(input())
for battle in range(n):
    a,b,c,d,e,f = map(int,input().split())
    g,h,i,j,k,l,m = map(int,input().split())
    gandalf = a + 2*b + 3*c + 3*d + 4*e + 10*f
    sauron = g + 2*h + 2*i + 2*j + 3*k + 5*l + 10*m
    if gandalf > sauron:
        print("Battle {0}: Good triumphs over Evil".format(battle+1))
    elif gandalf == sauron:
        print("Battle {0}: No victor on this battle field".format(battle+1))
    else:
        print("Battle {0}: Evil eradicates all trace of Good".format(battle+1))