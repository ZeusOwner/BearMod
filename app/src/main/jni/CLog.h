#pragma once

// Simple CLog class for Logger compatibility
class CLog {
public:
    static bool Open(const char* filename);
    static void Write(const char* format, ...);
    static void Close();
};
