# --- Stage 1: Build ---
FROM gcc:latest AS builder
WORKDIR /app
COPY main.cpp .
# We use -static to ensure all libraries are packed into the binary
RUN g++ -o sys-pulse main.cpp -static

# --- Stage 2: Runtime ---
# Alpine is a tiny, 5MB Linux distribution
FROM alpine:latest
WORKDIR /root/
# We only copy the finished "sys-pulse" binary from the builder
COPY --from=builder /app/sys-pulse .
CMD ["./sys-pulse"]
