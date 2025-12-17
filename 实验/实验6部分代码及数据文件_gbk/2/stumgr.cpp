#include "stumgr.hpp"
#include <fstream>
#include <algorithm>
#include <sstream>
void StuMgr::write(std::ostream &os) const  // 把数据写到任意输出流
{
    for (const auto& student : students) {
        os << student << '\n';
    }
}

void StuMgr::load(const std::string& file)  // 加载数据文件（空格分隔）
{

    std::ifstream is(file);
    if (!is.is_open()) {
        throw std::runtime_error("无法打开文件: " + file);
    }

    students.clear();
    std::string line;
    std::getline(is, line); 

    Student t;
    int line_no = 1;

    while (std::getline(is, line)) {
        ++line_no;
        std::istringstream ss(line);
        if(!(ss >> t)) 
        {
            std::cerr << "[load warning] bad line " << line_no
                      << ": " << line << '\n';
            continue; 
        }else if(t.get_grade() < 0 || t.get_grade() > 100) 
        {
            std::cerr << "[load warning] invalid grade at line " << line_no
                      << ": " << line << '\n';
            continue; 
        }
        students.push_back(t);
    }

}

void StuMgr::sort()                         // 排序: 按专业字典序升序、同专业分数降序
{
    if (students.empty()) {
        throw std::runtime_error("没有加载任何学生数据，无法排序");
        return;
    }
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  if (a.get_major() != b.get_major()) {
                      return a.get_major() < b.get_major();
                  }
                  return a.get_grade() > b.get_grade();
              });
}

void StuMgr::print() const                  // 打印到屏幕
{
    if (students.empty()) {
        throw std::runtime_error("没有加载任何学生数据，无法打印");
        return;
    }
    write(std::cout);
}

void StuMgr::save(const std::string& file) const // 保存到文件
{
    if(students.empty()) {
        throw std::runtime_error("没有加载任何学生数据，无法保存");
        return;
    }

    std::ofstream out(file);
    if(!out)
    {
        throw std::runtime_error("无法打开文件: " + file);
    }
    write(out);
}
