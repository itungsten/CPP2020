gcc -c *.c
g++ -c *.cpp -I include -std=c++11
g++ *.o -lgdi32 -lole32 -loleaut32 -luuid -lwinmm -lmsimg32 -o sprite.exe -mwindows
del *.o