#pragma once

template<typename T>
bool is_digit_0_9(T c);

template<typename T>
bool is_digit_0_9(char c) { if (c >= '0' && c <= '9') return true; else return false; }

template<typename T>
bool is_digit_1_9(T c);

template<typename T>
bool is_digit_1_9(char c) { if (c >= '1' && c <= '9') return true; else return false; }

template<typename T>
bool is_a_z(T c);

template<typename T>
bool is_a_z(char c) { if (c >= 'a' && c <= 'z') return true; else return false; }

template<typename T>
bool is_A_Z(T c);

template<typename T>
bool is_A_Z(char c) { if (c >= 'A' && c <= 'Z') return true; else return false; }

template<typename T>
bool is_a_f(T c);

template<typename T>
bool is_a_f(char c) { if (c >= 'a' && c <= 'f') return true; else return false; }

template<typename T>
bool is_A_F(T c);

template<typename T>
bool is_A_F(char c) { if (c >= 'A' && c <= 'F') return true; else return false; }
