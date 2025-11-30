#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "codegen.hpp"
#include "node.hpp"

using namespace std;

static map<string, int> offsets;
static int current_offset = 0;

void gen_lval(Node *node) {
    if (node->op != ND_IDENT) {
        cerr << "left node is not variable." << endl;
        exit(1);
    }

    if (offsets.find(node->name) == offsets.end()) {
        current_offset += 8;
        offsets[node->name] = current_offset;
    }

    int offset = offsets[node->name];

    cout << "  mov rax, rbp" << endl;
    cout << "  sub rax, " << offset << endl;
    cout << "  push rax" << endl;
}


void gen(Node *node) {
    if (node->op == ND_NUM) {
        cout << "  push " << node->intvalue << endl;
        return;
    }

    if (node->op == ND_IDENT) {
        gen_lval(node);
        cout << "  pop rax" << endl;
        cout << "  mov rax, [rax]" << endl;
        cout << "  push rax" << endl;
        return;
    }


    if (node->op == ND_ASSIGN) {
        gen_lval(node->left);
        gen(node->right);
        cout << "  pop rdi" << endl;
        cout << "  pop rax" << endl;
        cout << "  mov [rax], rdi" << endl;
        cout << "  push rdi" << endl;
        return;
    }

    gen(node->left);
    gen(node->right);

    cout << "  pop rdi" << endl;
    cout << "  pop rax" << endl;

    switch (node->op) {
    case ND_ADD:
        cout << "  add rax, rdi" << endl;
        break;
    case ND_MIN:
        cout << "  sub rax, rdi" << endl;
        break;
    case ND_MUL:
        cout << "  imul rax, rdi" << endl;
        break;
    case ND_DIV:
        cout << "  cqo" << endl;
        cout << "  idiv rdi" << endl;
        break;
    }

    cout << "  push rax" << endl;
}

void codegen(vector<Node*> &nodes) {
    cout << ".intel_syntax noprefix" << endl;
    cout << ".global main" << endl;
    cout << "main:" << endl;

    cout << "  push rbp" << endl;
    cout << "  mov rbp, rsp" << endl;
    cout << "  sub rsp, 208" << endl;

    for (Node* node : nodes) {
        gen(node);
        cout << "  pop rax" << endl;
    }

    cout << "  mov rsp, rbp" << endl;
    cout << "  pop rbp" << endl;
    cout << "  ret" << endl;
}
