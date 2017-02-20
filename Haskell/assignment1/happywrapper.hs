countHappyNumbers :: Integer -> Integer -> Int
countHappyNumbers a b
 | a > b = 0
 | otherwise = (isHappy a) + (countHappyNumbers (a + 1) b)

-- if x reches 4, it will never reach 1 (sequence behaviour for the sum of the squares of a number's digits)
isHappy :: Integer -> Int
isHappy x
 | x == 1 = 1
 | x == 4 = 0
 | otherwise = isHappy (sumSqDigits x)
 
sumSqDigits :: Integer -> Integer
sumSqDigits 0 = 0
sumSqDigits x = ((x `mod` 10)^2) + sumSqDigits (x `div` 10)

wrapper :: [String] -> Int
wrapper (a:b:_) = countHappyNumbers (read a::Integer) (read b::Integer)

main =  print . wrapper . words =<< getLine
