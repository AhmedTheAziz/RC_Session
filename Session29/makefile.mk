CC=g++
C=gcc
OBJs= Date.o testDate.o
Target= app2
LFLAG=-o
Use_sum=2

$(Target) : $(OBJs)
	@echo "--exe File is BUilding--" 
	$(CC) $(LFLAG) $@ $(OBJs)
# $@ == testdate.exe (target)

#testDate.o: testDate.cpp Date.h
#	@echo "--TestDate.o is Building--"
#	$(C) -c $<  
# $< == testDate.cpp (first dependency)

#Date.o : Date.cpp Date.h
#	@echo "--Date.o is Building--"
#	$(CC) -c $*.cpp 
# $*.cpp == Date (first dependency sufics)

#Pattern Rule


ifeq ($(Use_sum),1)
	@echo "IF cond."
testDate.o: testDate.cpp Date.h
	@echo "--Building testDate--"
	g++ -c testDate.cpp
Date.o: Date.cpp Date.h
	@echo "--Building Date--"
	g++ -c Date.cpp	

else
	@echo "Else cond."
%.o: %.cpp
	@echo "--Building--"
	$(CC) -c $<
	
endif
#.PHONY: Date.o testDate.o #cleanOBJs (it works) (anything in PHONY must be Defiend)

cleanOBJs:
	rm *.o
clean : cleanOBJs
	rm testdate

rule1:  cleanOBJs # (it works)
	@echo "at rule 1"
#rm *.o  (it works)
rule2: rule1 #cleanOBJs (it works)
	@echo " at rule2"
rule3:
	@echo "rule3"
