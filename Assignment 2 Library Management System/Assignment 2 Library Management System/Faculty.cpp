#include "Faculty.h"

Faculty::Faculty(string name) : User(name) {}
string Faculty::getUserType() const { return "Faculty"; }