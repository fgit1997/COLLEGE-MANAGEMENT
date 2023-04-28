
# import OS module
import os
from difflib import SequenceMatcher
import sys
import time

file = open("plagresult.txt","w")
file.close()
#os.remove("plagresult.txt")

#print ('Number of arguments:',len(sys.argv))
#print ('Arguments:', str(sys.argv))
#print(sys.argv[1]) #will print main.py

 
# Get the list of all files and directories
path="C:/Users/Desktop/pythonplagrisim/Files"
dir_list = os.listdir(path)
 
print("Files and directories in '", path, "' :")
 
# prints all files
print(dir_list)

for submittedfiles in dir_list:
  print(submittedfiles )
  fileslocation=path+"/"+submittedfiles
  print(fileslocation)

  with open(fileslocation) as file1, open(sys.argv[1]) as file2:
    file1data=file1.read()
    file2data=file2.read()
    print("FILES DATA:",file1data)
    print("ARG FILE:",file2data)
    similarity=SequenceMatcher(None,file1data,file2data).ratio()
    similarityvalue=similarity*100
    similaritypercent=round(similarityvalue)
    print(similaritypercent)
    f = open("plagresult.txt", "a")
    #f.write(submittedfiles+":"+file1data+":"+str(similaritypercent))
    f.write(submittedfiles+":"+str(similaritypercent))
    f.write("\n")
    f.close()