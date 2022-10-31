import math
import pandas

FILENAME = "Python/時數表.xlsx"
SHEETNAME = "Sheet"

data_df = pandas.read_excel(FILENAME, sheet_name= SHEETNAME, header= None)
data_list = data_df.values.tolist()


name = data_list[0][1]
out_file = open("Python/" + name + ".txt", "w")
total = 0
for data in data_list[2:]:
    if (math.isnan(data[0])): break
    data = list(map(int, data))
    out_file.write("%02d/%02d_%02d:%02d~%02d:%02d_" % (
        data[0], data[1], data[2], data[3], data[4], data[5]
    ))
    work_time = (data[4] * 60 + data[5] - data[2] * 60 - data[3]) / 60
    if (work_time < int(work_time) + 0.25):
        work_time = int(work_time)
    elif (work_time < int(work_time) + 0.75):
        work_time = int(work_time) + 0.5
    else:
        work_time = int(work_time) + 1.0
    total += work_time
    out_file.write("%.1fHr\n" % (work_time))
out_file.write("總計%.1fHr" % (total))