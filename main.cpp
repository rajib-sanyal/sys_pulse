/*#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string line;
    std::ifstream loadFile("/proc/loadavg");
    std::string load1, load5, load15;

    std::cout << "--- Sys-Pulse RHEL Health Report ---" << std::endl;
    if (loadFile >> load1 >> load5 >> load15) {
        std::cout << "System Load (1/5/15 min): " << load1 << " " << load5 << " " << load15 << std::endl;
    }

    std::ifstream memFile("/proc/meminfo");
    std::string label;
    long value;
    while (memFile >> label >> value) {
        if (label == "MemTotal:" || label == "MemAvailable:") {
            std::cout << label << " " << value / 1024 << " MB" << std::endl;
        }
    }
    return 0;
}*/

#include <iostream>
#include <fstream>
#include <string>
#include <sys/statvfs.h>

void getSystemStats() {
    // 1. CPU Load
    std::ifstream loadFile("/proc/loadavg");
    std::string load1, load5, load15;
    if (loadFile >> load1 >> load5 >> load15) {
        std::cout << "CPU Load (1/5/15 min): " << load1 << ", " << load5 << ", " << load15 << std::endl;
    }

    // 2. Memory Info
    std::ifstream memFile("/proc/meminfo");
    std::string label;
    long value;
    while (memFile >> label >> value) {
        if (label == "MemTotal:" || label == "MemAvailable:") {
            std::cout << label << " " << value / 1024 << " MB" << std::endl;
        }
    }

    // 3. Disk Usage (New Feature for v1.1.0)
    struct statvfs stat;
    if (statvfs("/", &stat) == 0) {
        long long total = (long long)stat.f_blocks * stat.f_frsize;
        long long available = (long long)stat.f_bavail * stat.f_frsize;
        std::cout << "Disk Total: " << total / (1024 * 1024 * 1024) << " GB" << std::endl;
        std::cout << "Disk Available: " << available / (1024 * 1024 * 1024) << " GB" << std::endl;
    }
}

int main() {
    std::cout << "--- Sys-Pulse Health Report (v1.1.0) ---" << std::endl;
    getSystemStats();
    return 0;
}
