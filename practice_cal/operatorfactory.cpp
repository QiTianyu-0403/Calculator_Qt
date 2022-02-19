#include"operatorfactory.h"

map<string, function<shared_ptr<Operator>()>> Factory::ms_operator;
