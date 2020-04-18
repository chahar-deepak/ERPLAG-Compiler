output : codegen.o astDriver.o ast.o typeChecker.o lexTest.o lexer.o parser.o symbolTableDriver.o lexer.h typeChecker.h lexerDef.h symbolTable.o parser.h parserDef.h symbolTable.h
	gcc -o ast.exe astDriver.o ast.o lexTest.o lexer.o parser.o
	gcc -o ST.exe symbolTableDriver.o ast.o lexTest.o lexer.o parser.o symbolTable.o typeChecker.o
	gcc -o codegen.exe codegen.o ast.o lexTest.o lexer.o parser.o symbolTable.o typeChecker.o
	make clean

asm :
	make -f make.asm
	make clean

clean :
	rm *.o