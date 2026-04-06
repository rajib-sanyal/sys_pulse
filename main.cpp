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

/*#include <iostream>
#include <fstream>
#include <string>
#include <sys/statvfs.h>
#include <sstream>
#include <vector>
#include <dirent.h>
#include <ctype.h>
#include <iomanip>

void printSeparator() {
    std::cout << std::string(55, '-') << std::endl;
}*/
/*
void printDashboard() {
    std::cout << "\n" << std::string(55, '=') << std::endl;
    std::cout << std::left << std::setw(25) << "SYSTEM RESOURCE" << "STATUS / VALUE" << std::endl;
    std::cout << std::string(55, '=') << std::endl;

    std::cout << std::left << std::setw(25) << "CPU Load (1/5/15):" << getCPULoad() << std::endl;
    std::cout << std::left << std::setw(25) << "System Uptime:"    << getUptime() << std::endl;
    std::cout << std::left << std::setw(25) << "Memory Usage:"     << getMemory() << " MB" << std::endl;
    //std::cout << std::left << std::setw(25) << "CPU Usage:" << getCPUUsage() << std::endl;
    std::cout << std::left << std::setw(25) << "Active Processes:" << getProcessStats() << std::endl;
                      
    
    printSeparator();
    getNetworkStats(); // Update this function internally to use setw(25) too!
    printSeparator();
   // getDiskStats();    // Update this function internally to use setw(25) too!
    getCPUUsage();
    std::cout << std::string(55, '=') << "\n" << std::endl;
                        }
*/
/*int countProcesses() {
    int count = 0;
    DIR* dir = opendir("/proc");
    if (dir == nullptr) return -1;

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        // Check if the directory name starts with a digit (it's a PID)
        if (isdigit(entry->d_name[0])) {
            count++;
        }
    }
    closedir(dir);
    return count;
}


void getCPULoad() {
      std::ifstream loadFile("/proc/loadavg");
      std::string load1, load5, load15;
      if (loadFile >> load1 >> load5 >> load15) {
          std::cout << "CPU Load (1/5/15 min): " << load1 << ", " << load5 << ", " << load15 << std::endl    ;
                                                }
                  }

void getUptime() {
  	std::ifstream uptimeFile("/proc/uptime");
        double uptimeSeconds;
        if (uptimeFile >> uptimeSeconds) {
        int days = uptimeSeconds / (24 * 3600);
        int hours = (static_cast<int>(uptimeSeconds) % (24 * 3600)) / 3600;
        int minutes = (static_cast<int>(uptimeSeconds) % 3600) / 60;
                                         }
        std::cout << "System Uptime: " << days << "days " << hours << "hours " << minutes << "minutes " << std::endl    ;
	          }

  void getMemory() {
  
     std::ifstream memFile("/proc/meminfo");
     std::string label;
     long value;
     while (memFile >> label >> value) {
         if (label == "MemTotal:" || label == "MemAvailable:") {
             std::cout << label << " " << value / 1024 << " MB" << std::endl;
         }
     }

                   }


  void getCPUUsage() {

	  struct statvfs stat;
          if (statvfs("/", &stat) == 0) {
          long long total = (long long)stat.f_blocks * stat.f_frsize;
          long long available = (long long)stat.f_bavail * stat.f_frsize;
          std::cout << std::left << std::setw(25) << "Disk Total: " << total / (1024 * 1024 * 1024) << " GB" << std::endl;
          std::cout << std::left << std::setw(25) << "Disk Available: " << available / (1024 * 1024 * 1024) << " GB" << std::endl;
                                        }
	             }

	  
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
}*/



/*void getNetworkStats() {
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

        std::cout << std::left << std::setw(25) << "Interface [" << interface << "]" << std::endl;
        std::cout << std::left << std::setw(25) << " Bytes Received:    " << rxBytes / (1024 * 1024) << " MB" << std::endl;
        std::cout << std::left << std::setw(25) << " Bytes Transmitted: " << txBytes / (1024 * 1024) << " MB" << std::endl;
   
    }
}

void getProcessStats() {
    int totalProcs = countProcesses();
    if (totalProcs != -1) {
        std::cout << "Total Number of Active Processes: " << totalProcs << std::endl;
    } else {
        std::cerr << "Error: Could not access /proc to count the number of processes." << std::endl;
    }
}


void printDashboard() {
    std::cout << "\n" << std::string(55, '=') << std::endl;
    std::cout << std::left << std::setw(25) << "SYSTEM RESOURCE" << "STATUS / VALUE" << std::endl;
    std::cout << std::string(55, '=') << std::endl;

    std::cout << std::left << std::setw(25) << "CPU Load (1/5/15):" << getCPULoad() << std::endl;
    std::cout << std::left << std::setw(25) << "System Uptime:"    << getUptime() << std::endl;
    std::cout << std::left << std::setw(25) << "Memory Usage:"     << getMemory() << " MB" << std::endl;
    //std::cout << std::left << std::setw(25) << "CPU Usage:" << getCPUUsage() << std::endl;
    std::cout << std::left << std::setw(25) << "Active Processes:" << getProcessStats() << std::endl;


    printSeparator();
    getNetworkStats(); // Update this function internally to use setw(25) too!
    printSeparator();
   // getDiskStats();    // Update this function internally to use setw(25) too!
    getCPUUsage();
    std::cout << std::string(55, '=') << "\n" << std::endl;
                        }

int main() {
    std::cout << "--- Sys-Pulse Health Report (v1.4.0) ---" << std::endl;
    //getSystemStats();
    //getNetworkStats();
   //getProcessStats();
    printDashboard();
    return 0;
}*/

