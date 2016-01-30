#include "value.h"

Value::Value(Data * data):data(data == 0? 0:data->getClone())
{
}
