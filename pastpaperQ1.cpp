
#include <iostream>
#include <string>
using namespace std;

struct Tab {
    int tabID;
    string title;
    string url;
    Tab* prev;
    Tab* next;

    Tab(int id, string t, string u) {
        tabID = id;
        title = t;
        url = u;
        prev = next = nullptr;
    }
};

class TabManager {
private:
    Tab* head;
    Tab* tail;
    Tab* activeTab;

public:
    TabManager() {
        head = tail = activeTab = nullptr;
    }

    // 1. Open a new tab
    void openTab(int id, string title, string url) {
        Tab* newTab = new Tab(id, title, url);
        if (!head) {
            head = tail = activeTab = newTab;
        } else {
            tail->next = newTab;
            newTab->prev = tail;
            tail = newTab;
        }
        cout << "Tab opened: " << title << " (" << url << ")\n";
    }

    // 2. Close tab by ID
    void closeTabByID(int id) {
        Tab* current = head;
        while (current) {
            if (current->tabID == id) {
                if (current == activeTab) {
                    activeTab = (current->next) ? current->next : current->prev;
                }
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;
                delete current;
                cout << "Tab with ID " << id << " closed.\n";
                return;
            }
            current = current->next;
        }
        cout << "Tab ID not found.\n";
    }

    // 3. Switch to a tab by ID
    void switchTab(int id) {
        Tab* current = head;
        while (current) {
            if (current->tabID == id) {
                activeTab = current;
                cout << "Switched to tab: " << current->title << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Tab ID not found.\n";
    }

    // 4. Display tabs forward
    void displayTabsForward() {
        Tab* current = head;
        cout << "Tabs in forward order:\n";
        while (current) {
            cout << "[" << current->tabID << "] " << current->title << " (" << current->url << ")";
            if (current == activeTab) cout << " [ACTIVE]";
            cout << "\n";
            current = current->next;
        }
    }

    // 5. Display tabs reverse
    void displayTabsReverse() {
        Tab* current = tail;
        cout << "Tabs in reverse order:\n";
        while (current) {
            cout << "[" << current->tabID << "] " << current->title << " (" << current->url << ")";
            if (current == activeTab) cout << " [ACTIVE]";
            cout << "\n";
            current = current->prev;
        }
    }
};

int main() {
    TabManager manager;
    manager.openTab(101, "YouTube", "www.youtube.com");
    manager.openTab(102, "Google", "www.google.com");
    manager.openTab(103, "GitHub", "www.github.com");

    manager.displayTabsForward();
    manager.switchTab(102);
    manager.displayTabsReverse();
    manager.closeTabByID(101);
    manager.displayTabsForward();

    return 0;
}
