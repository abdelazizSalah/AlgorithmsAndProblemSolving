#for i in range(10, 16 ,3): #range function takes 3 parameters -> start -> end -> step
#    print("hi")

#from PIL import Image , ImageFilter # all libraries should be installed if you want to use them
#def add (dictionary):#def to define the fucntion then we write the name then the parameter list
#    file = open(ddictionary, "r")
#    for line in file:
#        words.add(line.rstrip())

x = int( input ("x:") ) # if we didn't do a casting it will deal with it as a string not integer
y = int( input ("y:") )
print (x + y) 

#lets do a division
print(x / y) #-> no int division it will give the right float answer

#conditions 
if x < y : 
    print ("x is less than y")
elif x > y:
    print("x is greater than y")
elif x == y :
    print ("x is equal to y")

S = input ("Do you Agree? ")
#in order to avoid this conditions we can use this trick
#if S.lower() in ["y" , "yes"] -> this covers all the conditions 
if S == "Y" or S == "y" or S == "YES" or S == "yes": # we use the words (or, and , not), also there is no difference between '' and " ", every thing is string even if it is only one character
    print("Agree")
else :
    print("Disagree")

def meow():#to use a function it must be declared above the usage
    print("meow")

for i in range(3): 
    meow()

#in order to print without an automatic new line we use
for i in range(4):
    print("?" , end = " ") #end is ending every line with the given string #the default is "/n"
#or we can use this 
print() #this print new line
print("? " * 10)

#do while concept
#we make an infinte loop and put a condition to exit this loop
while True :
    i = int (input("insert number"))
    if i < 0 : 
        break 

#arrays and lists
scores= [12 , 6 , 20]
print(f"average = {str(sum(scores) / len(scores))}") #we need to convert the integer to string in order to not make a mistake and print it easily

#dynamic allocating
grades = [] #this is how we define empty list
i =int (input("enter integer"))

for k in range(i):
    grades.append(int(input("enter the grades"))) #append adds values to ur list

names = ["samy", "Ziz", "mona"]

#in function that do a linear search
if "Ziz" in names: 
    print ("found")
else :
    print("not found")


#dictionary-> similar to maps -> uses sth like hashtables to make the search in constant time 
people = {
    "abdo": "01153705735",  
    "ahmed": "01147137622"
    }
name = input("name: ")
if name in people: 
    print(f"number: {people[name]}")

#how to swap?
h = 12
j = 90
h , j = j , h 
print(f"j = {j} , h = {h}")

#how to make a file and read and write in it
file = open("phonebook.csv", "a")
name = input("Name: ")
number = input ("Number: ")

writer = csv.writer(file)
writer.writerow([name, number])
file.close()






