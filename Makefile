all:
	mkdir -p build
	gcc src/* -l raylib -o build/cgol
clean:
	rm -r -f build
	rn -r -f debug_build
debug:
	mkdir -p debug_build
	gcc src/* -l raylib -o debug_build/cgol -g