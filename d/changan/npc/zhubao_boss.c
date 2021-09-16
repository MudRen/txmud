// zhubao_boss.c

#include <ansi.h>

inherit F_DEALER;

private string *passwds = ({"��","��","��","��","��","��","��","��","��","��","��","��"});
private string party_ob = __DIR__"shouqian";
int want_jingong(object who);
string random_pass()
{
	int i,r;
	string out = "",*temp = passwds;

	for(i=0;i<6;i++)
	{
		out += temp[r = random(sizeof(temp))];
		temp -= ({ temp[r] });
	}
	return out;
}

void create()
{
        set_name("��Ǭ��", ({ "liu qianhong","liu","boss" }) );
	set("title","�������ƹ�");
        set("gender", "����" );
        set("age", 57);
        set("long","�ƹ���Ѿ�ж��,������ɣ����һ˫�������۾�ȴ�������⡣\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
	set("inquiry",([
	random_pass() : (: want_jingong :),
]));

        set("vendor_goods", ([
		__DIR__"obj/diamond_ring" : 3,
		__DIR__"obj/shouzhuo":3,
		__DIR__"obj/picture_1":1,
        ]) );

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string day_night;
	int time;

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N����$n˵������⵰�Ͻ�����ȥ��\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"���ƹ�����˵���������Ѿ������ˣ�"+RANK_D->query_respect(ob)+
			"��������ʲô�����𣿡�\n"NOR
			: ( (time <= 60) ? CYN"���ƹ�Ц���е�˵�����͹����һ�°ɣ����ϾͿ��š�\n"NOR
			: CYN"���ƹ������һ��˵���������Ǳ�����Ϣʱ�䣬������ʲô���顣\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"���ƹ�Ц�����˵�����������ǰ����Ϻţ������ʵ��\n"NOR);
                        break;
                case 1:
                        say( CYN"���ƹ�Ц���е�˵������ӭ���٣���������\n"NOR);
                        break;
		}
	}
}

void set_passwd(string str)
{
	if( !stringp(str)
	|| str == ""
	|| previous_object() != find_object(party_ob) )
		return;

	set("inquiry",([ str : (: want_jingong :) ]));
}

int want_jingong(object who)
{
	if( !who
	|| !who->query_temp("enter_huanggong_asked")
	|| !environment()
	|| (base_name(environment()) != query("startroom")) )
		return 0;

	if( sizeof( filter_array(all_inventory(environment())-({who,this_object()}),(: $1->is_charactor() :)) ) )
		return 0;

	message_vision("$N������Ĵ������ˣ�һ�Ѱ�$nק�������ݡ�\n",this_object(),who);
	who->move("/d/changan/zhubao_behind");
	tell_room(environment(who),sprintf("%s�������ĵĴ��������˽�����\n",who->name()),({who}) );
	who->delete_temp("enter_huanggong_asked");
	return 1;
}
