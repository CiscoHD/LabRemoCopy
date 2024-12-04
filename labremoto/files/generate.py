from numpy import random
import pandas as pd
from datetime import datetime 

def generate_code_topics(path='/home/laboratorio_remo_remasterizado/labremoto/files/topics.csv'):
    topics = pd.read_csv(path)
    topics['code_topic'] = random.randint(1000000000, 9999999999, size=len(topics))
    topics['date_time'] = datetime.now()
    topics.to_csv(path, index=False, encoding='utf-8')

generate_code_topics()