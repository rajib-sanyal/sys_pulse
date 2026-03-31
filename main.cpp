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
#include <sstream>
#include <vector>


void getSystemStats() {
    // 1. CPU Load
    std::ifstream loadFile("/proc/loadavg");
    std::string load1, load5, load15;
    if (loadFile >> load1 >> load5 >> load15) {
        std::cout << "CPU Load (1/5/15 min): " << load1 << ", " << load5 << ", " << load15 << std::endl;
	std::ifstream uptimeFile("/proc/uptime");
double uptimeSeconds;
if (uptimeFile >> uptimeSeconds) {
    int days = uptimeSeconds / (24 * 3600);
    int hours = (static_cast<int>(uptimeSeconds) % (24 * 3600)) / 3600;
    int minutes = (static_cast<int>(uptimeSeconds) % 3600) / 60;

    std::cout << "System Uptime: " << days << "days " << hours << "hours " << minutes << "minutes " << std::endl;
}
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

void getNetworkStats() {
    std::ifstream netFile("/proc/net/dev");
    std::string line;

    // Skip the first two header lines
    std::getline(netFile, line);
    std::getline(netFile, line);

    while (std::getline(netFile, line)) {
        std::stringstream ss(line);
        std::string interface;
        ss >> interface;

        // Skip the loopback interface
        if (interface == "lo:") continue;

        unsigned long long rxBytes, txBytes, dummy;
        // The 1st value after the interface name is Rx Bytes
        ss >> rxBytes;
        // Skip the next 7 values (packets, errs, drop, etc.)
        for(int i=0; i<7; ++i) ss >> dummy;
        // The 9th value total is Tx Bytes
        ss >> txBytes;

        std::cout << "Interface [" << interface << "]" << std::endl;
        std::cout << " Bytes Received:    " << rxBytes / (1024 * 1024) << " MB" << std::endl;
        std::cout << " Bytes Transmitted: " << txBytes / (1024 * 1024) << " MB" << std::endl;
    }
}

int main() {
    std::cout << "--- Sys-Pulse Health Report (v1.3.0) ---" << std::endl;
    getSystemStats();
    getNetworkStats();
    return 0;
}
