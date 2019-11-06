#include "InsightHandle.h"
#include "BaseFunction.h"
#include "StockCode.h"
#include "trade_day.h"
#include <iostream>
#include <string>
std::string user = "MDCTest2032";
std::string password = "dfyhe._dfRFd984";
std::string ip = "218.94.125.135";
int port = 8162;
std::string cert_folder = "./cert";
std::string export_folder = "./history_data/history_TICK/";
int test_type = 1;
std::string StockCodetab_path = "./StockCode.csv";
std::string Tradeday_path = "./trade_day.csv";
const std::string start = "090000";
const std::string stop = "155959";

ClientInterface* client = NULL;
InsightHandle* handle = NULL;


/**
* ��ʼ������
*/
void test_init() {
	open_trace();//��trace�����������־��Ϣ��Ĭ�ϴ�
	open_heartbeat_trace();//��heartbeat_trace�����������־��Ϣ��Ĭ�ϴ�
	open_response_callback();//��response_callback�����д���response��Ϣ	
	//open_cout_log();
	//close_cout_log();
	//close_trace();
	//close_file_log();
	//close_heartbeat_trace();//�ر�heartbeat_trace�������������־��Ϣ
	//close_response_callback();//�ر�response_callback�������Զ�����response��Ϣ
	
}

/**
* ��¼
* @return ����ֵ true �ɹ� false ʧ��
*/
bool test_login() {
	client = ClientFactory::Instance()->CreateClient(true, cert_folder.c_str());
	if (!client) {
		error_print("create client failed!");
		ClientFactory::Uninstance();
		client = NULL;
		return false;
	}
	//ע����
	handle = new InsightHandle(export_folder);
	client->set_handle_pool_thread_count(1);
	client->RegistHandle(handle);
	//��ӱ��÷������ص�ַ
	std::map<std::string, int> backup_list;
	backup_list.insert(std::pair<std::string, int>("112.4.154.165", 8162));
	backup_list.insert(std::pair<std::string, int>("221.6.24.39", 8162));
	//backup_list.insert(std::pair<std::string, int>("153.3.219.107", 9242));
	//��¼
	int ret = client->LoginByServiceDiscovery(ip, port, user, password, false, backup_list);
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		ClientFactory::Uninstance();
		client = NULL;
		DELETE_P(handle);
		return false;
	}
	return true;
}

/**
* �˳�
*/
void test_logout() {
	ClientFactory::Uninstance();
	client = NULL;
	DELETE_P(handle);
}

/**
* ����ȫ�г�֤ȯ���ݲ�ͨ��ID�޳�����֤ȯ
* Ч�ʵͣ����Ƽ�ʹ��
*/
void test_subscribe_by_all_and_decrease() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//���� SubscribeAll
	ESubscribeActionType action_type = COVERAGE;
	std::unique_ptr<SubscribeAll> subscribe_all(new SubscribeAll());
	subscribe_all->add_marketdatatypes(MD_TICK);
	subscribe_all->add_marketdatatypes(MD_TRANSACTION);
	subscribe_all->add_marketdatatypes(MD_ORDER);
	if ((client->SubscribeAll(action_type, &(*subscribe_all)) < 0)) {
		return;
	}
	//ͨ��DECREASE���ٶ���
	action_type = DECREASE;
	std::unique_ptr<SubscribeByID> subscribe_decrease(new SubscribeByID());
	SubscribeByIDDetail* id_detail = subscribe_decrease->add_subscribebyiddetails();
	id_detail->set_htscsecurityid("000002.SZ");
	id_detail->add_marketdatatypes(MD_TICK);
	//����
	int ret = client->SubscribeByID(action_type, &(*subscribe_decrease));
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	std::cout << "input any key to quit...>>";
	char a[4096];
	std::cin >> a;
	return;
}

