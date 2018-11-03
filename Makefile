HERE:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
SHARED_LIBRARY:=bitmap.so
APP:=app.out

# Avoid hard-coding g++, pick the g++ version from the CXX environment variable.
# This is useful when building the project with Travis CI.
# CXX = g++
CXX_FLAGS = -pipe -fPIC -O2 -Wall -W
LINKER_FLAGS = -shared -Wl,--verbose

CATCH_URL:=https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp

# This seems to work, but prevents the recipe that builds app.out from being
# executed. Why is that?
# $(SHARED_LIBRARY): src/Bitmap.cpp
# 	@echo 'Compile and link $< to shared library $(SHARED_LIBRARY)'
# 	$(CXX) src/Bitmap.cpp -shared -fPIC --verbose -o $(SHARED_LIBRARY)

$(APP): Bitmap.o main.o
	@echo 'Link object files $^ to assembler output $(APP)'
	$(CXX) Bitmap.o main.o -o $(APP)

%.o: src/%.cpp
	@echo 'Compile src file $< to object file $@'
	$(CXX) -c $(CXXFLAGS) $<

.PHONY: help
help:
	@echo 'help    - Show this help and exit.'
	@echo 'install - Copy the shared library to the site-packages of the '
	@echo '          activated python virtual environment.'
	@echo 'clean   - Clean compilation output (.o, .so, .out).'
	@echo 'format  - Format C++ code with clang-format.'
	@echo 'test    - Test the C++ library with Catch.'
	@echo 'docs    - Create documentation with Doxygen.'
	@echo 'run     - Run the app and display the bitmap with ImageMagick.'
	@echo ''
	@echo 'You are here: ${HERE}'
	@echo 'The project will be built with this compiler: $(CXX)'

# .PHONY: install
# install: $(SHARED_LIBRARY)
# 	cp --force $(SHARED_LIBRARY) $(VENV)/lib/python3.6/site-packages/$(SHARED_LIBRARY)
# 	strip $(DESTDIR)/home/giacomo/.virtualenvs/sip-hello-world-QlxdDS6B/lib/python3.6/site-packages/$(SHARED_LIBRARY)

.PHONY: clean
clean:
	@echo 'clean   - Clean compilation output (.o, .so, .out).'
	rm --force Bitmap.o
	rm --force main.o
	rm --force ${SHARED_LIBRARY}
	rm --force ${APP}
	rm --force test.bmp
	rm --force TestBitmap.o
	rm --force test_suite.out

.PHONY: format
format:
	@echo 'format  - Format C++ code with clang-format.'
	clang-format -i -style=file -verbose src/*.cpp
	clang-format -i -style=file -verbose src/*.hpp
	clang-format -i -style=file -verbose tests/*.cpp

.PHONY: run
run:
	@echo 'run     - Run the app and display the bitmap with ImageMagick.'
	./$(APP)
	display test.bmp

.PHONY: test
test:
	@echo 'test    - Test the C++ library with Catch.'
	@echo 'Download Catch single header file'
	wget -O tests/catch.hpp $(CATCH_URL)
	$(CXX) -c tests/TestBitmap.cpp
	$(CXX) TestBitmap.o -o test_suite.out
	./test_suite.out

.PHONY: docs
docs:
	doxygen docs/Doxyfile
