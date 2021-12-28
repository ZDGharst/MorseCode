compile_and_run:
	g++ -std=c++17 -o obj/MorseCode.o -I include/ src/*.cpp
	./obj/MorseCode.o

profiler: diagnostics strace

diagnostics:
	/usr/bin/time -v -p -o profile/time.log ./obj/MorseCode.o
	
strace:
	strace -o profile/strace.log ./obj/MorseCode.o
