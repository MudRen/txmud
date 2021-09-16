// shu_boss.c
// By Find.

#include <ansi.h>

inherit F_DEALER;

static int being_doing = 0;

mixed poem =({
({
		"��������ҹ�Ɑ��",
		"�����������ϴߡ�",
		"����ɳ����ĪЦ��",
		"������ս���˻ء�",
	}),

({
		"��������Ϊ��ͣ�",
		"ÿ��ѽڱ�˼�ס�",
		"ң֪�ֵܵǸߴ���",
		"���������һ�ˡ�",
	}),

({
		"��ҹȹ���⣬",
		"�����ӷɡ�",
		"Ǧ����������",
		"Ī��޻��顣",
	}),

({
		"���߲�������",
		"����������",
		"ҹ����������",
		"����֪���١�",
	}),

({
		"��ǰ���¹⣬",
		"���ǵ���˪��",
		"��ͷ�����£�",
		"��ͷ˼���硣",
	}),

({
		"�������˽ܣ�",
		"����Ϊ���ۡ�",
		"����˼����",
		"���Ϲ�������",
	}),

({
		"������й���",
		"������į�졣",
		"��ͷ��Ů�ڣ�",
		"����˵���ڡ�",
	}),

({
		"�������ֹ���",
		"���ɰ���ͼ��",
		"����ʯ��ת��",
		"�ź�ʧ���⡣",
	}),

({
		"�����ٸ���֪�",
		"������ױ�ϴ�¥��",
		"����İͷ����ɫ��",
		"�ڽ̷����ٷ�",
	}),

({
		"��ҹ�翪¶���ң�",
		"δ��ǰ�����ָߡ�",
		"ƽ�������³г裬",
		"���ⴺ���ͽ��ۡ�",
	}),

({
		"��԰����·������",
		"˫�������᲻�ɡ�",
		"���������ֽ�ʣ�",
		"ƾ�����ﱨƽ����",
	}),

({
		"�������Ÿ�Ұ�̣�",
		"ʯ��������洬��",
		"�һ���������ˮ��",
		"������Ϫ�δ��ߡ�",
	}),

({
		"��������˪���죬",
		"�������Գ��ߡ�",
		"���ճ��⺮ɽ�£�",
		"ҹ���������ʹ���",
	}),

({
		"���Ź����º۹���",
		"����Ω������񽡣",
		"б�����ε�Ӱ�ϣ�",
		"�޿�����ȷɶꡣ",
	}),

({
		"������Сɽ¥��",
		"һ�������Կɳ",
		"����ҹ��б���",
		"�����ǻ��ǹ��ݡ�",
	}),

({
		"�չ�б�ռ���̨��",
		"������ӭ��¶����",
		"��ҹ�ϻ�����¼��",
		"̫�溬Ц��������",
	}),
});

string *head = ({
"���ϰ��������ţ�",
"���ϰ�ҡͷ���Ե�������",
"���ϰ��Ŀ����̾����",
});

string *end = ({
"���ϰ�̾��������˹�ģ���",
"���ϰ�˵�������˾���ôʣ�",
"���ϰ�ҡͷ����˵��������...������������",
"���ϰ�˵����������",
});

void elocnte_poem();

void create()
{
        set_name("��ҫ��", ({ "boss zhang", "boss", "zhang" }) );
	set("title","����ϰ�");
        set("gender", "����" );
        set("age", 45);
        set("long","���ĸ��ϰ塣\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		BOOK_DIR"luo_book":5,
		BOOK_DIR"guwen_book":5,
        ]) );

	set("chat_chance", 10);
	set("night_chat_msg", ({
	(: elocnte_poem :),
}));

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
		message_vision(CYN"$N����$n˵������Ӱ���������⣬�Ͻ���ȥ��\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"�Բ��𣬱ɺ��Ѿ������ˣ�"+RANK_D->query_respect(ob)+
			"�����������ɡ�\n"NOR
			: ( (time <= 60) ? CYN"���ϰ�Ц���е�˵����������һ�°ɣ�С�����ϾͿ����ˡ�\n"NOR
			: CYN"���ϰ�˵�����������������ɡ�\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"���ϰ����ﹾ���ţ��������лƽ��ݡ����������񡣡���\n"NOR);
                        break;
                case 1:
                        say( CYN"���ϰ�һ����˵������λ" + RANK_D->query_respect(ob)
                                + "���٣�С��������ԣ�����������\n"NOR);
                        break;
		}
	}
}

void elocnte_poem()
{
	if(being_doing || is_day())
		return;
	being_doing = 1;
	call_out("doing",1,random(sizeof(poem)),0);
}

void doing(int which,int num)
{
	remove_call_out("doing");
	if(num >= sizeof(poem[which]))
	{
		say(CYN+end[random(sizeof(end))]+"\n\n"+NOR);
		being_doing = 0;
		return;
	}
	say( CYN+head[random(sizeof(head))]+poem[which][num] +"\n"+NOR);
	call_out("doing",1+random(3),which,num+1);
}