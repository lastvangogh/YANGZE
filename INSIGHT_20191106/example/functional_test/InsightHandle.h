#ifndef INSIGHTHANDLE_H
#define INSIGHTHANDLE_H
#include "BaseFunction.h"

#include "base_define.h"
#include "mdc_client_factory.h"
#include "client_interface.h"
#include "message_handle.h"

using namespace com::htsc::mdc::gateway;
using namespace com::htsc::mdc::model;
using namespace com::htsc::mdc::insight::model;

//���԰洦����
class InsightHandle : public MessageHandle {
public:
	/**
	* ���캯��
	*/
	InsightHandle(const std::string& forder_name) :base_forder_(forder_name), service_value_(0), query_exit_(false),
		reconnect_(false), login_success_(false), reconnect_count_(0), no_connections_(false) {
		//��֤����Ŀ¼������������򴴽�����Ŀ¼
		if (!folder_exist(base_forder_.c_str())) {
			debug_print("input folder[%s] not exists!\n", base_forder_.c_str());
			if (!create_folder(base_forder_)) {
				error_print("mkdir base folder[%s] failed! maybe exists!\n", base_forder_.c_str());
			} else {
				debug_print("mkdir base folder[%s] successfully!\n", base_forder_.c_str());
			}
		}
	}

	/**
	* ��������
	*/
	virtual ~InsightHandle() {}

public:
	/**
	* ���Ͷ�����������˻ظ���Ϣ���鿴�Ƿ��ĳɹ�
	* @param[in] data_stream
	*/
	void OnServiceMessage(const ::com::htsc::mdc::insight::model::MarketDataStream& data_stream) {
		debug_print("==========> NewHandle: process a Service message");
		service_value_ = 1;
	}

