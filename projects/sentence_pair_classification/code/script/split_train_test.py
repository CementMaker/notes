#coding: utf-8
from __future__ import division
from __future__ import print_function
from __future__ import absolute_import
import os
import sys
import random
import math
import pandas as pd
import numpy as np
import argparse
import yaml
import gzip

def write_data(data, fname, update=False):
    if not update and os.path.isfile(fname) is True:
        return False

    if not os.path.exists(os.path.dirname(fname)):
        os.makedirs(os.path.dirname(fname))

    with open(fname, 'w') as fout:
        fout.write("\n".join(map(str, data)))
    return True


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("-c", "--config", default="../conf/config.yaml",
                        help="Project configuration file.")
    parser.add_argument("-u", "--update", action='store_true',
                        help="Update data even if it is existed")
    return parser.parse_args()

if __name__ == "__main__":
    args = parse_args()

    with open(args.config, 'r') as f:
        conf = yaml.safe_load(f)

    # step 1. split train test
    train_ratio, dev_ratio, test_ratio = map(float, conf['model_data']['split_ratio'].split(':'))
    with gzip.open("{}/train.csv.gz".format(conf['zipdata'])) as f:
        file_content = f.readlines()
        file_head = file_content[0]
        file_content = file_content[1:]

    random.seed(conf['random_seed'])
    random.shuffle(file_content)
    total = len(file_content)
    train_num = math.ceil(total * train_ratio)
    dev_num = math.ceil(total * dev_ratio)
    test_num = total - train_num - dev_num

    train_data = file_content[: train_num]
    dev_data = file_content[train_num : train_num + dev_num]
    test_data = file_content[train_num + dev_num : ]

    write_data([file_head] + train_data, conf['model_data']['train'], args.update)
    write_data([file_head] + dev_data, conf['model_data']['dev'], args.update)
    write_data([file_head] + test_data, conf['model_data']['test'], args.update)

    # step 2. unzip test data for labeling
    with gzip.open("{}/test.csv.gz".format(conf['zipdata'])) as f:
        write_data(f.readlines(), conf['model_data']['unlabeled'], args.update)

