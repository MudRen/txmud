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
        set_name("����", ({ "mailbox", "box" }) );
        set("long",
                "����һ���������š����ŵ����䣬�����������ָ������������ʼ���\n\n"
                "mail <ĳ��>               ���Ÿ����ˡ�\n"
		"mail <ĳ��@��Ϸ��>        ���Ÿ�������Ϸ����ˡ�\n"
                "forward <�ż����> <ĳ��> ��ĳ����ת�ĸ����ˡ�\n"
                "from                      �鿴�����е��ż���\n"
                "read <�ż����>           �Ķ�һ���ż���\n"
                "discard <�ż����>        ����һ���ż���\n"
        );

	// ��ʦ�����Ĵ����������
        set("wiz_long",
                "����һ���������š����ŵ����䣬�����������ָ������������ʼ���\n\n"
                "mail <ĳ��>               ���Ÿ����ˡ�\n"
		"mail <ĳ��@��Ϸ��>        ���Ÿ�������Ϸ����ˡ�\n"
                "forward <�ż����> <ĳ��> ��ĳ����ת�ĸ����ˡ�\n"
                "from                      �鿴�����е��ż���\n"
                "read <�ż����>           �Ķ�һ���ż���\n"
                "discard <�ż����>        ����һ���ż���\n"
		"wizards                   �����еı�����ʦ����(��ʦר��)��\n"
		"wizards all               �����е���Ϸ�е�������ʦ����(��ʦר��)��\n"
        );

        set("unit", "��");
        set("no_drop", 1);
        set("no_insert", 1);
 
        seteuid(getuid());
}

nomask int set_owner(string id)	/* ԭ���˺������ڰ�ȫ©��. */
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
                set_name( this_player()->name(1) + "������", ({ "mailbox", "box" }) );
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
		write("û������˴��ڡ�\n");
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
			write("�Է�����������\n");
			return;
		}
		if(flag)
			mbx->move(ppl);
		tell_object(ppl,HIG"\n�ʲ���������ǰ˵����������һ���ţ����պá���  ת���ֲ�����...\n\n"NOR);
	}

	else
	{
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
		if(!mbx->receive_mail(mail))
			write("�Է�����������\n");
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
			return notify_fail("�򱾵����е���ʦ������ʹ�� wizards ���\n��������ͨ����Ϸ��������ʦ������ʹ�� wizards all ���\n");
		else wizard_all_lable =1;
	}

        list = sort_array(SECURITY_D->query_wizlist(), 1);

	if(wizard_all_lable && !find_object(DNS_MASTER))
		return notify_fail("���ʾ���û�б����룬�޷���������Ϸȡ����ϵ��\n");

        mail =
	([
		"fromid": this_player()->query("id"),
                "from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"otherfrom":sprintf("%s(%s@%s)",this_player(1)->name(),this_player()->query("id"),mud_nname()),
                "title": "����",
                "to": arg,
                "time": time(),
                "text": ""
        ]);

        write("�ż����⣺");
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
                return notify_fail("��Ҫ���Ÿ�˭��\n");

	if(sscanf(arg,"%s@%s",who,mud) == 2)
	{
		if(!find_object(DNS_MASTER))
			return notify_fail("��·���鲢û�б����룬���ɷ���Զ���ż���\n�����ż���ʹ�� mail ID(���id) ���͡�\n");

		mud = htonn( mud );
		if(mud == mud_nname())
			return notify_fail("�����ż���ʹ�� mail ID(���id) ���͡�\n");

		if(!find_object(DNS_MASTER))
			return notify_fail("���ʾ���û�б����룬�޷���������Ϸȡ����ϵ��\n");

		minfo = (mapping)DNS_MASTER->query_mud_info(mud);

		if(!minfo)
			return notify_fail("δ�����Ϸ��ͨ������ mudlist ������ҵ�ǰ��ͨ����Ϸ��\n");

	        mail = ([
		"from": sprintf("%s(%s@%s)",this_player(1)->name(),this_player()->query("id"),mud_nname()),
		"fromid": this_player()->query("id"),
                "title": "����",
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
			return notify_fail("û������˴��ڡ�\n");

		mail = ([	// modified by Find.
                	"from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
	                "title": "����",
        	        "to": arg,
                	"time": time(),
	                "text": ""
        	]);
	}
        write("�ż����⣺");
        input_to( (: get_mail_title :), mail);
        return 1;
}

protected void get_mail_title_wiz(string str, mapping mail,string *list)
{
	if(strlen(str) > 24)
	{
		write("�ż����ⳤ�Ȳ�Ҫ���� 12 �����֡�\n�����������ż����⣺");
		input_to( (: get_mail_title :), mail);
		return;
	}

        if( str!="" ) mail["title"] = str;
        write("�ż����ݣ�\n");
        this_player()->edit( (: get_mail_text_wiz, mail, list :) );
}

protected void get_mail_text_wiz(mapping mail, string *list, string str)
{
	mail["text"] = str;
	write("���Լ�Ҫ��һ�ݱ�����(y/n)��[n]");
	input_to( (: confirm_copy_wiz :), mail, list);
}

protected void confirm_copy_wiz(string yn, mapping mail, string *list)
{
        int i;
        if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);

        for (i=0;i<sizeof(list);i++){
                  mail["to"]= list[i];
                  send_mail(mail["to"], mail);
        printf("�ż��ѷ��� %-15s\n.", list[i]);
        }

	if(wizard_all_lable)
	{
		wizard_all_lable = 0;
		MAIL_Q->send_msg(mail,1);
		write("�����ʼ���ʼ���ͣ����Ժ�\n");
	}
	else write("Ok.\n");
}

