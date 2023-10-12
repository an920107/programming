while True:
    try:
        n = int(input())
        m_str = "1"
        while int(m_str) % n != 0:
            m_str += "1"
        print(len(m_str))
    except:
        break
