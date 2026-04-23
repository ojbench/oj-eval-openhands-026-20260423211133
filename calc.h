

// 你需要提交这份代码
#pragma once

#include "visitor.h"
#include <iostream>

struct calculator : visitor {
    // Visit a node and return its value
    std::any visit(node *ctx) override { 
        return ctx->accept(this); 
    }
    
    // Visit a number node and return its value
    std::any visit_num(num_node *n) override {
        return n->number;
    }
    
    // Visit an addition node and return the sum of its children
    std::any visit_add(add_node *a) override {
        auto left = std::any_cast<double>(a->lnode->accept(this));
        auto right = std::any_cast<double>(a->rnode->accept(this));
        return left + right;
    }
    
    // Visit a subtraction node and return the difference of its children
    std::any visit_sub(sub_node *s) override {
        auto left = std::any_cast<double>(s->lnode->accept(this));
        auto right = std::any_cast<double>(s->rnode->accept(this));
        return left - right;
    }
    
    // Visit a multiplication node and return the product of its children
    std::any visit_mul(mul_node *m) override {
        auto left = std::any_cast<double>(m->lnode->accept(this));
        auto right = std::any_cast<double>(m->rnode->accept(this));
        return left * right;
    }
    
    // Visit a division node and return the quotient of its children
    std::any visit_div(div_node *d) override {
        auto left = std::any_cast<double>(d->lnode->accept(this));
        auto right = std::any_cast<double>(d->rnode->accept(this));
        return left / right;
    }
    
    ~calculator() override = default;
};

