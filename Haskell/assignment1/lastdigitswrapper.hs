-- sum of n^k, where k goes from 0 to n == (n^(n-1)-1)/(n-1),
--unless n == 1, in which case the sum is simply 2
lastDigits :: Integer -> Int -> [Integer]
lastDigits n d
 | n == 1 = intToDigits 2 d
 | otherwise = intToDigits (((n ^ (n + 1)) - 1) `div` (n - 1)) d

-- get the list of the last d digits
intToDigits :: Integer -> Int -> [Integer]
intToDigits num d
 | d == 0 = []
 | num == 0 = []
 | otherwise = (intToDigits (num `div` 10) (d - 1)) ++ [num `mod` 10]

wrapper :: [String] -> [Integer]
wrapper (a:b:_) = lastDigits (read a::Integer) (read b::Int)

main =  print . wrapper . words =<< getLine
