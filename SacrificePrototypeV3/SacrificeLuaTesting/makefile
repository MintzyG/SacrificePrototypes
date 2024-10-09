CXX = g++
CXXFLAGS = -std=c++17 -I./Includes
LDFLAGS = -llua -lm -ldl -lgtest -lgtest_main -pthread

OBJDIR = objects

SOURCES = main.cpp externlua.cpp card.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

TARGET = game.out

all: $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJDIR) $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
	rm -rf $(OBJDIR)

# Phony targets
.PHONY: all clean

