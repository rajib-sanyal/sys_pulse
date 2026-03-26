#include <iostream>
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
}
