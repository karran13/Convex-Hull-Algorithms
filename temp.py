import matplotlib.pyplot as plt
fa=open('andrew_time.txt');
xa=[]
ya=[]
lines=fa.readlines()
for ln in lines[0:len(lines)]:
    a,b=ln.strip().split()
    xa.append(a)
    ya.append(b)
plt.xlabel('Number of points')
plt.ylabel('Time taken')
plt.plot(xa,ya,'r')
fb=open('graham_time.txt');
xb=[]
yb=[]
lines=fb.readlines()
for ln in lines[0:len(lines)]:
    a,b=ln.strip().split()
    xb.append(a)
    yb.append(b)
plt.plot(xb,yb,'g')
fc=open('jarvis_time.txt');
xc=[]
yc=[]
lines=fc.readlines()
for ln in lines[0:len(lines)]:
    a,b=ln.strip().split()
    xc.append(a)
    yc.append(b)
plt.plot(xc,yc,'b')
plt.savefig('time_anal.png')