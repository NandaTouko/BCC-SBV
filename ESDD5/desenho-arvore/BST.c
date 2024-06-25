#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "BST.h"

BST* newBST() {

    BST* abb = (BST*) malloc( sizeof( BST ) );
    abb->root = NULL;
    abb->size = 0;

    return abb;

}

void bstPut( BST* abb, int key ) {
    abb->root = bstPutR( abb->root, key );
}

BSTNode* bstPutR( BSTNode* node, int key ) {

    if ( node == NULL ) {
        BSTNode* newNode = (BSTNode*) malloc( sizeof(BSTNode) );
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->key = key;
        newNode->rank = 0;
        newNode->level = 1;
        return newNode;
    } else {
        if ( key < node->key ) {
            node->left = bstPutR( node->left, key );
        } else if ( key > node->key ) {
            node->right = bstPutR( node->right, key );
        } else {
            // value update if storing value
        }
    }

    return node;

}

void bstPreOrder( BSTNode* node ) {
    if ( node != NULL ) {
        bstPrintNode( node );
        bstPreOrder( node->left );
        bstPreOrder( node->right );
    }
}

void bstInOrder( BSTNode* node ) {
    if ( node != NULL ) {
        bstInOrder( node->left );
        bstPrintNode( node );
        bstInOrder( node->right );
    }
}

void bstPostOrder( BSTNode* node ) {
    if ( node != NULL ) {
        bstPostOrder( node->left );
        bstPostOrder( node->right );
        bstPrintNode( node );
    }
}

void bstProcess( BSTNode* node, int* currentRank, int level, int *maxLevel ) {
    if ( node != NULL ) {
        bstProcess( node->left, currentRank, level+1, maxLevel );
        node->rank = *currentRank;
        node->level = level;
        (*currentRank)++;
        bstProcess( node->right, currentRank, level+1, maxLevel );
        if ( *maxLevel < node->level ) {
            *maxLevel = node->level;
        }
    }
}

void bstDraw( BST *bst ) {
    percursoDesenho(bst->root, NULL);
}

void percursoDesenho(BSTNode *no, BSTNode *noAnterior) {
    int margem = 100;
    int noX = margem + no->rank * 50;
    int noY = margem + no->level * 50;

    if(no != NULL){
        if(noAnterior != NULL) {
            DrawLine(noX, noY, margem + noAnterior->rank * 50, margem + noAnterior->level * 50, BLACK);
        }

        percursoDesenho(no->left, no);
        percursoDesenho(no->right, no);

        DrawCircle(noX, noY, 20, WHITE);
        DrawCircleLines(noX, noY, 20, BLACK);
        DrawText(TextFormat("%d", no->key), noX - 6, noY - 6, 12, BLACK);
    }
}

void bstPrintNode( BSTNode *node ) {
    printf( "%d (%d/%d) ", node->key, node->rank, node->level );
}