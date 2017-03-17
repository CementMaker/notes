data_in=../data_in
data_out=../data_out

if [ ! -e ${data_in}/text8 ]; then
    wget http://mattmahoney.net/dc/text8.zip -O ${data_in}/text8.gz
    unzip ${data_in}/text8.gz -d ${data_in}
fi

if [ 1 -eq 1 ]; then
    time ../bin/word2vec -train ${data_in}/text8 \
                         -output ${data_out}/vectors.bin \
                         -cbow 1 \
                         -size 200 \
                         -window 8 \
                         -negative 25 \
                         -hs 1 \
                         -sample 1e-4 \
                         -threads 4 \
                         -binary 1 \
                         -iter 15
fi

../bin/distance ${data_out}/vectors.bin
