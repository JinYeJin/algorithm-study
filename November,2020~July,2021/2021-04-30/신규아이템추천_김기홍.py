import re


def solution(new_id):
    answer = ''
    answer = re.sub(r"[^a-z0-9\-\_\.]", "", new_id.lower())
    answer = re.sub(r"\.\.+", ".", answer)
    answer = re.sub(r"^\.|\.$", "", answer)
    if answer == "":
        answer += "a"
    if len(answer) >= 16:
        answer = re.sub(r"\.$", "", answer[:15])
    while len(answer) <= 2:
        answer += answer[-1]
    return answer
