CXX = g++
CXXFLAGS = -O3 -g -pipe -Wall -Wextra -Wpedantic
LIBS = -lgmpxx

ZetaStack.exe: src/ZetaStack.o src/Zetacompiler.o src/Execute.o src/Preprocessor.o src/variable.o src/Cache.o src/Entropy.o src/Function.o src/Link.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

src/ZetaStack.o: src/ZetaStack.cpp src/Zetacompiler.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

src/variable.o: src/variable.cpp src src/variable.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

src/Zetacompiler.o: src/Zetacompiler.cpp src/Zetacompiler.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

src/Preprocessor.o: src/Preprocessor.cpp src/Preprocessor.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

src/Execute.o: src/Execute.cpp src/Execute.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

src/Cache.o: src/Cache.cpp src/Cache.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

src/Entropy.o: src/Entropy.cpp src/Entropy.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

src/Function.o: src/Function.cpp src/Function.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

src/Link.o: src/Link.cpp src/Link.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)
