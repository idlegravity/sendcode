# Defines the RPI variable which is needed by rc-switch/RCSwitch.h
CXXFLAGS=-DRPI

all: sendcode

sendcode: rc-switch/RCSwitch.o sendcode.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi
	
clean:
	$(RM) rc-switch/*.o *.o sendcode

