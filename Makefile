build:
	@cd src; \
		g++ -O3 -o ../raytracing *.cpp -lSDL3
