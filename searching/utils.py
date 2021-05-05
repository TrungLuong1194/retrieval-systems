import random


def generate_random_sequence(totals_of_number):
    random.seed(10)
    random_list = list()

    for _ in range(0, totals_of_number):
        n = random.randint(1, 1000)
        random_list.append(n)

    return random_list
