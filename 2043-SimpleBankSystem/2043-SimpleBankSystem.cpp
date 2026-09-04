// Last updated: 9/5/2026, 12:24:30 AM
class Bank {
private:
    vector<long long> bal;
    int n;

public:
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    bool withdraw(int account, long long money) {
        if (account < 1 || account > n)
            return false;
        if (bal[account - 1] < money)
            return false;
        bal[account - 1] -= money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account < 1 || account > n)
            return false;
        bal[account - 1] += money;
        return true;
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > n || account2 < 1 || account2 > n)
            return false;
        if (bal[account1 - 1] < money)
            return false;
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }
};
