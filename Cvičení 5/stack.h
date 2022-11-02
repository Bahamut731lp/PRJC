typedef struct stack {
    struct Node* top;
};

struct Node {
    char* data;
    int size;

    struct Node *next;  
};

void push(struct stack*, struct Node*);
void display(struct stack*);
struct Node* new_node(char*, int);
struct Node* pop(struct stack*);
struct Node* peek(struct stack*);
