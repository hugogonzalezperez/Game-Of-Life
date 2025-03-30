# Compilador y banderas
CXX = g++
CXXFLAGS = -g -c -std=c++20 -I/usr/include/SDL2
LDFLAGS = 
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

# Archivos fuente y ejecutable
SRC = src/main.cc
OBJS = $(SRC:.cc=.o)
EXECUTABLE = bin/GameOfLife

# Reglas principales
.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	mkdir -p bin
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)
	@echo ✅ All done!

%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(OBJS) $(EXECUTABLE)
	rm -rf bin
	@echo 🧹 Clean done!