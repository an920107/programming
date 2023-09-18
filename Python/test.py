import os
import signal
import threading

def handler(signum, frame):
    raise KeyboardInterrupt()

class Lock:
    password: str
    message: str

    def __init__(self, password: str, message: str):
        self.password = password
        self.message = message

MAX_TRY = 10
LOCKS: list[Lock] = [
    Lock("??????", "Give me five~"),
    Lock("??????", "Rat is stupid but scary."),
    Lock("2B4841", "I've said, DON'T LOOK AT ME!!!"),
    Lock("B8BCAB", "The knife is pretty sharp, isn't it?"),
    Lock("??????", "Is this my head?"),
]

if __name__ == "__main__":
    signal.signal(signal.SIGTSTP, handler)

    tried = 0
    stage = 0
    while stage >= 0:
        try:
            print(f"Enter the password: (you have tried {tried}/{MAX_TRY})")
            pwd = input("#").upper()
            if pwd == LOCKS[stage].password:
                print(LOCKS[stage].message)
                stage = stage + 1 if stage < len(LOCKS) - 1 else -1
            elif len(pwd) == 0:
                continue
            else:
                print(f"WA ({stage / len(LOCKS) * 100}%)\n")
                stage = 0
                tried += 1
                if tried > MAX_TRY:
                    threading.Thread(target=lambda: os.system("play -q {os.getcwd()}/shriek.mp3")).start()
                    break
                threading.Thread(target=lambda: os.system("play -q {os.getcwd()}/laugh.mp3")).start()
        except KeyboardInterrupt:
            print()
            continue
    if stage < 0:
        print("Unlocked!!")
        threading.Thread(target=lambda: os.system("sox -q ??.mp3"))
    else:
        while True:
            try:
                cmd = input("Locked forever...")
                if cmd == "~":
                    break
            except KeyboardInterrupt:
                print()
                continue