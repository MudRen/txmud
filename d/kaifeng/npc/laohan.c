// laohan.c

#include <ansi.h>
inherit NPC;

int ask_quest(object me);

void create()
{
        set_name("���Ϻ�", ({ "lao han" }) );
	set("title","����רҵ��");
        set("gender", "����" );
        set("age", 63);

	set(NO_KILL, 1);
        set("long", "���Ϻ�ר������Ϊ������������������
��������ǵļ�����������﹩Ӧ��\n");

	set("inquiry",([
	"������" : (: ask_quest :),
	"����" : (: ask_quest :),
]));

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_quest(object me)
{
	if( (me->query("quest/shaolin_quest/name") != "������")
	|| me->query("quest/shaolin_quest/have_jiguan") )
	{
		write(sprintf(CYN"%s���˷��۾�˵���������������������˼������ģ�����ҵ��ң�\n"NOR,name()));
		return 1;
	}

	command(sprintf("say %s","����������ѽ,������Ѽ��ڸ�����,�һ���ô��ѽ,
\tҪ����ѹ���������һֻ��.ÿֻ 1 ������."));
	me->set_temp("asked_zhanglaohan",1);
	return 1;
}

int accept_object(object who, object ob)
{
	if(!is_money(ob))
		return 0;

	if(!who->query_temp("asked_zhanglaohan"))
	{
		command("say ���������׸�Ǯ�����鶼�У�лл����");
		return 1;
	}

	if(ob->value() < 100)
	{
		write(sprintf("%s˵������1������һֻ����һ��ͭ�Ӷ�Ҳ���У���\n",name()));
		return 0;
	}

	who->delete_temp("asked_zhanglaohan");
	call_out("give_guan",1,who);
	return 1;
}

protected void give_guan(object me)
{
	object guan;

	if(!me || (environment(me) != environment())
	|| me->query("quest/shaolin_quest/have_jiguan") )
		return;

	guan = new(__DIR__"obj/jiguan");
	guan->move(this_object());
	me->set("quest/shaolin_quest/have_jiguan",1);
	tell_object(me,sprintf("%s���ͷ˵�����ã�����һ�¡�\n",name()));
	tell_object(me,sprintf("%s�����ݵ���һ�������˵����������Ҫ�ģ��Ͻ���ȥ�ɡ�\n",name()));
	command(sprintf("give ji guan to %s",me->query("id")));
}
