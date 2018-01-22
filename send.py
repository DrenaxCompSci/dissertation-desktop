#!/usr/bin/env python
import pika

connection = pika.BlockingConnection(pika.ConnectionParameters(host='http://192.168.10.115:15672/'))
channel = connection.channel()

channel.queue_declare(queue='data')

channel.basic_publish(exchange = '', routing_key = 'data', body = 'Temperature: N/A')

print(" [x] Sent 'Temperature: N/A'")

connection.close()