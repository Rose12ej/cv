Python 3.13.1 (tags/v3.13.1:0671451, Dec  3 2024, 19:06:28) [MSC v.1942 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> """This simple Python Program collects user input
... and computes retirement planning advice
... Written by: 
... Rosalia Nunez Leon
... for LU's CSIS 110 course 
... Spring 2023
... Be sure you fully document your code with 
... comments like you see here."""
... 
... """getting the following information from user:
... Full Name
... Current Age
... Desired Retirement Age
... Current Level of Retirement Savings
... Total Amount of Retirements Savings Needed at Retirement"""
... 
... fullName = input ("Enter your full name:")
... x = input("Enter your current age:")
... currentAge = int(x)
... x = input ("Enter desired retirement age:")
... retirementAge = int(x)
... x = input("Enter current level of retirement savings:")
... currentSavings = int(x)
... x = input("Enter the total amount of retirement savings desired to retire:")
... goalSavings = int(x)
... 
... 
... """output name, years left to retire, and
... how much needs to be saved to reach goal"""
... 
... yearsLeft = retirementAge - currentAge
... savingsNeeded = goalSavings - currentSavings
... print("\n Retirement Plan")
... print("Name: ", fullName)
... 
... if yearsLeft > 0:
...     print("Years left to retire: ", yearsLeft)
else:
    print("Years left to retire: You have already reached your retirement age!")

if savingsNeeded > 0:
    print ("Savings needed to retire: ", savingsNeeded)
else:
    print("Savings needed to retire: You have already reached your desired savings!")
        

""" exiting when user is ready"""

