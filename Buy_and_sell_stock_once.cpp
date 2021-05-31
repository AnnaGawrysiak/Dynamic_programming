#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices);

int main()
{
    std::vector<int> stock_prices= { 7,1,5,3,6,4 };

    std::cout << "Maximum possible profit is: " << maxProfit(stock_prices) << std::endl;

    return 0;
}

int maxProfit(const std::vector<int>& prices)
{
    if (prices.size() <= 1)
        return 0;

    int min_so_far = prices[0];
    int profit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        profit = std::max(profit, prices[i] - min_so_far);
        min_so_far = std::min(min_so_far, prices[i]);
    }

    return profit;
}