#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Product {
    string name;
    int quantity;
};

class Order {
private:
    vector<Product> products;
    string status;
    string DateDelivery;
public:
    Order() {
        status = "Not_paid";
        DateDelivery = "Not_selected";
    }

    void AddProduct(string name, int quantity) {
        products.push_back({ name, quantity });
    }

    void RemoveProduct(string name) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i].name == name) {
                products.erase(products.begin() + i);
                break;
            }
        }
    }

    void ChangeQuantity(string name, int quantity) {
        for (auto& p : products) {
            if (p.name == name) {
                p.quantity = quantity;
            }
        }
    }

    void SetStatus(string s) {
        status = s;
    }

    void SetData(string date) {
        DateDelivery = date;
    }

    void ShowOrder() {
        cout << "\nSilpo Order\n";
        for (auto p : products) {
            cout << p.name << " - " << p.quantity << endl;
        }
        cout << "Date of delivery: " << DateDelivery << endl;
        cout << "Status: " << status << endl;
    }

    void SaveInFile() {
        ofstream file("order.txt");
        file << DateDelivery << endl;
        file << status << endl;
        file << products.size() << endl;

        for (auto p : products) {
            file << p.name << " " << p.quantity << endl;
        }
        file.close();
    }

    void LoadFromFile() {
        ifstream file("order.txt");
        if (!file) {
            cout << "File not found!" << endl;
            return;
        }

        int size;

        file >> DateDelivery;
        file >> status;
        file >> size;

        products.clear();

        for (int i = 0; i < size; i++) {
            Product p;
            file >> p.name >> p.quantity;
            products.push_back(p);
        }
        file.close();
    }

    int GetProductsCount() {
        return products.size();
    }
    int GetQuantity(string name) {
        for (auto p : products) {
            if (p.name == name) {
                return p.quantity;
            }
        }
        return -1;
    }
    string GetStatus() {
        return status;
    }
    string GetDate() {
        return DateDelivery;
    }
};