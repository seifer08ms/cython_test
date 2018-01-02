CXX=g++
SRC_PATH=PyGISCore

all:
	python setup.py build_ext --inplace

force:
	python setup.py build_ext --inplace -f

clean:
	rm -rf build ${SRC_PATH}/PySize.cpp ${SRC_PATH}/PySize.so ${SRC_PATH}/PySize.*.so 

test:
	python test.py

# clib:
# 	rm -rf lib
# 	mkdir lib
# 	${CXX}  -fPIC -shared  Rectangle.h Rectangle.cpp  -o ./lib/libRect.so

