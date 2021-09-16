// mail_q.c
// for intermud mail, work with MAILBOX_OB.

// By Find (11/25/98)

#include <ansi.h>
#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>
#include <net/config.h>

#define RESEND_TIME	180

inherit F_DBASE;

private static mixed *wait_alignment;	// �����ʼ����С������Ͷ���sigh��

void create() { seteuid(ROOT_UID); }

void send_msg(mapping mail,int wiz_broadcast)
{
	mapping minfo;
	string *list,*lost_mud = ({});
	object ob;
	int i;
	mixed temp_mail;

	if(base_name(previous_object()) != MAILBOX_OB)
		return;

	if( wiz_broadcast )
	{
		list = keys( LISTNODES );
		for(i=0;i<sizeof(list);i++)
		{
			list[i] = htonn( list[i] );
			minfo = (mapping)DNS_MASTER->query_mud_info(list[i]);
			if(!minfo)
			{
				if(ob = find_player(mail["fromid"]))
				tell_object(ob,list[i]+" վ��ʱ�޷���ͨ���Ժ��ʼ�������Զ�Ϊ�����վ�ط���\n");
				lost_mud += ({ list[i] });
				continue;
			}
			if(ob = find_player(mail["fromid"]))
			tell_object(ob,"��·�ʼ����� " + list[i] + " վ���ͳ���\n");

			DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
				"@@@" + DNS_MAIL_Q +
				"||NAME:" + Mud_name() +
				"||PORTUDP:" + udp_port() +
				"||WIZARDALL:1" +	// ������ ID Ϊ "all" ����ҡ�
				"||MAILTO:" + mail["to"] +
				"||MAILFROM:" + mail["otherfrom"] +
				"||FROMID:" + mail["fromid"] +
				"||TITLE:" + mail["title"] +
				"||TEXT:"+ mail["text"] +"@@@\n");
		}

		if(sizeof(lost_mud))
		{
			if(find_call_out("resend_mail") == -1)
			{
				call_out("resend_mail",RESEND_TIME,mail,lost_mud);
				if(ob = find_player(mail["fromid"]))
				tell_object(ob,HIG "�������ʼ����顿���Զ��ط�����������\n" NOR);
				return;
			}
			temp_mail["mail"] = mail;
			temp_mail["lost_mud"] = lost_mud;
			wait_alignment += ({ temp_mail });
			if(ob = find_player(mail["fromid"]))
				tell_object(ob,HIG "�������ʼ����顿�������ʼ������������ʼ��������ʼ����ڵ�"+
					chinese_number(sizeof(wait_alignment))+"λ��\n" NOR);
			return;
		}

		if(ob = find_player(mail["fromid"]))
			tell_object(ob,"ok.\n");
	}

	minfo = (mapping)DNS_MASTER->query_mud_info(mail["to_mud"]);

	if(!minfo)
	{
		if(ob = find_player(mail["fromid"]))
			tell_object(ob,"�Է���Ϸ��ʱ�޷��������ݣ����Ժ��ٷ���\n");
		return;
	}

	if(ob = find_player(mail["fromid"]))
		tell_object(ob,"��·�ʼ����ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");

	DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
		"@@@" + DNS_MAIL_Q +
		"||NAME:" + Mud_name() +
		"||PORTUDP:" + udp_port() +
		"||MAILTO:" + mail["to"] +
		"||MAILFROM:" + mail["from"] +
		"||FROMID:" + mail["fromid"] +
		"||TITLE:" + mail["title"] +
		"||TEXT:"+ mail["text"] +"@@@\n");

	return;
}

