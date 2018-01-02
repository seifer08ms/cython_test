#!/bin/bash
g++ -fPIC -shared  Rectangle.h Rectangle.cpp  -o ./lib/libRect.so
