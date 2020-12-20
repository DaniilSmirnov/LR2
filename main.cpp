#include <stack>
#include <string>
#include <exception>
#include <iostream>
#include <sstream>
int divide(int a, int b);
void polish_counting();

int main() {
    polish_counting();
    return 0;
}

int divide(int a, int b){
    std::cout << "ok" << std::endl;
    if(b==0) throw std::exception();
    else return a/b;
}

void polish_counting(){
    int number;
    std::stack<float> stack;
    while (true){
        std::string count;
        std::cin >> count;
            if(count=="0") break;
        char counting = count[0];
        std::istringstream iss(count); // строковый поток ввода
            if (iss>>number) stack.push(number); // считывание данных из потока, пробел - разделитель
            else{
                number = stack.top();
                stack.pop();
                switch (counting){
                    case '+':
                        number+=stack.top();
                        stack.pop();
                        stack.push(number);
                        continue;
                    case '-':
                        number-=stack.top();
                        stack.pop();
                        stack.push(number);
                        continue;
                    case '*':
                        number*=stack.top();
                        stack.pop();
                        stack.push(number);
                        continue;
                    case '/':
                        std::cout << "ok1" << std::endl;
                        try {
                            std::cout << "ok2" << std::endl;
                            number=divide(stack.top(), number);
                            stack.pop();
                            stack.push(number);
                        }
                        catch (const std::exception &err) {
                            std::cout << err.what() << std::endl;
                            std::cout << "error: division by zero" << std::endl;
                        }
                        continue;
                    case '=':
                        std::cout << "= " << number << std::endl;
                        break;
                    default:
                        std::cout << "error: change the expression for counting" << std::endl;
                    break;
                } //switch
            } //если цифра
        } // пока не 0
}

