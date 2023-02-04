/* program to add the two given polynomial equation using linked list*/

#include <iostream>
using namespace std;

struct Node
{
    int cofficient;
    int exponent;
    Node *next;
};

Node *creatNode(int coff, int expo)
{
    Node *newNode = new Node();
    newNode->cofficient = coff;
    newNode->exponent = expo;
    newNode->next = NULL;
    return newNode;
}

Node *addPolynomial(Node *poly1, Node *poly2)
{
    Node *result = NULL, *tail = NULL, *temp1, *temp2;
    temp1 = poly1;
    temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL)
    {
        Node *node = NULL;

        if (temp1->exponent > temp2->exponent)
        {
            node = creatNode(temp1->cofficient, temp1->exponent);
            temp1 = temp1->next;
        }

        if (temp2->exponent > temp1->exponent)
        {
            node = creatNode(temp2->cofficient, temp2->exponent);
            temp2 = temp2->next;
        }

        else
        {
            node = creatNode(temp1->cofficient + temp2->cofficient, temp1->exponent);

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (result == NULL)
        {
            result = tail = node;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
    }
    while (temp1 != NULL)
    {
        Node *node = creatNode(temp1->cofficient, temp1->exponent);
        result = tail = node;
        tail = tail->next;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        Node *node = creatNode(temp2->cofficient, temp2->exponent);
        result = tail = node;
        tail = tail->next;
        temp2 = temp2->next;
    }
    return result;
}

void printPolynomial(Node *poly)
{
    while (poly != NULL)
    {
        cout << poly->cofficient << "x^" << poly->exponent << "+";
        poly = poly->next;
    }
    cout << endl;
}
int main()
{
    Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    poly1 = creatNode(2, 4);
    poly1->next = creatNode(3, 3);
    poly1->next->next = creatNode(1, 1);

    poly2 = creatNode(5, 3);
    poly2->next = creatNode(3, 2);
    poly2->next->next = creatNode(5, 1);

    cout << "Polynomial1: " << endl;
    printPolynomial(poly1);

    cout << "Polynomial2 : " << endl;
    printPolynomial(poly2);

    result = addPolynomial(poly1, poly2);

    cout << "The result is: " << endl;
    printPolynomial(result);
    return 0;
}