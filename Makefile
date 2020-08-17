lab5:  	lab5.l lab5.y
		flex lab5.l
		bison lab5.y
		cc -o $@ lab5.tab.c yyerror.c main.c -lfl -g

inter02:  inter022020.l inter022020.y
		flex inter022020.l
		bison inter022020.y
		cc -o $@ inter022020.tab.c yyerror.c main.c -lfl -g

