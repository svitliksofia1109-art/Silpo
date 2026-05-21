#include "Order.cpp"

int main() {
    int choice;
    Order order;

    do {
        cout << "Select to continue" << endl;
        cout << "1 - Add product" << endl;
        cout << "2 - Remove product" << endl;
        cout << "3 - Change quantity" << endl;
        cout << "4 - Change status" << endl;
        cout << "5 - Set a date" << endl;
        cout << "6 - Show an order" << endl;
        cout << "7 - Save to file" << endl;
        cout << "8 - Load from file" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choose: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int q;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> q;
            order.AddProduct(name, q);
        }
        else if (choice == 2) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            order.RemoveProduct(name);
        }
        else if (choice == 3) {
            string name;
            int q;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> q;
            order.ChangeQuantity(name, q);
        }
        else if (choice == 4) {
            cout << "1 - Paid" << endl;
            cout << "2 - Not_paid" << endl;
            cout << "3 - Completed" << endl;
            cout << "4 - Canceled" << endl;

            int s;
            cin >> s;

            if (s == 1) order.SetStatus("Paid");
            else if (s == 2) order.SetStatus("Not_paid");
            else if (s == 3) order.SetStatus("Completed");
            else if (s == 4) order.SetStatus("Canceled");
        }
        else if (choice == 5) {
            string date;
            cout << "Date(YYYY-MM-DD): ";
            cin >> date;
            order.SetData(date);
        }
        else if (choice == 6) {
            order.ShowOrder();
        }
        else if (choice == 7) {
            order.SaveInFile();
        }
        else if (choice == 8) {
            order.LoadFromFile();
            cout << "Loaded successfully!" << endl;
        }

    } while (choice != 0);

    return 0;
}