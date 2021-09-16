// huanerjj.c

#include <ansi.h>

inherit NPC;

int ask_me1(object me);
int ask_me(object me);

void create()
{
        set_name("������", ({ "wu ruochen","wu","ruochen" }) );
        set("gender", "����" );
        set("age", 52);
        set("title", HIW "����������ң��" NOR);
        set("attitude", "peaceful");
        set("combat_exp",1600000);
        set("max_force",3200);
        set("force",3200);
        set("force_factor",200);
        set("inquiry", ([
                "����" : (: ask_me :),
                "������" : (: ask_me1 :),
        ]) );

        set_skill("unarmed",280);
        set_skill("force",280);
        set_skill("dodge",280);
        set_skill("parry",280);

        set_skill("suiyu-force", 250);
        set_skill("zuiyue-strike", 250);
        set_skill("piaoyu-steps", 250);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("force","suiyu-force");
        set("long","���ǻ����ľ˾�,�Ǹ�������������ʦ.\n");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_me(object me)
{
        command("say �ǻ����Ǹ�СѾͷ����������\n");
        call_out("greeting",5,me);
        return 1;
}

void greeting(object me)
{
	object ob;

	if( !objectp(me) || (environment(me) != environment()) )
		return;

        if(!me->query_temp("mark/huaner_pu"))  
        {
		command("shake");
		return;
        }

        if(sizeof(filter_array(children(__DIR__"obj/xiaopu"),(: clonep :))) > 0)
	{
		tell_object(me,"�Ǳ��������Ѿ�������,������һ��.\n");
		return;
	}

	command ("nod");
	command ("say ��Ȼ���ҵĺ�ֶŮ��������,�Ȿ��������ȥ��.\n");
	ob=new(__DIR__"obj/xiaopu");
	ob->move(me);

	return;
}

int ask_me1(object me)
{
	if(!me->query_temp("mark/huaner_pu"))  
		return 0;

	command("say �Ǹ������Ҽǵ��Ƿ������������һ��������.��ȥ�ҿ���.");
	me->set_temp("mark/louth_quxiao",1);
	return 1;
}
