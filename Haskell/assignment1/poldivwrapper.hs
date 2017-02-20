polDivision :: [Double] -> [Double] -> ([Double],[Double])
polDivision xs ys
 | length xs < length ys = ([], removeLeadingZeros xs)
 -- compute the next coeficient in the quotient and put it at the start of the first element of the tuple
 | otherwise = tuplePolyDiv ((head xs) / (head ys)) (polDivision (tail (listDif xs (map ((*) ((head xs) / (head ys))) ys))) ys) 

-- builds the quotient list inside the tuple
tuplePolyDiv :: Double -> ([Double],[Double]) -> ([Double],[Double])
tuplePolyDiv coF zz = (coF:(fst zz), snd zz)

-- computes the vectorial difference of 2
-- the result will have as many elemens as the first argument
listDif :: Num a => [a] -> [a] -> [a]
listDif [] ys = []
listDif xs [] = xs
listDif (x:xs) (y:ys) = (x - y):listDif xs ys

removeLeadingZeros :: [Double] -> [Double]
removeLeadingZeros xs
 | null xs = xs
 | head xs == 0.0 = removeLeadingZeros (tail xs)
 | otherwise = xs

wrapper :: String -> ([Double],[Double])
wrapper line = polDivision (makeList num) (makeList denom)
  where
    num = takeWhile (/= '/') line
    denom = tail (dropWhile (/= '/') line)
    makeList str = map (\s -> read s::Double) (words str)

main =  print . wrapper =<< getLine
