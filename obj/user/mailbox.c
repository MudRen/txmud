// mailbox.c
// Modified by Find.

#include <ansi.h>
#include <net/macros.h>
#include <net/dns.h>
#include <origin.h>

inherit ITEM;
inherit F_SAVE;

protected nosave string owner_id;
protected mapping *mails;

protected void get_mail_title(string str, mapping mail);
protected void get_mail_text(mapping mail, string str);
protected void confirm_copy(string yn, mapping mail);
protected void get_mail_text_wiz(mapping mail, string str, string *list);
protected void get_mail_title_wiz(string str, mapping mail,string *list);
protected void confirm_copy_wiz(string yn, mapping mail, string *list);

protected static int wizard_all_lable = 0;
protected static int intermud_mail = 0;

int query_unread_count() { return sizeof(mails)?sizeof(filter_array(mails,(: $1["unread"] :))):0; }
int query_mails_count() { return sizeof(mails); }
int no_save_in_home() { return 1; }

void create()
{
        set_name("信箱", ({ "mailbox", "box" }) );
        set("long",
                "这是一个用来寄信、收信的信箱，你可以用以下指令来处理你的邮件：\n\n"
                "mail <某人>               寄信给别人。\n"
		"mail <某人@游戏名>        寄信给其它游戏里的人。\n"
                "forward <信件编号> <某人> 将某封信转寄给别人。\n"
                "from                      查看信箱中的信件。\n"
                "read <信件编号>           阅读一封信件。\n"
                "discard <信件编号>        丢弃一封信件。\n"
        );

	// 巫师看到的此物件描述。
        set("wiz_long",
                "这是一个用来寄信、收信的信箱，你可以用以下指令来处理你的邮件：\n\n"
                "mail <某人>               寄信给别人。\n"
		"mail <某人@游戏名>        寄信给其它游戏里的人。\n"
                "forward <信件编号> <某人> 将某封信转寄给别人。\n"
                "from                      查看信箱中的信件。\n"
                "read <信件编号>           阅读一封信件。\n"
                "discard <信件编号>        丢弃一封信件。\n"
		"wizards                   向所有的本地巫师发信(巫师专用)。\n"
		"wizards all               向所有的游戏中的所有巫师发信(巫师专用)。\n"
        );

        set("unit", "个");
        set("no_drop", 1);
        set("no_insert", 1);
 
        seteuid(getuid());
}

nomask int set_owner(string id)	/* 原来此函数存在安全漏洞. */
{
	if( (origin() == ORIGIN_CALL_OUT)
	|| (previous_object()
	&& (base_name(previous_object()) == MAILBOX_OB)) )
	{
        	owner_id = id;
        	return restore();
	}
	else
		return 0;
}

void init()
{
        if( this_player() && (environment()==this_player()) ) {
                set_owner( (string)this_player()->query("id") );
                this_player()->set_temp("mbox_ob", this_object());
                set_name( this_player()->name(1) + "的信箱", ({ "mailbox", "box" }) );
                add_action("do_mail", "mail");
                add_action("do_forward", "forward");
                add_action("do_from", "from");
                add_action("do_read", "read");
                add_action("do_discard", "discard");
                add_action("do_wizard","wizards");
        }
}

nomask string query_save_file()
{
        if( !stringp(owner_id) ) return 0;

        return DATA_DIR + "mail/" + owner_id[0..0] + "/" + owner_id;
}

int receive_mail(mapping mail)
{
	if( (wiz_level(owner_id) < 1) && (sizeof(mail) > 30) )
		return 0;

	if(undefinedp(mail["unread"]))
		mail += (["unread":1]);
	else
		mail["unread"] = 1;
        if( !pointerp(mails) ) mails = ({ mail });
        else mails += ({ mail });
        save();
}

