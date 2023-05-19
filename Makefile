source_files = color.cpp shapes.cpp ppm_img.cpp ppm_test.cpp
object_files = color.o shapes.o ppm_img.o ppm_test.o
.PHONY: test
test: compile
	./test > image.ppm
	open image.ppm
debug: compile
	gdb test
compile:
	g++ -g -c $(source_files)
	g++ -o test $(object_files)
clean:
	rm -f *.o
	rm -f test
	rm -f err.txt
	rm -f image.ppm
	rm -f test.ppm
