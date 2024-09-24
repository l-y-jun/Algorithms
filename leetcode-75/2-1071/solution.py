def find_divisor(v:int):
    div = 2;
    left = v;
    ret = {1};

    if (v == 0):
        return (ret);

    while div < left and div < ((v // 2) + 1):
        if left % div == 0:
            ret.add(div);

        div += 1;

    if left != v:
        ret.add(left);
    ret.add(v);

    return (sorted(ret, reverse=True));

def find_maxrepeat(src1:str, src2:str):
    common_divs = find_divisor(len(src1));
    print(common_divs)
    if len(src1) != len(src2):
        divs = find_divisor(len(src2));
        common_divs = list(filter(lambda el: el in divs, common_divs));

    while common_divs:
        div, *common_divs = common_divs;
        pattern = src1[:div]; 
        if is_repeat(src1, pattern) and is_repeat(src2, pattern):
            return (pattern);

    return ("");


def is_repeat(src, pattern):
    n = len(pattern);
    while src and src.find(pattern) == 0:
        src = src[n:]

    return (False if src else True); 

print(find_maxrepeat("ABAB", "ABABABAB"));

