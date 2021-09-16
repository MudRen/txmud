// who.c
// by Find.

#define WIZ	1
#define LONG	2
#define FAMILY	4

#include <ansi.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
int all;
mixed main(object me, string arg, int remote)
{
	string *str=({}), *option,mud_name,out,bps_string;
	object *list;
	int flag,n,i,l,bk,s_all;
	mapping mud_list;
	float *bps;

	if(arg)
	{
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i])
			{
				case "-l":
					flag |= LONG;
					break;
				case "-f":
/*
					if(!me->query("family"))
						return notify_fail("你目前没有加入任何组织！\n");
					else
*/
						flag |= FAMILY;
					break;
				case "-w":
					flag |= WIZ;
					break;
				default:
                                        if( option[i][0]=='@' )
					{
						if(!find_object(DNS_MASTER))
							return notify_fail("网路精灵并没有被载入。\n");
						mud_list = (mapping)DNS_MASTER->query_muds();
						if(!mud_list)
							return notify_fail( "本游戏目前并没有跟网路上其它游戏取得联系。\n");

						mud_name = option[i][1..];
						mud_name = htonn(mud_name);

						if(mud_name == mud_nname())
							return notify_fail("查看本游戏的在线玩家请使用 who [-l|-f|-w] 格式。\n");
						if(!mapp(mud_list[mud_name]))
							return notify_fail("未与此游戏取得联系。\n");

						RWHO_Q->send_rwho_q(mud_name, me, flag&LONG?1:0);
						write("网路讯息已送出，请稍候。\n");
						return 1;
					}
					return notify_fail("指令格式：who [-l|-f|-w]\n");
			}
	}

	bps = query_bandwide();
	bps_string = sprintf("端口进入数据流量：%.2f K/秒，送出流量：%.2f K/秒",bps[0]*8/1000, bps[1]*8/1000);
	s_all = LOGIN_D->all_online_players();

	out = sprintf("█ 网络游戏：%s\n",MUD_NAME);
	out += "—————————————————————————————————————\n";
	all = 0;
	list = filter_array(children(USER_OB),"filter_users",this_object(),me,flag);
	if(!(n=sizeof(list)))
	{
		out += "没有符合您查询条件的玩家。\n";
		out += "—————————————————————————————————————\n";
		out += sprintf("[本地时间：%s]\n",cctime(time()));
		out += sprintf("[目前共有 %d 位使用者连线中%s]\n[%s]\n\n",s_all+all,
			all?sprintf("，本站共有 %d 人",all):"",bps_string);
		if( remote )
			return out;
		else
			write(out);
		return 1;
	}

	list = sort_array(list, "sort_user", this_object());

	if(flag&LONG)
	{
		for(i=0;i<n;i++)
			out += sprintf("%12s %s%s%s\n",
				RANK_D->query_rank(list[i]),
				list[i]->short(2),
				list[i]->query_temp("netdead")?HIR+"<断线中>"+NOR:"",
				list[i]->query("env/invisibility")?"[隐身]":"");
		out += "—————————————————————————————————————\n";
		out += sprintf("[本地时间：%s]\n",cctime(time()));
		out += sprintf("[目前共有 %d 位使用者连线中%s]\n[%s]\n\n",s_all+all,
			all?sprintf("，本站共有 %d 人",all):"",bps_string);
		if( remote )
			return out;
		else
			me->start_more(out);
		return 1;
	}

	for(i=0;i<n;i++)
	{
		string item;
		item = sprintf("%s(%s)",list[i]->name(1),capitalize(list[i]->query("id")));
		if(strlen(item) > l)
			l = strlen(item);
		str += ({ item });
	}

	bk = to_int(85/(l+2));
	for(i=0;i<n;i++)
		out += sprintf("%-"+(string)l+"s  %s",str[i],(i%bk==(bk-1))||i==n-1?"\n":"");

	out += "—————————————————————————————————————\n";
	out += sprintf("[本地时间：%s]\n",cctime(time()));
	out += sprintf("[目前共有 %d 位使用者连线中%s]\n[%s]\n\n",s_all+all,
		all?sprintf("，本站共有 %d 人",all):"",bps_string);
	if( remote )
		return out;
	else
		me->start_more(out);
	return 1;
}

int filter_users(object user,object me,int flag)
{
	if(!clonep(user) || !environment(user))
		return 0;
	all++;
	if(me && !me->visible(user))
		return 0;
	/* 远端游戏不能查知本地隐身巫师 */
	if( !me && wizardp(user) && user->query("env/invisibility"))
		return 0;

	if( (flag&WIZ) && !wizardp(user))
		return 0;

	if( (flag&FAMILY)
	&& (user->query("family/family_name") != me->query("family/family_name")) )
		return 0;
	return 1;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return 1;
	
	if( wizardp(ob2) && !wizardp(ob1) ) return -1;

	if( wizardp(ob1) && wizardp(ob2) )
		return  wiz_level(ob1) - wiz_level(ob2);
	
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : who [-l|-f|-w]

这个指令可以列出所有在线上的玩家及其等级。

-l 选项列出较长的讯息。
-f 列出在线的同门玩家讯息。
-w 只列出线上所有的巫师。

用 who @ 加上远端的游戏名可以列出与本游戏
取得联系的远端游戏的在线玩家列表，远端游戏
名可由 mudlist 命令查知。

相关指令： finger	mudlist
HELP
    );
    return 1;
}
