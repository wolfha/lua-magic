#
# Makefile for lua-magic
#

LUA=lua5.1

default:
	gcc -c -fPIC -Wno-implicit-function-declaration -Wall -m64 -lmagic -l$(LUA) -I/usr/include/$(LUA) src/magic.c -o src/lua-magic.o
	gcc -fPIC -Wl,-soname,lib$(LUA)-magic.so.0 -Wall -lmagic -l$(LUA) -I/usr/include/$(LUA) src/lua-magic.o -o src/magic.so -shared

clean:
	rm -f src/*.0
	rm -f src/*.so
	rm -f src/*.o
