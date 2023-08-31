nums = [-1, 0, 1, 2, -1, 4]
# nums = [0, 1, 1]
# nums = [0, 0, 0]


def is_list_in_2d_list(target_list, list_2d):
    for sublist in list_2d:
        if sublist == target_list:
            return True
    return False


# nums = [-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4]
res = []
existingVals = {}
for i in range(len(nums)):
    for j in range(i + 1, len(nums)):
        for k in range(j + 1, len(nums)):
            summation = nums[i] + nums[j] + nums[k]
            if(summation == 0):
                possibleList = [nums[i], nums[j], nums[k]]
                possibleList.sort()
                if(not is_list_in_2d_list(possibleList, nums)):
                    res.append(possibleList)

print(res)
