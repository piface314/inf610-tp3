from math import log2
from sys import argv
import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
import os
import pandas as pd


bounds = {
    "bf": lambda n, w: 3 * 2**n,
    "xs": lambda n, w: 2**n * n,#n * 2**(n - 1) + 4 * 2**n - 2,
    "bt": lambda n, w: 6 * 2**n,
    "dpb": lambda n, w: 3 * n * w,
    "dpt": lambda n, w: 3 * n * w,
    "gd": lambda n, w: 2 * n * np.log2(n)
}

labels = {
    "bf": "$T_{bf}(n)$ medido",
    "xs": "$T_{xs}(n)$ medido",
    "bt": "$T_{bt}(n)$ medido",
    "dpb": "Prog. Dinâmica (Bottom-Up)",
    "dpt": "Prog. Dinâmica (Top-Down)",
    "gd": "$T_{gd}(n)$ medido",
}

functions = {
    "bf":  "$3 \cdot 2^n$",
    "xs":  "$2^n n$",
    "bt":  "$6 \cdot 2^n$",
    "dpb": "$3nw$",
    "dpt": "$3nw$",
    "gd":  "$2n\log n$"
}

def plot_bf_group(df: pd.DataFrame, out_fp: str):
    ps = ["bf", "xs", "bt"]
    colors = ["orange", "red", "yellow"]
    plt.subplots(figsize=(10,5), dpi=300)
    for p, color in zip(ps, colors):
        df_p = df[df.paradigm == p]
        df_p = df_p.groupby("n_items")["op"].agg(["min", "median", "max"])
        x = df_p.index
        yerr = df_p[["max", "min"]].copy()
        yerr["max"] -= df_p["median"]
        yerr["min"] -= df_p["median"]
        y = df_p["median"]
        x_ref = np.linspace(x.min(), x.max(), x.max() - x.min())
        plt.plot(x_ref, bounds[p](x_ref, 0), color=color, label=functions[p], linestyle='--')
        plt.errorbar(x, y, yerr=(np.abs(yerr["min"]), yerr["max"]), label=labels[p], color=color, marker="o")
    plt.xticks(x)
    plt.ylim(bottom=0)
    plt.yscale("symlog")
    plt.grid(alpha=0.3)
    plt.xlabel("Qt. de itens ($n$)")
    plt.ylabel("Qt. de operações")
    plt.legend()
    plt.savefig(os.path.join(out_fp, "bf.png"), bbox_inches='tight', pad_inches = 0.1)
    plt.close()

def plot_dp_group(df: pd.DataFrame, out_fp: str):
    plt.subplots(figsize=(10,5), dpi=300)
    df_dpb = df[df.paradigm == "dpb"]
    ws = df_dpb["w_max"].drop_duplicates().sort_values()
    for i, w in enumerate(ws):
        r = 0.3 + 0.7 * (i / len(ws))
        color = mpl.colormaps["YlGn"](r)
        df_ = df_dpb[df_dpb["w_max"] == w]
        x = df_["n_items"]
        y = df_["op"]
        plt.plot(x, y, color=color, label=f"$T_{{dpb}}(n,{w})$ medido", marker="o")
    x_ref = np.linspace(x.min(), x.max(), x.max() - x.min())
    plt.plot(x_ref, bounds["dpb"](x_ref, w), color=color, label=f"$3nW, W={x.max()}$", linestyle='--')
    plt.xticks(x)
    plt.xlabel("Qt. de itens ($n$)")
    plt.ylabel("Qt. de operações")
    plt.grid(alpha=0.3)
    plt.legend(reverse=True)
    plt.savefig(os.path.join(out_fp, "dpb.png"), bbox_inches='tight', pad_inches = 0.1)
    plt.close()

    plt.subplots(figsize=(10,5), dpi=300)
    df_dpb = df[df.paradigm == "dpt"]
    ws = df_dpb["w_max"].drop_duplicates().sort_values()
    for i, w in enumerate(ws):
        r = 0.4 + 0.6 * (i / len(ws))
        color = mpl.colormaps["GnBu"](r)
        df_ = df_dpb[df_dpb["w_max"] == w]
        x = df_["n_items"]
        y = df_["op"]
        plt.plot(x, y, color=color, label=f"$T_{{dpt}}(n,{w})$ medido", marker="o")
    x_ref = np.linspace(x.min(), x.max(), x.max() - x.min())
    plt.plot(x_ref, bounds["dpt"](x_ref, w), color=color, label=f"$3nW, W={x.max()}$", linestyle='--')
    plt.xticks(x)
    plt.xlabel("Qt. de itens ($n$)")
    plt.ylabel("Qt. de operações")
    plt.grid(alpha=0.3)
    plt.legend(reverse=True)
    plt.savefig(os.path.join(out_fp, "dpt.png"), bbox_inches='tight', pad_inches = 0.1)
    plt.close()
    

def plot_gd(df: pd.DataFrame, out_fp: str):
    ps = ["gd"]
    colors = ["purple"]
    plt.subplots(figsize=(10,5), dpi=300)
    for p, color in zip(ps, colors):
        df_p = df[df.paradigm == p]
        df_p = df_p.groupby("n_items")["op"].agg(["min", "median", "max"])
        x = df_p.index
        yerr = df_p[["max", "min"]].copy()
        yerr["max"] -= df_p["median"]
        yerr["min"] -= df_p["median"]
        y = df_p["median"]
        x_ref = np.linspace(x.min(), x.max(), x.max() - x.min())
        plt.plot(x_ref, bounds[p](x_ref, 0), color=color, label=functions[p], linestyle='--')
        plt.errorbar(x, y, yerr=(np.abs(yerr["min"]), yerr["max"]), label=labels[p], color=color, marker="o")
    plt.xticks(x)
    plt.xlabel("Qt. de itens ($n$)")
    plt.ylabel("Qt. de operações")
    plt.grid(alpha=0.3)
    plt.legend()
    plt.savefig(os.path.join(out_fp, "gd.png"), bbox_inches='tight', pad_inches = 0.1)
    plt.close()

if __name__ == "__main__":
    if len(argv) <= 2:
        print(f"Usage:\n\t$ {argv[0]} <out> <in>...")
        exit(1)
    
    out_fp = argv[1]
    in_fps = argv[2:]

    dfs = [pd.read_csv(in_fp, header=0) for in_fp in in_fps]
    df = pd.concat(dfs, axis=0)
    plot_bf_group(df, out_fp)
    plot_dp_group(df, out_fp)
    plot_gd(df, out_fp)