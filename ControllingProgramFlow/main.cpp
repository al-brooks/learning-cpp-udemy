#include <iostream>
#include <vector>

// Solution without using Functions

int main()
{
    std::vector<int> collection{};
    char choice{};
    
    do{
        std::cout << "\n============================" << std::endl;
        std::cout << "P - Print numbers" << std::endl;
        std::cout << "A - Add a number" << std::endl;
        std::cout << "M - Display Mean of numbers" << std::endl;
        std::cout << "S - Display Smallest of number" << std::endl;
        std::cout << "L - Display Largest number" << std::endl;
        std::cout << "Q - Quit" << std::endl;
        
        std::cout << "\nEnter your choice: " << std::endl;
        std::cin >> choice;
        
        if(choice == 'P' || choice == 'p'){
            if(collection.size() == 0)
                std::cout << "[] - the list is empty" << std::endl;
            else {
                std::cout << "[";
                for(int i{0}; i < collection.size(); ++i) {
                    if(collection.size() == 1 || i == 0) {
                        std::cout << collection[i];
                    } else{
                    std::cout << ", " << collection[i];
                    }
                }
                std::cout << "]" << std::endl;
            }
        } else if(choice == 'A' || choice == 'a') {
            int num {};
            std::cout << "Enter the number you want to add: " << std::endl;
            std::cin >> num;
            
            collection.push_back(num);
            std::cout << num << " is added." << std::endl;
        } else if(choice == 'M' || choice == 'm') {
            if(collection.size() == 0)
                std::cout << "Unable to calculate Mean. List is empty." << std::endl;
            else if(collection.size() == 1)
                std::cout << "The Mean of the list is: " << collection[0] << std::endl;
            else {
                int sum{0};
                double avg{0.0};
                for(auto val: collection) {
                    sum += val;
                }
                avg = static_cast<double> (sum) / collection.size();
                std::cout << "The Mean of the list is: " << avg << std::endl;
            }
        } else if(choice == 'S' || choice == 's') {
            if(collection.size() == 0)
                std::cout << "Cannot find Smallest number. List is empty." << std::endl;
            else if(collection.size() == 1)
                std::cout << "The smallest number is: " << collection[0] << std::endl;
            else {
                int min{collection[0]};
                for(int i{1}; i < collection.size(); ++i) {
                    if(collection[i] < min)
                        min = collection[i];
                }
                std::cout << "The Smallest number is: " << min << std::endl;
            }
            
        } else if(choice == 'L' || choice == 'l') {
            if(collection.size() == 0)
                std::cout << "Cannot find largest number. List is empty" << std::endl;
            else if(collection.size() == 1)
                std::cout << "The largest number is: " << collection[0] << std::endl;
            else {
                int max{collection[0]};
                for(int i{1}; i < collection.size(); ++i) {
                    if(collection[i] > max)
                        max = collection[i];
                }
                std::cout << "The Largest number is: " << max << std::endl;
            }
        } else if(choice == 'Q' || choice == 'q'){
            std::cout << "Goodbye..." << std::endl;
        } else {
            std::cout << "Unknown choice...try again." << std::endl;
        }
    } while (choice != 'Q' && choice != 'q');
    
    return 0;
}
