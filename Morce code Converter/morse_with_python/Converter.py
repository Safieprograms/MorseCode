import time
from playsound import playsound
import threading
import keyboard

transaltion = {
    ".-": "A",
    "-...": "B",
    "-.-.": "C",
    "-..": "D",
    ".": "E",
    "..-.": "F",  
    "--.": "G",
    "....": "H",
    "..": "I",
    ".---": "J",
    "-.-": "K",
    ".-..": "L",
    "--": "M",
    "-.": "N",
    "---": "O",
    ".--.": "P",
    "--.-": "Q",
    ".-.": "R",
    "...": "S",
    "-": "T",
    "..-": "U",
    "...-": "V",
    ".--": "W",
    "-..-": "X",
    "-.--": "Y",
    "--..": "Z",
    "-----": "0",
    ".----": "1",
    "..---": "2",
    "...--": "3",
    "....-": "4",
    ".....": "5",
    "-....": "6",
    "--...": "7",
    "---..": "8",
    "----.": "9",
    "SOS": "... --- ...",
}

transaltion_reversed = { k : v for v, k in transaltion.items()}

def play_sound(text):
    def play_code():
        print("Morse code sound is playing, to stop it press 'F' . ")
        for c in text:
            if c == ".":
                playsound("Shortsound.mp3")
                time.sleep(0.7)
            elif c == "-":
                playsound("Longsound.mp3")
                time.sleep(0.7)
            elif c == "/" or c == " ":
                time.sleep(1.2)
            else:
                print("Incorrect character '{}', enter a valid one!".format(c))
                break
            if stop_playing == True :
                return


    play_thread = threading.Thread(target=play_code)
    play_thread.start()

    stop_playing = False
    while not stop_playing:
        if keyboard.is_pressed('F') or keyboard.is_pressed('f') :
            stop_playing = True
            return

    play_thread.join()

def morse_to_text(text):
    res = "".join(transaltion[c] for c in text.split(" ") if c in transaltion)
    return res

def text_to_morse(text):
    msgtomorse = " ".join(transaltion_reversed[c] for c in text.upper() if c in transaltion_reversed)
    return msgtomorse

i = 1
while i == 1:
    print("____________________________________________________________\n")
    print("\033[1m        Welcome to the morse Code converter\033[0m")
    print("____________________________________________________________ \n")
    print(
    "             ____           __     \n"
    "             \\===\\=========|__|=[]\n"
    "  <========^==='======>    _||_   \n"
    " _/_|_|_|_|_|_|_|_|_|_\\_^__||||_   \n"
    "|                              |   \n"
    "|                              |   \n"
    "+---/||\\----------------/||\\---+   \n"
    "   ^^^^^^              ^^^^^^")        
    print("\n____________________________________________________________ \n")

    c = input("Choose what you want to do: \n 1/ Morse to text \n 2/ Text to Morse \n 3/ Exit\n")
    if c == "1":
        msg = input("Enter your Morse code:")
        print("The generated morse code :", morse_to_text(msg))
        input("Click Enter to continue")
    elif c == "2":
        msg = input("Input your text:")
        code = text_to_morse(msg)
        print(code)
        play_sound(code)
    elif c == "3":
        i = 22
        exit()
    else:
        print("Enter a valid option please")
        time.sleep(2)