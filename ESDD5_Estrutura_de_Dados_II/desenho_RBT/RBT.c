#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "RBT.h"

RBT *newRBT()
{

    RBT *abb = (RBT *)malloc(sizeof(RBT));
    abb->root = NULL;
    abb->size = 0;

    return abb;
}

void rbtPut(RBT *rbt, int key)
{
    rbt->root = rbtPutR(rbt->root, key);
}

RBTNode *rbtPutR(RBTNode *node, int key)
{

    if (node == NULL)
    {

        RBTNode *newNode = (RBTNode *)malloc(sizeof(RBTNode));
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->key = key;
        newNode->color = RBT_COLOR_RED;
        newNode->rank = 0;
        newNode->level = 0;
        newNode->blackLevel = 0;

        return newNode;
    }
    else
    {
        if (key < node->key)
        {
            node->left = rbtPutR(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = rbtPutR(node->right, key);
        }
        else
        {
            // value update if storing value
        }
    }

    if (rbtIsRed(node->right) && !rbtIsRed(node->left))
    {
        node = rbtRotateLeft(node);
    }

    if (rbtIsRed(node->left) && rbtIsRed(node->left->left))
    {
        node = rbtRotateRight(node);
    }

    if (rbtIsRed(node->left) && rbtIsRed(node->right))
    {
        rbtFlipColors(node);
    }

    return node;
}

RBTNode *rbtRotateLeft(RBTNode *node)
{

    RBTNode *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    temp->color = node->color;
    node->color = RBT_COLOR_RED;

    return temp;
}

RBTNode *rbtRotateRight(RBTNode *node)
{

    RBTNode *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    temp->color = node->color;
    node->color = RBT_COLOR_RED;

    return temp;
}

void rbtFlipColors(RBTNode *node)
{
    node->color = RBT_COLOR_RED;
    node->left->color = RBT_COLOR_BLACK;
    node->right->color = RBT_COLOR_BLACK;
}

bool rbtIsRed(RBTNode *node)
{
    if (node == NULL)
    {
        return false;
    }
    return node->color == RBT_COLOR_RED;
}

void rbtPreOrder(RBTNode *node)
{
    if (node != NULL)
    {
        rbtPrintNode(node);
        rbtPreOrder(node->left);
        rbtPreOrder(node->right);
    }
}

void rbtInOrder(RBTNode *node)
{
    if (node != NULL)
    {
        rbtInOrder(node->left);
        rbtPrintNode(node);
        rbtInOrder(node->right);
    }
}

void rbtPostOrder(RBTNode *node)
{
    if (node != NULL)
    {
        rbtPostOrder(node->left);
        rbtPostOrder(node->right);
        rbtPrintNode(node);
    }
}

void rbtProcess(RBTNode *node, int *currentRank, int level, int *redNodeCount, int *maxBlackLevel)
{
    if (node != NULL)
    {

        if (node->color == RBT_COLOR_RED)
        {
            (*redNodeCount)++;
        }

        rbtProcess(node->left, currentRank, level + 1, redNodeCount, maxBlackLevel);
        node->rank = *currentRank;
        node->level = level;
        node->blackLevel = level - *redNodeCount;
        (*currentRank)++;
        rbtProcess(node->right, currentRank, level + 1, redNodeCount, maxBlackLevel);

        if (node->color == RBT_COLOR_RED)
        {
            (*redNodeCount)--;
        }

        if (*maxBlackLevel < node->blackLevel)
        {
            *maxBlackLevel = node->blackLevel;
        }
    }
}

void rbtDraw(RBT *rbt)
{
    // desenhe a árvore vermelho e preto aqui
    drawingPath(rbt->root, NULL);
}

void drawingPath(RBTNode *no, RBTNode *noAnterior)
{
    int margem = 100;
    int noX = margem + no->rank * 50;
    int noY = margem + no->level * 50;

    if (no != NULL)
    {
        if (noAnterior != NULL)
        {
            int noAnteriorX = margem + noAnterior->rank * 50;
            int noAnteriorY = margem + noAnterior->level * 50;

            if (no->color == RBT_COLOR_RED)
            {
                noY = noAnteriorY; // Ajusta a altura do nó vermelho para ser a mesma do pai
                no->level = noAnterior->level;

                if (no->left != NULL)
                {
                    no->left->level = no->level + 1; // Aumenta o nível do filho esquerdo
                }

                if (no->right != NULL)
                {
                    no->right->level = no->level + 1; // Aumenta o nível do filho direito
                }
            }

            DrawLine(noX, noY, noAnteriorX, noAnteriorY, no->color == RBT_COLOR_RED ? RED : BLACK);
        }

        drawingPath(no->left, no);
        drawingPath(no->right, no);

        DrawCircle(noX, noY, 20, WHITE);
        DrawCircleLines(noX, noY, 20, no->color == RBT_COLOR_RED && noAnterior != NULL ? RED : BLACK);
        DrawText(TextFormat("%d", no->key), noX - 6, noY - 6, 12, no->color == RBT_COLOR_RED && noAnterior != NULL ? RED : BLACK);
    }
}

void rbtPrintNode(RBTNode *node)
{
    printf("%d %c (%d/%d) %d ",
           node->key,
           node->color == RBT_COLOR_RED ? 'R' : 'B',
           node->rank,
           node->level,
           node->blackLevel);
}