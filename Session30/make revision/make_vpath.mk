CC=g++
C=gcc
OBJ= Date.o testDate.o src/math.o 
vpath=src #used with pattern rule

testdate: $(OBJ)
	$(CC) -o testdate Date.o testDate.o src/math.o 

# Pattern Rule : Apply for each object file
%.o: %.cpp
	$(CC) -c $<

clean:
	@echo "Removing Objects.."
	rm*.o

#Excute Even if not Updated = Execute even if no change -_0_-
.PHONY: cleanall cleanobj

cleanall: cleanobj

cleanobj:
	rm*.o