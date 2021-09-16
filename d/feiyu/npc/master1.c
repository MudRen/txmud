// master1.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me(object me);

void create()
{
        set_name("����˪", ({ "master yu", "master","yu" }) );
        set("long","����˪������ܲ��ʦ�㡣\n");
        set("title", HIM"������ϯ�����"NOR);
        set("attitude", "peaceful");
        set("age", 31);
	set("class","rain");
        set("gender", "Ů��");
        set("per", 30);
	set("str", 50);
	set("kar", 35);
        set("int",30);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",200);
        set("combat_exp", 3000000);
	set("max_kee",2000);
	set("max_gin",2000);
	set("max_sen",2000);

        create_family("����", 2, "Ů����");

        set("inquiry", ([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"�뿪" : (: call_other, __FILE__, "want_to_leave" :),
	"��ʦ" : (: call_other, __FILE__, "want_to_leave" :),

        "���̽�" : (: ask_me :),
]) );

        set_skill("unarmed", 200);
        set_skill("sword",200);
        set_skill("force",200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate",200);
        set_skill("jieqing-sword", 200);
        set_skill("suiyu-force", 200);
        set_skill("zuiyue-strike", 200);
        set_skill("feiyu-zhen", 150);
        set_skill("piaoyu-steps", 200);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");
        setup();

        carry_object(__DIR__"obj/bingxue")->wear();
        carry_object(__DIR__"obj/ziqingsword")->wield();
}

void attempt_apprentice(object me)
{
        if( me->query("title") != "��ͨ����" || me->query("gender")!="Ů��" )
        {
		command("say ����������ֻ��Ů���ӡ�");
		return;
        }

	if( (me->query("per") < 25) || (me->query("age") >= 30) )
	{
		command("say ����������ֻ������Ư����Ů���ӣ��㻹���߰ɡ�");
		return;
	}

	else
	{
		command("xixi");
		command("say �ܺã���Ȼ������Ե���Ժ������ѧ�ɡ�\n");
		command("recruit " + me->query("id") );
	}
}

int recruit_apprentice(object me)
{
	::recruit_apprentice(me);
	me->set("class", "rain");
        return 1;
}

string ask_me(object me)
{
	if(me->query("class") != "rain" || me->query("gender") != "Ů��")
		return "�������ʲô��\n";

	if(me->query("combat_exp") < 1800000)
		return "��Ľ���������̫ǳ����ĥ��ĥ���ɡ�\n";

	if(me->query_skill("sword") < 200)
		return "��Խ�����Ƿ����������ʮ��Σ���Ѱ죬�㻹���Ȱ��书���ðɡ�\n";

	if(me->query_temp("feiyu_upgrade_quest/ask_my"))
		return "��֪���Ķ��������ˣ����Լ�ȥ��취�ɡ�\n";

        me->set_temp("feiyu_upgrade_quest/ask_my",1);
            
	return "�Ƕ��Ƕ�ʮ��ǰ�ľ����ˣ���ʱ������Ҳ��С��ֻ����һЩ
            ӡ����ʱʦ��������һ���С����ˡ������ӣ����˳��ú�
            Ӣ���书Ҳ�ܺá����Ǿ��������˼��������Ҷ���ϲæµ
            ��ʱ������ȴ���˲���������ʦ�洫�µ�����������
            ������֮��--����̽�����ʱʦ������׷�ϣ�ֻ����������
            �أ�ȴ�����������ˣ��Ӵ�������Ѷ��ʦ�����Ҳ��Ȼ���ߡ�
            �������²����Ĵ��������˵���Ϣ����������ҲҪ�������
            ��ޣ�������̽�������д�־��Ϊ����Ȼ�����������㣬
            ��˵���츮�����Ի�֪��һЩ����������ȥ�˽�һ�¡���
            �����·ǳ����գ���Ҫ���С�ġ�\n";
}
