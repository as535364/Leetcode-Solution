class Bank:
    def __init__(self, balance: list[int]):
        self._balance = [0] + balance[:]
        self._n = len(balance)
    
    def valid_account(self, accounts: List[int]):
        return all(1 <= account <= self._n for account in accounts)

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if not self.valid_account([account1, account2]):
            return False

        if self._balance[account1] < money:
            return False

        self._balance[account1] -= money
        self._balance[account2] += money

        return True

    def deposit(self, account: int, money: int) -> bool:
        if not self.valid_account([account]):
            return False

        self._balance[account] += money

        return True

    def withdraw(self, account: int, money: int) -> bool:
        if not self.valid_account([account]):
            return False

        if self._balance[account] < money:
            return False

        self._balance[account] -= money

        return True
        


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)