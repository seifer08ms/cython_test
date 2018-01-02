#!/usr/bin/env python3
# coding=utf-8
from __future__ import print_function

from cysize import PySize

s1 = PySize(y=3)
s2 = PySize(1, 2)
print('s1=', s1)
print('s2=', s2)
s3 = s1 + s2
print('s3 = s1 + s2 = ', s3)
s3 += s3
print('s3+=s3 = ', s3)
print('s3 == s2', s3 == s2)
print('-s3=', -s3)
s4 = s3 - s2
print('s4 = s3 - s2 = ', s4)
s4 -= s1
print('s4 -= s1 = ', s4)

from cypoint import PyPoint

p1 = PyPoint(1, 2)
print('p1 = ', p1)
print('from s4 = ', PyPoint(s4))
ps4 = PyPoint(s4)
print('p1 + p(s4) = ', p1 + p1)
