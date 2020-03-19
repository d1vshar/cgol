all:
	mkdir -p build
	gcc -o build/cgol -l raylib src/main.c src/ui.c src/ui.h
clean:
	rm -r -f build
	rn -r -f debug_build
debug:
	mkdir -p debug_build
	gcc -g -o debug_build/cgol -l raylib src/main.c src/ui.c src/ui.h