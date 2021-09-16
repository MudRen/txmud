// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int kill_me(object me);
int ask_father(object me);
int ask_rainplate(object me);

void create()
{
	object ob;

        set_name("����ܲ", ({ "master zhang", "master","zhang" }) );
        set("long","������ܲ��һ����ʮ���СѾͷ����������ĸ
�̸�����һ����ȴ�Ѿ��ڽ����Ϻ��е��֡�\n");
        set("title", RED"����Ů����"NOR);
        set("attitude", "heroism");
        set("gender","Ů��");

	set("class","rain");
	set("age",22);

        set("str", 35);
        set("cor", 40);
        set("per", 30);
        set("int",30);
	set("kar",50);

	set("max_kee",2500);
	set("max_gin",2000);
	set("max_sen",2000);

        set("max_force",8000);
        set("force",8000);
        set("force_factor",240);

	set("combat_exp", 6000000);
        set("inquiry", ([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"�뿪" : (: call_other, __FILE__, "want_to_leave" :),
	"��ʦ" : (: call_other, __FILE__, "want_to_leave" :),

                "��ɱ��": (: kill_me :),
                "����"	: (: ask_father :),
                "�����": (: ask_rainplate :),
        ]) );

        set_temp("apply/damage",200);

        create_family("����", 1, "Ů����");
        set_skill("unarmed", 220);
        set_skill("sword",300);
        set_skill("force",280);
        set_skill("parry", 280);
        set_skill("dodge", 280);
        set_skill("literate",250);
        set_skill("jieqing-sword", 280);
        set_skill("suiyu-force", 250);
        set_skill("zuiyue-strike", 250);
        set_skill("feiyu-zhen", 250);
        set_skill("piaoyu-steps", 250);

        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");
        setup();

	ob = carry_object(__DIR__"obj/ziyansword");
        if(objectp(ob))
                ob->wield();

        carry_object(__DIR__"obj/shang")->wear();
}

void attempt_apprentice(object me)
{
	if(!me->query_temp("feiyu_upgrade_quest/passed"))
		return;

	else
	{
		me->delete_temp("feiyu_upgrade_quest");
		command("smile");
		command("say �ã������Ҿ�����Ϊͽ����\n");
		command("recruit " + me->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	::recruit_apprentice(ob);
	ob->set("class","rain");
	return 1;
}

int kill_me(object me)
{
	if(me->query("class") != "rain")
		return 0;

	if(me->query("combat_exp") > 300000 )
	{
		command("?");
		command ("say ������֪����̫���ˣ����Ѿ���������Ļ���ˡ�\n");
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
		return 1;
	}

	command("?");
	command("say ������ô����");
	return 1;
}

int accept_object(object me, object ob)
{
	object obj;

	if(me->query("class") != "rain")
		return 0;

	if(ob->query("id") == "feiyu sword")
	{
		if(ob->query("master") != me->query("id"))
		{
			command("say ��ѽ��Ǽٵģ���û�ã�");
			return 1;
		}

		me->set_temp("feiyu_upgrade_quest/passed",1);

		say("����ܲ˵����û�뵽���Ȼ�һ�������֮������Ϊ�������˴��ˡ�\n");
		return 1;
	}

	if(ob->query("id") == "qingxia sword")
        {
                if (!me->query_temp("louth_kfather"))
			return 1;

                tell_object(me,"����ܲ�������Ȼ����ɱ���Ǹ���������Ҳ
û��ʲô���Ա�����ģ���������־��
��������ĸ�ף�����ѡ���꾪�轣������
����ġ�\n");
		obj=new(__DIR__"obj/shoujuan"); 
		obj->move(me);
		ob->set("master",me->query("id"));
		return 1;
        }
        return 0;
}

int ask_father(object me)
{
        command ("heng");
        command ("say ��Ҫ���Ǹ���������Ĺ�����������ܰ���ɱ
�������û������ϵ���ϼ�����ң��һ����ر�����ġ�\n");
        me->set_temp("louth_kfather",1);
        return 1;
}

int ask_rainplate(object me)
{
	if(me->query("combat_exp") <= 1200000 )
	{
		command ("say ����Ŀǰ����������������ȡ����\n");
		return 1;
	}

	command ("nod");
	command ("say �ã�ȥ���Űɣ�����������õĻ����Ǹ��˾��ܸ�������\n");
	me->set_temp("louth_qupai",1);
	return 1;
}
