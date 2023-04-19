#include <iostream>
#include <string>
#include <chrono>

static long long count = 100;
static char base_chars[] = "efghdNDUVQRSTu01BCioEOP23Mpq567vwxyzA89arsjklmntWXYZ$4bcF!GHIJKL";
static int flag = 0x3F;

static std::string toBase62(long long num)
{
    std::string result;
    int temp = 0;
    while (num > 0)
    {
        temp = (num & flag);
        num >>= 6;
        result += base_chars[temp];
    }
    return result;
}

int main()
{
    // 获取当前时间戳
    auto now = std::chrono::system_clock::now();
    auto now_milliseconds = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto start = now_milliseconds.time_since_epoch().count();
    for (; count <= 80000000; ++count)
    {
        std::string ans = toBase62(count);
    }
    // 获取当前时间戳
    now = std::chrono::system_clock::now();
    now_milliseconds = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto end = now_milliseconds.time_since_epoch().count();
    std::cout << "位运算版本耗时: " << (end - start) << "ms" << std::endl;
    count = 0;
    return 0;
}