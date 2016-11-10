#include <iostream>
using namespace std;

struct TreeNode
{
	bool isLeaf;			//true for leaf node
	int number;				//filled for leaf node
	TreeNode* leftTree;		//Pointer to left Tree
	TreeNode* rightTree; 	//Pointer to right Tree
	char op; 				// +,-,*,/
}

typedef TreeNode* TreePtr;

TreePtr buildLeaf (int number)
{
	TreePtr newNode;
	
	newNode = new TreeNode;
	newNode->isLeaf = true;		//This is a leaf node
	newNode->number = number;
	newNode->leftTree = NULL;	//empty left tree
	newNode->rightTree = NULL;	//empty right tree
	newNode->op = '\0';			//no operator
	return newNode;
}

TreePtr buildNode (TreePtr op1,		//left operand tree
				   TreePtr op2,		//right operand tree
				   char op)
{
	TreePtr newNode;
	newNode = new TreeNode;
	newNode->isLeaf = false;		//this is NOT a leaf node
	newNode->leftTree = op1;
	newNode->rightTree = op2;
	newNode->op = op;
	newNode->number = 0;			//empty number field
	return newNode;
}

void parseExpression (string& expression, TreePtr& expTree)
{
	TreePtr tempTree;
	char op;
	
	parseTerm (expression, expTree);
	while ((notEmpty(expression)) &&
	      ((nextChar(expression)=='+') ||
		   (nextChar(expression)=='-')))
	{
		op = getNextChar(expression);
		parseTerm(expression, tempTree);
		expTree = buildNode(expTree, tempTree, op);
	}
}

void parseTerm (string& expression, TreePtr& expTree)
{
	TreePtr tempTree;
	char op;
	
	parseFactor (expression, expTree);
	while ((notEmpty(expression)) &&
		  ((nextChar(expression)=='*') ||
		   (nextChar(expression)=='/')))
	{
		op = getNextChar(expression);
		parseFactor(expression, tempTree);
		expTree = buildNode(expTree, tempTree, op);
	}
}

void parseFactor (string& expression, TreePtr& expTree)
{
	if(notEmpty(expression) && (nextChar(expression) != '('))
		expTree = buildLeaf(getNum(expression));
	else
	{
		getNextChar(expression);					//Skip '('
		parseExpression(expression, expTree);
		getNextChar(expression);					//Skip ')'
	}
}

int evalTree (TreePtr expTree)
{
	int result;
	
	if(isLeafNode(expTree))
		result = leafValue(expTree);
	else
	{
		switch (nodeOp(expTree))
		{
			case '+':
				result = evalTree(leftOf(expTree)) + evalTree(rightOf(expTree));
				break;
			case '-':
				result = evalTree(leftOf(expTree)) - evalTree(rightOf(expTree));
				break;
			case '*':
				result = evalTree(leftOf(expTree)) * evalTree(rightOf(expTree));
				break;
			case '/':
				result = evalTree(leftOf(expTree)) / evalTree(rightOf(expTree));
				break;
			default:
				result = 0;
				cout << "Error in evaluating expression tree\n";
		}
	}
	return result;
}

void printTree(TreePtr expTree)
{
	if(isLeafNode(expTree))
		cout << leafValue(expTree) << endl;
	else
	{
		printTree(leftOf(expTree));
		cout << nodeOp(expTree) << endl;
		printTree(rightOf(expTree));
	}
}

int main()
{
	string expression;
	
	cout << "Input: ";
	cin >> expression;
	printTree();
}
