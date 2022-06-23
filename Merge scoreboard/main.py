import omegaup.api
import sys
import os
import math
from pprint import pprint
import json
import pandas as pd


def getCredentialsFromFile(filename):
    """
    Reads the login credentials from the file. If they are not there, then it will ask for them and write them to the file.
    """
    if os.path.isfile(filename):
        with open(filename, "r") as f:
            username = f.readline().strip()
            password = f.readline().strip()
    else:
        print("Provide your omegaup account")
        username = input(" Username: ")
        password = input(" Password: ")
        with open(filename, "w") as f:
            f.write(username + "\n")
            f.write(password + "\n")
    f.close()

    return username, password


def getContestsFromFile(filename):
    """
    Reads the contests to be merged from the file. If they are not there a warning will be displayed.
    """
    contests = []
    if os.path.isfile(filename):
        with open(filename, "r") as f:
            for id in f.readlines():
                id = id.strip()
                contests.append(id)
    else:
        print(f"{filename} not found.")
    f.close()
    return contests


username, password = getCredentialsFromFile("login.txt")

client = omegaup.api.Client(username=username, password=password)
contestController = omegaup.api.Contest(client)

contests = getContestsFromFile("contests.txt")

if len(contests) > 0:
    data = []
    pos = dict()
    total = dict()

    for contest in contests:
        scoreboard = contestController.scoreboardMerge(contest_aliases=[contest])

        for user in scoreboard.ranking:
            if user.name not in pos:
                pos[user.name] = len(pos)
                total[user.name] = 0
                data.append({"Name:": user.name})

            data[pos[user.name]][contest] = user.total.points
            total[user.name] += user.total.points

    for username, total in total.items():
        data[pos[username]]["Total"] = total

    data.sort(key=lambda x: -x["Total"])

    df = pd.DataFrame(data)
    df.to_excel("results.xlsx", index=False)

    print("Contests results merged.")
else:
    print("Not contests found.")
