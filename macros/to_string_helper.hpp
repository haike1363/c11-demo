#pragma once
#include <string>
#include <sstream>

/*
支持 << 重载符号的结构体或者原始类型
使用方法:
struct ToStringNode {
    int v1 = 1;
    int v2 = 2;
    std::string v3 = "3";
    ENABLE_TO_STRING_HELP(v1, v2, v3)
};

void testToString(){
    ToStringNode node;
    std::cout << node.to_string_help() << std::endl;
    std::cout << "==========" << std::endl;
    int aa = 0;
    std::string bb = "bb";
    std::cout << TO_STRING_HELP(node.v1, aa, bb) << std::endl;
}
*/

#define TO_STRING_HELP_HINT ": "
#define TO_STRING_HELP_SEPARATOR " "

template <class P1>
std::string g_to_string_help(const char* name, const P1& p1)
{
    std::ostringstream ostm;
    ostm << name << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3, class P4>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3,\
                             const char* n4, const P4& p4)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    ostm << n4 << TO_STRING_HELP_HINT << p4 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3, class P4, class P5>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3,\
                             const char* n4, const P4& p4,\
                             const char* n5, const P5& p5)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    ostm << n4 << TO_STRING_HELP_HINT << p4 << TO_STRING_HELP_SEPARATOR;
    ostm << n5 << TO_STRING_HELP_HINT << p5 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3, class P4, class P5, class P6>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3,\
                             const char* n4, const P4& p4,\
                             const char* n5, const P5& p5,\
                             const char* n6, const P6& p6)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    ostm << n4 << TO_STRING_HELP_HINT << p4 << TO_STRING_HELP_SEPARATOR;
    ostm << n5 << TO_STRING_HELP_HINT << p5 << TO_STRING_HELP_SEPARATOR;
    ostm << n6 << TO_STRING_HELP_HINT << p6 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3, class P4, class P5, class P6, class P7>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3,\
                             const char* n4, const P4& p4,\
                             const char* n5, const P5& p5,\
                             const char* n6, const P6& p6,\
                             const char* n7, const P7& p7)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    ostm << n4 << TO_STRING_HELP_HINT << p4 << TO_STRING_HELP_SEPARATOR;
    ostm << n5 << TO_STRING_HELP_HINT << p5 << TO_STRING_HELP_SEPARATOR;
    ostm << n6 << TO_STRING_HELP_HINT << p6 << TO_STRING_HELP_SEPARATOR;
    ostm << n7 << TO_STRING_HELP_HINT << p7 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3,\
                             const char* n4, const P4& p4,\
                             const char* n5, const P5& p5,\
                             const char* n6, const P6& p6,\
                             const char* n7, const P7& p7,\
                             const char* n8, const P8& p8)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    ostm << n4 << TO_STRING_HELP_HINT << p4 << TO_STRING_HELP_SEPARATOR;
    ostm << n5 << TO_STRING_HELP_HINT << p5 << TO_STRING_HELP_SEPARATOR;
    ostm << n6 << TO_STRING_HELP_HINT << p6 << TO_STRING_HELP_SEPARATOR;
    ostm << n7 << TO_STRING_HELP_HINT << p7 << TO_STRING_HELP_SEPARATOR;
    ostm << n8 << TO_STRING_HELP_HINT << p8 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8, class P9>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3,\
                             const char* n4, const P4& p4,\
                             const char* n5, const P5& p5,\
                             const char* n6, const P6& p6,\
                             const char* n7, const P7& p7,\
                             const char* n8, const P8& p8,\
                             const char* n9, const P9& p9)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    ostm << n4 << TO_STRING_HELP_HINT << p4 << TO_STRING_HELP_SEPARATOR;
    ostm << n5 << TO_STRING_HELP_HINT << p5 << TO_STRING_HELP_SEPARATOR;
    ostm << n6 << TO_STRING_HELP_HINT << p6 << TO_STRING_HELP_SEPARATOR;
    ostm << n7 << TO_STRING_HELP_HINT << p7 << TO_STRING_HELP_SEPARATOR;
    ostm << n8 << TO_STRING_HELP_HINT << p8 << TO_STRING_HELP_SEPARATOR;
    ostm << n9 << TO_STRING_HELP_HINT << p9 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8, class P9, class P10>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3,\
                             const char* n4, const P4& p4,\
                             const char* n5, const P5& p5,\
                             const char* n6, const P6& p6,\
                             const char* n7, const P7& p7,\
                             const char* n8, const P8& p8,\
                             const char* n9, const P9& p9,\
                             const char* n10, const P10& p10)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    ostm << n4 << TO_STRING_HELP_HINT << p4 << TO_STRING_HELP_SEPARATOR;
    ostm << n5 << TO_STRING_HELP_HINT << p5 << TO_STRING_HELP_SEPARATOR;
    ostm << n6 << TO_STRING_HELP_HINT << p6 << TO_STRING_HELP_SEPARATOR;
    ostm << n7 << TO_STRING_HELP_HINT << p7 << TO_STRING_HELP_SEPARATOR;
    ostm << n8 << TO_STRING_HELP_HINT << p8 << TO_STRING_HELP_SEPARATOR;
    ostm << n9 << TO_STRING_HELP_HINT << p9 << TO_STRING_HELP_SEPARATOR;
    ostm << n10 << TO_STRING_HELP_HINT << p10 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8, class P9, class P10, class P11>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3,\
                             const char* n4, const P4& p4,\
                             const char* n5, const P5& p5,\
                             const char* n6, const P6& p6,\
                             const char* n7, const P7& p7,\
                             const char* n8, const P8& p8,\
                             const char* n9, const P9& p9,\
                             const char* n10, const P10& p10,\
                             const char* n11, const P11& p11)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    ostm << n4 << TO_STRING_HELP_HINT << p4 << TO_STRING_HELP_SEPARATOR;
    ostm << n5 << TO_STRING_HELP_HINT << p5 << TO_STRING_HELP_SEPARATOR;
    ostm << n6 << TO_STRING_HELP_HINT << p6 << TO_STRING_HELP_SEPARATOR;
    ostm << n7 << TO_STRING_HELP_HINT << p7 << TO_STRING_HELP_SEPARATOR;
    ostm << n8 << TO_STRING_HELP_HINT << p8 << TO_STRING_HELP_SEPARATOR;
    ostm << n9 << TO_STRING_HELP_HINT << p9 << TO_STRING_HELP_SEPARATOR;
    ostm << n10 << TO_STRING_HELP_HINT << p10 << TO_STRING_HELP_SEPARATOR;
    ostm << n11 << TO_STRING_HELP_HINT << p11 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

