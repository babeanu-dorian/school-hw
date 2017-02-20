fibcats :: [Integer]
-- Insert your own code here.
fibcat = [0, 1] ++ fibcatSeq (drop 3 fib) (drop 2 catNum)
 where
  fibcatSeq :: [Integer] -> [Integer] -> [Integer]
  fibcatSeq (x:xs) (y:ys)
   | x == y = x:fibcatSeq xs ys
   | x < y = x:fibcatSeq xs (y:ys)
   | y < x = y:fibcatSeq (x:xs) ys

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

-- Do not change the following wrapper code
wrapper :: String -> [Integer]
wrapper input = take (read input::Int) fibcats

main =  print . wrapper =<< getLine
