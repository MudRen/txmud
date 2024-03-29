// 玩家房屋物件。level two.
// by 发现号(Find).

// 等级 2， 瓦房.

#define HOME_DIR	"/d/phome/"
#define CAN_SAVE_OBJECT	7	// 此房屋可以保存的物品数量。
#define MAX_FUR		3
#define WORN_TIME	525600	/* MUD 中一年，超过此时间房屋变旧 */
#define BREAKDOWN_TIME	1051200 /* MUD 中两年，超过此时间房屋倒塌 */

#include <room.h>
inherit ROOM;
inherit F_SAVE;

class s_ob
{
	string file;
	mixed arg;
}

protected class s_ob *save_objs;

void get_long(string str, string text);
int home_level() { return 2; }	//房屋等级。
int is_player_home() { return 1; }
string home_master() { return query("master_name"); }

class s_ob *query_save_objs()
{
	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return 0;

	return save_objs;
}

void create()
{
	if(!restore())
	{
	set("short", "如水的瓦房");
	set("long", @LONG
这里是一间的大瓦房。
·你可以用 changelong 命令改变你的家的描述。
·<<郑重提醒：出入房屋请把门锁好，否则任何人均可随意
  出入你的房屋拿走你的保存物品，您的钥匙请不要轻易交
  给别人>>。
·要配钥匙可以去铁匠铺 (pei key) 。
·此房屋里可以收藏 7 件物品。
  请用 baocun 命令保存
  list 命令可列出你房间内已保存的物品
  quzou 命令可以拿走保存的物品。
·check 房主检查房屋状态命令
·您的房屋要定期进行修缮，长时间不修缮房屋会倒塌。
·房屋修缮归户部的工程队管理。如您一段时间无法来修缮
  可以去户部预交(pay)修缮费，工程队会按时给您来维护房
  屋。
·如您一时周转不灵，可以把您的房屋向银行、钱庄抵押，
  在抵押期间您一样可以使用维护，但过期不赎将被没收。
·添置家具可以去家具商店看看。买好了家具可以放置
  (fangzhi)在你的家里。家具以后如果你不想要了也可以
  把它搬走(banzou)。

祝您生活愉快！！
LONG
);
}

	set(SAFE_ENV,1);
	set("master_id","rushui");	// 房主的 ID。
	set("master_name","如水"); // 房主的中文名。
	set("valid_startroom", 1);
	set("exits",([
	"west"  : "/d/path1/cc_tch1",
	]));

	call_out("check_room",1);
	setup();
        create_door("west", "木门", "east", DOOR_CLOSED,LOCKED,__DIR__"rushui_key");

}

string query_save_file()
{
	return HOME_DIR+"path1/rushui_home_data";
}

void check_room()
{
	if(!query("built_time"))
	{
		set("built_time", time());
		return;
	}
	PLAYERHOME_D->check_player_room(this_object());
}

void init()
{
	add_action("do_changelong","changelong");
	add_action("do_baocun","baocun");
	add_action("do_list","list");
	add_action("do_quzou","quzou");
	add_action("do_save","save");
	add_action("do_fangzhi","fangzhi");
	add_action("do_banzou","banzou");
	add_action("do_check", "check");
}


int do_check(string arg)
{
	object me = this_player();
	int time, btime,des, tmp;
	string out;
	mapping bank;

	if( (me->query("id") != query("master_id"))
	&& !wizardp(me) )
		return 0;

	time = time();
	out = "房屋状态：\n";

	if(!(btime = query("built_time")) || (btime < 0))
	{
		set("built_time", time);
		btime = time;
	}

	des = time - btime;

	if(des >= 0)
	{
		out += "◆你需要去缴纳房屋修缮费了\n";
		if(des <= WORN_TIME)
		{
			tmp = (WORN_TIME - des)/1440;
			if(!tmp)
				out += "◆你需要去缴纳房屋修缮费了\n  否则这里很快会变得破败不堪\n";
			else
				out += sprintf("  否则大约再有 %d 天这里就会变得破败不堪\n", tmp);
		}
		else if(time <= BREAKDOWN_TIME)
		{
			tmp = (BREAKDOWN_TIME - des)/1440;
			if(!tmp)
				out += "◆你需要去赶快缴纳房屋修缮费了\n  否则这里马上会倒塌的\n";
			else
				out += sprintf("  否则大约再有 %d 天这里可能会倒塌的\n", tmp);

		}
		else
			out += "◆你要立刻去缴纳房屋修缮费！！\n  能不能来得及只有神仙知道了\n";
	}
	else
	{
		tmp = abs(des/1440);
		if(!tmp)
			out += "◆你的房屋修缮费马上就要到期了\n";
		else
			out += sprintf("◆你的房屋修缮费还能支持 %d 天\n", tmp);
	}

	if(mapp(bank = query("bank")))
	{
		des = bank["time"] - time;

		if(des >= 0)
		{
			tmp = des/1440;
			if(!tmp)
				out += "◆你的房屋在银行进行了抵押\n  赶紧去还款吧，能不能来得及都不好说了\n";
			else
				out += sprintf("◆你的房屋在银行进行了抵押\n  大约再有 %d 天就要到期了\n", tmp);
		}
		else
			out += "◆你的房屋在银行进行了抵押\n  等着银行来收房子吧\n";
	}

	write(out);
	return 1;
}

