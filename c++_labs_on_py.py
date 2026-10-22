#First lab
def fact(x: int)->int:
    if x <= 0:
        print("Can't count fact of non positive number")
        return 0
    else:
        res = 1
        for _ in range(1, x):
            res *= x
        return res
    
def count_ex(x: int, n: int)->float:
    if n <= 0:
        print("Can't count with this precision")
        return 0
    elif n == 1:
        return 1
    else:
        res = 1
        for _ in range(1, n):
            res += (x ** (n - 1)) / fact(n - 1)
        return res

#Second lab
def length(num: int)->int:
    len = 1
    t = 0
    while num // (10 ** t):
        if num // (10 ** (t + 1)):
            len += 1
        t += 1
    return len

def check_difference(num: int)->bool:
    len = lenght(num)
    for i in range(1, len):
        digit = num // 10 ** (len - i) % 10
        for j in range(i + 1, len):
            if digit == num // 10 ** (len - j) % 10:
                return False
    return True

def is_simple(num: int)->bool:
    check = True
    if num % 2 == 0 and num != 2:
        check = False
    else:
        for i in range(3, num // 2, 2):
            if num % i == 0:
                check = False
                break
    return check

def find_simples_less_then(num: int):
    if num <= 1:
        print("There are no simple numbers not bigger then ", num)
    else:
        print(2, end='')
        for res in range(3, num + 1, 2):
            if is_simple(res):
                print(', ', res, end='')

import math

def find_double_simple_nums_in_otrezok(left_border: float, right_border: float):
    if left_border > right_border:
        left_border, right_border = right_border, left_border
    left_border, right_border = math.floor(left_border), math.floor(right_border)
    if right_border <= 1:
            print("There are no simple numbers not bigger then ", right_border)
    else:
        if left_border <= 1:
            left_border = 3
        if left_border % 2 == 0:
            left_border += 1
        print(2, end='')
        for res in range(left_border, right_border + 1, 2):
            if is_simple(res):
                len = length(res)
                summ = 0
                for i in range(len + 1):
                    summ += res // 10 ** (len - i) % 10
                if is_simple(summ):
                    print(', ', res, end='')

#Third lab
#def input_n_el_str(n: int)->str:
#    print("Input string with ", n, " elements: ")
#    str = input()
#    length = len(str)
#    if length < n:
#        print("ERROR: Inputed string's length is ", length, " < ", n)
#        return "ERROR"
#    elif length > n:
#        res = str[:n]
#       print("Inputed string's length is ", length, " > ", n, ". Last ", length - n, " simbols are cut. Result string is '", res, "'")
#       return res
#   return str
#def multiply_nums_with_even_indexes(arr: list)->int:
#    if row.isdigt() == False:
#            print("ERROR: Inputed string has non digit simbols")
#            return 0
#    res = 1
#    length = len(row)
#    for i in range(0, length, 2):
#       res *= row[i]
#    return res
def multiply_nums_with_even_indexes(arr: list)->int:
    res = 1
    length = len(arr)
    for i in range(0, length, 2):
        if str(arr[i]).isdigit():
           res *= arr[i]
    return res

def summ_between_zeroes(arr: list)->int:
    first_zero_flag = False
    first_zero_pos = 0
    last_zero_pos = 0
    length = len(arr)
    for i in range(length):
        if arr[i] == 0:
            if first_zero_flag == False:
                first_zero_pos = i
                first_zero_flag = True
            else:
                last_zero_pos = i
    if last_zero_pos == 0:
        print("ERROR: Not enough zeroes in array")
        return 0
    res = 0
    for i in range(first_zero_pos + 1, last_zero_pos):
        res += arr[i]
    return res

def sort_by_zero(arr: list):
    length = len(arr)
    amount_of_non_neg = 0#if you need the same order inside groups
    for i in range(length):
        if arr[i] >= 0:
            amount_of_non_neg += 1
    i = 0
    counter = 0
    while i < length - 1:
        if counter == amount_of_non_neg:
            break
        print(i, arr[i])
        if arr[i] >= 0:
            print("Move")
            counter += 1
            for j in range(i + 1, length):
                arr[j - 1], arr[j] = arr[j], arr[j - 1]
            print(arr)
        else:
            i += 1
#Forth lab
def is_int_mtr(mtr: list)->bool:
    if isinstance(mtr, list) == False:
        return False
    amount_of_rows = len(mtr)
    if isinstance(mtr[0], list) == False:
        return False
    first_row_len = len(mtr[0])
    for i in range(amount_of_rows):
        if isinstance(mtr[i], list) == False or len(mtr[i]) != first_row_len:
            return False
        for j in range(first_row_len):
            if isinstance(mtr[i][j], int) == False:
                return False
    return True
    
def is_row_neg(mtr: list, row: int)->bool:
    if len(mtr) <= row:
        print("ERROR: there isn't a row with this number")
        return False
    row_length = len(mtr[row])
    for i in range(row_length):
        if mtr[row][i] > 0:
            return False
    return True

def get_max_in_neg_rows(mtr: list)->int:
    if is_int_mtr(mtr) == False:
        print("ERROR: it isn't int matrix")
        return False
    amount_of_rows = len(mtr)
    row_len = len(mtr[0])
    for t in range(amount_of_rows):
        if is_row_neg(mtr, t):
            res = mtr[t][0]
            break
    for j in range(t - 1, amount_of_rows):
        if is_row_neg(mtr, j):
            for i in range(row_len):
                if res < mtr[j][i]:
                    res = mtr[j][i]
    return res

def is_mtr_int_square(str: list)->bool:
    if isinstance(mtr, list) == False:
        return False
    amount_of_rows = len(mtr)
    for i in range(amount_of_rows):
        if isinstance(mtr[i], list) == False or len(mtr[i]) != amount_of_rows:
            return False
        for j in range(amount_of_rows):
            if isinstance(mtr[i][j], int) == False:
                return False
    return True

def amount_of_negs_in_lower_triangle(mtr: list)->int:
    if is_mtr_int_square(mtr) == False:
        print("ERROR: this isn't square int matrix")
        return 0
    step = int(0)
    size = len(mtr)
    res = int(0)
    for i in range(step, size):
        for j in range(size - step - 1, size):
            if mtr[i][j] < 0:
                res += 1
        step += 1
    return res
#Fifth lab
def find_longest(txt: str)->str:
    array = txt.split()
    index = int(0)
    max_len = len(array[0])
    for i in range(len(array)):
        if len(array[i]) > max_len:
            max_len = len(array[i])
            index = i
    res = array[index]
    return res

def find_shortest(txt: str)->str:
    array = txt.split()
    index = int(0)
    min_len = len(array[0])
    for i in range(len(array)):
        if len(array[i]) <= min_len:
            min_len = len(array[i])
            index = i
    res = array[index]
    return res

import re

def swap_longest_and_shortest(txt: str)->str:
    long = find_longest(txt)
    short = find_shortest(txt)
    print(long)
    print(short)
    short_pos = (re.search(r'\b' + re.escape(short) + r'\b', txt)).start()
    long_pos = (re.search(r'\b' + re.escape(long) + r'\b', txt)).start()
    if short_pos < long_pos:
        res = txt[:short_pos] + txt[long_pos:long_pos + len(long)] + txt[short_pos + len(short):long_pos] + txt[short_pos:short_pos + len(short)] + txt[long_pos + len(long):]
    else:
        res = txt[:long_pos] + txt[short_pos:short_pos + len(short)] + txt[long_pos + len(long):short_pos] + txt[long_pos:long_pos + len(long)] + txt[short_pos + len(short):]
    return res