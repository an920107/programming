#include <iostream>
#include <algorithm>
#include <vector>

long long int l1 = 0, l2 = 0, r1 = 0, r2 = 0;

struct city
{
    long long int x_, l_, r_;
    std::vector<int> r_inv_id;
};

bool cmp1(city a, city b)
{
    if(a.x_ != b.x_) return a.x_ < b.x_;
    return a.r_ < b.r_;
}
bool cmp2(city a, city b)
{
    if(a.r_ != b.r_) return a.r_ < b.r_;
    return a.l_ < b.l_;
}

long long int inv(std::vector<city> pos_, int left, int right);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    std::cin >> n;
    std::cin >> l1 >> l2 >> r1 >> r2;
    
    std::vector<city> pos(n);
    for(int i = 0; i < n; i++)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        pos[i].x_ = x;
        pos[i].l_ = l1*x - l2*y;
        pos[i].r_ = r1*x - r2*y;
    }

    std::sort(pos.begin(), pos.end(), cmp1);
    
    std::cout << "\n";
    for(int i = 0; i < n; i++)
        std::cout << pos[i].x_ << " " << pos[i].l_ << " " << pos[i].r_ << "\n";
    std::cout << "\n";

    long long int res = 0;
    res = inv(pos, 0, n - 1);
    std::cout << res;

    return 0;
}

long long int inv(std::vector<city> pos_, int left, int right)
{
    if(left == right)
        return 0;
    int mid = (left + right) / 2;
    long long int left_ = inv(pos_, left, mid);
    long long int right_ = inv(pos_, mid + 1, right);

    int i = left;
    int j = mid + 1;
    int k = 0;
    std::vector<city> output(right - left + 1);
    long long int inv_ = 0;

    while(i <= mid && j <= right)
    {
        if(pos_[i].r_ < pos_[j].r_ || pos_[i].x_ == pos_[j].x_)
        {
            output[k] = pos_[i];
            k++;
            i++;
        }
        else
        {
            output[k] = pos_[j];
            k++;
            j++;
            inv_ += (mid - i) + 1;
            std::cout << i << " " << j << "\n";
        }
    }
    while(i <= mid)
    {
        output[k] = pos_[i];
        k++;
        i++;
    }
    while(j <= right)
    {
        output[k] = pos_[j];
        k++;
        j++;
    }

    k = 0;
    for(int i = left; i <= right; i++)
    {
        pos_[i] = output[k];
        k++;
    }
    return inv_ + left_ + right_;
}