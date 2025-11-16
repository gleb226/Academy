import random


def merge_lists(list1, list2):
    return list1 + list2


list_a = [random.randint(1, 50) for _ in range(5)]
list_b = [random.randint(1, 50) for _ in range(5)]
merged_list = merge_lists(list_a, list_b)

print("List 1:", list_a)
print("List 2:", list_b)
print("Merged list:", merged_list)
