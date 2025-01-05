gcc -c tm_doubly.c -I ../../include/doubly/ -o tm_doubly.o
ar rcs libtm_doubly.a *.o
mv libtm_doubly.a ../../lib/
rm -rf *.o
