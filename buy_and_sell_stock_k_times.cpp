#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices, int k);

int main()
{
    std::vector<int> stock_prices = { 2, 5, 7, 1, 4, 3, 1, 3 };
    int k = 3;
    std::cout << "Maximum possible profit is: " << maxProfit(stock_prices, k) << std::endl;

    return 0;
}

int maxProfit(const std::vector<int>& prices, int k)
{
    if (prices.size() <= 1)
        return 0;
  
    int days = prices.size();

    std::vector<int> row(days, 0);
    std::vector<std::vector<int>> subproblems(k+1, row);

    for (int i = 1; i < subproblems.size(); i++)
    {
        int profit = 0;

        for (int j = 1; j < row.size(); j++)
        {

            for (int m = 0; m < j; m++)
            {
                profit = std::max(prices.at(j) - prices.at(m) + subproblems.at(i - 1).at(m), profit);
            }

            subproblems.at(i).at(j) = std::max(subproblems.at(i).at(j), profit);
        }
    }

    for (int i = 0; i < subproblems.size(); i++)
    {
        for (int j = 0; j < row.size(); j++)
        {
            std::cout << subproblems.at(i).at(j) << " ";
        }

        std::cout << std::endl;
    }
    
    return subproblems.at(k).at(days-1);
}