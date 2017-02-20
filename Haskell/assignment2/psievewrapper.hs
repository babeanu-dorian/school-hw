primes :: [Integer]
-- Insert your own code here.

{-
i + j + 2ij = x
i + j(1 + 2i) = x
j(1 + 2i) = x - i
j = (x - i)/(1 + 2i)

(x - i)/(1 + 2i) <= i
x - i <= i + 2i^2  (1 + 2i > 0)
2i^2 + 2i - x >= 0
delta = 4 + 8x
i = (- 2 + 2sqrt(1 + 2x))/4  (i > 0)
i = (- 1 + sqrt(1 + 2x))/2 (i becomes greater than j after this point)
-}

primesTM = 2:[ 2 * x + 1 | x <- [1..], notWrongForm x (floor (((sqrt (1 + 2 * (fromIntegral x)) - 1) / 2)))]
 where
  notWrongForm :: Integer -> Integer -> Bool
  notWrongForm x maxI = null [i | i <- [1..maxI], (x - i) `mod` (1 + 2*i) == 0]



-- Do not change the following wrapper code
wrapper :: String -> [Integer]
wrapper input = take (read input::Int) primes

main =  print . wrapper =<< getLine
