// huaner.c

#include <ansi.h>

inherit NPC;

int query_is_feiyu_huaner() { return 1; }

int ask_pu(object me);

void create()
{
        set_name("����", ({ "huan er"}) );
        set("title",WHT"����������"NOR);
        set("gender", "Ů��" );
        set("age", 22);
        set("long", "����һͷ������㷢,���紵������һЩ���ҡ�
��ɫ��ɴ�ڣ�ҷ�صĳ�ȹ��
ͷ���£��������ᡢ毺ã��������������
Ƥ���ף�����������
����Ц����ů�紺���۲�������ˮ��
");
        set("combat_exp", 500);
        set("per", 30);
        set_skill("literate",360);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                "���������������˭���ٸ��Ҵ�һ������ܲ�ġ�ѽ��\n",
        }) );   

        set("inquiry", ([
                "�����ص�" : "��˵�ص���ȫ�ǻ��أ����ҽ�ȥ�˾���·��\n", 
                "�ص����" : "����������˵����һ��С���\n", 
                "��������" : "�����������������������书�ؼ���\n",
                "ѧϰ" : "������ܸ��Ҵ�һ�� ����ܲ�ġ��Ļ����Ҿʹ�Ӧָ��ָ���� ��\n",
                "ָ��" : "������ܸ��Ҵ�һ�� ����ܲ�ġ��Ļ����Ҿʹ�Ӧָ��ָ���� ��\n",
                "����" : "������ܸ��Ҵ�һ�� ����ܲ�ġ��Ļ����Ҿʹ�Ӧָ��ָ���� ��\n",
                "�ص�" : "��˵�ص���ȫ�ǻ��أ����ҽ�ȥ�˾���·��\n", 
                "��ܲ������" : (: ask_pu :),
                "����" : (: ask_pu :),
                "������" : "����һ�����������ֻ�����Ǹ�������ܴ����ˡ���ܲ�ġ��������ӡ�\n",
                "��ɽ֮��" : "��˵������һ�Ѱ��꺱���ı��������������źܶ౦ʯŶ��\n",
]) );
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int recognize_apprentice(object ob)
{
	if(ob->query("mark/louth_huaner")
	&& (ob->query("class") == "rain"))
		return 1;
	else
		return 0;
}

int ask_pu(object me)
{
	if(me->query("mark/louth_huaner"))
	{
		command("say лл����Ҵ�����ܲ�ġ�������������\n");
		return 1;
	}

	command ("think");
	call_out("think",5,me);
	return 1;
}

void think(object me)
{
	if(!objectp(me) || (environment(me) != environment()))
		return;

	tell_object(me,CYN"
����˵���� ��Ȼ����������������СС��Ը�����ǾͶ�л����
�Ǳ�����ܲ�ġ��������Ҿ˾������ء���˵���ࡺ��ܲ�ġ�����
Ҫ��������С�\n"NOR);
	me->set_temp("mark/huaner_pu",1);
}

void start_call()
{ call_out("do_refresh",2); }

void do_refresh()
{
	object *obs;
	int n;

	obs = all_inventory(this_object());
	if(!n = sizeof(obs))
		return;

	for(int i=0;i<n;i++)
	{
		if(obs[i]->query("equipped"))
			continue;
		else
			destruct(obs[i]);
	}
}
