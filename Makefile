all:
	mkdir -p build
	gcc -o build/main -l raylib main.c
clean:
	rm -r -f build
	rn -r -f debug_build
debug:
	mkdir -p debug_build
	gcc -g -o debug_build/main -l raylib main.c