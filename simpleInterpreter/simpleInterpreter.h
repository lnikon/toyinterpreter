// simpleInterpreter.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <string>

class Buffer {
public:
    explicit Buffer(const std::string& cmd)
        : m_buffer(cmd) {}

    auto read() const {
        return m_buffer;
    }

    void write(const std::string& cmd) {
        m_buffer = cmd;
    }

private:
    std::string m_buffer;
};

class HistoryManager {
public:
    void addHistory(const Buffer& buf) {
        m_cmds.push_back(buf);
    }

    auto getLatest() const {
        return m_cmds.back();
    }

    void clearHistory() {
        m_cmds.clear();
    }

    auto historySize() {
        return m_cmds.size();
    }

private:
    std::vector<Buffer> m_cmds;
};

class Interpreter {
public:
    void addHistory(const std::string& cmd) {
        m_hisMan.addHistory(Buffer{ cmd });
    }

    void read(const std::string& cmd) {
        m_buf = Buffer{ cmd };
        m_hisMan.addHistory(m_buf);
    }

    void eval() {

    }

    void print(const std::string& cmd) {
        std::cout << cmd << '\n';
    }
private:
    Buffer m_buf;
    HistoryManager m_hisMan;
};

// TODO: Reference additional headers your program requires here.
