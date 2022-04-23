from lib2to3.pgen2 import token
import requests
import cfscrape
import cloudscraper
from fake_useragent import UserAgent

url = "https://bingx.com/en-us/traders/1026369846363258884"
headers = {
    'user-agent':
        'Mozilla / 5.0(Windows NT 10.0; WOW64) '
        # 'AppleWebKit / 537.36(KHTML, likeGecko)? '
        # 'Chrome / 53.0.2785.104Safari / 537.36Core / 1.53.4882.400QQBrowser / 9.7.13059.400'
}
# ua = UserAgent()
# scraper = cfscrape.create_scraper()

# res = scraper.get(url, headers=headers)
res = requests.get(url, headers=headers)
file = open("res.html", "w")
file.write(res.text)
print(res.status_code)
