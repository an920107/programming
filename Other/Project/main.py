from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from fake_headers import Headers
import mysql.connector
import subprocess
import time

def GetId(s):
    id=""
    flag=False
    for i in s[::-1]:
        if(i=="/" and flag): break
        if(i=="/"):
            flag=True
            continue
        if(flag):
            id+=i
    return id[::-1]



input_path = '../webclimber/hot_traders.txt'
#input_path = '../traders_link_crawler/hot_traders.txt'
f = open(input_path,'r')

header = Headers(
    browser = "chrome",  # Generate only Chrome UA
    os = "win",  # Generate only Windows platform
    headers = False # generate misc headers
)
customUserAgent = header.generate()['User-Agent']

id_path = './traders_id.txt'
photo_path = './traders_photo_src.txt'
name_path = './traders_name.txt'
profit_path = './traders_profit.txt'
fid = open(id_path,'w')
fphoto = open(photo_path,'w')
fname = open(name_path,'w')
fprofit = open(profit_path,'w')

service = Service("/usr/bin/chromedriver")
options = Options()
options.add_argument("--disable-notifications")
options.add_argument("--headless")
options.add_argument(f"--user-agent={customUserAgent}")
options.add_argument("--window-size=1280x720")
options.add_argument("--disable-dev-shm-usage")
options.add_argument("--no-sandbox")

chrome = webdriver.Chrome(service=service, options=options)
url_list=f.readlines()

subprocess.call(["mkdir", "-p", "photo"])
sqldb = mysql.connector.connect(
    host = "127.0.0.1",
    user = "csie",
    password = "CSIEProject",
    database = "test",
)
cursor = sqldb.cursor()

for trader_url in url_list:
    chrome.get(trader_url)

    actions = ActionChains(chrome)
    id = GetId(chrome.current_url)
    photo = WebDriverWait(chrome,5).until(
        EC.presence_of_element_located((By.XPATH,'//*[@id="__layout"]/div/div[1]/div/div[1]/div[1]/img'))
    )
    name = WebDriverWait(chrome,5).until(
        EC.presence_of_element_located((By.CLASS_NAME,'nick-name'))
    )
    profit = WebDriverWait(chrome,5).until(
        EC.presence_of_element_located((By.XPATH,'//*[@id="__layout"]/div/div[1]/div/div[1]/div[3]/div/div[3]/div[1]/div[4]/div[2]'))
    )

    print(id)
    print(str(photo.get_attribute('src')))
    print(name.text)
    print(profit.text)
    fid.write(id+"\n")
    fphoto.write(str(photo.get_attribute('src'))+"\n")
    fname.write(name.text+"\n")
    fprofit.write(profit.text+"\n")
    subprocess.call(["wget", "-O", "./photo/" + str(id) + ".jpg", str(photo.get_attribute('src'))])
    subprocess.call(["cp", "./photo/" + str(id) + ".jpg", "/var/www/html/traders-photo"])
    profit_text = profit.text[0:-1]
    while (profit_text.find(",") >= 0):
        profit_text = profit_text.replace(",", "")
    print("REPLACE INTO `trader` VALUES(" + str(id) + ", '" + name.text + "', " + profit_text + ", " + "'/var/www/html/traders-photo/" + str(id) + ".jpg');")
    cursor.execute("REPLACE INTO `trader` VALUES(" + str(id) + ", '" + name.text + "', " + profit_text + ", " + "'/var/www/html/traders-photo/" + str(id) + ".jpg');")

chrome.quit()
f.close()
fid.close()
fphoto.close()
fname.close()
fprofit.close()
