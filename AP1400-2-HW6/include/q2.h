#ifndef Q2_H
#define Q2_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
namespace q2
{
    struct Patient
    {
        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };

    std::vector<string> split(string origin, char delimeter);

    std::string trim(const std::string &s);

    std::vector<Patient> read_file(std::string filename)
    {
        std::ifstream fs;
        fs.open(filename);
        std::string line;
        std::vector<Patient> ret;
        while (std::getline(fs, line))
        {
            /* code */
            std::vector<string> v = split(line, ',');
            if (v.size() == 0 || v.size() == 1 || v[0] == "Name")
            {
                continue;
            }
            Patient p;
            p.name = v[0] + " " + v[1];
            p.age = std::stod(v[2]);
            p.smokes = std::stod(v[3]);
            p.area_q = std::stod(v[4]);
            p.alkhol = std::stod(v[5]);
            ret.push_back(p);
        }
        fs.close();
        return ret;
    }

    std::vector<string> split(string origin, char delimeter)
    {
        std::vector<string> v;
        std::stringstream fs(origin);
        string token;
        while (std::getline(fs, token, delimeter))
        {
            /* code */
            token = trim(token);
            v.push_back(token);
        }
        return v;
    }

    std::string trim(const std::string &s)
    {
        auto start = s.begin();
        auto end = s.end();

        // 查找第一个非空白字符
        while (start != end && std::isspace(*start))
        {
            start++;
        }

        // 从末尾查找第一个非空白字符
        while (start != end && std::isspace(*(end - 1)))
        {
            end--;
        }

        return std::string(start, end);
    }

    void sort(std::vector<Patient> &v)
    {
        std::sort(v.begin(), v.end(),
                  [](Patient &pa, Patient &pb)
                  {
                      return (3 * pa.age + 5 * pa.smokes + 2 * pa.area_q + 4 * pa.alkhol) >
                             (3 * pb.age + 5 * pb.smokes + 2 * pb.area_q + 4 * pb.alkhol);
                  });
    }
}

#endif // Q2_H