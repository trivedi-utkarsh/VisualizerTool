#include <stdlib.h>
#include <gtk/gtk.h>
#include "shapes.h"

struct FigureNode
{
    int type;
    struct FigureNode *next;
    int dim[6];
};

void push_figure(struct FigureNode **head, int dimension[], int type)
{
    struct FigureNode *newNode = (struct FigureNode *)malloc(sizeof(struct FigureNode));
    newNode->type = type;
    for (int i = 0; i < 6; i++)
    {
        newNode->dim[i] = dimension[i];
    }

    newNode->next = *head;
    *head = newNode;
}

void drawFigures(struct FigureNode *head, cairo_t *cr, int cx , int cy)
{
    while (head != NULL)
    {

        switch (head->type)
        {
        case 1:
            // creating a circle
            draw_circle(cr, cx + head->dim[0], cy+head->dim[1], head->dim[2]);
            break;

        default:
            break;
        }
        head = head->next;
    }
}
