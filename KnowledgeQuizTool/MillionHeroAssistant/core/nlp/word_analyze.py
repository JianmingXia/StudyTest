# -*- coding: utf-8 -*-


import multiprocessing
import platform
import re  
import jieba
import jieba.analyse

if not platform.system().upper().startswith("WINDOWS"):
    jieba.enable_parallel(multiprocessing.cpu_count())

Noun_flags = [
    "n",
    "nr",
    "nr2",
    "nrj",
    "nrf",
    "ns"
    "nsf"
    "nt"
    "nz",
    "nl",
    "ng"
    "v",
    "vn",
    "an",
    "a"
]


def pre_process_question(keyword):
    """
    strip charactor and strip ?

    :param question:
    :return:
    """

    for char, repl in [("“", ""), ("”", ""), ("？", "")]:
        keyword = keyword.replace(char, repl)

    keyword = keyword.split(r"．")[-1]
    keywords = keyword.split(" ")
    keyword = "".join([e.strip("\r\n") for e in keywords if e])
    return keyword


def analyze_keyword_from_question(question):
    """
    analyze the main key words from questions

    :param question:
    :return:
    """

    if len(question) > 38:
        question = pre_process_question(question)
        main_keywords = jieba.analyse.extract_tags(
            question,
            topK=20,
            withWeight=False,
            allowPOS=Noun_flags
        )
        # print ("main_keywords")
        # print (main_keywords)

        word = u'《'  
        left_book_title = [m.start() for m in re.finditer(word, question)]  
        word = u'》'  
        right_book_title = [m.start() for m in re.finditer(word, question)] 

        book_title = (min(len(left_book_title), len(right_book_title)))
        if book_title > 0:
            print ("book_title")
            print (left_book_title)
            print (right_book_title)
            main_keywords.insert(0, question[(left_book_title[0] + 1):right_book_title[0]])

        return " ".join(main_keywords)
    else:
        return question
    
