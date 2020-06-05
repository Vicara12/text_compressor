
ALL_O = main.o chartree.o domainctl.o presentationctl.o compressor.o \
extractor.o persistencectl.o

PROGRAM_NAME = text_compressor

OPTIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11

all: text_compressor

text_compressor: $(ALL_O)
	g++ $(OPTIONS) -o $(PROGRAM_NAME) $(ALL_O)

cleano:
	rm $(ALL_O)

clean:
	rm $(ALL_O) $(PROGRAM_NAME)


main.o: main.cc
	g++ $(OPTIONS) -c main.cc

chartree.o: chartree.cc chartree.hh
	g++ $(OPTIONS) -c chartree.cc

domainctl.o: domainctl.cc domainctl.hh presentationctl.hh compressor.hh extractor.hh persistencectl.hh
	g++ $(OPTIONS) -c domainctl.cc

presentationctl.o: presentationctl.cc presentationctl.hh
	g++ $(OPTIONS) -c presentationctl.cc

compressor.o: compressor.cc compressor.hh algorithm.hh domainctl.hh persistencectl.hh
	g++ $(OPTIONS) -c compressor.cc

extractor.o: extractor.cc extractor.hh algorithm.hh
	g++ $(OPTIONS) -c extractor.cc

persistencectl.o: persistencectl.cc persistencectl.hh domainctl.hh exceptions.hh
	g++ $(OPTIONS) -c persistencectl.cc
