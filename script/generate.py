from random import randint
from sys import argv


def generate_one(n: int, w: int):
    return ' '.join(f"{randint(1, w//2)} {randint(1, 100)}" for _ in range(n))

if __name__ == "__main__":
    if len(argv) <= 7:
        print(f"Usage:\n\t$ {argv[0]} <n0> <nf> <nstep> <w0> <wf> <wstep> <out>")
        exit(1)
    n0, nf, ns, w0, wf, ws = map(int, argv[1:7])
    out_fp = argv[7]
    with open(out_fp, "w") as f:
        for n in range(n0, nf+1, ns):
            for w in range(w0, wf+1, ws):
                f.write(f"{n} {w}\n")
                f.write(generate_one(n, w) + "\n")