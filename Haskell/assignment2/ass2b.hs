import Data.List
import Data.Char

type Name = String
type Domain = [Integer]
type Valuation = [(Name, Integer)]

data Expr = Val Integer
 | Var Name
 | Expr :+: Expr
 | Expr :-: Expr
 | Expr :*: Expr
 | Expr :/: Expr
 | Expr :%: Expr

--ex 1:
instance Show Expr where
 show (Val a) = show a
 show (Var a) = a
 show (a :+: b) = "(" ++ (show a) ++ " + " ++ (show b) ++ ")"
 show (a :-: b) = "(" ++ (show a) ++ " - " ++ (show b) ++ ")"
 show (a :*: b) = "(" ++ (show a) ++ " * " ++ (show b) ++ ")"
 show (a :/: b) = "(" ++ (show a) ++ " / " ++ (show b) ++ ")"
 show (a :%: b) = "(" ++ (show a) ++ " % " ++ (show b) ++ ")"

--ex 2:
vars :: Expr -> [Name]
vars e = sort (varList e)
 where
  varList :: Expr -> [Name]
  varList (Val a) = []
  varList (Var a) = [a]
  varList (a :+: b) = (varList a) `union` (varList b)
  varList (a :-: b) = (varList a) `union` (varList b)
  varList (a :*: b) = (varList a) `union` (varList b)
  varList (a :/: b) = (varList a) `union` (varList b)
  varList (a :%: b) = (varList a) `union` (varList b)

--ex 3:
evalCorrectExpr (Val a) v = a
evalCorrectExpr (Var a) v = lookUp a v
 where
  lookUp :: Name -> Valuation -> Integer
  lookUp n ((vName, vVal):vs)
   | n == vName = vVal
   | otherwise = lookUp n vs
evalCorrectExpr (a :+: b) v = (evalCorrectExpr a v) + (evalCorrectExpr b v)
evalCorrectExpr (a :-: b) v = (evalCorrectExpr a v) - (evalCorrectExpr b v)
evalCorrectExpr (a :*: b) v = (evalCorrectExpr a v) * (evalCorrectExpr b v)
evalCorrectExpr (a :/: b) v = (evalCorrectExpr a v) `div` (evalCorrectExpr b v)
evalCorrectExpr (a :%: b) v = (evalCorrectExpr a v) `mod` (evalCorrectExpr b v)

--checks that all variableshave values before starting the actual evaluation
evalExpr :: Expr -> Valuation -> Integer
evalExpr e v
 | foldr (&&) True (map (`elem` (map fst v)) (vars e)) = evalCorrectExpr e v
 | otherwise = error "Invalid Valuation"

valuations :: [(Name, Domain)] -> [Valuation]
valuations [] = []
valuations [(n, [])] = []
valuations [(n, (d:ds))] = [(n, d)]:valuations [(n,ds)]
valuations ((n,[]):vs) = []
valuations ((n, (d:ds)):vs) = (map ((n, d):) (valuations vs)) ++ (valuations ((n, ds):vs))

pytriples :: Integer -> [Valuation]
pytriples n = findPy (buildValuations 1 1 n)
 where
  buildValuations :: Integer -> Integer -> Integer -> [Valuation]
  buildValuations a c n
   | c > n = []
   | a == c = buildValuations 1 (c + 1) n
   | otherwise = (valuations [("a",[a]), ("b",[a..(c - 1)]), ("c",[c])]) ++ buildValuations (a + 1) c n
  findPy :: [Valuation] -> [Valuation]
  findPy [] = []
  findPy (v:vs) = tryPy v vs
   where
    tryPy :: Valuation -> [Valuation] -> [Valuation]
    tryPy v vs
     | evalExpr ((Var "a" :*: Var "a") :+: (Var "b" :*: Var "b") :-: (Var "c" :*: Var "c")) v == 0 = v:findPy vs
     | otherwise = findPy vs

--ex 5:
{-
In order to respect the left-to-right order for operations of the same rank,
it is better to start building the expression from the end of the token list.
In order to do that efficiently, we reversed the list before starting to parse it.
As a side effect, the brackets are reversed, ')' is the opening bracket and '('
is the closing one.
-}
toExpr :: String -> Expr
toExpr str = buildTerms(reverse (tokenize str)) []

tokenize :: String -> [String]
tokenize [] = []
tokenize (c:cs)
 | elem c "+-*/%()" = [c]:(tokenize cs)
 | isAlpha c = (c:takeWhile isAlpha cs): tokenize(dropWhile isAlpha cs)
 | isDigit c = (c:takeWhile isDigit cs): tokenize(dropWhile isDigit cs)
 | c == ' ' = tokenize cs
 | otherwise = error ("Syntax Error: " ++ [c])

buildTerms :: [String] -> [String] -> Expr
buildTerms [] term = buildFactors term []
buildTerms ("+":xs) term = (buildTerms xs []) :+: (buildFactors term [])
buildTerms ("-":xs) term = (buildTerms xs []) :-: (buildFactors term [])
buildTerms (")":xs) term = buildTerms (drop (length (getBracket xs 1 0)) xs) (term ++ (")":getBracket xs 1 0))
buildTerms (x:xs) term = buildTerms xs (term ++ [x])

buildFactors :: [String] -> [String] -> Expr
buildFactors [] factor = parser factor []
buildFactors ("*":xs) factor = (buildFactors xs []) :*: (parser factor "*")
buildFactors ("/":xs) factor = (buildFactors xs []) :/: (parser factor "/")
buildFactors ("%":xs) factor = (buildFactors xs []) :%: (parser factor "%")
buildFactors (")":xs) factor = buildFactors (drop (length (getBracket xs 1 0)) xs) (")":getBracket xs 1 0)
buildFactors (x:xs) [] = buildFactors xs [x]
buildFactors (x:xs) factor = error ("Syntax Error: " ++ x)

getBracket :: [String] -> Int -> Int -> [String]
getBracket xs open close
 | open == close = []
 | null xs = error ("Syntax Error: )")
 | head xs == "(" = "(":getBracket (tail xs) open (close + 1)
 | head xs == ")" = ")":getBracket (tail xs) (open + 1) close
 | otherwise = (head xs):getBracket (tail xs) open close

parser :: [String] -> String -> Expr
parser [] err = error ("Syntax Error: " ++ err)
parser (")":xs) err = buildTerms (init xs) []
parser [(x:xs)] err
 | isAlpha x = (Var (x:xs))
 | isDigit x = (Val (integerFromString (x:xs) 0))
 | otherwise = error ("Syntax Error: " ++ (x:xs))

integerFromString :: String -> Integer -> Integer
integerFromString [i] output = 10*output + (toInteger (digitToInt i))
integerFromString (i:input) output = integerFromString input (10*output + (toInteger (digitToInt i)))