/**
* ����֤ȯ������Դ������������,��������ȷ����������
* ����Դ(SecurityIdSource):XSHG(����)|XSHE(����)|...������Ĭ��ȫѡ
* ֤ȯ����(SecurityType):BondType(ծ)|StockType(��)|FundType(��)|IndexType(ָ)|OptionType(��Ȩ)|...
* ��������(MarketDataTypes):MD_TICK(����)|MD_TRANSACTION(��ʳɽ�)|MD_ORDER(���ί��)|...
*/
void test_subscribe_by_source_type() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//���� SubscribeBySourceType
	ESubscribeActionType action_type = COVERAGE;
	std::unique_ptr<SubscribeBySourceType> source_type(new SubscribeBySourceType());

	//////ծȯ
	//SubscribeBySourceTypeDetail* detail_1 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_1 = new SecuritySourceType();
	//security_source_type_1->set_securityidsource(XSHG);
	//security_source_type_1->set_securitytype(BondType);
	//detail_1->set_allocated_securitysourcetypes(security_source_type_1);
	//detail_1->add_marketdatatypes(MD_TICK);

	//SubscribeBySourceTypeDetail* detail_2 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_2 = new SecuritySourceType();
	//security_source_type_2->set_securityidsource(XSHE);
	//security_source_type_2->set_securitytype(BondType);
	//detail_2->set_allocated_securitysourcetypes(security_source_type_2);
	//detail_2->add_marketdatatypes(MD_TICK);

	////��Ʊ
	SubscribeBySourceTypeDetail* detail_3 = source_type->add_subscribebysourcetypedetail();
	SecuritySourceType* security_source_type_3 = new SecuritySourceType();
	security_source_type_3->set_securitytype(StockType);
	security_source_type_3->set_securityidsource(XSHG);
	detail_3->set_allocated_securitysourcetypes(security_source_type_3);
	detail_3->add_marketdatatypes(MD_TICK);
	detail_3->add_marketdatatypes(MD_TRANSACTION);
	detail_3->add_marketdatatypes(MD_ORDER);

	SubscribeBySourceTypeDetail* detail_4 = source_type->add_subscribebysourcetypedetail();
	SecuritySourceType* security_source_type_4 = new SecuritySourceType();
	security_source_type_4->set_securityidsource(XSHE);
	security_source_type_4->set_securitytype(StockType);
	detail_4->set_allocated_securitysourcetypes(security_source_type_4);
	detail_4->add_marketdatatypes(MD_TICK);
	detail_4->add_marketdatatypes(MD_TRANSACTION);
	detail_4->add_marketdatatypes(MD_ORDER);

	//////����
	//SubscribeBySourceTypeDetail* detail_5 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_5 = new SecuritySourceType();
	//security_source_type_5->set_securityidsource(XSHG);
	//security_source_type_5->set_securitytype(FundType);
	//detail_5->set_allocated_securitysourcetypes(security_source_type_5);
	//detail_5->add_marketdatatypes(MD_TICK);
	////detail_5->add_marketdatatypes(MD_TRANSACTION);
	////detail_5->add_marketdatatypes(MD_ORDER);

	//SubscribeBySourceTypeDetail* detail_6 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_6 = new SecuritySourceType();
	//security_source_type_6->set_securityidsource(XSHE);
	//security_source_type_6->set_securitytype(FundType);
	//detail_6->set_allocated_securitysourcetypes(security_source_type_6);
	//detail_6->add_marketdatatypes(MD_TICK);
	////detail_6->add_marketdatatypes(MD_TRANSACTION);
	////detail_6->add_marketdatatypes(MD_ORDER);

	//////ָ��
	//SubscribeBySourceTypeDetail* detail_7 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_7 = new SecuritySourceType();
	//security_source_type_7->set_securityidsource(XSHG);
	//security_source_type_7->set_securitytype(IndexType);
	//detail_7->set_allocated_securitysourcetypes(security_source_type_7);
	//detail_7->add_marketdatatypes(MD_TICK);

	//SubscribeBySourceTypeDetail* detail_8 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_8 = new SecuritySourceType();
	//security_source_type_8->set_securityidsource(XSHE);
	//security_source_type_8->set_securitytype(IndexType);
	//detail_8->set_allocated_securitysourcetypes(security_source_type_8);
	//detail_8->add_marketdatatypes(MD_TICK);

	//////��Ȩ
	//SubscribeBySourceTypeDetail* detail_9 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_9 = new SecuritySourceType();
	//security_source_type_9->set_securityidsource(XSHG);
	//security_source_type_9->set_securitytype(OptionType);
	//detail_9->set_allocated_securitysourcetypes(security_source_type_9);
	//detail_9->add_marketdatatypes(MD_TICK);

	//SubscribeBySourceTypeDetail* detail_10 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_10 = new SecuritySourceType();
	//security_source_type_10->set_securityidsource(XSHE);
	//security_source_type_10->set_securitytype(OptionType);
	//detail_10->set_allocated_securitysourcetypes(security_source_type_10);
	//detail_10->add_marketdatatypes(MD_TICK);

	////�ڻ�
	//SubscribeBySourceTypeDetail* detail_11 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_11 = new SecuritySourceType();
	//security_source_type_11->set_securitytype(FuturesType);
	//detail_11->set_allocated_securitysourcetypes(security_source_type_11);
	//detail_11->add_marketdatatypes(MD_TICK);

	////�ֻ�����
	//SubscribeBySourceTypeDetail* detail_12 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_12 = new SecuritySourceType();
	//security_source_type_12->set_securitytype(SpotType);
	//detail_12->set_allocated_securitysourcetypes(security_source_type_12);
	//detail_12->add_marketdatatypes(MD_TICK);

	////����
	//SubscribeBySourceTypeDetail* detail_13 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_13 = new SecuritySourceType();
	//security_source_type_13->set_securitytype(ForexType);
	//detail_13->set_allocated_securitysourcetypes(security_source_type_13);
	//detail_13->add_marketdatatypes();

	//Ȩ֤
	//SubscribeBySourceTypeDetail* datail_14 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_14 = new SecuritySourceType();
	//security_source_type_14->set_securitytype(WarrantType);
	//security_source_type_14->set_securityidsource(XHKG);
	//datail_14->set_allocated_securitysourcetypes(security_source_type_14);
	//datail_14->add_marketdatatypes(MD_TICK);

	//����
	int ret = client->SubscribeBySourceType(action_type, &(*source_type));
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	std::cout << "input any key to quit...>>";
	char a[4096];
	std::cin >> a;
	return;
}

