#!/usr/bin/env python
import pika

creds = pika.PlainCredentials('drenax', 'kirkjt03')
connection = pika.BlockingConnection(pika.ConnectionParameters('192.168.10.124', 5672, '/', creds))
channel = connection.channel()

channel.exchange_declare(exchange='logs', exchange_type='fanout')

result = channel.queue_declare(exclusive=True)
queue_name = result.method.queue

channel.queue_bind(exchange='logs', queue=queue_name)

def callback(ch, method, properties, body):
    print(" [x] Received %r" % body)

channel.basic_consume(callback, queue=queue_name, no_ack=True)

print(' [*] Waiting for messages. To exit press CTRL+C')
channel.start_consuming()