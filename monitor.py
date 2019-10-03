import os.path
import QueryString as QS
#import QueryDML as Q_DML
import logging
import logging.handlers
from logging.handlers import RotatingFileHandler
import sys

from cm_api.api_client import ApiResource
from datetime import datetime
from datetime import timedelta

import pandas as pd
import pymysql

import pytz

#pd.set_option("display.width", 1500)
#pd.set_option("display.max_Columns", 11)

#command are consist of "opne" and "close"
def db_connection(command):
	global connection
	
	if command == "Open":
		logger = create_logger("db_connection.open")
		try:
			connection = pymysql.connect(host='bd-dev01', user='root', password='', db='TEST', charset='utf8')
		except Exception as e:
			logger.exception(e)
	
	elif command == "Close":
		if connection.open == True:
			logger = create_logger("db_connection.close")

			try:
				connection.close
			except Exception as e:
				logger.exception(e)
		else:
			return()

		
def create_logger(logger_name):
		today_date = datetime.today().strftime('%Y')

		#Create Logger
		logger = logging.getLogger(logger_name)
		
		#Check handler exists
		if len(logger.handlers) > 0:
			return logger # Logger already exists

		logger.setLevel(logging.INFO)

		formatter = logging.Formatter('[ %(asctime)s | %(levelname)s | %(name)s | #(filename)s:%(lineno)s ] > %(message)s')

		#Create Handlers
		streamHandler = logging.StreamHandler()
		
		if not os.path.exists('./log'):
				os.makedirs('./log/')

		#FileHandler = logging.FileHandler('./log/' + 'job_duration' + str(today_date) + '.log')
		rotatingFileHandler = RotatingFileHandler('./log/' + 'job_duration' + str(today_date) + '.log', maxBytes=10485760, backupCount=2) #10MB

		streamHandler.setLevel(logging.INFO)
		streamHandler.setFormatter(formatter)

		#FileHandler.setLevel(logging.INFO)
		#FileHandler.setFomatter(formatter)

		rotatingFileHandler.setLevel(logging.INFO)
		rotatingFileHandler.setFormatter(formatter)

		#Handlers Add
		logger.addHandler(streamHandler)
		#logger.addHandler(FileHandler)
		logger.addHandler(rotatingFileHandler)
		
		return logger


def pre_process(query_data_df,user_jobstate):
	logger=create_logger("pre_process")


def db_select(query):
	logger=create_logger("db_query")
	logger.info("# db_select START #")

	try:
		with connection.cursor(pymysql.cursors.DictCursor) as cursor:
		
			select_sql = str(query)

			#Linux Consol ANSI Control Word
			print("\033[3m" + "\033[32m" + "\t\t\t" + query + "\033[0m")

			cursor.execute(select_sql)
			select_data = cursor.fetchall()

	except Exception as e:
		logger.exception(e)
	finally:
		logger.info("# db_select END #")
		return select_data


def db_insert(pre_process_data, query_date):
	logger=create_logger("db_insert")
	logger.info("# db_insert START #")
	
	try:
		with connection.cursor() as cursor:
		
			insert_sql = "INSERT INT ?tbl_nm (?col_nm) VALUES (?Col_TP)"

			insert_data = []
			for data in pre_process_data:
				insert_data.append((data['base_dt'], data['user'], data['app_name'], data['application_duration'], data['state'], data['start_time'], data['end_time']))

			cursor.executemany(insert_sql, insert_data)
			connection.commit()

	except Exception as e:
		logger.exception(e)
	finally:
		connection.close()
	logger.info("# db_insert END #")


def db_update(query):
	logger=create_logger("db_update")
	
	try:
		with connection.cursor() as cursor:
		
			#"UPDATE BYDY_RISK_NTC_PRTC SET SEND_PROC_TP = '02' WHERE SEND_PROC_TP = '01')"
			update_sql = str(query)

			#Linux Consol ANSI Control Word
			print("\033[3m" + "\033[32m" + "\t\t\t" + query + "\033[0m")
			
			cursor.executemany(update_sql)
			connection.commit()

	except Exception as e:
		logger.exception(e)
	finally:
		return()

def read_exist_json():
	logger=create_logger("read_exist_json")
	logger.info("# read_exist_json START #")
	
	global json_dir
	_1_day_ago     = datetime.today()-timedelta(1)

	json_dir       = './' + 'mostRecentEvent_cumulateCount/'
	json_today     = json_dir + datetime.today().strftime('%Y-%m-%d')  + ".json"
	json_1_day_ago = json_dir + _1_day_ago.strftime('%Y-%m-%d')  + ".json"

	try:
		if not os.path.exists(json_dir) :
			os.makedirs(json_dir)

		if os.path.exists(json_today):
			json_df = pd.read_json(json_today) 
			print("json File Path : " + json_today)
		elif os.path.exists(json_1_day_ago):
			json_df = pd.read_json(json_1_day_ago) 
			print("json File Path : " + json_1_day_ago)
		else :
			json_df = pd.DataFrame()
			print("json File Doesn't exiest ")

		if not json_df.empty :
			json_df.OCR_DTM=json_df.OCR_DTM.astype('datetime64[ns]')
			json_df = json_df[['OCR_DTM', 'RISK_CLS_TP', 'SRVR_NM', 'TR_NM', 'HIGH_CALC_CNT', 'SUM_CNT', 'LOW_CALC_CNT', 'count(SRVR_NM)']]
		
		print(json_df)

	except Exception as e:
		logger.exception(e)

	logger.info("# read_exist_json END #")
	return(json_df.sort_index())


