#include "parser.ih"

RuleValue Parser::angleOut(double rad)
{
    if (d_angleType == ANGLE_DEG)
    	rad = 180.0 * rad / PI_VAL;
    else if (d_angleType == ANGLE_GRAD)
    	rad = 200.0 * rad / PI_VAL;

    return RuleValue(rad);
}