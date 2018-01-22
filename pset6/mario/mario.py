height = -1
while height < 0 or height > 23:
    height = int(input("Height: "))
    
for i in range(height):
    print(" "*(height - i - 1),"#"*(i + 1),"#"*(i + 1))