template <class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8, class P9, class P10, class P11, class P12>
std::string g_to_string_help(const char* n1, const P1& p1,\
                             const char* n2, const P2& p2,\
                             const char* n3, const P3& p3,\
                             const char* n4, const P4& p4,\
                             const char* n5, const P5& p5,\
                             const char* n6, const P6& p6,\
                             const char* n7, const P7& p7,\
                             const char* n8, const P8& p8,\
                             const char* n9, const P9& p9,\
                             const char* n10, const P10& p10,\
                             const char* n11, const P11& p11,\
                             const char* n12, const P12& p12)
{
    std::ostringstream ostm;
    ostm << n1 << TO_STRING_HELP_HINT << p1 << TO_STRING_HELP_SEPARATOR;
    ostm << n2 << TO_STRING_HELP_HINT << p2 << TO_STRING_HELP_SEPARATOR;
    ostm << n3 << TO_STRING_HELP_HINT << p3 << TO_STRING_HELP_SEPARATOR;
    ostm << n4 << TO_STRING_HELP_HINT << p4 << TO_STRING_HELP_SEPARATOR;
    ostm << n5 << TO_STRING_HELP_HINT << p5 << TO_STRING_HELP_SEPARATOR;
    ostm << n6 << TO_STRING_HELP_HINT << p6 << TO_STRING_HELP_SEPARATOR;
    ostm << n7 << TO_STRING_HELP_HINT << p7 << TO_STRING_HELP_SEPARATOR;
    ostm << n8 << TO_STRING_HELP_HINT << p8 << TO_STRING_HELP_SEPARATOR;
    ostm << n9 << TO_STRING_HELP_HINT << p9 << TO_STRING_HELP_SEPARATOR;
    ostm << n10 << TO_STRING_HELP_HINT << p10 << TO_STRING_HELP_SEPARATOR;
    ostm << n11 << TO_STRING_HELP_HINT << p11 << TO_STRING_HELP_SEPARATOR;
    ostm << n12 << TO_STRING_HELP_HINT << p12 << TO_STRING_HELP_SEPARATOR;
    return ostm.str();
}