int do_save(string arg)
{
	object link_ob,me = this_player();

	if(me->query("id") != query("master_id"))
	{
		if( !objectp(link_ob = me->query_temp("link_ob")) )
		{
                	write("你不是经由正常连线进入，不能储存。\n");
			return 1;
		}
		if( (int)link_ob->save() && (int)me->save() )
		{
			write("档案储存完毕。\n");
			return 1;
		}
		else
		{
			write("储存失败。\n");
			return 1;
		}
	}
	return 0;
}

int do_changelong(string arg)
{
	string str;
	object me = this_player();

	if(me->query("id") != query("master_id"))
		return notify_fail("这个命令是房主专用命令。\n");

	write("为了您房间的美观，每一行请不要超过二十五个中文字。\n");
	write("第一行的内容长度比其它行的长度少两个中文字宽才能对齐。\n");
	this_player()->edit( (: get_long , str :) );
	return 1;
}

void get_long(string str, string text)
{
	if( sizeof( explode(text, "\n") ) > 8 )
	{
		write("请将您的家庭描述控制在不超过八行。\n");
		return ;
	}	

	set("long",text);
	save();
	write("ok.\n");
	return;
}

int do_list(string arg)
{
	string out;

	if(!arrayp(save_objs) || !sizeof(save_objs))
		return notify_fail("这里没有保存任何物品。\n");

	out = "这里保存的物品有：\n";

	foreach(class s_ob tmp in save_objs)
	{
		object ob;

		if(tmp->file->is_self_object())
		{
			ob = new(tmp->file, tmp->arg);
			out += sprintf("%s(%s)\n", ob->name(), ob->query("id"));
			destruct(ob);
		}
		else
			out += sprintf( "%s(%s)\n", tmp->file->name(), tmp->file->query("id"));
	}
	write(out);
	return 1;
}

int do_baocun(string arg)
{
	object obj,me = this_player();
	class s_ob tmp;

	if(!arg || arg == "")
		return notify_fail("你要保存什么？\n");

	if(!obj = present(arg,me))
		obj = present(arg,this_object());
	if(!obj)
		return notify_fail("你要保存什么？\n");

	if(obj->is_character())
		return notify_fail("你要保存什么？\n");

#ifdef WIZARD_FLAG
	if(obj->query_wiz_flag())
	{
		sys_log("wiz_ob",sprintf("%s企图在%s的家宅私藏巫师物品 %s 被没收.%s\n",
			geteuid(me),query("master_id"),base_name(obj),ctime(time())));
		write(obj->name()+"是巫师物品被没收了，请立刻向天神发信做出解释,否则后果自负.\n");
		destruct(obj);
		return 1;
	}
#endif

	if(sizeof(save_objs) >= CAN_SAVE_OBJECT)
		return notify_fail("这间房子里再也保存不下更多的物品了。\n");

	if(obj->is_food() || obj->is_liquid())
		return notify_fail("吃喝的东西还是别放在家里的好。\n");

	if(obj->query("money_id"))
		return notify_fail("钱还是存在银行里比较妥当。\n");

	if(obj->query_credit_point_flag() || obj->no_save_in_home())
		return notify_fail("这件东西不能保存。\n");

	if(obj->is_weapon() && obj->query("weapon_mangle"))
		return notify_fail("这件兵器已经坏了，先去修好了在保存吧。\n");

	if(obj->is_armor() && obj->query("armor_mangle"))
		return notify_fail("这件护具已经坏了，先去修好了在保存吧。\n");

	if(obj->query_amount() && (obj->query_amount() > 1))
		return notify_fail("你一次只能保存一件物品。\n");

	if(obj->is_container() && sizeof(all_inventory(obj)))
		return notify_fail(sprintf("你一次只能保存一件物品，请先将%s里的物品取出。\n",obj->name()));

	tmp = new(class s_ob);
	tmp->file = base_name(obj);
	tmp->arg = obj->query_save_args();

	if(!arrayp(save_objs) || !sizeof(save_objs))
		save_objs = ({ tmp });
	else
		save_objs += ({ tmp });

	if(obj->is_ctl_ob())
		CTLOB_D->save_to_mud(base_name(obj));

	destruct(obj);
	save();
	write("ok.\n");
	return 1;
}

