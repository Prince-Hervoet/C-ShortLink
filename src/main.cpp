#include <iostream>
#include <string>
#include <random>
#include <chrono>

static long long count = 100;
static char base_chars[] = "efghdNDUVQRSTu01BCioEOP23Mpq567vwxyzA89arsjklmntWXYZ$4bcF!GHIJKL";
static int flag = 0x3F;
// 使用当前时间戳作为随机数种子
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 gen(seed);
// 创建均匀分布
std::uniform_int_distribution<> dis(0, 63);

static std::string toShort(long long num, int minLength)
{
    std::string result;
    int temp = 0;
    while (num > 0)
    {
        temp = (num & flag);
        num >>= 6;
        result += base_chars[temp];
    }
    if (result.size() < minLength)
    {
        int remain = minLength - result.size() - 1;
        result += "_";
        int index = 0;
        for (int i = 0; i < remain; i++)
        {
            index = dis(gen);
            result += base_chars[index];
        }
    }
    return result;
}

int main()
{
    // 获取当前时间戳
    auto now = std::chrono::system_clock::now();
    auto now_milliseconds = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto start = now_milliseconds.time_since_epoch().count();
    std::string ans = toShort(3, 6);
    std::cout << ans << std::endl;
    // 获取当前时间戳
    now = std::chrono::system_clock::now();
    now_milliseconds = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto end = now_milliseconds.time_since_epoch().count();
    std::cout << "位运算版本耗时: " << (end - start) << "ms" << std::endl;
    count = 0;
    return 0;
}