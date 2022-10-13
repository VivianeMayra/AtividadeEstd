#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aux
{
    float value;
    struct aux *next;
}Enum;

float operate(float a, float b, char operator){
    switch (operator)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    
    default:
        return 0.0;
    }
}

Enum *stack(float num, Enum *list){
    Enum *new = malloc(sizeof(Enum));

    if(new){
        new->value = num;
        new->next = list;

        return new;
    }else{
        printf("Erro ao alocar memoria!");
    }
    return NULL;
}

Enum *unstack(Enum **list){
    Enum *remove = NULL;

    if(*list){
        remove = *list;
        *list = remove->next;
    }else{
        printf("Expressao invalida");
        exit(0);
    }
    return remove;
}

float solve_expression( char expression[]){
    char *elements;
    float result;
    Enum *n1,*n2,*list = NULL;
    elements=strtok(expression," ");
    while(elements){
        if(elements[0]=='+'|| elements[0]=='-'|| elements[0]=='*'|| elements[0]=='/'){
            n1=unstack(&list);
            n2=unstack(&list);
            result = operate(n2->value, n1->value, elements[0]);
            list = stack( result, list);
            free(n1);
            free(n2);
        }else{
            result = strtol(elements, NULL, 10);
             list = stack( result, list);
        }
        elements = strtok(NULL, " ");
    }
    n1 = unstack(&list);
    result = n1 ->value;
    free(n1);
    return result;
}

 void main()
{
    char expression[200];
    printf("Digite aqui sua expressao posfixada: ");
    fgets(expression, 200,stdin);
    printf("\nresultado: %f\n", solve_expression(expression));
    
}

/*
20 30 + 7 4 - 9 50 * 9 8 + = 17

1- Criar um vetor fixo de 200
2- Pedir a expressão por usuário (em String)
3- Fazer validação
4- Retornar o resultado







*/