void send_mail(string rcvr, mapping mail)
{
        object ppl, mbx;

	if( intermud_mail )
	{
		intermud_mail = 0;
		MAIL_Q->send_msg(mail,0);
		return;
	}

	if(file_size(sprintf(DATA_DIR+"login/%c/%s.o",rcvr[0],rcvr)) <= 0)
	{
		write("没有这个人存在。\n");
		return;
	}
/*
        ob->set("new_mail", 1);
        ob->save();
*/
        ppl = find_player(rcvr);

        if(ppl)
	{
		int flag = 0;
		mbx = ppl->query_temp("mbox_ob");
		if(!mbx)
		{
			flag = 1;
			mbx = new(MAILBOX_OB);
        	        mbx->set_owner(rcvr);
		}
		if(!mbx->receive_mail(mail))
		{
			write("对方信箱已满。\n");
			return;
		}
		if(flag)
			mbx->move(ppl);
		tell_object(ppl,HIG"\n邮差来到你面前说道：“有您一封信，请收好。”  转眼又不见了...\n\n"NOR);
	}

	else
	{
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
		if(!mbx->receive_mail(mail))
			write("对方信箱已满。\n");
		destruct(mbx);
	}
}

int do_wizard(string arg)
{
        mapping mail;
        string  *list;

        if( this_player()!=environment() || !wizardp(this_player())) return 0;

	if( arg )
	{
		if(arg != "all")
			return notify_fail("向本地所有的巫师发信请使用 wizards 命令，\n向所有连通的游戏的所有巫师发信请使用 wizards all 命令。\n");
		else wizard_all_lable =1;
	}

        list = sort_array(SECURITY_D->query_wizlist(), 1);

	if(wizard_all_lable && !find_object(DNS_MASTER))
		return notify_fail("网际精灵没有被载入，无法与其它游戏取得联系。\n");

        mail =
	([
		"fromid": this_player()->query("id"),
                "from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"otherfrom":sprintf("%s(%s@%s)",this_player(1)->name(),this_player()->query("id"),mud_nname()),
                "title": "无题",
                "to": arg,
                "time": time(),
                "text": ""
        ]);

        write("信件标题：");
        input_to( (: get_mail_title_wiz :), mail, list);

        return 1;
}

int do_mail(string arg)
{
        mapping mail;
	string who,mud;
	mapping minfo;

        if( this_player()!=environment() ) return 0;

        if( !arg || arg=="" )
                return notify_fail("你要寄信给谁？\n");

	if(sscanf(arg,"%s@%s",who,mud) == 2)
	{
		if(!find_object(DNS_MASTER))
			return notify_fail("网路精灵并没有被载入，不可发送远程信件。\n本地信件请使用 mail ID(玩家id) 发送。\n");

		mud = htonn( mud );
		if(mud == mud_nname())
			return notify_fail("本地信件请使用 mail ID(玩家id) 发送。\n");

		if(!find_object(DNS_MASTER))
			return notify_fail("网际精灵没有被载入，无法与其它游戏取得联系。\n");

		minfo = (mapping)DNS_MASTER->query_mud_info(mud);

		if(!minfo)
			return notify_fail("未与此游戏连通，请用 mudlist 命令查找当前连通的游戏。\n");

	        mail = ([
		"from": sprintf("%s(%s@%s)",this_player(1)->name(),this_player()->query("id"),mud_nname()),
		"fromid": this_player()->query("id"),
                "title": "无题",
                "to": who,
		"to_mud":mud,
                "time": time(),
                "text": ""
		]);

		intermud_mail = 1;
	}

        else
	{
		if(file_size(sprintf(DATA_DIR+"login/%c/%s.o",arg[0],arg)) <= 0)
			return notify_fail("没有这个人存在。\n");

		mail = ([	// modified by Find.
                	"from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
	                "title": "无题",
        	        "to": arg,
                	"time": time(),
	                "text": ""
        	]);
	}
        write("信件标题：");
        input_to( (: get_mail_title :), mail);
        return 1;
}

protected void get_mail_title_wiz(string str, mapping mail,string *list)
{
	if(strlen(str) > 24)
	{
		write("信件标题长度不要超过 12 个汉字。\n请重新输入信件标题：");
		input_to( (: get_mail_title :), mail);
		return;
	}

        if( str!="" ) mail["title"] = str;
        write("信件内容：\n");
        this_player()->edit( (: get_mail_text_wiz, mail, list :) );
}

protected void get_mail_text_wiz(mapping mail, string *list, string str)
{
	mail["text"] = str;
	write("您自己要留一份备份吗(y/n)？[n]");
	input_to( (: confirm_copy_wiz :), mail, list);
}

