
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_ORDERS = 100;

struct Order {
    int orderID;
    string restaurantName;
    string customerLocation;
    string items;
    int prepTime;
    int timestamp;
};

class OrderDispatchManager {
private:
    Order orders[MAX_ORDERS];
    int size;

public:
    OrderDispatchManager() {
        size = 0;
        srand(time(0)); // For random rider availability
    }

    // 1. Add Order
    void addOrder(int id, string rest, string loc, string items, int prepTime, int timestamp) {
        if (size >= MAX_ORDERS) {
            cout << "Order queue is full!\n";
            return;
        }

        Order newOrder = {id, rest, loc, items, prepTime, timestamp};

        // If quick items (simulate by checking if "drink" in items), insert at front
        if (items.find("drink") != string::npos || items.find("Drink") != string::npos) {
            for (int i = size; i > 0; i--) {
                orders[i] = orders[i - 1];
            }
            orders[0] = newOrder;
        } else {
            orders[size] = newOrder;
        }
        size++;
        cout << "Order added successfully!\n";
    }

    // 2. Dispatch Order
    void dispatchOrder() {
        if (size == 0) {
            cout << "No orders to dispatch!\n";
            return;
        }

        bool riderAvailable = rand() % 2; // Simulate rider availability
        if (!riderAvailable) {
            cout << "No rider available right now. Try again later.\n";
            return;
        }

        cout << "Dispatching Order ID: " << orders[0].orderID << " (" << orders[0].restaurantName << ")\n";

        // Remove front order
        for (int i = 0; i < size - 1; i++) {
            orders[i] = orders[i + 1];
        }
        size--;
    }

    // 3. View Next Order
    void viewNextOrder() {
        if (size == 0) {
            cout << "No orders available.\n";
            return;
        }
        cout << "Next Order: ID " << orders[0].orderID << ", Restaurant: " << orders[0].restaurantName
             << ", Location: " << orders[0].customerLocation << "\n";
    }

    // 4. Display All Orders
    void displayAllOrders() {
        if (size == 0) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Pending Orders:\n";
        for (int i = 0; i < size; i++) {
            cout << "[" << orders[i].orderID << "] " << orders[i].restaurantName << " | "
                 << orders[i].customerLocation << " | Items: " << orders[i].items
                 << " | Prep Time: " << orders[i].prepTime << " mins\n";
        }
    }

    // 5. Cancel Order by ID
    void cancelOrder(int id) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (orders[i].orderID == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Order ID not found.\n";
            return;
        }

        for (int i = index; i < size - 1; i++) {
            orders[i] = orders[i + 1];
        }
        size--;
        cout << "Order ID " << id << " canceled successfully.\n";
    }
};

int main() {
    OrderDispatchManager manager;

    manager.addOrder(1001, "Burger Lab", "G-10 Islamabad", "Burger, Fries", 15, 1);
    manager.addOrder(1002, "Pizza Hut", "F-7 Islamabad", "Drink", 5, 2);
    manager.addOrder(1003, "KFC", "Blue Area", "Zinger, Drink", 10, 3);

    manager.displayAllOrders();
    manager.viewNextOrder();
    manager.dispatchOrder();
    manager.displayAllOrders();
    manager.cancelOrder(1003);
    manager.displayAllOrders();

    return 0;
}
