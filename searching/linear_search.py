from utils import generate_random_sequence


def search(seq, x):
    num_comparisons = 0

    for i in range(len(seq)):
        num_comparisons += 1

        if seq[i] == x:
            return i, num_comparisons

    return -1, num_comparisons


if __name__ == '__main__':
    random_seq = generate_random_sequence(20)
    print('- Random sequence: ' + str(random_seq))

    # Implement binary search
    number_search = 534
    print('\n- Search number: ' + str(number_search))
    result, comps = search(random_seq, number_search)
    print('Number of comparisons: ' + str(comps))
    if result == -1:
        print('Not found!')
    else:
        print('Index: ' + str(result))

    number_search = 150
    print('\n- Search number: ' + str(number_search))
    result, comps = search(random_seq, number_search)
    print('Number of comparisons: ' + str(comps))
    if result == -1:
        print('Not found!')
    else:
        print('Index: ' + str(result))
