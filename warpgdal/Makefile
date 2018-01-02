CXX=g++
PACK_NAME=readtif

all:
	python setup.py build_ext --inplace

clean:
	rm -rf build ${PACK_NAME}.cpp ${PACK_NAME}.so ${PACK_NAME}.*.so 

test:
	python test.py
 
deps:
	pip install -r requirements-dev.txt

clib:
	${CXX}  -fPIC -shared  Rectangle.h Rectangle.cpp  -o ./lib/libRect.so
	
ctest:
	${CXX} -Wl,-rpath='$$ORIGIN/lib'  -I./include  -L./lib  gdalreadtest.cpp -lgdal  -o gdaltest
