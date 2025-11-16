import random

list1 = [random.randint(-100, 100) for _ in range(17)]
list2 = [random.randint(-100, 100) for _ in range(17)]

list_union = list1 + list2
list_union_unique = []
seen = set()
for item in list_union:
    if item not in seen:
        list_union_unique.append(item)
        seen.add(item)

list_intersection = []
set_list2 = set(list2)
for item in list1:
    if item in set_list2:
        list_intersection.append(item)

list_unique_elements = []
set_list1 = set(list1)
set_list2 = set(list2)

for item in list1:
    if item not in set_list2:
        list_unique_elements.append(item)

for item in list2:
    if item not in set_list1:
        list_unique_elements.append(item)

print("List 1:", list1)
print("List 2:", list2)
print("Union of lists:", list_union)
print("Union without duplicates:", list_union_unique)
print("Common elements:", list_intersection)
print("Unique elements:", list_unique_elements)
