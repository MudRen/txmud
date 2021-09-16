// huanerjj.c

#include <ansi.h>

inherit NPC;

int ask_me1(object me);
int ask_me(object me);

void create()
{
        set_name("吴若尘", ({ "wu ruochen","wu","ruochen" }) );
        set("gender", "男性" );
        set("age", 52);
        set("title", HIW "清箫雅琴逍遥客" NOR);
        set("attitude", "peaceful");
        set("combat_exp",1600000);
        set("max_force",3200);
        set("force",3200);
        set("force_factor",200);
        set("inquiry", ([
                "箫谱" : (: ask_me :),
                "白玉箫" : (: ask_me1 :),
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
        set("long","他是环儿的舅舅,是个很有名气的乐师.\n");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_me(object me)
{
        command("say 是环儿那个小丫头让你来的吗？\n");
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
		tell_object(me,"那本箫谱我已经给人了,你来晚一步.\n");
		return;
	}

	command ("nod");
	command ("say 既然是我的好侄女让你来的,这本箫谱你拿去吧.\n");
	ob=new(__DIR__"obj/xiaopu");
	ob->move(me);

	return;
}

int ask_me1(object me)
{
	if(!me->query_temp("mark/huaner_pu"))  
		return 0;

	command("say 那根玉箫我记得是放在了绯雨阁里的一间寝室里.你去找看吧.");
	me->set_temp("mark/louth_quxiao",1);
	return 1;
}
