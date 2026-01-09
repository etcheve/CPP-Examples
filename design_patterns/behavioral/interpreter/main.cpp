
#include <iostream>
#include <string>


class Expression {
    public:
        virtual ~Expression() = default;
        virtual int interpret() const = 0;  
};

class NumberExpression : public Expression {
    private:
        int number_;
    public:
        explicit NumberExpression(int number) : number_(number) {}
        int interpret() const override {
            return number_;
        }
};

class AddExpression : public Expression {
    private:
        Expression *left_;
        Expression *right_;
    public:
        AddExpression(Expression *left, Expression *right) : left_(left), right_(right) {}
        ~AddExpression() {
            delete left_;
            delete right_;
        }
        int interpret() const override {
            return left_->interpret() + right_->interpret();
        }
};
class MultiplicationExpression : public Expression {
private:
    Expression* left;
    Expression* right;

public:
    MultiplicationExpression(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret() const override {
        return left->interpret() * right->interpret();
    }

    ~MultiplicationExpression() {
        delete left;
        delete right;
    }
};
class Interpreter {
    public:
        int interpret(const std::string& expression) {
        Expression* expressionTree = buildExpressionTree(expression);
        
        // Interpret expression tree
        int result = expressionTree->interpret();

        delete expressionTree;

        return result;
        }

    private:
        Expression* buildExpressionTree(const std::string& expression) {
            std::cout << "Building expression tree for: " << expression << std::endl;
        // For simplicity, hardcoding an expression tree for "2 + 3 * 4"
            return new AddExpression(
                new NumberExpression(2),
                new MultiplicationExpression(
                    new NumberExpression(3),
                    new NumberExpression(4)
                )
            );
        }
};
int main(){
    std::string expression = "2 + 3 * 4";
    
    // Create interpreter
    Interpreter interpreter;
    
    // Interpret expression
    int result = interpreter.interpret(expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}