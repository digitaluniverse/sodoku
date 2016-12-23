name = 'e1.txt'
form = ""
#print name
with open(name, 'r+') as myfile:
    data=myfile.read()
    lst = list(data)
    print lst
def deleteContent(myfile):
    myfile.seek(0)
    myfile.truncate()

with open(name, 'r+') as myfile:
    myfile.write(data)

''.join(data)

print data
    