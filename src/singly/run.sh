gcc -c tm_singly.c -I ../../include/singly/ -o tm_singly.o
ar rcs libtm_singly.a *.o
mv libtm_singly.a ../../lib/
rm -rf *.o
