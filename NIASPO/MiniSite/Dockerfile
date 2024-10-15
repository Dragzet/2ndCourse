FROM golang:1.23-alpine AS build

WORKDIR /MiniSite

COPY go.mod go.sum ./
RUN go mod download

COPY . .

RUN go build -v -o app ./cmd/minisite

FROM alpine:latest
WORKDIR /root/

COPY --from=build /MiniSite/app /MiniSite/app

EXPOSE 8080

CMD ["/MiniSite/app"]