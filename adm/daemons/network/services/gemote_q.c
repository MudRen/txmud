// gemote_q.c
// for intermud emote

// by By Find (11/25/98)

#undef DEBUG
#define NO_VERB		"No this emote"
#define NO_ACTION	"No this action"

#include <ansi.h>
#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

void create() { seteuid(ROOT_UID); }

int send_msg(object me,string vb,string remote_user,string mud,string verb)
{
	mapping minfo;
	string msg;

	if(!ACCESS_CHECK(previous_object()))
		return 0;

	mud = htonn( mud );

	if(mud == mud_nname() || !geteuid(me))
		return 0;

	minfo = (mapping)DNS_MASTER->query_mud_info(mud);

	if(!minfo)
	{
		tell_object(me,"δ�����Ϸ��ͨ��\n");
		return 1;
	}

	msg = EMOTE_D->query_intermud_emote(me,vb);

	if( msg == NO_VERB )
	{
		tell_object(me,CYN"û�ж������ emote��\n"NOR);
		return 1;
	}

	if( msg == NO_ACTION )
	{
		tell_object(me,CYN"û�ж����������.:)\n"NOR);
		return 1;
	}

	tell_object(me,"��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");

	msg = replace_string(msg, "|", "");
	msg = replace_string(msg, "@@@", "");

	DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
		"@@@" + DNS_GEMOTE_Q +
		"||NAME:" + Mud_name() +
		"||PORTUDP:" + udp_port() +
		"||EMOTETO:" + remote_user +
		"||TONAME:0" +
		"||EMOTEFROM:" + geteuid(me) +
		"||CNAME:" + me->name(1) +
		"||CHANNEL:" + verb +
		"||MSG:"+msg+"@@@\n");

#ifdef DEBUG
	set("channel_id", "���� EMOTE �Դ���");
	CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("EMOTEFROM: (%s) EMOTETO (%s) CHANNEL (%s) to_mud (%s).",
		geteuid(me),remote_user,verb,mud));
#endif

	return 1;
}

void incoming_request(mapping info)
{
	string str,id,msg;
	object target;
	mapping minfo;

	if(!ACCESS_CHECK(previous_object()))
		return;

	if (!info["NAME"] || !info["PORTUDP"])
		return;

	if (info["NAME"] == Mud_name())
		return ;

	//����fake���.
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

#ifdef DEBUG
	set("channel_id", "���� EMOTE �Դ���");
	CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("Receive a emote request from (%s),EMOTEFROM (%s) EMOTETO (%s) CHANNEL (%s).",
		info["NAME"],info["EMOTEFROM"],info["EMOTETO"],info["CHANNEL"]));
#endif

	id = info["EMOTETO"];
	target = find_player(id);

	if(!target)
	{
		(AUX_PATH+"affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
		info["PORTUDP"], "Gemote@"+Mud_name(),
		info["EMOTEFROM"], "û�������ҡ�\n", "gemote");
		return;
	}

	msg = info["MSG"];
/*
	msg = replace_string(msg, "$C", RANK_D->query_self_close(target));
	msg = replace_string(msg, "$c", RANK_D->query_close(target));
	msg = replace_string(msg, "$R", RANK_D->query_respect(target));
	msg = replace_string(msg, "$r", RANK_D->query_rude(target));
*/
	msg = replace_string(msg, "$p", gender_pronoun(target->query("gender")));

	str = replace_string(msg,"$n",target->name());

	str = replace_string(str,"$N",sprintf("%s(%s@%s)", info["CNAME"], capitalize(info["EMOTEFROM"]), info["NAME"]));

#ifdef DEBUG
	set("channel_id", "���� EMOTE �Դ���");
	CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("Receive a emote request from (%s),find player (%s).",
		info["NAME"],info["EMOTETO"]));
#endif

	set("channel_id", sprintf("%s(%s@%s)", info["CNAME"], info["EMOTEFROM"], info["NAME"]));
	CHANNEL_D->do_channel(this_object(), lower_case(info["CHANNEL"]),str,1);

	str = replace_string(str, "|", "");
	str = replace_string(str, "@@@", "");
	DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
	"@@@" + DNS_GEMOTE_A +
	"||NAME:" + Mud_name() +
	"||PORTUDP:" + udp_port() +
	"||EMOTETO:" + info["EMOTETO"] +
	"||TONAME:" + target->name() +
	"||EMOTEFROM:" + info["EMOTEFROM"] +
	"||CNAME:" + info["CNAME"] +
	"||CHANNEL:" + info["CHANNEL"] +
	"||MSG:"+msg+"@@@\n");

	return;
}
