# Python running example

from __future__ import print_function

import numpy as np
from rect import PyRectangle

# Initialising the wrapped c++ function
R1 = PyRectangle(0, 0, 9, 9)
R2 = PyRectangle(9, 9, 9, 9)
R4 = PyRectangle(19, 19, 19, 19)

print(R1.getLength())

# operactor test
print("R1 = ", R1)
print("R2 = ", R2)
print("R1 + R2 = ", R1 + R2)
print("R1 = ", R1)
print("R4 = ", R4)
R1 += R4
print("R1 = ", R1)
print("R1 - R2 = ", R1 - R2)
