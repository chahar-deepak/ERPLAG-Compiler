/*
Group #52 -
Anwesh Bhattacharya (2016B5A70590P)
Deepak Chahar (2017A7PS0147P)
Rohan Kela (2016B1A70822P)
Komal Vasudeva (2017A7PS0103P)
*/


#ifndef _AST
#define _AST

#include "lexerDef.h"
#include "lexer.h"
#include "parser.h"

typedef struct _arrayTypeInfo
{
	tokenID type ;
	token *tokLeft ;
	token *tokRight ;
} arrayTypeInfo ;

typedef enum _datTag
{
	PRIMITIVE, ARRAY, DARRAY
} datTag ;

typedef tokenID primitive ;

typedef union _datType
{
	primitive pType ;
	arrayTypeInfo *arrType ;
} datType ;

struct _moduleST ;
typedef struct _moduleST moduleST ;


typedef struct _astNode 
{
	tokenID id ;
	token *tok ;

	datTag dtTag ;
	datType *dt ;

	moduleST *localST ;

	struct _astNode *parent , *child , *next, *prev ;
} astNode ;

int getNumberASTNodes (astNode *node) ;
void deleteAST (astNode *node) ;

astNode* applyASTRule (treeNode *PTNode) ;
void inorderAST (astNode *node, int space) ;
void preorderAST (astNode *node, int space) ;
#endif