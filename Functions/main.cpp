#include <iostream>
#include <vector>

using
std::cin,
std::cout,
std::endl,
std::vector;

// Function Prototypes
void display_menu();
void user_choice(char &input);
void program_output(const char &input, vector<int> &vec);
void print_numbers(const vector<int> &vec);
void add_number(vector<int> &vec);
void display_mean(const vector<int> &vec);
void display_sm(const vector<int> &vec);
void display_lg(const vector<int> &vec);
void display_number(const vector<int> &vec);
void clear_numbers(vector<int> &vec);

int main()
{
    vector<int> collection{};
    char choice{};

    do{
        display_menu();
        user_choice(choice);
        program_output(choice, collection);
    } while (choice != 'q');
}

void display_menu() {
    cout << "\n============================" << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display Mean of numbers" << endl;
    cout << "S - Display Smallest of number" << endl;
    cout << "L - Display Largest number" << endl;
    cout << "F - Find and Display Number" << endl;
    cout << "C - Clear all Numbers" << endl;
    cout << "Q - Quit" << endl;
}

void user_choice(char &input){
    cout << "\nEnter your choice: " << endl;
    cin >> input;
    input = std::tolower(input);
}

void program_output(const char &input, vector<int> &vec) {
    if(input == 'p')
        print_numbers(vec);
    else if(input == 'a')
        add_number(vec);
    else if(input == 'm')
        display_mean(vec);
    else if(input == 's')
        display_sm(vec);
    else if(input == 'l')
        display_lg(vec);
    else if(input == 'f')
        display_number(vec);
    else if(input == 'c')
        clear_numbers(vec);
    else if(input == 'q'){
        cout << "Goodbye..." << endl;
    } else {
        cout << "Unknown choice...try again." << endl;
    }
}

void print_numbers(const vector<int> &vec) {
    if(vec.size() == 0)
        cout << "\n[] - the list is empty" << endl;
    else {
        cout << "[";
        for(int i{0}; i < vec.size(); ++i) {
            if(vec.size() == 1 || i == 0) {
                cout << vec[i];
            } else{
            cout << ", " << vec[i];
            }
        }
        cout << "]" << endl;
    }
}

void add_number(vector<int> &vec){
    int num {};
    cout << "\nEnter the number you want to add: " << endl;
    cin >> num;

    for(auto element: vec) {
        if(element == num) {
            cout << "\nThis number already exists in this list." << endl;
            cout << "Please enter a unique number." << endl;
            add_number(vec);
        }
    }

    vec.push_back(num);
    cout << "\nThe Number: " << num << " is added." << endl;
}

void display_mean(const vector<int> &vec) {
    if(vec.size() == 0)
        cout << "\nUnable to calculate Mean. List is empty." << endl;
    else if(vec.size() == 1)
        cout << "\nThe Mean of the list is: " << vec[0] << endl;
    else {
        int sum{0};
        double avg{0.0};
        for(auto val: vec) {
            sum += val;
        }
        avg = static_cast<double> (sum) / vec.size();
        cout << "\nThe Mean of the list is: " << avg << endl;
    }
}

void display_sm(const vector<int> &vec) {
    if(vec.size() == 0)
        cout << "\nCannot find Smallest number. List is empty." << endl;
    else if(vec.size() == 1)
        cout << "\nThe smallest number is: " << vec[0] << endl;
    else {
        int min{vec[0]};
        for(int i{1}; i < vec.size(); ++i) {
            if(vec[i] < min)
                min = vec[i];
        }
        cout << "\nThe Smallest number is: " << min << endl;
    }
}

void display_lg(const vector<int> &vec) {
    if(vec.size() == 0)
        cout << "\nCannot find largest number. List is empty" << endl;
    else if(vec.size() == 1)
        cout << "\nThe largest number is: " << vec[0] << endl;
    else {
        int max{vec[0]};
        for(int i{1}; i < vec.size(); ++i) {
            if(vec[i] > max)
                max = vec[i];
        }
        cout << "\nThe Largest number is: " << max << endl;
    }
}

void display_number(const vector<int> &vec) {
    int num{};
    cout << "\nEnter a number you want to display from the list: ";
    cin >> num;

    for(auto element: vec) {
        if(element == num) {
            cout << "\nHere is your selected number: " << element << endl;
            return;
        }
    }

    cout << "\nThe number you wish to display does not exist in this collection." << endl;
}

void clear_numbers(vector<int> &vec) {
    if(vec.size() == 0)
        cout << "\nThe collection is already empty.." << endl;
    else{
        vec.clear();
        cout << "\nThe collection is now cleared of all values";
    }
}
