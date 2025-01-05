gcc -c tm_stack.c -I ../../include/stack/ -I ../../include/singly/ -L ../../lib/ -ltm_singly -o tm_stack.o
ar rcs libtm_stack.a *.o
mv libtm_stack.a ../../lib/
rm -rf *.o
