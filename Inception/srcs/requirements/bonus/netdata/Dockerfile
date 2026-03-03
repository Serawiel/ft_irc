FROM debian:12

RUN apt-get update && apt-get install -y \
	netdata \
	&& rm -rf /var/lib/apt/lists/*

EXPOSE 19999

CMD ["netdata", "-D"]