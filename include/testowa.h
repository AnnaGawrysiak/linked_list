#pragma once
#include "NodeVar.h"
#include "Node.h"

class testowa
{
private:
    testowa();
    static testowa* wsk;

public:
void operator = (const testowa&) = delete;
testowa (const testowa&) = delete;

static testowa* get_instance();

bool test_push_beginning();

bool test_push_end();

bool test_n_pop_front();

bool test_n_pop_back();

bool test_reverseList();

bool test_linear_search();

bool test_bubble_sort();

bool test_find_min();

bool test_insert_at();

bool test_swap_value();

bool test_swap_();

bool test_size_();

bool test_remove_from_position();

void run(); // obiekt testowy mamy tylko jeden i mozemy go sobie wywolywac ile chcemy

};
