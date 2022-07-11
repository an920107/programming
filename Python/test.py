import requests
from bs4 import BeautifulSoup

BASE_URL = "https://files.minecraftforge.net/net/minecraftforge/forge/"

output_file = open("ForgeVersions.txt", "w")

res = requests.get(BASE_URL + "index_1.1.html")
soup = BeautifulSoup(res.text, "html.parser")
for ver_mc in soup.select("ul.nav-collapsible a"):
    ver_mc_text = str(ver_mc.text)
    ver_mc_list = ver_mc_text.split(".")
    if (len(ver_mc_list) == 2): ver_mc_list.append("-1")
    try:
        ver_mc_major = int(ver_mc_list[0])
        ver_mc_minor = int(ver_mc_list[1])
        ver_mc_patch = int(ver_mc_list[2])
    except: continue
    if (ver_mc_minor <= 7 and ver_mc_patch < 10): continue
    print(ver_mc_text)

    res = requests.get(BASE_URL + "index_%s.html" % (ver_mc.text))
    soup = BeautifulSoup(res.text, "html.parser")
    for ver_fg in soup.select("td.download-version"):
        ver_fg_text = str(ver_fg.text)
        while (ver_fg_text.find(" ") >= 0):
            ver_fg_text = ver_fg_text.replace(" ", "")
        while (ver_fg_text.find("\n") >= 0):
            ver_fg_text = ver_fg_text.replace("\n", "")
        ver_fg_list = ver_fg_text.split(".")
        if (len(ver_fg_list) == 3): ver_fg_list.append("-1")
        try:
            ver_fg_major = int(ver_fg_list[0])
            ver_fg_minor = int(ver_fg_list[1])
            ver_fg_patch = int(ver_fg_list[2])
            ver_fg_build = int(ver_fg_list[3])
        except: continue
        print("|-", ver_fg_text)
        
        if ((ver_fg_major == 10 and ver_fg_minor == 13 and 1300 <= ver_fg_build <= 1614) or
                (ver_fg_major == 11 and ver_fg_minor == 14 and 1237 <= ver_fg_build <= 1259) or
                (ver_fg_major == 11 and ver_fg_minor == 14 and 1575 <= ver_fg_build <= 1654) or
                (ver_fg_major == 11 and ver_fg_minor == 15 and 1890 <= ver_fg_build <= 2318) or
                (ver_fg_major == 12 and ver_fg_minor == 16 and 1766 <= ver_fg_build <= 1885) or
                (ver_fg_major == 12 and ver_fg_minor == 17 and 1908 <= ver_fg_build <= 1918) or
                (ver_fg_major == 12 and ver_fg_minor == 17 and 1920 <= ver_fg_build <= 1936) or
                (ver_fg_major == 12 and ver_fg_minor == 18 and 1981 <= ver_fg_build <= 2007)):
            ver_total_text = "%s-%s-%s" % (ver_mc_text, ver_fg_text, ver_mc_text)
        elif (ver_fg_major == 13 and ver_fg_minor == 19 and 2126 <= ver_fg_build <= 2129):
            ver_total_text = "%s-%s-%s" % (ver_mc_text, ver_fg_text, "1.11.x")
        elif (ver_fg_major == 12 and ver_fg_minor == 17 and ver_fg_build == 1919):
            ver_total_text = "%s-%s-%s" % (ver_mc_text, ver_fg_text, "EHUnit")
        else:
            ver_total_text = "%s-%s" % (ver_mc_text, ver_fg_text)

        output_file.write("%s %s %s\n" % (ver_mc_text, ver_fg_text, ver_total_text))

