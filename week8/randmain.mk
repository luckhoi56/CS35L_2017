randmain: randmain.o randcpuid.o

	$(CC) $(CFLAGS) randmain.o randcpuid.o -ldl -Wl,-rpath=$(PWD) -o randmain

randlibhw.so: randlibhw.c

	$(CC) $(CFLAGS) randlibhw.c -shared -fPIC -o randlibhw.so

randlibsw.so: randlibsw.c

	$(CC) $(CFLAGS) randlibsw.c -shared -fPIC -o randlibsw.so

# 1. static linking to combine randmain.o and
# randcpuid.o into executable file
# dynamic linking to C library before main
# function is called
#3. after main function is called, dynamic linking using 
# dlsym