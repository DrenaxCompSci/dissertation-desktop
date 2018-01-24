#!/usr/bin/env python
import pika

creds = pika.PlainCredentials('drenax', 'kirkjt03')
connection = pika.BlockingConnection(pika.ConnectionParameters('192.168.10.114', 5672, '/', creds))
channel = connection.channel()

channel.queue_declare(queue='data')

def callback(ch, method, properties, body):
    print(" [x] Received %r" % body)

channel.basic_consume(callback, queue='data', no_ack=True)

print(' [*] Waiting for messages. To exit press CTRL+C')
channel.start_consuming()