/**
* ����֤ȯID��Դ������������
*/
void test_subscribe_by_id() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//���� SubscribeByID
	ESubscribeActionType action_type = COVERAGE;
	std::unique_ptr<SubscribeByID> id(new SubscribeByID());
	//list1����MD_TRANSACTION��MD_ORDER
	std::vector<std::string> securityIdList1;
	securityIdList1.clear();
	securityIdList1.push_back("600031.SH");
/*	securityIdList1.push_back("000014.SZ");
	securityIdList1.push_back("000015.SZ");
	securityIdList1.push_back("000016.SZ");*/
	for (unsigned int index = 0; index < securityIdList1.size(); index++) {
		SubscribeByIDDetail* id_detail = id->add_subscribebyiddetails();
		id_detail->set_htscsecurityid(securityIdList1[index]);
		id_detail->add_marketdatatypes(MD_TICK);
		id_detail->add_marketdatatypes(MD_TRANSACTION);
	}
	//list2����MD_ORDER
	std::vector<std::string> securityIdList2;
	securityIdList2.clear();
	securityIdList2.push_back("600031.SZ");
	/*securityIdList2.push_back("000018.SZ");
	securityIdList2.push_back("000019.SZ");
	securityIdList2.push_back("000020.SZ");*/
	for (unsigned int index = 0; index < securityIdList2.size(); index++) {
		SubscribeByIDDetail* id_detail = id->add_subscribebyiddetails();
		id_detail->set_htscsecurityid(securityIdList2[index]);
		id_detail->add_marketdatatypes(MD_TICK);
		id_detail->add_marketdatatypes(MD_ORDER);
	}
	//add_globalmarketdatatypes�Ḳ�����е�������������
	//id->add_globalmarketdatatypes(MD_TRANSACTION)

	//����
	int ret = client->SubscribeByID(action_type, &(*id));
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	std::cout << "input any key to quit...>>";
	char a[4096];
	std::cin >> a;
	return;
}