#define TO_STRING_HELP1(p1) ::g_to_string_help(#p1, p1)
#define TO_STRING_HELP2(p1, p2) ::g_to_string_help(#p1, p1, #p2, p2)
#define TO_STRING_HELP3(p1, p2, p3) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3)
#define TO_STRING_HELP4(p1, p2, p3, p4) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3, #p4, p4)
#define TO_STRING_HELP5(p1, p2, p3, p4, p5) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3, #p4, p4, #p5, p5)
#define TO_STRING_HELP6(p1, p2, p3, p4, p5, p6) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3, #p4, p4, #p5, p5, #p6, p6)
#define TO_STRING_HELP7(p1, p2, p3, p4, p5, p6, p7) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3, #p4, p4, #p5, p5, #p6, p6, #p7, p7)
#define TO_STRING_HELP8(p1, p2, p3, p4, p5, p6, p7, p8) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3, #p4, p4, #p5, p5, #p6, p6, #p7, p7, #p8, p8)
#define TO_STRING_HELP9(p1, p2, p3, p4, p5, p6, p7, p8, p9) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3, #p4, p4, #p5, p5, #p6, p6, #p7, p7, #p8, p8, #p9, p9)
#define TO_STRING_HELP10(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3, #p4, p4, #p5, p5, #p6, p6, #p7, p7, #p8, p8, #p9, p9, #p10, p10)
#define TO_STRING_HELP11(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3, #p4, p4, #p5, p5, #p6, p6, #p7, p7, #p8, p8, #p9, p9, #p10, p10, #p11, p11)
#define TO_STRING_HELP12(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12) ::g_to_string_help(#p1, p1, #p2, p2, #p3, p3, #p4, p4, #p5, p5, #p6, p6, #p7, p7, #p8, p8, #p9, p9, #p10, p10, #p11, p11, #p12, p12)


#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME

#define TO_STRING_HELP(...) GET_MACRO(__VA_ARGS__,\
    TO_STRING_HELP12,\
    TO_STRING_HELP11,\
    TO_STRING_HELP10,\
    TO_STRING_HELP9,\
    TO_STRING_HELP8,\
    TO_STRING_HELP7,\
    TO_STRING_HELP6,\
    TO_STRING_HELP5,\
    TO_STRING_HELP4,\
    TO_STRING_HELP3,\
    TO_STRING_HELP2,\
    TO_STRING_HELP1)(__VA_ARGS__)


#define ENABLE_TO_STRING_HELP1(p1) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1);\
}

#define ENABLE_TO_STRING_HELP2(p1, p2) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2);\
}

#define ENABLE_TO_STRING_HELP3(p1, p2, p3) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3);\
}

#define ENABLE_TO_STRING_HELP4(p1, p2, p3, p4) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3, p4);\
}

#define ENABLE_TO_STRING_HELP5(p1, p2, p3, p4, p5) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3, p4, p5);\
}

#define ENABLE_TO_STRING_HELP6(p1, p2, p3, p4, p5, p6) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3, p4, p5, p6);\
}

#define ENABLE_TO_STRING_HELP7(p1, p2, p3, p4, p5, p6, p7) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3, p4, p5, p6, p7);\
}

#define ENABLE_TO_STRING_HELP8(p1, p2, p3, p4, p5, p6, p7, p8) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3, p4, p5, p6, p7, p8);\
}

#define ENABLE_TO_STRING_HELP9(p1, p2, p3, p4, p5, p6, p7, p8, p9) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3, p4, p5, p6, p7, p8, p9);\
}

#define ENABLE_TO_STRING_HELP10(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);\
}

#define ENABLE_TO_STRING_HELP11(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);\
}

#define ENABLE_TO_STRING_HELP12(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12) \
    std::string to_string_help() { \
    return TO_STRING_HELP(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);\
}

#define ENABLE_TO_STRING_HELP(...) GET_MACRO(__VA_ARGS__,\
    ENABLE_TO_STRING_HELP12,\
    ENABLE_TO_STRING_HELP11,\
    ENABLE_TO_STRING_HELP10,\
    ENABLE_TO_STRING_HELP9,\
    ENABLE_TO_STRING_HELP8,\
    ENABLE_TO_STRING_HELP7,\
    ENABLE_TO_STRING_HELP6,\
    ENABLE_TO_STRING_HELP5,\
    ENABLE_TO_STRING_HELP4,\
    ENABLE_TO_STRING_HELP3,\
    ENABLE_TO_STRING_HELP2,\
    ENABLE_TO_STRING_HELP1)(__VA_ARGS__)
