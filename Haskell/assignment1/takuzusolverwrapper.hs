isCorrectTakuzu :: [[Char]] -> Bool
isCorrectTakuzu xss = (countTakuzu xss [] [] ((length xss) `div` 2) ((length xss) `div` 2, (length xss) `div` 2) ('a', 'b') (replicate (length xss) (((length xss) `div` 2, (length xss) `div` 2), ('a', 'b'))) []) == 1

{- arguments explained:
	xss - the inputed takuzu, being parsed one Char at a time
	yss - the solution takuzu, being built by the program
	ys - the current row in the solution being built
	halfWidth - the number of 0's and 1's allowed per row/column
	remRow - a tuple containing the number of 0's and 1's still available for the current row
	rowLast - a tuple of the last 2 characters used in the curent row (initialised with dummy values 'a' and 'b')
	cols - a list of tuples, each one containing 2 tuples, the first contains the number of 0's and 1's still available for the corresponding column and the second one contains the last 2 characters used in the corresponding column (initialised with dummy values 'a' and 'b')
	usedCols - once an element of cols is used in a row, it is stored in this list for use in the next rows
-}

countTakuzu :: [[Char]] -> [[Char]] -> [Char] -> Int -> (Int, Int) -> (Char, Char) -> [((Int, Int), (Char, Char))] -> [((Int, Int), (Char, Char))] -> Int
countTakuzu xss yss ys halfWidth remRow rowLast cols usedCols
 | null xss = checkTakuzu yss --takuzu ended, verify solution
 -- row ended, go to the next one, add the built row to the solution and reset it to 0, reinitialize remRow and rowLast, reverse cols and usedCols
 | null (head xss) = countTakuzu (tail xss) (yss ++ [ys]) [] halfWidth (halfWidth, halfWidth) ('a', 'b') usedCols cols
 -- a free position, try both 0 and 1
 | head (head xss) == '.' = (tryAtPos '0' ((tail (head xss)) : tail xss) yss ys halfWidth remRow rowLast cols usedCols) + (tryAtPos '1' ((tail (head xss)) : tail xss) yss ys halfWidth remRow rowLast cols usedCols)
 -- position value in input, try it to check validity
 | otherwise = tryAtPos (head (head xss)) ((tail (head xss)) : tail xss) yss ys halfWidth remRow rowLast cols usedCols

-- makes sure that the value of toTry fits the current position (so far at least) and stops or continues the recursion based on that check
tryAtPos :: Char -> [[Char]] -> [[Char]] -> [Char] -> Int -> (Int, Int) -> (Char, Char) -> [((Int,Int), (Char, Char))] -> [((Int,Int), (Char, Char))] -> Int
tryAtPos toTry xss yss ys halfWidth remRow rowLast cols usedCols
 | ((fst rowLast) == (snd rowLast) && (fst rowLast) == toTry) || ((fst (snd (head cols))) == (snd (snd (head cols))) && (fst (snd (head cols))) == toTry) = 0
 | toTry == '0' && (fst remRow) > 0 && (fst (fst (head cols))) > 0 = countTakuzu xss yss (ys ++ ['0']) halfWidth ((fst remRow) - 1, snd remRow) (snd rowLast, '0') (tail cols) (usedCols ++ [(((fst (fst (head cols))) - 1, snd (fst (head cols))), (snd (snd (head cols)), '0'))])
 | toTry == '1' && (snd remRow) > 0 && (snd (fst (head cols))) > 0 = countTakuzu xss yss (ys ++ ['1']) halfWidth (fst remRow, (snd remRow) - 1) (snd rowLast, '1') (tail cols) (usedCols ++ [((fst (fst (head cols)), (snd (fst (head cols))) - 1), (snd (snd (head cols)), '1'))])
 | otherwise = 0


--checks if all rows and columns are different
checkTakuzu :: [[Char]] -> Int
checkTakuzu xss
 | (allDif xss) && (allDif (flipTakuzu xss)) = 1
 | otherwise = 0

--make columns into rows
flipTakuzu :: [[Char]] -> [[Char]]
flipTakuzu xss
 | null xss = []
 | null (head xss) = []
 | otherwise = [(map head xss)] ++ flipTakuzu (map tail xss)  

--checks if all elements of a list are different
allDif :: (Eq a) => [a] -> Bool
allDif xs
 | null xs = True
 | otherwise = (notElem (head xs) (tail xs)) && (allDif (tail xs))

main =  print . isCorrectTakuzu .lines =<< getContents
