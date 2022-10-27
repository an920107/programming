import xlwt
import pandas

FILENAME = "時數表.xlsx"
SHEETNAME = "Sheet"

data_df = pandas.read_excel(FILENAME, sheet_name= SHEETNAME)