	/**
	* �����ĺ����͵�ʵʱ��������
	* @param[in] data
	*/
	void OnMarketData(const com::htsc::mdc::insight::model::MarketData& data) {
		static unsigned int count = 0;
		++count;
		if (count % 10000 == 0) {
			debug_print("==========> NewHandle: process %d MarketData message", count);
		}
		//��ȡ��������
		std::string data_type = get_data_type_name(data.marketdatatype());
		switch (data.marketdatatype()) {
		case MD_TICK:
		{//����
			if (data.has_mdstock()) {//��Ʊ
				//��ȡ֤ȯ����
				std::string security_type = get_security_type_name(data.mdstock().securitytype());
				//д�ļ�
				save_debug_string(base_forder_, data_type, security_type,
					data.mdstock().htscsecurityid(), data.mdstock().ShortDebugString());
				//���ʹ�Ʊ���ݲ����ֶ�
				if (false) {
					MDStock stock = data.mdstock();
					debug_print("证券代码 : %s", stock.htscsecurityid().c_str());
					debug_print("交易日期 : %d", stock.mddate());
					debug_print("交易时间 : %d", stock.mdtime());
					debug_print("成交价格 : %d", stock.lastpx());
					//���ʶ���(queue)���ݷ�ʽ
					for (int i = 0; i < stock.buypricequeue_size(); i++) {
						debug_print("买%d价格 : %d", i + 1, stock.buypricequeue(i));
					}
					for (int i = 0; i < stock.sellpricequeue_size(); i++) {
						debug_print("卖%d价格 : %d", i + 1, stock.sellpricequeue(i));
					}
				}
			} else if (data.has_mdbond()) {//ծȯ
				std::string security_type = get_security_type_name(data.mdbond().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdbond().htscsecurityid(), data.mdbond().ShortDebugString());
			} else if (data.has_mdindex()) {//ָ��
				std::string security_type = get_security_type_name(data.mdindex().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdindex().htscsecurityid(), data.mdindex().ShortDebugString());
			} else if (data.has_mdfund()) {//����
				std::string security_type = get_security_type_name(data.mdfund().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdfund().htscsecurityid(), data.mdfund().ShortDebugString());
			} else if (data.has_mdoption()) {//��Ȩ
				std::string security_type = get_security_type_name(data.mdoption().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdoption().htscsecurityid(), data.mdoption().ShortDebugString());
			} else if (data.has_mdfuture()) {//�ڻ�
				std::string security_type = get_security_type_name(data.mdfuture().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdfuture().htscsecurityid(), data.mdfuture().ShortDebugString());
			} else if (data.has_mdforex()) {//���
				std::string security_type = get_security_type_name(data.mdforex().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdforex().htscsecurityid(), data.mdforex().ShortDebugString());
			} else if (data.has_mdspot()) {//�ֻ�
				std::string security_type = get_security_type_name(data.mdspot().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdspot().htscsecurityid(), data.mdspot().ShortDebugString());
			} else if (data.has_mdwarrant()) {//Ȩ֤
				std::string security_type = get_security_type_name(data.mdwarrant().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdwarrant().htscsecurityid(), data.mdwarrant().ShortDebugString());
			}
			break;
		}
		case MD_TRANSACTION:
		{//��ʳɽ�
			if (data.has_mdtransaction()) {
				std::string security_type = get_security_type_name(data.mdtransaction().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdtransaction().htscsecurityid(), data.mdtransaction().ShortDebugString());
			}
			break;
		}
		case MD_ORDER:
		{//���ί��
			if (data.has_mdorder()) {
				std::string security_type = get_security_type_name(data.mdorder().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdorder().htscsecurityid(), data.mdorder().ShortDebugString());
			}
			break;
		}
		case MD_CONSTANT:
		{//��̬��Ϣ
			if (data.has_mdconstant()) {
				std::string security_type = get_security_type_name(data.mdconstant().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdconstant().htscsecurityid(), data.mdconstant().ShortDebugString());
			}
		}
		case MD_KLINE_15S:
		case MD_KLINE_1MIN:
		case MD_KLINE_5MIN:
		case MD_KLINE_15MIN:
		case MD_KLINE_30MIN:
		case MD_KLINE_60MIN:
		case MD_KLINE_1D:
		{//ʵʱ����ֻ�ṩ15S��1MIN K��
			if (data.has_mdkline()) {
				std::string security_type = get_security_type_name(data.mdkline().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdkline().htscsecurityid(), data.mdkline().ShortDebugString());
			}
			break;
		}
		case MD_TWAP_1MIN:
		{//TWAP����
			if (data.has_mdtwap()) {
				std::string security_type = get_security_type_name(data.mdtwap().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdtwap().htscsecurityid(), data.mdtwap().ShortDebugString());
			}
			break;
		}
		case MD_VWAP_1MIN:
		case MD_VWAP_1S:
		{//VWAP����
			if (data.has_mdvwap()) {
				std::string security_type = get_security_type_name(data.mdvwap().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdvwap().htscsecurityid(), data.mdvwap().ShortDebugString());
			}
			break;
		}
		case AD_FUND_FLOW_ANALYSIS:
		{//�ʽ������������
			if (data.has_mdfundflowanalysis()) {
				std::string security_type = get_security_type_name(data.mdfundflowanalysis().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdfundflowanalysis().htscsecurityid(), data.mdfundflowanalysis().ShortDebugString());
			}
			break;
		}
		case MD_ETF_BASICINFO:
		{//ETF�Ļ�����Ϣ
			if (data.has_mdetfbasicinfo()) {
				std::string security_type = get_security_type_name(data.mdetfbasicinfo().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdetfbasicinfo().htscsecurityid(), data.mdetfbasicinfo().ShortDebugString());
			}
		}
		case AD_ORDERBOOK_SNAPSHOT:
		{
			if (data.has_orderbooksnapshot()) {
				std::string security_type = get_security_type_name(data.orderbooksnapshot().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.orderbooksnapshot().htscsecurityid(), data.orderbooksnapshot().ShortDebugString());
			}
		}
		default:
			break;
		}
	}

