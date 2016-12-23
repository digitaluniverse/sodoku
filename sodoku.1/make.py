import subprocess
import os
proc=subprocess.Popen('ls *.cpp', shell=True, stdout=subprocess.PIPE, )
output=proc.communicate()[0]
files = "" 
test =  str.split(output)
for i in range(len(test)):
    files += test[i]+" "
run = "g++ -std=c++11 %s -o prog" %(files)
os.system(run)
os.system("./prog")
