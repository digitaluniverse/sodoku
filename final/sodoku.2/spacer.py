x=6
name = 'e%d.txt'%(x);
with open(name, 'r+') as myfile:
    data=myfile.read().replace('', ' ')

def deleteContent(myfile):
    myfile.seek(0)
    myfile.truncate()
with open(name, 'r+') as myfile:

    myfile.write(data)
    print data

