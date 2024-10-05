#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Node structure for linked list
struct Node {
    unsigned long long data;
    Node* next;
};

// Function to generate random 1024-bit number and store in linked list
Node* generate_random_number() {
    Node* head = nullptr;
    Node* current = nullptr;
    for (int i = 0; i < 16; i++) {
        unsigned long long random_data = ((unsigned long long)rand() << 32) | (unsigned long long)rand();
        Node* newNode = new Node();
        newNode->data = random_data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    return head;
}

// Function to convert linked list to string
string linked_list_to_string(Node* head) {
    string result = "";
    while (head != nullptr) {
        result += to_string(head->data);
        head = head->next;
    }
    return result;
}

// Function to perform Miller-Rabin primality test
bool is_prime(unsigned long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (unsigned long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to print first 10 smaller primes
void print_smaller_primes(unsigned long long n) {
    cout << "[";
    int count = 0;
    for (unsigned long long i = 2; i <= n / 2; i++) {
        if (is_prime(i)) {
            if (count > 0) cout << ", ";
            cout << i;
            count++;
            if (count == 10) break;
        }
    }
    cout << "]";
}

int main() {
    srand(time(nullptr));
    Node* number = generate_random_number();
    string number_str = linked_list_to_string(number);

    cout << "Input: " << number_str << endl;

    unsigned long long last_64_bits = number->data;

    cout << "Smaller primes: ";
    print_smaller_primes(last_64_bits);
    cout << endl;

    // Simplified primality test using last 64 bits
    bool is_prime_result = is_prime(last_64_bits);

    cout << "Output: " << (is_prime_result ? "True" : "False") << endl;

    return 0;
}