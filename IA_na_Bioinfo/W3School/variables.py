#Python variables are created when you assign a value to them.
#Example:
x = 5
y = "Hello, World!"
print(x) # Output: 5
print(y) # Output: Hello, World!

# Variables do not need to be declared with any particular type and can even change type after they have been set.
# Example:
x = 4       # x is of type int
x = "Sally" # x is now of type str
print(x) # Output: Sally

#If you want to specify the data type of a variable, this can be done with casting.
# Example:
x = str(3)    # x will be '3'
y = int(3)    # y will be 3
z = float(3)  # z will be 3.0
print(x) # Output: 3
print(y) # Output: 3
print(z) # Output: 3.0

#You can get the data type of a variable with the type() function.
# Example:
x = 5
y = "John"
print(type(x)) # Output: <class 'int'>
print(type(y)) # Output: <class 'str'>

#String variables can be declared either by using single or double quotes.
# Example:
x = "John"  # is the same as x = 'John'
y = 'John'  # is the same as y = "John"
print(x) # Output: John
print(y) # Output: John

#Variable names are case-sensitive.
# Example:
a = 5
A = "John"
print(a) # Output: 5
print(A) # Output: John

#Variable names must start with a letter or underscore (_), followed by letters, numbers, or underscores.
# Example:
myvar = "John" # valid variable name
my_var = "John" # valid variable name
_my_var = "John" # valid variable name
myVar = "John" # valid variable name
MYVAR = "John" # valid variable name
myvar2 = "John" # valid variable name

# myvar = "John" # invalid variable name (cannot start with a number)
# my-var = "John" # invalid variable name (cannot contain hyphen)
# my var = "John" # invalid variable name (cannot contain space)

#Multi words variables names can be difficult to read. The best way to avoid this is to use one of hte techniques below:
# Example:
# camelCase
myVariableName = "John" # camelCase
# PascalCase
MyVariableName = "John" # PascalCase
# snake_case
my_variable_name = "John" # snake_case

#Python alows you to assign values to multiple variables in one line.
# Example:
x, y, z = "Orange", "Banana", "Cherry"
print(x) # Output: Orange
print(y) # Output: Banana
print(z) # Output: Cherry

#You can also assign the same value to multiple variables in one line.
# Example:
x = y = z = "Orange"
print(x) # Output: Orange
print(y) # Output: Orange
print(z) # Output: Orange

#You can also unpack a collection (list, tuple, set) into variables.
# Example:
my_list = ["apple", "banana", "cherry"]
x, y, z = my_list
print(x) # Output: apple
print(y) # Output: banana
print(z) # Output: cherry

#The print() function is used to print the value of a variable.
# Example:
x = "Python is awesome"
print(x) # Output: Python is awesome

#You can also use the print() function to print multiple variables at once.
# Example:
x = "John"
y = 36
print(x, y) # Output: John 36

#For numbers, the + character works as a mathematical operator.
# Example:
x = 5
y = 10
print(x + y) # Output: 15

#Global variables are variables that are declared outside of a function and can be accessed from anywhere in the code.
# Example:
x = "awesome" # global variable
def myfunc():
    print("Python is " + x) # accessing global variable
myfunc() # Output: Python is awesome

def myfunc2():    
    x = "fantastic" 
    print("Python is " + x) # accessing local variable
myfunc2() # Output: Python is fantastic
print("Python is " + x) # Output: Python is awesome

#To create a global variable inside a function, you can use the global keyword.
# Example:
x = "awesome" # global variable
def myfunc():
    global x # declare x as global variable
    x = "fantastic" # change the value of global variable
    print("Python is " + x) # accessing global variable
myfunc() # Output: Python is fantastic
print("Python is " + x) # Output: Python is fantastic