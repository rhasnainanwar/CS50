amount = -1.0

while amount < 0:
    amount = float(input("How much is owed? "))
    
owed = round(amount * 100)
coins = 0
quarter = 25
dime = 10
nickel = 5
penny = 1
    
if owed >= quarter :
    coins += owed//quarter
    owed = int(owed) % quarter

if owed >= dime :
    coins += owed//dime
    owed = int(owed) % dime

if owed >= nickel :
    coins += owed//nickel
    owed = int(owed) % nickel

if owed >= penny :
    coins += owed

print(coins)