/**
* ��ѯ֤ȯ�Ļ�����Ϣ/����״̬
* ��Ҫ�ر�response_callback��response��Ϣͨ����ѯ�ӿڲ�������
*/
void test_query() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//���ò�ѯ����
	std::unique_ptr<MDQueryRequest> request(new MDQueryRequest());
	//���ò�ѯ��������
	/*
	QUERY_TYPE_BASE_INFORMATION			// ��ѯ��ʷ�����е�ָ��֤ȯ�Ļ�����Ϣ(MarketDataTypes = MD_CONSTANT)
	QUERY_TYPE_LATEST_BASE_INFORMATION	// ��ѯ�������µ�ָ��֤ȯ�Ļ�����Ϣ(MarketDataTypes = MD_CONSTANT)
	QUERY_TYPE_STATUS					// ��ѯָ��֤ȯ������һ��Tick����(MarketDataTypes = MD_TICK)
	QUERY_TYPE_ETF_BASE_INFORMATION    //��ѯETF�Ļ�����Ϣ(MarketDataTypes = MD_ETF_BASICINFO)
	*/
	request->set_querytype(QUERY_TYPE_LATEST_BASE_INFORMATION);
	request->add_securitysourcetype()->set_securityidsource(XSHE);
	request->add_securitysourcetype()->set_securitytype(IndexType);
	request->add_htscsecurityids("601688.SH");

	//���ղ�ѯ�ظ�
	std::vector<MDQueryResponse*>* responses;
	//���Ͳ�ѯ���󲢽��ջظ���Ϣ
	int ret = client->RequestMDQuery(&(*request), responses);
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}

	//����responses����Ա���£�
	/*
	int32 queryType;             	     //��ѯ����
	bool isSuccess;                    // �����Ƿ�ɹ�
	InsightErrorContext errorContext;  // ������Ϣ
	MarketDataStream marketDataStream; //�������ݰ�
	*/
	debug_print("query return message count=%d\n\n\n", responses->size());
	//�����ѯ���
	for (unsigned int i = 0; i < responses->size(); ++i) {
		if (!responses->at(i)->issuccess()) {
			continue;
		}
		if (!responses->at(i)->has_marketdatastream()) {
			continue;
		}
		//����constants
		google::protobuf::RepeatedPtrField<MarketData>::const_iterator it
			= responses->at(i)->marketdatastream().marketdatalist().marketdatas().begin();
		google::protobuf::RepeatedPtrField<MarketData>::const_iterator end
			= responses->at(i)->marketdatastream().marketdatalist().marketdatas().end();
		while (it != end) {
			handle->OnMarketData(*it);
			it++;
		}
	}
	//�ͷſռ�
	client->ReleaseQueryResult(responses);
	return;
}