int do_quzou(string arg)
{
	class s_ob *tt = ({});
	object ob;

	if(!arrayp(save_objs) || !sizeof(save_objs))
		return notify_fail("这里没有保存任何物品。\n");

	if(!stringp(arg) || !sizeof(arg))
		return notify_fail("你要取走什么物品？\n");

	foreach(class s_ob tmp in save_objs)
	{
		object idob;

		if(!objectp(ob))
		{
			if(tmp->file->is_self_object())
			{
				idob = new(tmp->file, tmp->arg);
				if(idob->id(arg))
					ob = idob;
				else
				{
					destruct(idob);
					tt += ({ tmp });
				}
			}
			else if(tmp->file->id(arg))
				ob = new(tmp->file, tmp->arg);
			else
				tt += ({ tmp });
		}
		else
			tt += ({ tmp });
	}

	if(!objectp(ob))
		return notify_fail("保存的物品里没有这个物品。\n");

	if(ob->is_ctl_ob())
		CTLOB_D->delete_from_mud(base_name(ob));

	if(!ob->move(this_player()))
		ob->move(this_object());

	save_objs = tt;
	save();

	write(sprintf("你将%s取了出来。\n", ob->name()));
	return 1;
}

int do_fangzhi(string arg)
{
	object me = this_player();
	string f;
	mapping obs,t_obs;
	int *sum,n;

	if(me->query("id") != query("master_id"))
		return 0;

	if( !(f = me->query_temp("furniture")) )
		return notify_fail("你好像没有新添置家具呀。\n");

	me->delete_temp("furniture");
	obs = query("objects");
	if(!obs || !sizeof(obs))
		set("objects",([f:1]));
	else
	{
		sum = values(obs);
		for(int i=0;i<sizeof(sum);i++)
			n += sum[i];
		if(n >= MAX_FUR)
			return notify_fail("这间屋子里再也放置不下更多的家具了。\n");

		else if(!undefinedp(obs[f]))
			obs[f]++;
		else
			obs += ([f:1]);
		set("objects",obs);
	}

	if(mapp(t_obs = query_temp("objects")))
	{
		foreach(string file,mixed ob in t_obs)
		{
			if(objectp(ob))
				destruct(ob);
			if(arrayp(ob))
			{
				for(int i=0;i<sizeof(ob);i++)
					if(objectp(ob[i]))
						destruct(ob[i]);
			}
		}

	}
	delete_temp("objects");
	
	save();
	setup();
	write(sprintf("小伙计把%s送到这里摆放好，一转眼又不见了。\n",f->name()));
	return 1;
}

int do_banzou(string arg)
{
	object ob,me=this_player();
	string f;
	mapping obs,t_obs;

	if(me->query("id") != query("master_id"))
		return 0;

	if(!stringp(arg))
		return notify_fail("你要搬走什么家具？\n");

	ob = present(arg,this_object());
	if(!ob)
		return notify_fail("你要搬走什么家具？\n");

	f = base_name(ob);

	obs = query("objects");

	if(undefinedp(obs[f]) || !obs[f])
		return notify_fail("你要搬走什么家具？\n");

	obs[f]--;
	if(!obs[f])
		map_delete(obs,f);
	message_vision("如水把$n从屋子里扔了出去。\n",me,ob);
	destruct(ob);
	set("objects",obs);

	if(mapp(t_obs = query_temp("objects")))
	{
		foreach(string file,mixed obj in t_obs)
		{
			if(objectp(obj))
				destruct(obj);
			if(arrayp(obj))
			{
				for(int i=0;i<sizeof(ob);i++)
					if(objectp(obj[i]))
						destruct(obj[i]);
			}
		}

	}
	delete_temp("objects");

	save();
	setup();
	return 1;
}
