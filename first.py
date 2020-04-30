print('Hello python')
x="Hello   0.5432"
print(x.lower())
count=0
for word in x :
    if word=='l' :
        count=count+1
print(count)
p=x.find('0')
print((x[p:]))
q=x.replace('Hell','helloooo')
print(q+' '+'bye')
print(q.capitalize())

#List evaluation from a file
cou=0
li=list()
fn=input("Enter file name")
f=open(fn)
for line in f :
    if line.startswith("I") :
        cou=cou+1
        for word in line.split() :
            if word not in li :
                li.append(word)
li.sort()
print(count,li)
num=[1,2,3,4,5,111,32,-98]
print(sum(num)/len(num))

#Dictonary part
word = 'brontosaurus'
d = dict()
for c in word:
    d[c]=d.get(c,0)+1
print(d)
#dictonary part for file
fname = input('Enter the file name: ')
try:
    fhand = open(fname)
except:
    print('File cannot be opened:', fname)
    exit()

counts = dict()
for line in fhand:
    words = line.split()
    for word in words:
        counts[word]=counts.get(word,0)+1
print(counts)

maximum = 0
k = 0
for key,value in counts.items():

    if maximum is 0 or value>maximum:
        maximum = value
        k=key
print(k,maximum)
