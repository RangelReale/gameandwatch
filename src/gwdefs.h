#ifndef H__GWDEFS__H
#define H__GWDEFS__H

#include <string>

using namespace std;

class GW_Exception
{
public:
    GW_Exception(const string &what) : what_(what) {}

    const string &what() { return what_; }
private:
    string what_;
};

#endif //H__GWDEFS__H
