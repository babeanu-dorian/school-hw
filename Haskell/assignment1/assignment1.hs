import Data.Char
import Data.List
import Data.Maybe

--countHappyNumbers Starts here

countHappyNumbers :: Int -> Int -> Int
countHappyNumbers a b
 | a > b = 0
 | otherwise = (isHappy a) + (countHappyNumbers (a+1) b)
 
isHappy :: Int -> Int
isHappy x
 | x == 1 = 1
 | x == 4 = 0
 | otherwise = isHappy (sumDigits x)
 
sumDigits :: Int -> Int
sumDigits 0 = 0
sumDigits x = ((x `mod` 10)^2) + sumDigits (x `div` 10)

--takuzuStrings starts here

takuzuStrings :: Int -> [[Char]]
takuzuStrings n = tListMaker n 'a' 'b' []

tListMaker :: Int -> Char -> Char -> [Char] -> [[Char]]
tListMaker n beforeLast lastChar xs
 | n == 0 = [xs]
 | beforeLast == lastChar = tListMaker (n - 1) lastChar (opposite lastChar) (xs ++ [(opposite lastChar)])
 | otherwise = (tListMaker (n - 1) lastChar '0' (xs ++ ['0'])) ++ (tListMaker (n - 1) lastChar '1' (xs ++ ['1']))

opposite :: Char -> Char
opposite c
 | c == '0' = '1'
 | otherwise = '0'

--RPN starts here

rpnEval :: [Char] -> Int
rpnEval xs = iterateRPN xs [] False

iterateRPN :: [Char] -> [Int] -> Bool -> Int
iterateRPN xs ns buildingNumber
 | null xs = head ns
 | head xs == ' ' = iterateRPN (tail xs) ns False
 | head xs == '/' = iterateRPN (tail xs) ([ns!!1 `div` ns!!0] ++ (drop 2 ns)) False
 | head xs == '*' = iterateRPN (tail xs) ([ns!!1 * ns!!0] ++ (drop 2 ns)) False
 | head xs == '+' = iterateRPN (tail xs) ([ns!!1 + ns!!0] ++ (drop 2 ns)) False
 | head xs == '-' = iterateRPN (tail xs) ([ns!!1 - ns!!0] ++ (drop 2 ns)) False
 | buildingNumber = iterateRPN (tail xs) ([((head ns)*10 + (digitToInt (head xs)))] ++ (tail ns)) True
 | otherwise = iterateRPN (tail xs) ([((digitToInt (head xs)))] ++ ns) True

--LastDigits starts here

lastDigits :: Integer -> Integer -> [Integer]
lastDigits n d = intToDigits (((n^(n+1))-1) `div` (n-1)) d
 
intToDigits :: Integer -> Integer -> [Integer]
intToDigits num d
 | d == 0 = []
 | num == 0 = []
 | otherwise = (intToDigits (num `div` 10) (d-1)) ++ [num `mod` 10]

--polynomial division starts here

polyDiv :: [Double] -> [Double] -> ([Double],[Double])
polyDiv xs ys
 | length xs < length ys = ([], removeLeadingZeros xs)
 | otherwise = tuplePolyDiv ((head xs) / (head ys)) (polyDiv (tail (listDif xs (map ((*) ((head xs) / (head ys))) ys))) ys) 

tuplePolyDiv :: Double -> ([Double],[Double]) -> ([Double],[Double])
tuplePolyDiv coF zz = ([coF] ++ (fst zz), snd zz)

--ask if listDif must have general type
listDif :: [Double] -> [Double] -> [Double]
listDif xs ys
 | null ys = xs
 | otherwise = [(head xs - head ys)] ++ listDif (tail xs) (tail ys)

removeLeadingZeros :: [Double] -> [Double]
removeLeadingZeros xs
 | null xs = xs
 | head xs == 0.0 = removeLeadingZeros (tail xs)
 | otherwise = xs

