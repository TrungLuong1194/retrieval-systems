from utils import generate_random_sequence


def search(seq, l, r, x):
    num_comparisons = 0

    if r >= l:
        mid = l + (r - l) // 2

        num_comparisons += 1

        if seq[mid] == x:
            return mid, num_comparisons
        elif seq[mid] > x:
            res, num = search(seq, l, mid - 1, x)
            num_comparisons += num

            return res, num_comparisons
        else:
            res, num = search(seq, mid + 1, r, x)
            num_comparisons += num

            return res, num_comparisons
    else:
        return -1, num_comparisons


if __name__ == '__main__':
    random_seq = generate_random_sequence(20)
    print('- Random sequence: ' + str(random_seq))
    sorted_seq = sorted(random_seq)
    print('- Sorted sequence: ' + str(sorted_seq))

    # Implement binary search
    number_search = 534
    print('- Search number: ' + str(number_search))
    result, comps = search(sorted(sorted_seq), 0, len(random_seq) - 1, number_search)
    print('Number of comparisons: ' + str(comps))
    if result == -1:
        print('Not found!')
    else:
        print('Index: ' + str(result))

    number_search = 150
    print('- Search number: ' + str(number_search))
    result, comps = search(sorted(sorted_seq), 0, len(random_seq) - 1, number_search)
    print('Number of comparisons: ' + str(comps))
    if result == -1:
        print('Not found!')
    else:
        print('Index: ' + str(result))
