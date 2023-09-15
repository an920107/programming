import signal
import os

PWD = "986052"
MAX_TRY = 10
EXIT_CODE = "_"

def signal_handler(sig, frame):
    raise KeyboardInterrupt

if __name__ == "__main__":
    os.system("clear")

    signal.signal(signal.SIGINT, signal_handler)
    signal.signal(signal.SIGTSTP, signal_handler)

    locking = True
    tried = 0
    while locking:
        try:
            print(f"Enter the password ({tried}/{MAX_TRY}):")
            val = input("#")
            if (len(val) == 0):
                continue
            elif (val == PWD):
                locking = False
            else:
                print("Wrong!!!")
                tried += 1
                if (tried == MAX_TRY):
                    break
        except KeyboardInterrupt:
            print()
            continue
    while locking:
        try:
            val = input("Locking forever...")
            if (val == EXIT_CODE):
                break
        except KeyboardInterrupt:
            print()
    print("Unlocked!!!")