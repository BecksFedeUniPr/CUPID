#include <string>
#include <vector>
#include <memory>

struct Node{
    std::string name;
    std::string dataType;
    std::vector<std::shared_ptr<Node>> children;
    float sim; 

    Node(std::string n, std::string type = "") : name(n), dataType(type), sim(0.0f) {}

    void addChild(std::shared_ptr<Node> child) {
        children.push_back(child);
    }
};