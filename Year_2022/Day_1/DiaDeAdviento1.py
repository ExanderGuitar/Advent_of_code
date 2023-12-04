#Advent day 1
expense_file = open("EntradaDia1.txt", 'r')

position = expense_file.tell()
print(position)

print(expense_file.readline())
position = expense_file.tell()
print(position)
flag = False

for i in expense_file.readline():
    if i == '\n':
        print("culo")
#    fixed_value = expense_file.readline()
#    position = expense_file.tell()
#    print("Run")
#    int_fixed_value = int(expense_file.readline())
#
#    print("New fixed value: %i" % int_fixed_value)
#    print("My position is: %r" % position)
#
#    for j in expense_file:
#        dinamic_value = int(expense_file.readline())
#
#        if int_fixed_value + dinamic_value == 2020:
#            print("We have a winner for the test 2020. The numbers are: %i and %i. Their product is %i" % (int_fixed_value, dinamic_value, (int_fixed_value*dinamic_value)))
#            pass


print("/////////////////////////////////////////////////")
print("See you soon!")

expense_file.close()
