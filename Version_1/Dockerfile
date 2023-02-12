#running cmake in Docker

FROM ubuntu:latest

MAINTAINER Jeff Machyo <machyo.j@northeastern.edu>

RUN apt-get -y update && apt-get install -y
RUN apt-get -y install g++ cmake git sqlite3

COPY . .

WORKDIR .

RUN rm -rf out/build CMakelists.txt
RUN cmake -S . -B out/build
RUN make -C out/build

CMD ["./out/build/main"]