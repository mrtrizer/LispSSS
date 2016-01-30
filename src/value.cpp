#include "value.h"

Value::Value(Data * data):data(data->getClone())
{
}
