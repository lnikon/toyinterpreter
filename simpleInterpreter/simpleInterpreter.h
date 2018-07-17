// simpleInterpreter.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>


class InfixToPostfix
{
public:
    void parse(const std::string& infix) {
        for (size_t i = 0; i < infix.size(); i++) {
            if ((infix[i] == '+') &&
                (infix[i] == '-'))
            {
                m_ops.push(infix[i]);
            }
            else if (isdigit(infix[i]))
            {
                m_values.push(infix[i]);
            }
        }
    }

    float eval() {
        float res = 0;

        while (!m_values.empty())
        {
            float lhs = m_values.top();
            m_values.pop();
            float rhs = m_values.top();
            m_values.pop();

            if (m_ops.top() == '+') {
                res += lhs + rhs;
                m_ops.pop();
            }
            else if (m_ops.top() == '-') {
                res += lhs - rhs;
                m_ops.pop();
            }
            m_values.push(res);
        }
        return res;
    }
private:
    std::string m_infix;
    std::string m_postfix;
    std::stack<float> m_values;
    std::stack<char> m_ops;
};

class Buffer {
public:
    Buffer() = default;
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
    Interpreter() {}
    void addHistory(const std::string& cmd) {
        m_hisMan.addHistory(Buffer{ cmd });
    }

    void read(const std::string& cmd) {
        m_buf = Buffer{ cmd };
        m_hisMan.addHistory(m_buf);
    }

    auto eval(const std::string& cmd) {
        m_itp.parse(cmd);
        auto res = m_itp.eval();
        return res;
    }

    void printBuffer() {
        std::cout << m_buf.read() << '\n';
    }
private:
    Buffer m_buf;
    HistoryManager m_hisMan;
    InfixToPostfix m_itp;
};

// TODO: Reference additional headers your program requires here.