	/**
	* ����ز�����ɹ������͵Ļز�����
	* @param[in] PlaybackPayload �ز�����
	*/
	void OnPlaybackPayload(const PlaybackPayload& payload) {
		service_value_ = 4;
		debug_print("------- PARSE message Playback payload, id:%s", payload.taskid().c_str());
		const MarketDataStream& stream = payload.marketdatastream();
		debug_print("total number=%d, serial=%d, isfinish=%d", stream.totalnumber(), stream.serial(), stream.isfinished());
		google::protobuf::RepeatedPtrField<MarketData>::const_iterator it
			= stream.marketdatalist().marketdatas().begin();
		while (it != stream.marketdatalist().marketdatas().end()) {
			OnMarketData(*it);
			++it;
		}
	}

	/**
	* ����ز�״̬
	* @param[in] PlaybackStatus �ز�״̬
	*/
	void OnPlaybackStatus(const com::htsc::mdc::insight::model::PlaybackStatus& status) {
		debug_print("===========> NewHandle playback status=%d", status.taskstatus());
		service_value_ = status.taskstatus();
	}

	/**
	* �����ѯ���󷵻ؽ��
	* @param[in] MDQueryResponse ��ѯ���󷵻ؽ��
	*/
	void OnQueryResponse(const ::com::htsc::mdc::insight::model::MDQueryResponse& response) {
		if (!response.issuccess()) {
			error_print("query response result: FAIL! ERROR INFO[%d,%s]",
				response.errorcontext().errorcode(), response.errorcontext().message().c_str());
			query_exit_ = true;
			return;
		} else {
			const MarketDataStream& stream = response.marketdatastream();
			debug_print("query response total number=%d, serial=%d, isfinish=%d",
				stream.totalnumber(), stream.serial(), stream.isfinished());
			if (stream.isfinished() == 1) {
				query_exit_ = true;
			}
			google::protobuf::RepeatedPtrField<MarketData>::const_iterator it
				= stream.marketdatalist().marketdatas().begin();
			while (it != stream.marketdatalist().marketdatas().end()) {
				OnMarketData(*it);
				++it;
			}
		}
	}

	/**
	* ��¼�ɹ�
	*/
	void OnLoginSuccess() {
		debug_print("-----------------------------");
		debug_print("------- OnLoginSuccess -------");
		login_success_ = true;
		debug_print("-----------------------------");
	}

	/**
	* ��¼ʧ��
	*/
	void OnLoginFailed(int error_no, const std::string& message) {
		error_print("-----------------------------");
		error_print("------- OnLoginFailed -------");
		login_success_ = false;
		error_print("------- server reply:%d,%s", error_no, message.c_str());
		error_print("-----------------------------");
	}

	/**
	* �������з��������޷����ӵ����
	*/
	void OnNoConnections() {
		error_print("-----------------------------");
		error_print("------- OnNoConnections -----");
		no_connections_ = true;
		reconnect_ = true;
		error_print("-----------------------------");
	}

	/**
	* ��������ʱ
	*/
	void OnReconnect() {
		error_print("-----------------------------");
		error_print("------- OnReconnect -----");
		++reconnect_count_;
		reconnect_ = true;
		error_print("-----------------------------");
	}
	void UpdateBash_forder(std::string& forder_name)
	{
		base_forder_ = forder_name;
		if (!folder_exist(base_forder_.c_str())) {
			debug_print("input folder[%s] not exists!\n", base_forder_.c_str());
			if (!create_folder(base_forder_)) {
				error_print("mkdir base folder[%s] failed! maybe exists!\n", base_forder_.c_str());
			}
			else {
				debug_print("mkdir base folder[%s] successfully!\n", base_forder_.c_str());
			}
		}
	}

public:
	int service_value_;
	bool query_exit_;
	bool reconnect_;
	bool login_success_;
	bool no_connections_;
	int reconnect_count_;
	std::string base_forder_; //����Ŀ¼
};

#endif
