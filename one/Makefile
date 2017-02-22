
all : build
.PHONY : dist
dist :
	mkdir -p dist/
.PHONY : clean
clean :
	rm -rf dist/
build : dist
	clang++ -o dist/one -std=c++11 -Wpedantic src/main.cpp
