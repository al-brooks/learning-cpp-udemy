// Smart Pointers Challenge
#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test()
    : data{0} { std::cout << "\tTest Constructor (" << data << ")" << std::endl; }
    Test(int data)
    : data{data} { std::cout << "\tTest Constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest Destructor (" << data << ")" << std::endl; }
};

// Function Prototypes
//std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

auto make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    std::cout << std::endl;
    int data;
    for (int i = 0; i  < num; ++i) {
        std::cout << "Enter in data[" << (i+1) << "]: ";
        std::cin >> data;
//        std::shared_ptr<Test> s_ptr = std::make_shared<Test>(data);
//        vec.push_back(s_ptr);
        vec.push_back(std::make_shared<Test>(data));
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "\nDisplaying Vector Data:" << std::endl;
    std::cout << "===========================" << std::endl;
    for (const auto &ptr: vec)
        std::cout << ptr->get_data() << std::endl;
    std::cout << "===========================\n" << std::endl;
}

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to make: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

//std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
//    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
//}


