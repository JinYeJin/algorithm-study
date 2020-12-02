x,y = map(int, input().split())
#plate = [[0]*x]*y
plate =  [ [0 for i in range(y)] for j in range(x) ]
stick = int(input())
sticks_info = []
for stick in range(stick):
    stick_len, stick_direc, x_coordi, y_coordi  = map(int, input().split())
    stick_dict = {'stick_len': stick_len, 'stick_direc':stick_direc, 'x_coordi':x_coordi, 'y_coordi':y_coordi}
    sticks_info.append(stick_dict)

for stick_dict in sticks_info:	
	for weight in range(stick_dict['stick_len']):
		if stick_dict['stick_direc'] == 0:#and stick_dict['y_coordi']-1+weight < len(plate[0]):
			plate[stick_dict['x_coordi']-1][stick_dict['y_coordi']-1+weight] = 1			
		else: #stick_dict['x_coordi']-1+weight < len(plate):
			plate[stick_dict['x_coordi']-1+weight][stick_dict['y_coordi']-1] = 1

for row in plate:
    for col in row:
        print(col, end=" ")
    print()
