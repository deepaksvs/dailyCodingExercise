
memoize = dict()


# Min steps of count m hops with n steps
def hop_stairs(steps, hop):
    global memoize

    if steps <= 0:
        return 0
    if steps in hop:
        return 1

    computed = memoize.get(steps)
    if computed is not None:
        return computed

    min_hop = min(list(map(lambda i_hop: hop_stairs(steps - i_hop, hop), hop)))
    hops = 1 + min_hop
    memoize[steps] = hops
    return hops


def main():
    n = int(input("Enter number if steps: "))
    hStr = raw_input("Enter steps: ")
    hop = map(lambda x: int(x), hStr.split(' '))
    print('Min steps: ', hop_stairs(n, hop))


if __name__ == '__main__':
    main()
