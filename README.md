
# CoAP Protocol Simulator in C++

A lightweight CoAP (Constrained Application Protocol) client simulator written in modern **C++17**, using the `libcoap` library. This project demonstrates how to send CoAP requests over UDP, ideal for learning or testing **IoT protocols** in constrained environments.

---

## 🚀 Features

- 📡 Send CoAP **GET** requests
- 🛰️ Simulate client behavior in IoT environments
- 🔧 Easily extensible for PUT/POST/OBSERVE
- 📦 CMake-based build system
- 🧪 Compatible with real CoAP servers like `coap.me`

---

## 🧱 Project Structure

```
CoAP-Simulator/
├── include/
│   └── coap_client.hpp        # CoAP client class definition
├── src/
│   ├── coap_client.cpp        # CoAP client implementation
│   └── main.cpp               # Entry point for simulation
├── CMakeLists.txt             # Build configuration
├── .gitignore                 # Ignored files
├── LICENSE                    # License file (MIT by default)
└── README.md                  # You're here!
```

---

## 📦 Requirements

- OS: Linux (Ubuntu recommended)
- C++17 or higher
- [libcoap](https://libcoap.net/) development files

---

## 🔧 Installation

### 1. Clone the repository

```bash
git clone https://github.com/yousefsmt/CoAP-Protocol.git
cd CoAP-Protocol
```

### 2. Install dependencies (on Ubuntu)

```bash
sudo apt update
sudo apt install cmake g++ libcoap3 libcoap3-dev
```

### 3. Build the project

```bash
mkdir build
cd build
cmake ..
make
```

---

## ▶️ Run the Simulation

```bash
./coap_simulator
```

By default, the client sends a GET request to a test server (e.g., `coap.me`). You can modify `main.cpp` to set a custom URI or test different message types.

---

## 🌐 Public CoAP Servers for Testing

- [`coap://coap.me`](https://coap.me/)
- [`californium.eclipseprojects.io`](https://www.eclipse.org/californium/)

Use Wireshark or `tcpdump` to inspect UDP packets.

---

## 📚 References

- [RFC 7252 - CoAP Specification](https://datatracker.ietf.org/doc/html/rfc7252)
- [libcoap Official Site](https://libcoap.net/)
- [Wireshark CoAP Filtering](https://wiki.wireshark.org/CoAP)

---

## ❓ FAQ

### Q: What port does CoAP use?

- Default CoAP UDP port is **5683**.

### Q: How is CoAP different from HTTP?

| Feature       | CoAP        | HTTP       |
|---------------|-------------|------------|
| Transport     | UDP         | TCP        |
| Encoding      | Binary      | Text (ASCII) |
| Multicast     | Yes         | No         |
| Lightweight   | ✅           | ❌         |

---

## 📝 License

This project is licensed under the [MIT License](LICENSE).