/**
* ��ѯ֤ȯ�Ļ�����Ϣ/����״̬
* ��Ҫ��response_callback��response��Ϣͨ���ص���������
*/
void test_query_callback() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//���ò�ѯ����
	std::unique_ptr<MDQueryRequest> request(new MDQueryRequest());
	//���ò�ѯ��������
	/*
	QUERY_TYPE_BASE_INFORMATION			// ��ѯ��ʷ�����е�ָ��֤ȯ�Ļ�����Ϣ(MarketDataTypes = MD_CONSTANT)
	QUERY_TYPE_LATEST_BASE_INFORMATION	// ��ѯ�������µ�ָ��֤ȯ�Ļ�����Ϣ(MarketDataTypes = MD_CONSTANT)
	QUERY_TYPE_STATUS					// ��ѯָ��֤ȯ������һ��Tick����(MarketDataTypes = MD_TICK)
	QUERY_TYPE_ETF_BASE_INFORMATION    //��ѯETF�Ļ�����Ϣ(MarketDataTypes = MD_ETF_BASICINFO)
	*/
	request->set_querytype(QUERY_TYPE_BASE_INFORMATION);
	SecuritySourceType* source_type = request->add_securitysourcetype();
	source_type->set_securitytype(StockType);
	source_type->set_securityidsource(XSHG);

	handle->query_exit_ = false;
	//���Ͳ�ѯ����
	int ret = client->RequestMDQuery(&(*request));
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	
	while (true) {
		if (handle->query_exit_) {
			break;
		}
		else{
			msleep(1);
		}		
	}
}

/**
* ������ʷ����ز⣬���λز���������������������û�ʹ���ֲ�
*/
void test_playback(std::string& stcode, std::string& tdate) {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//request ��Ҫ��ǰ����ռ䣬���ɵ��÷��ͷ�
	std::unique_ptr<PlaybackRequest> request(new PlaybackRequest());
	std::string starttime(tdate);
	std::string stoptime(tdate);
	starttime.insert(8, start);
	stoptime.insert(8, stop);
/*	starttime.append("090000");
	stoptime.append("155959");*/
	//std::cout << starttime + "090000" << std::endl;
	//���ûط�����ţ���������
	request->set_taskid(get_task_id(""));
	//StockCode stcode_tab(StockCodetab_path);
//	vector < vector <string>> fieldss = stcode_tab.getfieldss();
	//string stcode;
	//int i = 1;
/*	for(vector < vector <string>>::iterator it = fieldss.begin()+1; it != fieldss.end(); it++,i++)
	{
		stcode = (*it)[0];
		std::cout<< stcode << endl;*/
	request->add_htscsecurityids(stcode);
		/*if((i % 10 == 0) || (it+1 == fieldss.end()))
		{
			std::cout<<"i = "<<i<<endl;
			int ret = client->RequestPlayback(&(*request));
			if (ret != 0) {
				error_print("%s", get_error_code_value(r	std::cout << tdate << std::endl;
	std::cout << "090000" << std::endl;et).c_str());
				return;
			}

			handle->service_value_ = 0;
			while (1) {
				if (handle->service_value_ == CANCELED || handle->service_value_ == COMPLETED || handle->service_value_ == FAILED) {
					debug_print("receive playback end message, quit...");
					break;
				}
				else {
					msleep(1000);
				}
			}
			request.release();*/

	//		std::unique_ptr<MDQueryRequest> request(new MDQueryRequest());
		request->set_replaydatatype(MD_TICK);                //枚举见数据手册7.8
		request->set_exrightstype(NO_EXRIGHTS);

		request->set_starttime(starttime);
		request->set_stoptime(stoptime);
//		}

//	}
//	stcode = fieldss[5][0];
	//cout << fieldss[5][0];
	//===================================================
	// �����õĲ�������֤ȯid��֤ȯ�г���
	//===================================================
	//��д֤ȯid����������г��ǲ���
	//request->add_htscsecurityids(stcode);

	//��д�г���֤ȯ���ͣ�type1��type2�ǲ���
/*	SecuritySourceType* type1 = request->add_securitysourcetype();
	type1->set_securitytype(StockType);
	type1->set_securityidsource(XSHE);*/

//	SecuritySourceType* type2 = request->add_securitysourcetype();
//	type2->set_securitytype(StockType);
//	type2->set_securityidsource(XSHG);

	//���ͻط�����
	int ret = client->RequestPlayback(&(*request));
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	//��ѯ�ط�״̬ EPlaybackTaskStatus
	/*
	INITIALIZING = 11            // ��ʼ����
	PREPARING = 12               // ׼����
	PREPARED = 13				 // ׼�����
	RUNNING = 14				 // ������
	APPENDING = 15               // ���еȴ���
	CANCELED = 16                // ��ȡ��
	COMPLETED = 17               // �����
	FAILED = 18                  // ����ʧ��
	*/
	handle->service_value_ = 0;
	while (1) {
		if (handle->service_value_ == CANCELED || handle->service_value_ == COMPLETED || handle->service_value_ == FAILED) {
			debug_print("receive playback end message, quit...");
			break;
		}
		else {
			msleep(1000);
		}
	}
	return;
}

