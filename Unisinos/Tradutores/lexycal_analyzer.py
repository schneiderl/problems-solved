import re
import sys

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
    regex = r"(?!\w)[-+]?[0-9]\d*"
    matches = re.finditer(regex, currLex, re.IGNORECASE)
    matchNum = 0
    for matchNum, match in enumerate(matches):
        matchNum = matchNum + 1

    if(matchNum != 0):
        return True

    return False


def isDouble(currLex):
    regex = r"[0-9]{1,13}\.([0-9]+)?"
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
    lex = re.sub(r"\n|\s|\r|\t\f", "", currLex)
    if(lex == "||" or lex == "&&"):
        return True

    return False


def isArithOp(currLex):
    regex = r"(\=|\*|\/|\-|\+)"
    matches = re.finditer(regex, currLex, re.IGNORECASE)
    matchNum = 0
    for matchNum, match in enumerate(matches):
        matchNum = matchNum + 1

    if(matchNum != 0):
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
    if(isNum(currLex)):
        return 'num'
    if(isDouble(currLex)):
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



def isFuncName(currLex):
    regex = r"(\w)(^=)*(\s)*[(]{1}(.)*[)]{1}"
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
    input_var = re.sub(r"\n","", input_var)
    concatenatedCode = concatenatedCode + " " + input_var

concatenatedCode = re.sub(r"/\*(.|[\r\n])*?\*/", "", concatenatedCode)

for word in re.split("(\|{2}|;|if|int\s|else|switch|for|bool\s|float\s|string\s|void\s|while|do|==|!=|=|)", concatenatedCode):
    wordToScan = re.sub(r"\s", "", word)
    if (wordToScan != "" and wordToScan != None and word != "" and word != None):
        if(isFuncName(word)):
            functionName = re.sub(r"\n|\s|\r|\t\f", "", word)
            idx = functionName.find("(")
            idxword = word.find("(")
            print("[function," + functionName[:idx] + "]")
            word = word[idxword:]
        newWordToScan = re.sub(r"\n|\s|\r|\t\f", "", word)
        for word2 in re.split("([+|-|/|*]{1}|,|[(]|[)]|<=|!=|>=|&&|<|>|return|)", word):
            if (re.search(r"([0-9]+)", word2) is not None or (re.search(r"(\S)+", word2)) is not None):
                token = scan(word2)
                if(token != 'string_literal'):
                    word2 = re.sub(r"\n|\s|\r|\t\f", "", word2)
                    print("[" + token + "," + word2 + "]")
