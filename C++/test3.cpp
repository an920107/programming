#include <bits/stdc++.h>
using namespace std;

class Transaction {
private:

    string name;
    int income;
    int pay;

public:

    Transaction(const string &_name)
        : name(_name), income(0), pay(0) {}

    const string& getName() {
        return name;
    }

    int getIncome() {
        return income;
    }

    int getPay() {
        return pay;
    }

    void setIncome(int _income) {
        this->income = _income;
    }

    void setPay(int _pay) {
        this->pay = _pay;
    }

};

void print_transaction(Transaction &trans) {
    cout << trans.getName() << " "
        << trans.getIncome() << " "
        << trans.getPay() << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<Transaction> transactions;

    bool exit_flag = false;
    int command, tmp_num;
    string tmp_str;
    while (!exit_flag && cin >> command) {
        int sum = 0;
        int max_pay = 0, max_i = 0;
        switch (command) {
            case 1: // new income
                cin >> tmp_str >> tmp_num;
                transactions.emplace_back(tmp_str);
                transactions.back().setIncome(tmp_num);
                break;
            case 2: // new pay
                cin >> tmp_str >> tmp_num;
                transactions.emplace_back(tmp_str);
                transactions.back().setPay(tmp_num);
                break;
            case 3: // print all the trans and sum
                for (auto &trans : transactions) {
                    print_transaction(trans);
                    sum += trans.getIncome() - trans.getPay();
                }
                cout << "Total: " << sum << "\n";
                break;
            case 4: // print max pay
                for (int i = 0; i < transactions.size(); i ++) {
                    if (transactions[i].getPay() > max_pay) {
                        max_pay = transactions[i].getPay();
                        max_i = i;
                    }
                }
                print_transaction(transactions[max_i]);
                break;
            case 5:
                exit_flag = true;
                break;
            default:
                cout << "Invalid Operation\n";
                break;
        }
    }

    return 0;
}