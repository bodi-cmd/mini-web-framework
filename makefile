all:
	lex proj.l
	yacc -d proj.y
	gcc -o program.out lex.yy.c y.tab.c -ly -ll

clean:
	rm program.out
	rm lex.yy.c
	rm y.tab.*