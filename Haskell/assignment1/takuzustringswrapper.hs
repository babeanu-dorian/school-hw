takuzuStrings :: Integer -> [[Char]]
takuzuStrings n = tListMaker n 'a' 'b' []

tListMaker :: Integer -> Char -> Char -> [Char] -> [[Char]]
tListMaker n beforeLast lastChar xs
 | n == 0 = [xs] -- the built list has the desired lenght, return it
 -- the previous 2 characters coincide, only use their opposite
 | beforeLast == lastChar = tListMaker (n - 1) lastChar (opposite lastChar) (xs ++ [(opposite lastChar)])
 -- use both 0 and 1 (in this order)
 | otherwise = (tListMaker (n - 1) lastChar '0' (xs ++ ['0'])) ++ (tListMaker (n - 1) lastChar '1' (xs ++ ['1']))

opposite :: Char -> Char
opposite '0' = '1'
opposite '1' = '0'

wrapper :: [String] -> [String]
wrapper (a:_) = takuzuStrings (read a::Integer)

main =  print . wrapper . words =<< getLine
