import mysql.connector

def getData(_id, _pair):

    sql = mysql.connector.connect (
        # host = "finalproject.ddns.net",
        host = "localhost",
        user = "tradersuser",
        password = "TRADERSuser",
        database = "tradersdb"
    )
    cursor = sql.cursor()

    file_output = open("data.txt", "w")

    cursor.execute("SELECT * FROM `data` WHERE `data_id` = %s AND `data_pair` LIKE '%s%%';" % (_id, _pair))
    for (id, pair, multiply, isLong, openPrice, closePrice, openTime, closeTime, profit) in cursor:
        # print(id, pair, multiply, isLong, openPrice, closePrice, openTime, closeTime, profit)
        for elm in [id, pair, multiply, isLong, openPrice, closePrice, openTime, closeTime, profit]:
            file_output.write(str(elm) + "\t")
        file_output.write("\n")
    