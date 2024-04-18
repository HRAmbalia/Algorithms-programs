mapping = {'A':0, 'B':1, 'C':2}

start = 'A'
end = 'C'
nodes = 3
arr = [
    ['B', 'A'],
    ['C', 'A'],
    ['C', 'C']
]

str = '0010'

current = mapping[start]
for i in str:
    i = int(i)
    current = mapping[arr[current][i]]

if(mapping[end]==current):
    print('YES')
else:
    print('NO')
