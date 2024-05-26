from collections import deque
P_0 = {'label': 'P_0', 'burst': 40, 'default': 40,'e/s': 1}
P_1 = {'label': 'P_1', 'burst': 15, 'default': 15,'e/s': 2}
q_0 = deque([P_0, P_1])
q_1 = deque([])
q_2 = deque([])
time = 0
# es = {'label': '   ', 'time': 0, 'end': 0}
# es_history = deque([])
gantt = []

def dec_q_0(P: dict):
  if(P['burst'] - 10 > 0):
    P['burst'] -= 10
    q_0.popleft()
    q_1.append(P)
    return 10
  else:
    tmp = P['burst']
    P['burst'] = 0
    P['e/s'] -= 1
    q_0.popleft()
    return tmp
  
def dec_q_1(P: dict):
  if(P['burst'] - 15 > 0):
    P['burst'] -= 15
    q_1.popleft()
    q_2.append(P)
    return 15
  else:
    tmp = P['burst']
    P['burst'] = 0
    q_1.popleft()
    return tmp

def dec_q_2(P: dict):
  tmp = P['burst']
  P['burst'] = 0
  q_2.popleft()
  return tmp
    

def print_gantt():
  print('|', end='')
  for elem in gantt:
    print(' %s |'%(elem['process']), end='')
  print('')
  
  print('0 ', end='')
  for elem in gantt:
    print('    %s'%(elem['time']), end='')
  print('')
  print('=-='*20)
  
while(len(q_0) > 0 or len(q_1) > 0 or len(q_2) > 0):
  if(len(q_0) > 0):
    tmp = q_0[0]
    time += dec_q_0(q_0[0])
    gantt.append({'time': time, 'process': tmp['label']})
    print_gantt()
    
  elif(len(q_1) > 0):
    tmp = q_1[0]
    time += dec_q_1(q_1[0])
    gantt.append({'time': time, 'process': tmp['label']})
    print_gantt()
    
  elif(len(q_2) > 0):
    tmp = q_2[0]
    time += dec_q_2(q_2[0])
    gantt.append({'time': time, 'process': tmp['label']})
    print_gantt()