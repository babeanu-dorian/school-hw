#include "parser.ih"

double Parser::angleIn(RuleValue const &e)
{
    double val = valueOf(e);
    
    if (d_angleType == ANGLE_DEG)
    	val = PI_VAL * val / 180.0;
    else if (d_angleType == ANGLE_GRAD)
    	val = PI_VAL * val / 200.0;

    return val;
}