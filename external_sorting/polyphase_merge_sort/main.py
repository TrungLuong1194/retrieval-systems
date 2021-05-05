import random
import sys
import os


def generate_list(number):
    random_list = list()

    for _ in range(0, number):
        n = random.randint(1, 500)
        random_list.append([n])

    return random_list


def fibonacci_distributions(totals_of_tapes, level):
    if level < 0:
        return 0
    elif level == 0:
        return 1
    else:
        tmp = 0
        for i in range(1, totals_of_tapes + 1):
            tmp += fibonacci_distributions(totals_of_tapes, level - i)

        return tmp


def get_distribution_of_run(totals_of_tapes, totals_of_number):
    level = 0

    while True:
        distribution_list = list()

        if level == 0:
            distribution_list.append(1)
            for i in range(totals_of_tapes - 1):
                distribution_list.append(0)
        else:
            distribution_list.append(fibonacci_distributions(totals_of_tapes, level))
            tmp = fibonacci_distributions(totals_of_tapes, level)

            for i in range(totals_of_tapes, 1, -1):
                tmp -= fibonacci_distributions(totals_of_tapes, level - i)
                distribution_list.append(tmp)

        if sum(distribution_list) == totals_of_number:
            return distribution_list
        elif sum(distribution_list) > totals_of_number:
            return None
        else:
            level += 1


def polyphase_merge_sort(totals_of_tapes, number_list):
    # ----- Create distribution of run -----
    totals_of_tapes_real = totals_of_tapes - 1
    distribution_of_run = get_distribution_of_run(totals_of_tapes_real, len(number_list))

    distribution_ls = list()
    index = 0

    for i in distribution_of_run:
        distribution_ls.append(number_list[index:index + i])
        index = i

    distribution_ls.append(list())
    # print(distribution_ls)

    # ----- Save data to text file -----
    # Write the init sequence to file
    file_name = 'init.txt'
    with open(file_name, 'a') as f:
        for i in range(len(number_list)):
            if i != len(number_list) - 1:
                for j in number_list[i]:
                    f.write(str(j) + ' ')
                f.write('|')
            else:
                for j in number_list[i]:
                    f.write(str(j) + ' ')

    # Initialize Phase 1: Write sequences of each tape to file
    for i in range(len(distribution_ls)):
        file_name = 'tap_' + str(i + 1) + '.txt'
        with open(file_name, 'a') as f:
            if len(distribution_ls[i]) == 0:
                f.write('EMPTY')
            else:
                for j in range(len(distribution_ls[i])):
                    if j != len(distribution_ls[i]) - 1:
                        for k in distribution_ls[i][j]:
                            f.write(str(k) + ' ')
                        f.write('|')
                    else:
                        for k in distribution_ls[i][j]:
                            f.write(str(k) + ' ')

    while True:
        # Count the number of elements from each tap
        num_elements = dict()

        for i in range(len(distribution_ls)):
            file_name = 'tap_' + str(i + 1) + '.txt'
            with open(file_name, 'r') as f:
                last_line = f.readlines()[-1]
                if last_line == 'EMPTY':
                    num_elements[i + 1] = 0
                else:
                    num_elements[i + 1] = len(last_line.split('|'))

        # print(num_elements)

        # Merge elements of each tape
        if list(num_elements.values()).count(0) == totals_of_tapes - 1:

            # Get name of tape which have sorted sequence
            id_tape = list(num_elements.keys())[list(num_elements.values()).index(1)]

            # Get data
            file_name = 'tap_' + str(id_tape) + '.txt'
            sorted_ls = list()
            with open(file_name, 'r') as f:
                last_line = f.readlines()[-1]
                tmp1 = last_line.split('|')

                for ele in tmp1:
                    tmp2 = ele.split(' ')
                    for i in range(len(tmp2) - 1):
                        sorted_ls.append(int(tmp2[i]))

            # print('sorted: ' + str(sorted_ls))

            # Write data
            file_name = 'sorted.txt'
            with open(file_name, 'a') as f:
                for i in range(len(sorted_ls)):
                    if i != len(sorted_ls) - 1:
                        f.write(str(sorted_ls[i]) + ' ')
                        f.write('|')
                    else:
                        f.write(str(sorted_ls[i]) + ' ')

            break
        else:
            distribution_tmp = dict()
            for k, v in num_elements.items():
                if v != 0:
                    file_name = 'tap_' + str(k) + '.txt'
                    with open(file_name, 'r') as f:
                        last_line = f.readlines()[-1]
                        tmp1 = last_line.split('|')
                        tmp2 = list()

                        for ele in tmp1:
                            tmp3 = ele.split(' ')
                            tmp4 = list()
                            for i in range(len(tmp3) - 1):
                                tmp4.append(int(tmp3[i]))
                            tmp2.append(tmp4)

                        distribution_tmp[k] = tmp2

            # print(distribution_tmp)

            # Count the minimum number of elements per list
            min_elements = sys.maxsize

            for _, v in distribution_tmp.items():
                if len(v) < min_elements:
                    min_elements = len(v)

            # print(min_elements)

            # Merge step
            merge_list = list()

            for i in range(min_elements):
                tmp = list()
                for _, v in distribution_tmp.items():
                    tmp += v.pop(0)

                tmp.sort()
                merge_list.append(tmp)

            # print(merge_list)

            # Get name of tape which have empty
            id_tape = list(num_elements.keys())[list(num_elements.values()).index(0)]

            # Write the merge sequence to empty file
            file_name = 'tap_' + str(id_tape) + '.txt'
            with open(file_name, 'a') as f:
                f.write('\n\n')
                for i in range(len(merge_list)):
                    if i != len(merge_list) - 1:
                        for j in merge_list[i]:
                            f.write(str(j) + ' ')
                        f.write('|')
                    else:
                        for j in merge_list[i]:
                            f.write(str(j) + ' ')

            # Write the new data for other tapes
            for k, v in distribution_tmp.items():
                file_name = 'tap_' + str(k) + '.txt'
                with open(file_name, 'a') as f:
                    f.write('\n\n')
                    if len(v) == 0:
                        f.write('EMPTY')
                    else:
                        for i in range(len(v)):
                            if i != len(v) - 1:
                                for j in v[i]:
                                    f.write(str(j) + ' ')
                                f.write('|')
                            else:
                                for j in v[i]:
                                    f.write(str(j) + ' ')


if __name__ == '__main__':
    # Remove the old data: text data
    ls_dir = os.listdir()
    for ele in ls_dir:
        if ele.endswith('.txt'):
            os.remove(ele)

    # Generate the random sequence
    rd_list = generate_list(129)

    # Implement the polyphase merge sort
    polyphase_merge_sort(6, rd_list)
