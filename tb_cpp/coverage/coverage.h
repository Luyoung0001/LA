#ifndef COVERAGE_H
#define COVERAGE_H

#include <map>
#include <string>
#include <iostream>
#include <cstdint>

// 功能覆盖率收集器
class Coverage {
private:
    std::map<std::string, uint64_t> bins;
    std::map<std::string, uint64_t> goals;

public:
    // 添加覆盖点
    void add_bin(const std::string& name, uint64_t goal = 1) {
        bins[name] = 0;
        goals[name] = goal;
    }

    // 命中覆盖点
    void hit(const std::string& name) {
        if (bins.find(name) != bins.end()) {
            bins[name]++;
        }
    }

    // 获取覆盖率
    double get_coverage() const {
        if (bins.empty()) return 100.0;
        int covered = 0;
        for (const auto& pair : bins) {
            if (pair.second >= goals.at(pair.first)) {
                covered++;
            }
        }
        return (100.0 * covered) / bins.size();
    }

    // 打印报告
    void report() const {
        std::cout << "\n=== Coverage Report ===" << std::endl;
        std::cout << "Overall: " << get_coverage() << "%" << std::endl;
        for (const auto& pair : bins) {
            uint64_t goal = goals.at(pair.first);
            std::cout << "  " << pair.first << ": "
                     << pair.second << "/" << goal
                     << (pair.second >= goal ? " [PASS]" : " [FAIL]")
                     << std::endl;
        }
    }
};

#endif // COVERAGE_H