#include <iostream>
#include <fstream>
#include <string>
#include <sys/statvfs.h>
#include <sstream>
#include <vector>
#include <dirent.h>
#include <ctype.h>
#include <iomanip>

void printSeparator() {
    std::cout << std::string(55, '-') << std::endl;
}

int countProcesses() {
    int count = 0;
    DIR* dir = opendir("/proc");
    if (dir == nullptr) return -1;

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        // Check if the directory name starts with a digit (it's a PID)
        if (isdigit(entry->d_name[0])) {
            count++;
        }
    }
    closedir(dir);
    return count;
}

std::string getCPULoad() {
      std::ifstream loadFile("/proc/loadavg");
      std::string load1, load5, load15;
      if (loadFile >> load1 >> load5 >> load15) {
        std::stringstream ss;
        ss << load1 << ", " << load5 << ", " << load15;
        return ss.str(); // Returns "0.06, 0.09, 0.05"
    }
    return "Error";

 }

std::string getUptime() {
        std::ifstream uptimeFile("/proc/uptime");
        double uptimeSeconds;
        if (uptimeFile >> uptimeSeconds) {
          std::stringstream ss;
        int days = uptimeSeconds / (24 * 3600);
        int hours = (static_cast<int>(uptimeSeconds) % (24 * 3600)) / 3600;
        int minutes = (static_cast<int>(uptimeSeconds) % 3600) / 60;

        ss << days << "days " << hours << "hours " << minutes << "minutes ";
        return ss.str();
        }
        return "N/A";

    }

std::string getMemory() {

     std::ifstream memFile("/proc/meminfo");
     std::string label, unit;
     long value;
     long total = 0, avail = 0;
     while (memFile >> label >> value>>unit) {
          
         if (label == "MemTotal:") {
             total = value / 1024;
           
       } 
         else if(label == "MemAvailable:"){
               avail = value/1024;
          }   
     }
      
       if (total > 0 && avail > 0)
        {
        std::stringstream ss;
        ss << avail << " MB / " << total << " MB";
        return ss.str();
        }          
  return "N/A";
 }

std::string getDiskStats() {
    struct statvfs stat;

    // Check the root directory (/)
    if (statvfs("/", &stat) == 0) {
        long long total = (long long)stat.f_blocks * stat.f_frsize;
        long long available = (long long)stat.f_bavail * stat.f_frsize;

        std::stringstream ss;
        // Format: "Available / Total" to match the Memory row
        ss << (available / (1024 * 1024 * 1024)) << " GB / "
           << (total / (1024 * 1024 * 1024)) << " GB";

        return ss.str();
    }

    return "N/A";
}

std::string getNetworkStats() {
    std::ifstream netFile("/proc/net/dev");
    std::string line;
    std::stringstream report; // This will hold all the lines

    // Skip the two header lines
    std::getline(netFile, line);
    std::getline(netFile, line);

    while (std::getline(netFile, line)) {
        std::stringstream ss(line);
        std::string interface;
        ss >> interface;

        // Skip loopback and empty entries
        if (interface == "lo:" || interface.empty()) continue;

        // Clean up: Remove the trailing colon from interface names
        if (interface.back() == ':') interface.pop_back();

        unsigned long long rxBytes, txBytes, dummy;
        ss >> rxBytes;
        for(int i=0; i<7; ++i) ss >> dummy;
        ss >> txBytes;

        // Format each interface as a pair of aligned rows
        report << std::left << std::setw(25) << ("Net [" + interface + "] Rx:")
               << (rxBytes / (1024 * 1024)) << " MB" << "\n";
        report << std::left << std::setw(25) << ("Net [" + interface + "] Tx:")
               << (txBytes / (1024 * 1024)) << " MB" << "\n";
    }

    return report.str(); // Returns all interface data as one string
}


std::string getProcessStats() {
    int totalProcs = countProcesses();
    std::stringstream ss;
    if (totalProcs != -1) {
        ss << totalProcs;
        } else {
        ss << "N/A";
        }
    return ss.str();
}


void printDashboard() {
    std::cout << "\n" << std::string(55, '=') << std::endl;
    std::cout << std::left << std::setw(25) << "SYSTEM RESOURCE" << "STATUS / VALUE" << std::endl;
    std::cout << std::string(55, '=') << std::endl;

    // Single-line metrics
    std::cout << std::left << std::setw(25) << "CPU Load (1/5/15):" << getCPULoad() << std::endl;
    std::cout << std::left << std::setw(25) << "System Uptime:"    << getUptime() << std::endl;
    std::cout << std::left << std::setw(25) << "Memory (Avail/Tot):" << getMemory() << std::endl;
    std::cout << std::left << std::setw(25) << "Disk (Avail/Total):" << getDiskStats() << std::endl;
    std::cout << std::left << std::setw(25) << "Active Processes:"   << getProcessStats() << std::endl;

    // Multi-line metrics
    printSeparator();
    std::cout << getNetworkStats();

    std::cout << std::string(55, '=') << "\n" << std::endl;
}

int main() {
    std::cout << "--- Sys-Pulse Health Report (v1.5.0) ---" << std::endl;
    printDashboard();
    return 0;
}


