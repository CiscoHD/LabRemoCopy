from numpy import random
import pandas as pd
from datetime import datetime 

def generate_code_topics(path='/home/laboratorio_remo_remasterizado/labremoto/files/topics.csv'):
    topics = pd.read_csv(path)
    topics['code_topic'] = topics['code_topic'].apply(lambda x: int(random.randint(1000000000, 9999999999)))
    topics['date_time']  = topics['date_time'].apply(lambda x: datetime.now())
    topics.to_csv(path)

generate_code_topics()