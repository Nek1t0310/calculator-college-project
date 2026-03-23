# calculator-college-project
Simple, universal calculator, that can calculate in different number system

# now we have:
suppord systems:
- Binary(2)
- Octal(8)
- Decimal(10)
- Hexdecimal(16)

possibilities:
- check input
- user error defence
- translation between systems

# attention 1: 
Now you can see cycles while in each cpp file, this is explained by the fact that I submit these files as labs work to the teacher, they require: communication between the program and the user

# Issues!
Due to the use of floating-point arithmetic (`long double`), some inaccuracies may occur when working with fractional numbers.
This is related to the IEEE 754 standart

Possible effects: 
- numbers like `0.1`, `0.2`, `0.3` may be represented as `0.199999...`, `0.299999...`
- precision errors with float part
- rare cases where values slightly exceed expected boundaries (e.g. `0.999999 → 1.0`)
  for example 0.9999999(in 10) -> 1(in 10)

# in plans:
In fiture i wont postpone calculate to python for finaly passing and make good UI with Tkinter.
C++ i understand better, because now writing functions on it
