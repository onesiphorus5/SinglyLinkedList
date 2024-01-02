doctest_path := doctest/doctest
src_path := src
lib_path := lib

CXX := g++

libList.so: $(src_path)/list.cc
	(mkdir -p $(lib_path) && $(CXX) $< -shared -fPIC -o $(lib_path)/$@)

tests: tests.cc libList.so
	$(CXX) tests.cc -o $@ -I $(doctest_path) -I $(src_path) -L $(lib_path) -lList

run_tests: tests libList.so
	LD_LIBRARY_PATH=$(lib_path) ./tests