selfrle :: [Int]
-- Insert your own code here.

selfre = [1, 2, 2] ++ makeSelfre [2] 1
 where
  makeSelfre :: [Int] -> Int -> [Int]
  makeSelfre (x:xs) y = (replicate x y) ++ makeSelfre (xs ++ (replicate x y)) (1 + (mod y 2))

-- Do not change the fololowing wrapper code
wrapper :: String -> [Int]
wrapper input = take (read input::Int) selfrle

main =  print . wrapper =<< getLine
