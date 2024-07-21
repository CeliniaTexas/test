
#include <iostream>
#include <vector>
#include <memory>

// 假设的节点类型
enum class NodeType {
    FuncDef,
    Block,
    Decl,
    Stmt,
    SelectStmt,
    AddExp,
    MulExp,
    UnaryExp,
    PrimaryExp,
    LVal,
    Number,
    AOP,
    RelExp,
    RelOP,
    LAndExp,
    LOrExp,
    EqExp
};

// 抽象基类：语法树节点
class ASTNode {
public:
    virtual ~ASTNode() {}
    virtual void print(int depth) const = 0;
};

// 函数定义节点
class FuncDefNode : public ASTNode {
public:
    int funcType;
    std::string id;
    std::shared_ptr<BlockNode> block;

    FuncDefNode(int type, const std::string& identifier, std::shared_ptr<BlockNode> blk)
        : funcType(type), id(identifier), block(blk) {}

    void print(int depth) const override {
        std::cout << std::string(depth, ' ') << "Function Definition: " << id << std::endl;
        block->print(depth + 2);
    }
};

// 块节点
class BlockNode : public ASTNode {
public:
    std::vector<std::shared_ptr<ASTNode>> items;

    void print(int depth) const override {
        for (const auto& item : items) {
            item->print(depth);
        }
    }
};

// 声明节点
class DeclNode : public ASTNode {
public:
    std::string type;
    std::string id;

    DeclNode(const std::string& t, const std::string& i)
        : type(t), id(i) {}

    void print(int depth) const override {
        std::cout << std::string(depth, ' ') << "Declaration: " << type << " " << id << std::endl;
    }
};

// 语句节点
class StmtNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> statement;

    StmtNode(std::shared_ptr<ASTNode> stmt)
        : statement(stmt) {}

    void print(int depth) const override {
        statement->print(depth);
    }
};

// 其他节点类似，根据需要定义

