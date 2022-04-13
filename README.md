1. Install Google-gtest
	clone googletest
	mkdir build && cmake .. -DBUILD_GMOCK=ON
	make install

2. How to build
	mkdir build
	cmake ..

3. How to run
	cd build
	./hello_test

Refers
	https://google.github.io/googletest/quickstart-cmake.html
GMock
	https://google.github.io/googletest/gmock_for_dummies.html#getting-started
