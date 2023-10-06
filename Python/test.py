def decode(plain_text: str) -> str:
    SHIFT = 7

    chars_decoded = map(lambda x: chr(ord(x) - SHIFT), plain_text)
    return "".join(chars_decoded)


print(decode(input()))
