#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polynomial{
   int coeff, expX , expY, expZ;
   struct polynomial* next;
}node;

node* getNode(){
    node* x;
    x = (node*)malloc(sizeof(node));
    if (x == NULL)
    {
        printf("\nInsufficient memory\n");
        exit(0);
    }
    return x;
}

node* createPoly(node* head){
    node* temp,*p;
    int ch;
    do{
        temp= getNode();
        printf("\nEnter Coefficient:");
        scanf("%d",&temp->coeff);
        printf("\nEnter Exponents of x,y & z respectively:");
        scanf("%d%d%d",&temp->expX,&temp->expY,&temp->expZ);
        temp->next=NULL;
        if(head==NULL)
            head=p=temp;
        else{
            p->next=temp;
            p=temp;
        }
        printf("\nDo you want to add more terms to polynomial(1/0)?");
        scanf("%d",&ch);
    } while (ch);
    return head;
}

void displayPoly(node* head){
    if (head==NULL)
    {
        printf("\nPolynomial does not exist");
        return;
    }
    node* p = head;
    printf("\n");
    while (p != NULL)
    {
        printf("%dx^%d*y^%d*z^%d", p->coeff, p->expX, p->expY, p->expZ);
        if (p->next!=NULL)
            printf(" + ");
        p=p->next;
    }
    printf("\n");
}

node* sort(node* poly){
    int num1,num2,tco,tx,ty,tz;
    for(node* t1=poly;t1!=NULL;t1=t1->next){
        for(node* t2=poly;t2->next!=NULL;t2=t2->next){
            num1=(t2->expX*100)+(t2->expY*10)+t2->expZ;
            num2=(t2->next->expX*100)+(t2->next->expY*10)+t2->next->expZ;
            if(num1>num2){
                tco=t2->coeff;
                tx=t2->expX;
                ty=t2->expY;
                tz=t2->expZ;
                t2->coeff=t2->next->coeff;
                t2->expX=t2->next->expX;
                t2->expY=t2->next->expY;
                t2->expZ=t2->next->expZ;
                t2->next->coeff=tco;
                t2->next->expX=tx;
                t2->next->expY=ty;
                t2->next->expZ=tz;
            }
        }
    }
    return poly;
}

node* create(node* head, int c, int x, int y, int z){
    node* temp=getNode(), *p=head;
    temp->coeff=c;
    temp->expX=x;
    temp->expY=y;
    temp->expZ=z;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else{
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
        p=temp;
    }
    return head;
}

node* addPoly(node* poly1, node* poly2, node* r){
    int num1,num2;
    node* p1=poly1,*p2=poly2;
    while(p1!=NULL && p2!=NULL){
        num1=(p1->expX*100)+(p1->expY*10)+p1->expZ;
        num2=(p2->expX*100)+(p2->expY*10)+p2->expZ;
        if(num1==num2){
            r=create(r,p1->coeff+p2->coeff,p1->expX,p1->expY,p1->expZ);
            p1=p1->next;
            p2=p2->next;
        }
        else if(num1<num2){
            r=create(r,p1->coeff,p1->expX,p1->expY,p1->expZ);
            p1=p1->next;
        }
        else{
            r=create(r,p2->coeff,p2->expX,p2->expY,p2->expZ);
            p2=p2->next;     
        }
    }
    while(p1!=NULL){
        r=create(r,p1->coeff+p1->coeff,p1->expX,p1->expY,p1->expZ);
        p1=p1->next;
    }
    while(p2!=NULL){
        r=create(r,p2->coeff,p2->expX,p2->expY,p2->expZ);
        p2=p2->next;
    }
    return r;
}

void evaluate(node* head){
    node* p=head;
    int x, y, z;
    float result = 0.0;
    printf("\nEnter values of x, y, z to evaluate:\n");
    scanf("%d%d%d", &x, &y, &z);
    while (p!=NULL){
        result = result + (p->coeff * pow(x, p->expX) * pow(y, p->expY) * pow(z, p->expZ));
        p = p->next;
    }
    printf("\nPolynomial result is: %0.2f", result);
}

void main(){
    node* poly1=NULL, *poly2=NULL, *res=NULL;
    int ch;
    while (1)
    {
        printf("\n\n1.Evaluate polynomial\n2.Add two polynomials\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                printf("\nEnter polynomial to evaluate:");
                poly1 = createPoly(poly1);
                displayPoly(poly1);
                evaluate(poly1);
                break;
            case 2:
                printf("\nEnter the first polynomial:");
                poly1 = createPoly(poly1);
                printf("\nEnter the second polynomial:");
                poly2 = createPoly(poly2);
                printf("\nFirst polynomial is: ");
                displayPoly(poly1);
                printf("\nSecond polynomial is: ");
                displayPoly(poly2);
                poly1=sort(poly1);
                poly2=sort(poly2);
                res=addPoly(poly1,poly2,res);
                printf("\nThe sum of 2 polynomials is: ");
                displayPoly(res);
                break;
            case 3:
                printf("\nThank you.");
                exit(0);
                break;
            default:
                printf("\nInvalid entry");
                break;
        }
    }
}