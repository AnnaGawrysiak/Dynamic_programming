#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices);

int main()
{
    std::vector<int> stock_prices = { 7,1,5,3,6,4 };

    std::cout << "Maximum possible profit is: " << maxProfit(stock_prices) << std::endl;

    return 0;
}

int maxProfit(const std::vector<int>& prices)
{
    int maxprofit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[i - 1];
    }

    return maxprofit;
}
