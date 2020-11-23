def isAnagram(s, t):
    """
    :type s: str
    :type t: str
    :rtype: bool
    """
    count_dict = {}
    count_dict_s = {}
    for item in t:
        count_dict[item] = count_dict[item] + 1 if item in count_dict else 1
    print(count_dict)
    for item in s:
        count_dict_s[item] = count_dict_s[item] + 1 if item in count_dict_s else 1
    print(count_dict_s)
    if count_dict.keys() != count_dict_s.keys():
        return False
    for i in count_dict.keys():
        if count_dict[i] != count_dict_s[i]:
            return False
    return True

print(isAnagram('ab', 'a'))



