HERE:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
SHARED_LIBRARY:=bitmap.so
APP:=app.out

CXX = g++
CXX_FLAGS = -pipe -fPIC -O2 -Wall -W
LINKER_FLAGS = -shared -Wl,--verbose

# I can't understand why I need to declare the shared library as a make
# sourcefile. If I don't include it, this recipe is skipped.
$(APP): Bitmap.o main.o $(SHARED_LIBRARY)
	$(CXX) Bitmap.o main.o -o $(APP)

$(SHARED_LIBRARY): Bitmap.o
	$(CXX) $(LINKER_FLAGS) Bitmap.o -o $(SHARED_LIBRARY)

Bitmap.o: src/Bitmap.cpp
	$(CXX) -c $(CXX_FLAGS) src/Bitmap.cpp

main.o: src/main.cpp
	$(CXX) -c $(CXXFLAGS) src/main.cpp

# I can't understand why, but this pattern rule is not recognized
# %.o: %.cpp
# 	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY: help
help:
	@echo 'help    - Show this help and exit.'
	@echo 'install - Copy the shared library to the site-packages of the '
	@echo '          activated python virtual environment.'
	@echo 'clean   - Clean compilation output (.o, .so, .out).'
	@echo 'format  - Format C++ code with clang-format.'
	@echo 'test    - Run tests for the C++ library.'
	@echo 'run     - Run the app and display the bitmap with ImageMagick.'
	@echo ''
	@echo 'You are here: ${HERE}'

# .PHONY: install
# install: $(SHARED_LIBRARY)
# 	cp --force $(SHARED_LIBRARY) $(VENV)/lib/python3.6/site-packages/$(SHARED_LIBRARY)
# 	strip $(DESTDIR)/home/giacomo/.virtualenvs/sip-hello-world-QlxdDS6B/lib/python3.6/site-packages/$(SHARED_LIBRARY)

.PHONY: clean
clean:
	rm Bitmap.o
	rm main.o
	rm ${SHARED_LIBRARY}
	rm ${APP}
	rm test.bmp

.PHONY: format
format:
	clang-format -i -style=Google -verbose src/*.cpp
	clang-format -i -style=Google -verbose src/*.hpp

.PHONY: run
run:
	@echo 'Run the app and display the generated bitmap.'
	./$(APP)
	display test.bmp

.PHONY: test
test:
	@echo TODO: test C++ library
