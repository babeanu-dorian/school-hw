primes :: [Integer]
primes  =  sieve [2..]
  where
    sieve :: [Integer] -> [Integer]
    sieve (p:xs)  =  p : sieve [x | x <- xs, x `mod` p /= 0]


-- Insert your own code here.
composites :: [(Integer,[Integer])]
composites = [(x, divisors x primes) | x <- [4..], x /= head(divisors x primes)]
  where
   divisors :: Integer -> [Integer] -> [Integer]
   divisors x (p:xs)
    | x == 1 = []
    | mod x p == 0 = p:(divisors (div x p) (p:xs))
    | otherwise = divisors x xs

-- Do not change the following wrapper code
wrapper :: String -> [(Integer,[Integer])]
wrapper input = take (read input::Int) composites

main =  print . wrapper =<< getLine
