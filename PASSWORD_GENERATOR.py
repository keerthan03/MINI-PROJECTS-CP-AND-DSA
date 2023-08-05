#importing string and random library
import string
import random

#input from the user
a = int(input("How many letters do you want in your password? "))
b = int(input("How many numbers do you want in your password? "))
c = int(input("How many symbols do you want in your password? "))

#using some predefined fuction from the respective library
upper = string.ascii_uppercase
lower = string.ascii_lowercase
numbers = string.digits
symbols = string.punctuation

# using random.choices() to allow repetition
letter = random.choices(upper + lower,k=a)
num = random.choices(numbers, k=b)
sym = random.choices(symbols, k=c)

# concatenate the lists and shuffle them
word = letter + num + sym
random.shuffle(word)

# join the shuffled list elements to create the password
password = "".join(word)
print('The Generated Password is '+password)
