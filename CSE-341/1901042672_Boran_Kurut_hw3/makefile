all: out
	./out 

out: yacc lex
	gcc lex.yy.c y.tab.c -lm -o out

yacc: interpreter.y
	yacc -d interpreter.y

lex: lexer.l
	lex lexer.l
