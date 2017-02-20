import Data.List

-- Composites:

primes :: [Integer]
primes = sieve [2..]
 where
  sieve :: [Integer] -> [Integer]
  sieve (p:xs) = p : sieve [x | x <- xs, x `mod` p /= 0]

composites :: [(Integer, [Integer])]
composites = [(x, divisors x primes) | x <- [4..], x /= head(divisors x primes)]
  where
   divisors :: Integer -> [Integer] -> [Integer]
   divisors x (p:xs)
    | x == 1 = []
    | mod x p == 0 = p:(divisors (div x p) (p:xs))
    | otherwise = divisors x xs

-- Selfre:

selfre :: [Int]
selfre = [1, 2, 2] ++ makeSelfre [2] 1
 where
  makeSelfre :: [Int] -> Int -> [Int]
  makeSelfre (x:xs) y = (replicate x y) ++ makeSelfre (xs ++ (replicate x y)) (1 + (mod y 2))

-- Fibcat:

fib :: [Integer]
fib = [0, 1] ++ fibSeq 0 1
 where
  fibSeq :: Integer -> Integer -> [Integer]
  fibSeq x y = (x + y):fibSeq y (x + y)

catNum :: [Integer]
catNum = 1:catSeq [1]
 where
  catSeq :: [Integer] -> [Integer]
  catSeq xs = (nextCat xs):catSeq (xs ++ [nextCat xs])
   where
    nextCat :: [Integer] -> Integer
    nextCat [] = 0
    nextCat [x] = x^2
    nextCat (x:xs) = (2 * x * (last xs)) + nextCat (init xs)

fibcat :: [Integer]
fibcat = [0, 1] ++ fibcatSeq (drop 3 fib) (drop 2 catNum)
 where
  fibcatSeq :: [Integer] -> [Integer] -> [Integer]
  fibcatSeq (x:xs) (y:ys)
   | x == y = x:fibcatSeq xs ys
   | x < y = x:fibcatSeq xs (y:ys)
   | y < x = y:fibcatSeq (x:xs) ys

-- another primes sieve

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
i = (- 1 + sqrt(1 + 2x))/2
-}

primesTM :: [Integer]
primesTM = 2:[ 2 * x + 1 | x <- [1..], notWrongForm x (floor (((sqrt (1 + 2 * (fromIntegral x)) - 1) / 2)))]
 where
  notWrongForm :: Integer -> Integer -> Bool
  notWrongForm x maxI = null [i | i <- [1..maxI], (x - i) `mod` (1 + 2*i) == 0]
