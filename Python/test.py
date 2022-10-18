output_dict = {}
output_words_list = []
output_words_str = ''
input_words_list = []
input_words = input() 
ascii_values = [] 
ascii_values2 = []
output_words_list2 = []
the_same_list = []

the_same_list.append(' ')
for x in input_words :
    ascii_values.append(ord(x)) 



for i in range(len(input_words)):
    if 0x41<= ascii_values[i] <=0x5A:
        continue   
    elif 97<= ascii_values[i] <=122:
        continue   
    else:
        replace_word = chr(ascii_values[i])
        input_words = input_words.replace(replace_word,' ') 




input_words_list =  input_words.split()   


for i in range(len(input_words_list)):  
    the_same  = 1  
    j = 0
    k = 0
    the_same2 = 0
    for k in range(len(the_same_list)):
        if  input_words_list[i] ==  the_same_list[k] :
             the_same2 = 1  
    for j in range(len(input_words_list)-i-1):   
        if  the_same2 == 1  :
            break
        if input_words_list[i] == input_words_list[i+j+1]:
            the_same += 1 
            the_same_list.append(input_words_list[i])  
    if  the_same2 == 1  :
        continue                                   
    output_words_list.append(str(input_words_list[i])) 
    output_words_list.append(' ')
    output_words_list.append(str(the_same))
    output_words_list.append('\n')    

for x in range(len(output_words_list)) : 
        for i in range(0,len(output_words_list)-6,4):
            if int(output_words_list[i+6])>int(output_words_list[i+2]):
                temp = output_words_list[i+4]
                output_words_list[i+4] = output_words_list[i]
                output_words_list[i] = temp
                temp = output_words_list[i+2]
                output_words_list[i+2] = output_words_list[i+6]
                output_words_list[i+6] = temp
  
              
for w in range(len(output_words_list)-1):
    output_words_str += output_words_list[w]

for x in output_words_str :
    ascii_values2.append(ord(x)) 


for i in range(len(output_words_str)):
    if 0x41<= ascii_values2[i] <=0x5A  :
        replace_word = chr(ascii_values2[i])
        output_words_str = output_words_str.replace(replace_word,chr(ascii_values2[i]+32))            




print(output_words_str)