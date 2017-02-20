import Data.Char
import Data.List
import Data.Maybe

cipherEncode :: Int -> [Char] -> [Char]
cipherEncode key mes = cipherHelper key key mes

-- decoding with key = k is the same as encoding with key = -k
cipherDecode :: Int -> [Char] -> [Char]
cipherDecode key mes = cipherHelper (0 - key) (0 - key) mes

-- replace each character in the message with the one indicated by currentKey
-- after each replacement, increase currentKey by originalKey in the circular interval 0-25,
-- since key = k + 26 produces the same encription as key = k
cipherHelper :: Int -> Int -> [Char] -> [Char]
cipherHelper originalKey currentKey mes
 | null mes = []
 | (head mes) == ' ' = [' '] ++ cipherHelper originalKey currentKey (tail mes) --maintain spaces
 | otherwise = [['A'..'Z']!!(((fromJust (elemIndex (head mes) ['A'..'Z']))+ 26 - currentKey) `mod` 26)] ++ cipherHelper originalKey ((currentKey + originalKey) `mod` 26) (tail mes)

wrapper :: String -> String
wrapper line
  | cmd == "ENCODE"  = cipherEncode key txt
  | cmd == "DECODE"  = cipherDecode key txt
  where
    str  = dropWhile (not.isAlpha) line
    cmd  = takeWhile isAlpha str
    tail = dropWhile (not.isDigit) str
    key = read (takeWhile isDigit tail)::Int
    txt = dropWhile (not.isAlpha) (dropWhile isDigit tail)

main =  print . wrapper =<< getLine