-- Caesar cypher starts here
cipherEncode :: Int -> [Char] -> [Char]
cipherEncode key mes = cipherHelper key key mes

cipherDecode :: Int -> [Char] -> [Char]
cipherDecode key mes = cipherHelper (0 - key) (0 - key) mes

cipherHelper :: Int -> Int -> [Char] -> [Char]
cipherHelper originalKey currentKey mes
 | null mes = []
 | (head mes) == ' ' = [' '] ++ cipherHelper originalKey currentKey (tail mes)
 | otherwise = [['A'..'Z']!!(((fromJust (elemIndex (head mes) ['A'..'Z']))+ 26 - currentKey) `mod` 26)] ++ cipherHelper originalKey ((currentKey + originalKey) `mod` 26) (tail mes)

--takuzu solver starts here

isCorrectTakuzu :: [[Char]] -> Int
isCorrectTakuzu xss = (countTakuzu xss [] [] ((length xss) `div` 2) ((length xss) `div` 2, (length xss) `div` 2) ('a', 'b') (replicate (length xss) (((length xss) `div` 2, (length xss) `div` 2), ('a', 'b'))) []) -- == 1

countTakuzu :: [[Char]] -> [[Char]] -> [Char] -> Int -> (Int, Int) -> (Char, Char) -> [((Int, Int), (Char, Char))] -> [((Int, Int), (Char, Char))] -> Int
countTakuzu xss yss ys halfWidth remRow rowLast cols usedCols
 | null xss = checkTakuzu yss
 | null (head xss) = countTakuzu (tail xss) (yss ++ [ys]) [] halfWidth (halfWidth, halfWidth) ('a', 'b') usedCols cols
 | head (head xss) == '.' = (tryAtPos '0' ((tail (head xss)) : tail xss) yss ys halfWidth remRow rowLast cols usedCols) + (tryAtPos '1' ((tail (head xss)) : tail xss) yss ys halfWidth remRow rowLast cols usedCols)
 | otherwise = tryAtPos (head (head xss)) ((tail (head xss)) : tail xss) yss ys halfWidth remRow rowLast cols usedCols

tryAtPos :: Char -> [[Char]] -> [[Char]] -> [Char] -> Int -> (Int, Int) -> (Char, Char) -> [((Int,Int), (Char, Char))] -> [((Int,Int), (Char, Char))] -> Int
tryAtPos toTry xss yss ys halfWidth remRow rowLast cols usedCols
 | ((fst rowLast) == (snd rowLast) && (fst rowLast) == toTry) || ((fst (snd (head cols))) == (snd (snd (head cols))) && (fst (snd (head cols))) == toTry) = 0
 | toTry == '0' && (fst remRow) > 0 && (fst (fst (head cols))) > 0 = countTakuzu xss yss (ys ++ ['0']) halfWidth ((fst remRow) - 1, snd remRow) (snd rowLast, '0') (tail cols) (usedCols ++ [(((fst (fst (head cols))) - 1, snd (fst (head cols))), (snd (snd (head cols)), '0'))])
 | toTry == '1' && (snd remRow) > 0 && (snd (fst (head cols))) > 0 = countTakuzu xss yss (ys ++ ['1']) halfWidth (fst remRow, (snd remRow) - 1) (snd rowLast, '1') (tail cols) (usedCols ++ [((fst (fst (head cols)), (snd (fst (head cols))) - 1), (snd (snd (head cols)), '1'))])
 | otherwise = 0

checkTakuzu :: [[Char]] -> Int
checkTakuzu xss
 | (allDif xss) && (allDif (flipTakuzu xss)) = 1
 | otherwise = 0

flipTakuzu :: [[Char]] -> [[Char]]
flipTakuzu xss
 | null xss = []
 | null (head xss) = []
 | otherwise = [(map head xss)] ++ flipTakuzu (map tail xss)  

allDif :: (Eq a) => [a] -> Bool
allDif xs
 | null xs = True
 | otherwise = (notElem (head xs) (tail xs)) && (allDif (tail xs))











