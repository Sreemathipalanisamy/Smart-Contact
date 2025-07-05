#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Contact {
    int id;
    string name;
    string phone;
    string email;
    string address;
    
    Contact(int i, string n, string p, string e, string a) 
        : id(i), name(n), phone(p), email(e), address(a) {}
};

class ContactManager {
private:
    vector<Contact> contacts;
    int nextId = 1;
    
    void displayContact(const Contact& contact) {
        cout << "\nID: " << contact.id;
        cout << "\nName: " << contact.name;
        cout << "\nPhone: " << contact.phone;
        cout << "\nEmail: " << contact.email;
        cout << "\nAddress: " << contact.address;
        cout << "\n--------------------------\n";
    }
    
    vector<Contact>::iterator findContactById(int id) {
        return find_if(contacts.begin(), contacts.end(), 
            [id](const Contact& c) { return c.id == id; });
    }
    
    int generateId() {
        return nextId++;
    }
    
public:
    void addContact() {
        string name, phone, email, address;
        
        cout << "\nEnter Name: ";
        getline(cin >> ws, name);
        
        cout << "Enter Phone: ";
        getline(cin, phone);
        
        for (const auto& contact : contacts) {
            if (contact.phone == phone) {
                cout << "Contact with this phone number already exists!\n";
                return;
            }
        }
        
        cout << "Enter Email: ";
        getline(cin, email);
        
        cout << "Enter Address: ";
        getline(cin, address);
        
        int id = generateId();
        contacts.emplace_back(id, name, phone, email, address);
        
        cout << "Contact added successfully with ID: " << id << "\n";
    }
    
    void searchByName() {
        string name;
        cout << "\nEnter name to search: ";
        getline(cin >> ws, name);
        
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.name.find(name) != string::npos) {
                displayContact(contact);
                found = true;
            }
        }
        
        if (!found) {
            cout << "No contacts found with that name.\n";
        }
    }
    
    void searchByPhone() {
        string phone;
        cout << "\nEnter phone number to search: ";
        getline(cin >> ws, phone);
        
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.phone.find(phone) != string::npos) {
                displayContact(contact);
                found = true;
            }
        }
        
        if (!found) {
            cout << "No contacts found with that phone number.\n";
        }
    }
    
    void searchById() {
        int id;
        cout << "\nEnter ID to search: ";
        cin >> id;
        
        auto it = findContactById(id);
        if (it != contacts.end()) {
            displayContact(*it);
        } else {
            cout << "Contact not found with ID: " << id << "\n";
        }
    }
    
    void updateContact() {
        int id;
        cout << "\nEnter ID of contact to update: ";
        cin >> id;
        cin.ignore();
        
        auto it = findContactById(id);
        if (it != contacts.end()) {
            string name, phone, email, address;
            
            cout << "Enter new Name (current: " << it->name << "): ";
            getline(cin, name);
            
            cout << "Enter new Phone (current: " << it->phone << "): ";
            getline(cin, phone);
            
            for (const auto& contact : contacts) {
                if (contact.id != id && contact.phone == phone) {
                    cout << "Another contact already has this phone number!\n";
                    return;
                }
            }
            
            cout << "Enter new Email (current: " << it->email << "): ";
            getline(cin, email);
            
            cout << "Enter new Address (current: " << it->address << "): ";
            getline(cin, address);
            
            it->name = name;
            it->phone = phone;
            it->email = email;
            it->address = address;
            
            cout << "Contact updated successfully!\n";
        } else {
            cout << "Contact not found with ID: " << id << "\n";
        }
    }
    
    void deleteContact() {
        int id;
        cout << "\nEnter ID of contact to delete: ";
        cin >> id;
        
        auto it = findContactById(id);
        if (it != contacts.end()) {
            contacts.erase(it);
            cout << "Contact deleted successfully!\n";
        } else {
            cout << "Contact not found with ID: " << id << "\n";
        }
    }
    
    void displayAllContacts() {
        if (contacts.empty()) {
            cout << "No contacts to display.\n";
            return;
        }
        
        cout << "\nAll Contacts:\n";
        cout << "--------------------------\n";
        for (const auto& contact : contacts) {
            displayContact(contact);
        }
    }
    
    void sortByName() {
        sort(contacts.begin(), contacts.end(), 
            [](const Contact& a, const Contact& b) {
                return a.name < b.name;
            });
        cout << "Contacts sorted by name.\n";
    }
    
    void showMenu() {
        int choice;
        do {
            cout << "\nContact Management System\n";
            cout << "1. Add Contact\n";
            cout << "2. Search Contact by Name\n";
            cout << "3. Search Contact by Phone\n";
            cout << "4. Search Contact by ID\n";
            cout << "5. Update Contact\n";
            cout << "6. Delete Contact\n";
            cout << "7. Display All Contacts\n";
            cout << "8. Sort Contacts by Name\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            
            while (!(cin >> choice) || choice < 1 || choice > 9) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1-9: ";
            }
            
            cin.ignore(); // Clear the newline character
            
            switch (choice) {
                case 1: addContact(); break;
                case 2: searchByName(); break;
                case 3: searchByPhone(); break;
                case 4: searchById(); break;
                case 5: updateContact(); break;
                case 6: deleteContact(); break;
                case 7: displayAllContacts(); break;
                case 8: sortByName(); break;
                case 9: cout << "Exiting...\n"; break;
            }
        } while (choice != 9);
    }
};

int main() {
    ContactManager manager;
    manager.showMenu();
    return 0;
}