def main(argv):
	logger = create_logger("main")
	logger.info("################ main START ###################")
	
	db_connection("Open")

	# db select
	for num in range(1,3):
		select_data = db_select(eval("QS.Qry"+str(num)))
		db_data_df = pd.DataFrame(list(select_data))

	if not ( db_data_df.empty ):
		db_data_df = db_data_df[['OCR_DTM', 'RISK_CLS_TP', 'SRVR_NM', 'TR_NM', 'HIGH_CALC_CNT', 'SUM_CNT', 'LOW_CALC_CNT', 'count(SRVR_NM)' ]]
	print(db_data_df)

	#read json
	json_data_df=read_exist_json()

	if ( not (db_data_df.empty) and (json_data_df.empty) ) :
		db_data_df.to_json("./" + "mostRecentEvent_cumulateCount/" + datetime.today().strftime('%Y-%m-%d')  + ".json", date_format='iso')
		return 0
	

	print("#"*30 + " mostRecentEvent_cumulateCount dataframe " + "#"*30)
	if not ( (db_data_df.empty) or (json_data_df.empty) ):
		if 'OCR_DTM' in db_data_df.columns :
			
			#TypeError: Cannot convert tz-naive timestamps, use tz_localize to localize
			#db_data_df['OCR_DTM'] = db_data_df['OCR_DTM'].dt.tz_convert('Asia/Seoul')
			#TypeError: index is not a valid DatetimeIndex or PeriodIndex
			#db_data_df['OCR_DTM'] = db_data_df['OCR_DTM'].tz_localize('UTC').dt.tz_convert('Asia/Seoul')

			#print(json_data_df.dtypes)
			db_data_df.RISK_CLS_TP=db_data_df.RISK_CLS_TP.astype('int64')
			#print(db_data_df.dtypes)

			#SRVR_NM check if condition needed, if not error occur
			
			#if use df.append() then must do drop same tuple -> update recent_Time -> sum(count_1, count_2)
			#print("stored+select -> sort")
			gb_df=json_data_df.append(db_data_df).sort_values(by='OCR_DTM',ascending=False).sort_values(by=['SRVR_NM','TR_NM']).reset_index(drop=True, level=0)
			#print(gb_df)

			#print("agg_sum")
			gb_df2=gb_df.groupby(['RISK_CLS_TP','SRVR_NM','TR_NM'],as_index=False).agg('sum')
			#print(gb_df2)

			#print("agg_sum -> sort")
			gb_df2=gb_df2.sort_values(by=['SRVR_NM','TR_NM']).reset_index(drop=True, level=0)
			#print(gb_df2)

			#print("dup drop -> drop count")
			gb_df=gb_df.drop_duplicates(['RISK_CLS_TP','SRVR_NM','TR_NM'], keep='first').drop(['count(SRVR_NM)'], axis=1).reset_index(drop=True, level=0)
			#print(gb_df)
			#print("concat agg_sum")
			gb_df=pd.concat([gb_df,gb_df2['count(SRVR_NM)']],axis=1)
			#print(gb_df)

			merged_data_df=gb_df
			print(merged_data_df)

			merged_data_df.to_json(json_dir + datetime.today().strftime('%Y-%m-%d')  + ".json", date_format='iso')

			print("*"*50+"Dosen't Exist in MRE_&_CC TABLE"+"*"*50)
			a=db_data_df.append(json_data_df).append(json_data_df).reset_index(drop=True, level=0).drop_duplicates(subset=['RISK_CLS_TP','SRVR_NM','TR_NM'],keep=False).reset_index(drop=True, level=0)
			if not (a.empty):
				if not os.path.exists("./smsAlert/") :
					os.makedirs("./smsAlert/")

				a.to_json("./" + "smsAlert/" + "smsAlert" + datetime.today().strftime('%Y-%m-%d_%H-%M%S') + ".json", date_format='iso')
				print(a)
	else :
		print("there is no merged dataframe")


	#if (db_data_df['RISK_CLS_TP']==json_data_df['RISK_CLS_TP'] and db_data_df['SRVR_NM']==json_data_df['SRVR_NM'] and db_data_df['TR_NM']==json_data_df['TR_NM'])
	#print(db_data_df['OCR_DTM']-json_data_df['OCR_DTM'])
	
	if connection.open == True:
		db_connection("Close")
		connection.close()

	logger.info("############### main END ######################")


# The "main" entry
if __name__ == '__main__':
	sys.exit(main(sys.argv))