protected void get_mail_title(string str, mapping mail)
{
	if(strlen(str) > 24)
	{
		write("�ż����ⳤ�Ȳ�Ҫ���� 12 �����֡�\n�����������ż����⣺");
		input_to( (: get_mail_title :), mail);
		return;
	}

        if( str!="" ) mail["title"] = str;
	if(intermud_mail)
		write("�ż�����(�����ʼ���Ҫ̫��)��\n");
	else write("�ż����ݣ�\n");
        this_player()->edit( (: get_mail_text, mail :) );
}

protected void get_mail_text(mapping mail, string str)
{
	if(sizeof(str) >= 1000)
	{
		write("�ż����ݳ��������������롣\n�ż����ݣ�\n");
        	this_player()->edit( (: get_mail_text, mail :) );
		return;
	}
        mail["text"] = str;
        write("���Լ�Ҫ��һ�ݱ�����(y/n)��[n]");
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
                write("���������Ŀǰû���κ��ż���\n");
                return 1;
        }

	out = sprintf("������������ڹ��� %d ���ż�%s��\n",
		n,(i=query_unread_count())?sprintf("������ %d ��δ��",i):"");
        for(i=0; i<n; i++)
		out += sprintf("%s[e%2d] %-30s �����ˣ�%-20s\n"NOR,
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
                return notify_fail("��Ҫ����һ���ţ�\n");

        if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
                return notify_fail("û�������ŵ��ż���\n");

        num --;

        this_player()->start_more(sprintf("�ż����⣺%s\n�� �� �ˣ�%s\t�ĳ�ʱ�䣺(%s)\n\n%s\n",
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
                return notify_fail("��Ҫ������һ���ţ�\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("û�������ŵ��ż���\n");

        num --;

        if(sizeof(mails) == 1){
            mails = 0;
            write("����������.\n");
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
                return notify_fail("��Ҫ����һ����ת�ĸ����ˣ�\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("û�������ŵ��ż���\n");

        num --;

        m = ([]);
        m["title"] = mails[num]["title"];
        m["text"] = mails[num]["text"];
        m["time"] = mails[num]["time"];
        m["from"] = mails[num]["from"] + "/ת����" + this_player()->query("name");
        m["to"] = dest;
        send_mail( dest, m );
        write("Ok.\n");

        return 1;
}

void owner_is_killed() { destruct(this_object()); }
