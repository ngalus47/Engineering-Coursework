def myfunction():
  return 3+3
  print("Hello, World!")

print(myfunction())

a = "hello"
b = "welcome to the jungle"
c = "10.000"

print(a.zfill(10))
print(b.zfill(10))
print(c.zfill(10))

ownerCut = 5

print("${:,.2f}".format(ownerCut))

cars = ["Ford", "Volvo", "BMW"]
print(cars)

x = cars[0]
print(x)
cars[0] = "Toyota"
print(cars[0])
x = len(cars)
print(x)
for x in cars:
	print(x)
cars.append("Honda")
print(cars)

userInput = str(input("enter some stuff"))
for x in userInput:
	print(x)

lst = []

n = int(input("Enter number of elements : "))

for i in range(0, n):
	ele = int(input())

	lst.append(ele)

total = sum(lst) / n
print(total)
