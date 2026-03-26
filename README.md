# Sys-Pulse [![Build Status](https://github.com/rajib-sanyal/sys_pulse/actions/workflows/build.yml/badge.svg)](https://github.com/rajib-sanyal/sys_pulse/actions) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A lightweight C++ System Health Monitor designed for RHEL and containerized using Multi-Stage Docker builds.

## Features
- **Real-time CPU Load:** Extracts data from \`/proc/loadavg\`.
- **Memory Monitoring:** Parses \`/proc/meminfo\` for Total and Available memory.
- **Optimized Container:** Uses a multi-stage build to keep the final image under 10MB.

## How to Run
\`\`\`bash
docker build -t sys_pulse .
docker run sys_pulse
\`\`\`
