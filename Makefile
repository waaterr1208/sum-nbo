TARGET=sum-nbo
CXXFLAGS=-g

all: $(TARGET)

$(TARGEt): sum-nbo.o
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@