protected void confirm_copy_wiz(string yn, mapping mail, string *list)
{
        int i;
        if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);

        for (i=0;i<sizeof(list);i++){
                  mail["to"]= list[i];
                  send_mail(mail["to"], mail);
        printf("信件已发给 %-15s\n.", list[i]);
        }

	if(wizard_all_lable)
	{
		wizard_all_lable = 0;
		MAIL_Q->send_msg(mail,1);
		write("网际邮件开始发送，请稍候。\n");
	}
	else write("Ok.\n");
}

protected void get_mail_title(string str, mapping mail)
{
	if(strlen(str) > 24)
	{
		write("信件标题长度不要超过 12 个汉字。\n请重新输入信件标题：");
		input_to( (: get_mail_title :), mail);
		return;
	}

        if( str!="" ) mail["title"] = str;
	if(intermud_mail)
		write("信件内容(网际邮件不要太长)：\n");
	else write("信件内容：\n");
        this_player()->edit( (: get_mail_text, mail :) );
}

protected void get_mail_text(mapping mail, string str)
{
	if(sizeof(str) >= 1000)
	{
		write("信件内容超长，请重新输入。\n信件内容：\n");
        	this_player()->edit( (: get_mail_text, mail :) );
		return;
	}
        mail["text"] = str;
        write("您自己要留一份备份吗(y/n)？[n]");
        input_to( (: confirm_copy :), mail);
}

protected void confirm_copy(string yn, mapping mail)
{
        if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);
        send_mail(mail["to"], mail);
        write("Ok.\n");
}

int do_from()
{
        int i,n;
	string out;
	object me = this_player();

	if( !pointerp(mails) || !n = sizeof(mails) ) {
                write("你的信箱中目前没有任何信件。\n");
                return 1;
        }

	out = sprintf("你的信箱中现在共有 %d 封信件%s：\n",
		n,(i=query_unread_count())?sprintf("，其中 %d 封未读",i):"");
        for(i=0; i<n; i++)
		out += sprintf("%s[e%2d] %-30s 寄信人：%-20s\n"NOR,
			mails[i]["unread"]?BWHT HIR:"",i+1, mails[i]["title"], mails[i]["from"] );
        me->start_more(out);

	if(me->query("mails") != sizeof(mails))
	{
		me->set("mails", sizeof(mails));
		me->save();
	}
	return 1;
}

int do_read(string arg)
{
        int num;

        if( !arg || !sscanf(arg, "e%d", num) )
                return notify_fail("你要读哪一封信？\n");

        if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
                return notify_fail("没有这个编号的信件。\n");

        num --;

        this_player()->start_more(sprintf("信件标题：%s\n寄 信 人：%s\t寄出时间：(%s)\n\n%s\n",
		mails[num]["title"], mails[num]["from"],
		ctime(mails[num]["time"])[0..9], mails[num]["text"] ));

	if(mails[num]["unread"])
	{
		mails[num]["unread"] = 0;
		save();
	}
        return 1;
}

int do_discard(string arg)
{
        int num;

        if( !arg || !sscanf(arg, "e%d", num) )
                return notify_fail("你要丢弃哪一封信？\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("没有这个编号的信件。\n");

        num --;

        if(sizeof(mails) == 1){
            mails = 0;
            write("你的信箱空了.\n");
        } else if(num == 0) {
            mails = mails[num+1..sizeof(mails)-1];
        } else {
            mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
        }
        write("Ok.\n");
        save();
        if(this_player()->query("mails") != sizeof(mails)){
            this_player()->set("mails", sizeof(mails));
            this_player()->save();
        }
        return 1;
}

int do_forward(string arg)
{
        string dest;
        int num;
        mapping m;

        if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
                return notify_fail("你要将哪一封信转寄给别人？\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("没有这个编号的信件。\n");

        num --;

        m = ([]);
        m["title"] = mails[num]["title"];
        m["text"] = mails[num]["text"];
        m["time"] = mails[num]["time"];
        m["from"] = mails[num]["from"] + "/转寄自" + this_player()->query("name");
        m["to"] = dest;
        send_mail( dest, m );
        write("Ok.\n");

        return 1;
}

void owner_is_killed() { destruct(this_object()); }
