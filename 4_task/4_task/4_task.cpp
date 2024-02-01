// Metelkin Maksim -> int V = abs(int('M') - int('M')) % 5; -> 0 Variant "Приоритетная очеред"

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    int elements[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;

public:
    PriorityQueue() : size(0), elements{}, priorities{} {}

    ~PriorityQueue() {}

    void AddElement(int element, int priority) {
        if (size < MAX_SIZE) {
            elements[size] = element;
            priorities[size] = priority;
            size++;
        }
        else {
            cout << "Priority queue is full." << endl;
        }
    }

    void ExtractMax() {
        if (size > 0) {
            int maxPriorityIndex = 0;
            for (int i = 1; i < size; ++i) {
                if (priorities[i] > priorities[maxPriorityIndex]) {
                    maxPriorityIndex = i;
                }
            }

            cout << "Extracting element: " << elements[maxPriorityIndex] << " with priority: " << priorities[maxPriorityIndex] << endl;

            for (int i = maxPriorityIndex; i < size - 1; ++i) {
                elements[i] = elements[i + 1];
                priorities[i] = priorities[i + 1];
            }

            size--;
        }
        else {
            cout << "Priority queue is empty." << endl;
        }
    }

    void ExtractAllWithPriority(int priority) {
        int newSize = 0;

        for (int i = 0; i < size; ++i) {
            if (priorities[i] != priority) {
                elements[newSize] = elements[i];
                priorities[newSize] = priorities[i];
                newSize++;
            }
            else {
                cout << "Extracting element: " << elements[i] << " with priority: " << priority << endl;
            }
        }

        size = newSize;
    }

    bool ContainsElement(int element) const {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }

    //перегрузка операторов
    
    bool operator>(const PriorityQueue& other) const {
        return size > other.size;
    }

    bool operator<(const PriorityQueue& other) const {
        return size < other.size;
    }

    bool operator==(const PriorityQueue& other) const {
        return size == other.size;
    }

    void PrintQueue() const {
        cout << "Priority Queue:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Element: " << elements[i] << ", Priority: " << priorities[i] << endl;
        }
    }
};

int main()
{
    PriorityQueue queue;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Take a new file\n";
        cout << "2. Read the file\n";
        // cout << "3. Extract all elements with a specific priority\n";
        // cout << "4. Check if an element is in the priority queue\n";
        // cout << "5. Print the priority queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int element, priority;
            cout << "Enter element: ";
            cin >> element;
            cout << "Enter priority: ";
            cin >> priority;
            queue.AddElement(element, priority);
            break;
        }
        case 2:
            queue.ExtractMax();
            break;
        case 3: {
            int priority;
            cout << "Enter priority: ";
            cin >> priority;
            queue.ExtractAllWithPriority(priority);
            break;
        }
        case 4: {
            int element;
            cout << "Enter element to check: ";
            cin >> element;
            if (queue.ContainsElement(element)) {
                cout << "Element is in the priority queue.\n";
            }
            else {
                cout << "Element is not in the priority queue.\n";
            }
            break;
        }
        case 5:
            queue.PrintQueue();
            break;
        case 6:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "\nInvalid character: " << choice << endl;
        }
    }

    return 0;

}