/**
* ���лطŵ������ݣ�ʹ����Ҫ����Ȩ��
*/
void test_playbackToday() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	std::vector<std::string> idList;
	idList.push_back("601688.SH");
	idList.push_back("000001.SZ");

	int ret = client->RequestPlayback(idList, "20190523093000", "20190523103000", MD_KLINE_1MIN, NO_EXRIGHTS);
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	//��ѯ�ط�״̬ EPlaybackTaskStatus
	/*
	INITIALIZING = 11            // ��ʼ����
	PREPARING = 12               // ׼����
	PREPARED = 13				 // ׼�����
	RUNNING = 14				 // ������
	APPENDING = 15               // ���еȴ���
	CANCELED = 16                // ��ȡ��
	COMPLETED = 17               // �����
	FAILED = 18                  // ����ʧ��
	*/
	handle->service_value_ = 0;
	while (1) {
		if (handle->service_value_ == CANCELED || handle->service_value_ == COMPLETED || handle->service_value_ == FAILED) {
			debug_print("receive playback end message, quit...");
			break;
		}
		else {
			msleep(1000);
		}
	}
	return;

}

int main(int argc, char** argv)
{
	printf("\n=======================================================================\n");
	printf("usage: cmd user password ip port cert_folder export_folder test_type\n");
	printf("test_typ(0 test_subscribe_by_all_and_decrease \n");
	printf("test_typ(1 test_subscribe_by_source_type \n");
	printf("test_typ(2 test_subscribe_by_id \n");
	printf("test_typ(3 test_query \n");
	printf("test_typ(4 test_playback \n");
	printf("test_typ(5 test_playback_today \n");
	printf("=========================================================================\n\n");
	if (argc >= 2) {
	/*	user = argv[1];
		password = argv[2];
		ip = argv[3];
		port = atoi(argv[4]);
		cert_folder = argv[5];*/
	//	export_folder = argv[1];
		test_type = atoi(argv[1]);
	}
	//������ʼ������������
	open_file_log();	
	init_env();	
	test_init();
	//��¼
	if (!test_login()) {
		return 0;
	}
	switch (test_type)
	{
	case 0: {
		test_subscribe_by_all_and_decrease();
		break;
	}
	case 1: {
		test_subscribe_by_source_type();
		break;
	}
	case 2: {
		test_subscribe_by_id();
		break;
	}
	case 3: {
		test_query_callback();
		break;
	}
	case 4: {
		Trade_day tradeday(Tradeday_path);
		StockCode stcode_tab(StockCodetab_path);
		vector < vector <string>> fieldss = stcode_tab.getfieldss();
		vector < string > tradefields = tradeday.getfields();
		string tdate, tdatefile;
		string stcode;
		for(vector < string >::iterator i = tradefields.begin(); i != tradefields.end(); i++)
		{
			tdate = *i;
			tdate = tradeday.Trim(tdate);
			tdatefile = export_folder + tdate.c_str();
			handle->UpdateBash_forder(tdatefile);
			for(vector < vector <string>>::iterator it = fieldss.begin()+1; it != fieldss.end(); it++)
			{
				stcode = (*it)[0];
				test_playback(stcode, tdate);
			}
		}
		break;
	}
	case 5: {
		test_playbackToday();
		break;
	}
	default:
		break;
	}
	test_logout();
	fini_env();
}
