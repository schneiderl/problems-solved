import re
import sys

l_bracket_count = 0
r_bracket_count = 0


def isReservedWord(currLex):
    regex = r"(double|while|if|else|switch|for|return|null|int|float|do|string|bool|void)"
    matches = re.finditer(regex, currLex, re.IGNORECASE)
    matchNum = 0
    for matchNum, match in enumerate(matches):
        matchNum = matchNum + 1

    if(matchNum != 0):
        return True

    return False


def isNum(currLex):
    regex = r"^[-+]?[1-9]\d*$"
    matches = re.finditer(regex, currLex, re.IGNORECASE)
    matchNum = 0
    for matchNum, match in enumerate(matches):
        matchNum = matchNum + 1

    if(matchNum != 0):
        return True

    return False


def isDouble(currLex):
    regex = r"^[0-9]{1,13}(\.[0-9]+)?$"
    matches = re.finditer(regex, currLex, re.IGNORECASE)
    matchNum = 0
    for matchNum, match in enumerate(matches):
        matchNum = matchNum + 1

    if(matchNum != 0):
        return True

    return False


def isRelationalOp(currLex):
    regex = r"(<|<=|==|!=|>=|>)"
    matches = re.finditer(regex, currLex, re.IGNORECASE)
    matchNum = 0
    for matchNum, match in enumerate(matches):
        matchNum = matchNum + 1

    if(matchNum != 0):
        return True

    return False


def isLogicOp(currLex):
    # im too lazy to regex using ascii
    if(currLex == "||" or currLex == "&&"):
        return True

    return False


def isArithOp(currLex):
    if(currLex == "=" or currLex == "*" or currLex == "/" or currLex == "-" or currLex == "+"):
        return True
    return False


def isStringLiteral(currLex):
    regex = r"\"[^\"]*\""
    matches = re.finditer(regex, currLex, re.IGNORECASE)
    matchNum = 0
    for matchNum, match in enumerate(matches):
        matchNum = matchNum + 1

    if(matchNum != 0):
        return True

    return False


def isEqual(currLex):
    if(currLex == "="):
        return True
    return False


def islParen(currLex):
    if(currLex == "("):
        return True
    return False


def isrParen(currLex):
    if(currLex == ")"):
        return True
    return False


def islBracket(currLex):
    if(currLex == "{"):
        return True
    return False


def isrBracket(currLex):
    if(currLex == "}"):
        return True
    return False


def isComma(currLex):
    if(currLex == ","):
        return True
    return False


def isSemicolon(currLex):
    if(currLex == ";"):
        return True
    return False


def scan(currLex):
    if(isReservedWord(currLex)):
        return 'reserved_word'
    if(isNum(currLex) or isDouble(currLex)):
        return 'num'
    if(isRelationalOp(currLex)):
        return 'relationalOp'
    if(isLogicOp(currLex)):
        return 'logicOp'
    if(isStringLiteral(currLex)):
        return 'string_literal'
    if(isEqual(currLex)):
        return 'equal'
    if(islParen(currLex)):
        return 'l_paren'
    if(isrParen(currLex)):
        return 'r_paren'
    if(islBracket(currLex)):
        return 'l_bracket'
    if(isrBracket(currLex)):
        return 'r_bracket'
    if(isComma(currLex)):
        return 'comma'
    if(isSemicolon(currLex)):
        return 'semicolon'
    if(isArithOp(currLex)):
        return 'arith_op'

    return 'id'

# regex = r"\w*(//)+(.)*"


def isFuncName(currLex):
    regex = r"(.)(^=)*[(]{1}(.)*[)]{1}"
    matches = re.finditer(regex, currLex, re.IGNORECASE)
    matchNum = 0
    for matchNum, match in enumerate(matches):
        matchNum = matchNum + 1

    if(matchNum != 0):
        return True

    return False


concatenatedCode = ""
for input_var in sys.stdin:
    input_var = re.sub(r"(//)(.*)(?=)", "", input_var)  # delete // comments
    input_var = re.sub(r"\w*(//)+(.)*", "", input_var)
    # input_var = re.sub()
    concatenatedCode = concatenatedCode + " " + input_var

concatenatedCode = re.sub(r"/\*(.|[\r\n])*?\*/", "", concatenatedCode)

for word in re.split("({|}|;|if|int\s|bool\s|float\s|string\s|void\s|while|do|==|=)", concatenatedCode):
    wordToScan = re.sub(r"\s", "", word)
    if (wordToScan != "" and wordToScan != None and word != "" and word != None):
        if(isFuncName(word)):
            functionName = re.sub(r"\n|\s|\r|\t\f", "", word)
            idx = functionName.find("(")
            idxword = word.find("(")
            print("[function," + functionName[:idx] + "]")
            word = word[idxword:]
        newWordToScan = (r"\n|\s|\r|\t\f[\n]", "", word)
        print(newWordToScan)
        if (newWordToScan != "" and newWordToScan is not None):
            for word2 in re.split("([+|-|/|*]{1}|[(]|[)]|,|<=|!=|>=|&&|<|>|return|)", word):
                token = scan(word2)
                if(token != 'string_literal'):
                    word2 = re.sub(r"\n|\s|\r|\t\f", "", word2)
                print("[" + token + "," + word2 + "]")
