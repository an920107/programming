%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int yylex(void);
extern void yyerror(const char *);

void throw_error() {
    yyerror("");
}


// struct definitions
typedef struct node node_t;
struct node {
    node_t* last;
    int value;
};

typedef struct stack stack_t;
struct stack {
    node_t* top;
};

typedef struct pair pair_t;
struct pair {
    int x, y;
};

// method definitions
bool stack_is_empty(stack_t* s) { return s->top == NULL; }

void stack_push(stack_t* s, int value) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->last = s->top;
    new_node->value = value;
    s->top = new_node;
}

void stack_pop(stack_t* s) {
    if (stack_is_empty(s)) throw_error();
    s->top = s->top->last;
}

int stack_top(stack_t* s) {
    if (stack_is_empty(s)) {
        throw_error();
        return 0;
    }
    return s->top->value;
}

pair_t get_params(stack_t* s) {
    pair_t result;
    result.x = stack_top(s);
    stack_pop(s);
    result.y = stack_top(s);
    stack_pop(s);
    return result;
}

int get_param(stack_t* s) {
    int result = stack_top(s);
    stack_pop(s);
    return result;
}

// initialization
stack_t num_stack = {NULL};

%}

%token LOAD ADD SUB MUL MOD INC DEC LF NUM;

%%

commands: commands command LF | commands LF | ;

command: load | add | sub | mul | mod | inc | dec;

load: LOAD NUM {
    stack_push(&num_stack, $2);
};

add: ADD {
    pair_t params = get_params(&num_stack);
    stack_push(&num_stack, params.x + params.y);
};

sub: SUB {
    pair_t params = get_params(&num_stack);
    stack_push(&num_stack, params.x - params.y);
};

mul: MUL {
    pair_t params = get_params(&num_stack);
    stack_push(&num_stack, params.x * params.y);
};

mod: MOD {
    pair_t params = get_params(&num_stack);
    if (params.y == 0) throw_error();
    stack_push(&num_stack, params.x % params.y);
};

inc: INC {
    int param = get_param(&num_stack);
    stack_push(&num_stack, param + 1);
};

dec: DEC {
    int param = get_param(&num_stack);
    stack_push(&num_stack, param - 1);
};

%%
void yyerror(const char *message) {
	printf("Invalid format\n");
    exit(0);
}

int main(int argc, char **argv) {
    yyparse();

    int param = get_param(&num_stack);
    if (!stack_is_empty(&num_stack))
        throw_error();
    else printf("%d\n", param);

    return 0;
}
