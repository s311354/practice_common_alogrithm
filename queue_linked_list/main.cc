#include <iostream>
#include <stack>
#include <queue>

void stdlib_queue_experiment();
void stdlib_stack_experiment();

int main(int argc, char *argv[])
{
    std::cout << "====== Queue (FIFO) ======" << std::endl;
    stdlib_queue_experiment();

    std::cout << "====== Stack (LIFO) ======" << std::endl;
    stdlib_stack_experiment();

    return 0;
}


void stdlib_queue_experiment()
{
    auto local_queue = std::queue<int>();
    local_queue.push(34);
    local_queue.push(10);
    local_queue.push(12);
    local_queue.push(13);

    std::cout << "Size: " << local_queue.size() << std::endl;
    while (!local_queue.empty()) {
        std::cout << "Popping: " << local_queue.front() << std::endl;
        local_queue.pop();
    }
}

void stdlib_stack_experiment()
{
    auto local_stack = std::stack<int>();
    local_stack.push(34);
    local_stack.push(10);
    local_stack.push(12);
    local_stack.push(13);

    std::cout << "Size: " << local_stack.size() << std::endl;
    while (!local_stack.empty()) {
        std::cout << "Popping: " << local_stack.top() << std::endl;
        local_stack.pop();
    }
}
