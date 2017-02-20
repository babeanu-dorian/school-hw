import Data.Char

rpnEval :: [Char] -> Int
rpnEval xs = iterateRPN xs [0, 0] False --dummy 0's to fit pattern, never used

-- the second argument is the stack of numeric values read or obtained from calculations
iterateRPN :: [Char] -> [Int] -> Bool -> Int
iterateRPN [] (y:ys) buildingNumber = y
iterateRPN (x:xs) (y0:y1:ys) buildingNumber
 | x == ' ' = iterateRPN xs (y0:y1:ys) False -- ignore spaces
 -- if an operator is found, compute the corresponding operation with the top 2 values
 -- in the stack as operands and push the result on the stack after poping the operands
 | x == '/' = iterateRPN xs ((y1 `div` y0):ys) False
 | x == '*' = iterateRPN xs ((y1 * y0):ys) False
 | x == '+' = iterateRPN xs ((y1 + y0):ys) False
 | x == '-' = iterateRPN xs ((y1 - y0):ys) False
 -- x is a digit and a number is being built, append it to the number at the top of the stack
 | buildingNumber = iterateRPN xs ([(y0 * 10 + (digitToInt x))] ++ (y1:ys)) True
 -- x is a digit, but no number is being built, push it on the stack and start building a number
 | otherwise = iterateRPN xs ((digitToInt x):y0:y1:ys) True

main =  print . rpnEval =<< getLine