void incoming_request(mapping info)
{
	string id;
	object target,user,mbx;
	mapping minfo,mail;

	if(!ACCESS_CHECK(previous_object()))
		return;

	if (!info["NAME"] || !info["PORTUDP"])
		return;

	if (info["NAME"] == Mud_name())
		return ;

	minfo = DNS_MASTER->query_mud_info(info["NAME"]);
	if(!minfo || !DNS_MASTER->dns_mudp(info["NAME"]))
		PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

	if (minfo && minfo["HOSTADDRESS"] != info["HOSTADDRESS"])
	{
		// Its been faked! 
		dns_log("dns_fake", "Emotefrom: "+info["EMOTEFROM"]+"@"+info["NAME"]+
			"("+info["HOSTADDRESS"]+") Emoteto "+info["EMOTETO"]
			+" "+ info["MSG"]+"\n");
		DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
			"@@@"+DNS_WARNING+
			"||MSG: Faked gemote message "+info["WIZFROM"]+
			"@"+info["NAME"]+"> "+info["EMOTETO"]+
			" "+info["MSG"]+
			"||FAKEHOST:"+info["HOSTADDRESS"]+
			"@@@\n");
		return ;
	}

	if(!undefinedp(info["WIZARDALL"]))
	{
		string *list;
		int i;

		list = sort_array(SECURITY_D->query_wizlist(), 1);
		for(i=0;i<sizeof(list);i++)
		{
			mail = ([
			"from": info["MAILFROM"],
		        "title": info["TITLE"],
                	"to": list[i],
			"time": time(),
			"text": info["TEXT"]
			]);
			MAILBOX_OB->send_mail(mail["to"], mail);
		}
		return;
	}

	id = info["MAILTO"];
	target = FINGER_D->acquire_login_ob(id);

	if(!target)
	{
		(AUX_PATH+"affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
		info["PORTUDP"], "intermail@"+Mud_name(),
		info["FROMID"], "û�������Ҵ��ڡ�\n", "mail");
		return;
	}

	target->set("new_mail", 1);
	target->save();

	mail = ([
                "from": info["MAILFROM"],
                "title": info["TITLE"],
                "to": id,
                "time": time(),
                "text": info["TEXT"]
        ]);

	user = find_player(id);
	if(user)
	{
		int flag = 0;
		mbx = user->query_temp("mbox_ob");

		if( !mbx )
		{
		flag = 1;
                mbx = new(MAILBOX_OB);
                mbx->set_owner(id);
		}
		mbx->receive_mail(mail);
		if(flag)
			mbx->move(user);
		tell_object(user,HIG"\n�ʲ���������ǰ˵����������һ���ţ����պá���  ת���ֲ�����...\n\n"NOR);
	}

	else
	{
		mbx = new(MAILBOX_OB);
		mbx->set_owner(id);
		mbx->receive_mail(mail);
		destruct(mbx);
		destruct(target);
	}

	(AUX_PATH+"affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
		info["PORTUDP"], "intermail@"+Mud_name(),
		info["FROMID"], id+" ���յ����㷢���ʼ���\n", "mail");
	return;
}

void resend_mail(mapping mail,string *lost_mud)
{
	mapping minfo;
	object ob;
	int i;
	string *sent_mud = ({});

	remove_call_out("resend_mail");
	for(i=0;i<sizeof(lost_mud);i++)
	{
		minfo = (mapping)DNS_MASTER->query_mud_info(lost_mud[i]);
		if(!minfo) continue;
		
		DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
			"@@@" + DNS_MAIL_Q +
			"||NAME:" + Mud_name() +
			"||PORTUDP:" + udp_port() +
			"||WIZARDALL:1" +
			"||MAILTO:" + mail["to"] +
			"||MAILFROM:" + mail["otherfrom"] +
			"||FROMID:" + mail["fromid"] +
			"||TITLE:" + mail["title"] +
			"||TEXT:"+ mail["text"] +"@@@\n");

		if(ob = find_player(mail["fromid"]))
			tell_object(ob,"��·�ʼ����� " + lost_mud[i] + " վ���ͳ���\n");

		sent_mud += ({ lost_mud[i] });
	}

	if(sizeof(sent_mud))
		lost_mud -= sent_mud;

	if(!sizeof(lost_mud))
	{
		if(ob = find_player(mail["fromid"]))
			tell_object(ob,"������·�ʼ���ȫ��������ϡ�\n");
		if(!sizeof(wait_alignment))
			return;
		else
		{
			call_out("resend_mail",RESEND_TIME,wait_alignment[0]["mail"],
				wait_alignment[0]["lost_mud"]);
			wait_alignment -= wait_alignment[0];
		}
	}

	else
		call_out("resend_mail",RESEND_TIME,mail,lost_mud);
}