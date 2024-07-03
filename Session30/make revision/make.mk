VPATH=src1

prog: prog.c
	gcc $< -o $@
.PHONY: clean

clean:@rm -f prog 

#vpath always works with pattern rule
#
