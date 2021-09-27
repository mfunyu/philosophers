from enum import Flag, auto

class Error(Flag):
    LOGFORMAT = auto()
    FORK = auto()
    DEATH = auto()
    EOS = auto()

    def flag2str (flag):
        if flag == Error.LOGFORMAT:
            return "log format	  "
        if flag == Error.FORK:
            return "no stolen fork	  "
        if flag == Error.DEATH:
            return "death time	  "
        if flag == Error.EOS:
            return "end of simulation "

