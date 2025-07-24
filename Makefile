all:
	g++ src/*.cpp main.cpp -Iinclude -o forca

clean:
	rm -rf forca 